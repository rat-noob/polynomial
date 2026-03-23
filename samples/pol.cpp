//#include "Polynomial.h"
//#include <iostream>
//
//
//using namespace std;
//int main() {
//    
//    Monom m1(2.5, 2, 1, 0);   
//    Monom m2(3.0, 0, 2, 1);   
//    Monom m3(1.0, 1, 0, 0);   
//    Monom m4(4.0, 0, 0, 0);   
//
//    
//    Polynomial p1;
//    p1.addMonom(m1);
//    p1.addMonom(m2);
//    p1.addMonom(m3);
//
//    Polynomial p2;
//    p2.addMonom(m4);
//    p2.addMonom(m3);
//
//    cout << "p1 = ";
//    p1.print();  
//
//    cout << "p2 = ";
//    p2.print();  
//
//    
//    Polynomial sum = p1 + p2;
//    cout << "p1 + p2 = ";
//    sum.print();  
//
//    
//    Polynomial diff = p1 - p2;
//    cout << "p1 - p2 = ";
//    diff.print();  
//
//    
//    Polynomial prod = p1 * p2;
//    cout << "p1 * p2 = ";
//    prod.print();  
//
//    
//    double val = p1.evaluate(2.0, 1.0, 3.0);
//    cout << "p1(2,1,3) = " << val << endl;
//}


#include <iostream>
#include <string>
#include <fstream>

// Подключаем ANTLR runtime
#include "antlr4-runtime.h"

// Подключаем сгенерированные ANTLR файлы
#include "PolynomialLexer.h"
#include "PolynomialParser.h"
#include "PolynomialBaseVisitor.h"

// Подключаем наш visitor
#include "parser/PolyBuilderVisitor.h"

// Подключаем наши классы
#include "src/Polynomial.h"
#include "src/Monom.h"

/**
 * @brief Функция для обработки одной строки ввода
 *
 * @param line Строка с выражением
 * @param visitor Visitor для обработки
 * @return true если нужно продолжить, false если exit
 */
bool processLine(const std::string& line, PolyBuilderVisitor& visitor) {
    if (line.empty()) {
        return true;
    }

    if (line == "exit") {
        return false;
    }

    try {
        // ============================================
        // 1. Создаём входной поток из строки
        // ============================================
        antlr4::ANTLRInputStream input(line);

        // ============================================
        // 2. Лексический анализ (разбиваем на токены)
        // ============================================
        PolynomialLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);

        // ============================================
        // 3. Синтаксический анализ (строим дерево разбора)
        // ============================================
        PolynomialParser parser(&tokens);

        // Запускаем парсинг с корневого правила "prog"
        // prog - программа, состоящая из одной или нескольких инструкций
        auto tree = parser.prog();

        // ============================================
        // 4. Обходим дерево разбора с помощью visitor
        // ============================================
        Polynomial result = visitor.visitProg(tree).as<Polynomial>();

        // ============================================
        // 5. Выводим результат
        // ============================================
        std::cout << "= ";
        result.println();

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Неизвестная ошибка" << std::endl;
    }

    return true;
}

/**
 * @brief Основная функция программы
 */
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Полиномиальный калькулятор" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Поддерживаемые операции:" << std::endl;
    std::cout << "  - Полиномы: 2.5x^2y + 3yz^2 - 4" << std::endl;
    std::cout << "  - Переменные: a = 2x + 3y" << std::endl;
    std::cout << "  - Выражения с переменными: a + 5z" << std::endl;
    std::cout << "  - exit - выход" << std::endl;
    std::cout << std::endl;

    // Создаём visitor (хранит переменные между командами)
    PolyBuilderVisitor visitor;

    std::string line;
    bool running = true;

    while (running) {
        std::cout << "> ";
        std::getline(std::cin, line);

        running = processLine(line, visitor);
    }

    std::cout << "До свидания!" << std::endl;

    return 0;
}