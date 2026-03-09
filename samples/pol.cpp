#include "Polynomial.h"
#include <iostream>

int main() {
    // Создание мономов
    Monom m1(2.5, 2, 1, 0);   // 2.5x^2y
    Monom m2(3.0, 0, 2, 1);   // 3y^2z
    Monom m3(1.0, 1, 0, 0);   // x
    Monom m4(4.0, 0, 0, 0);   // 4

    // Создание полиномов
    Polynomial p1;
    p1.addMonom(m1);
    p1.addMonom(m2);
    p1.addMonom(m3);

    Polynomial p2;
    p2.addMonom(m4);
    p2.addMonom(m3);

    std::cout << "p1 = ";
    p1.print();  // 2.5x^2y + 3y^2z + x

    std::cout << "p2 = ";
    p2.print();  // x + 4

    // Сложение
    Polynomial sum = p1 + p2;
    std::cout << "p1 + p2 = ";
    sum.print();  // 2.5x^2y + 3y^2z + 2x + 4

    // Вычитание
    Polynomial diff = p1 - p2;
    std::cout << "p1 - p2 = ";
    diff.print();  // 2.5x^2y + 3y^2z - 4

    // Умножение
    Polynomial prod = p1 * p2;
    std::cout << "p1 * p2 = ";
    prod.print();  // (2.5x^2y + 3y^2z + x) * (x + 4)

    // Вычисление значения
    double val = p1.evaluate(2.0, 1.0, 3.0);
    std::cout << "p1(2,1,3) = " << val << std::endl;

    return 0;
}