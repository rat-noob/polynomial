#include <iostream>
#include <string>

// Подключаем ANTLR runtime
#include "antlr4-runtime.h"

// Подключаем сгенерированные файлы
#include "PolynomialLexer.h"
#include "PolynomialParser.h"

// Подключаем наш visitor
#include "PolyBuilderVisitor.h"

using namespace std;

/**
 * @brief Разбор строки и создание объекта Polynomial
 */
Polynomial parsePolynomial(const string& input) {
    // 1. Создаём входной поток
    antlr4::ANTLRInputStream inputStream(input);

    // 2. Лексер разбивает текст на токены
    PolynomialLexer lexer(&inputStream);

    // 3. Поток токенов
    antlr4::CommonTokenStream tokens(&lexer);

    // 4. Парсер строит дерево разбора
    PolynomialParser parser(&tokens);

    // 5. Запускаем парсинг с корневого правила "prog"
    auto tree = parser.prog();

    // 6. Visitor строит полином
    PolyBuilderVisitor visitor;
    Polynomial result = visitor.visitProg(tree).as<Polynomial>();

    return result;
}

int main() {
    cout << "=== Тестирование ANTLR парсера ===" << endl;

    // Тестовые выражения
    vector<string> tests = {
        "2x^2y + 3yz^2 - 4",
        "2.5x^2 + 3.5y - 1.5z",
        "x^2y^2z^2 + 2xyz - 3",
        "5",
        "a = 2x + 3y"
    };

    for (const auto& expr : tests) {
        cout << "\nВход: " << expr << endl;

        try {
            Polynomial p = parsePolynomial(expr);
            cout << "Результат: ";
            p.println();
        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}