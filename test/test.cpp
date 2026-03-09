#include <gtest/gtest.h>
#include "Polynomial.h"

TEST(PolynomialTest, can_create_empty_polynomial) {
    Polynomial p;
    EXPECT_TRUE(p.isEmpty());
    EXPECT_EQ(p.getSize(), 0);
}

TEST(PolynomialTest, can_add_monom) {
    Polynomial p;
    Monom m(2.5, 2, 1, 0);
    p.addMonom(m);

    EXPECT_EQ(p.getSize(), 1);
    EXPECT_FALSE(p.isEmpty());
}

//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "TList.h"  // ваш класс списка
//
//using namespace std;
//
//int main() {
//    // Инициализация генератора случайных чисел
//    srand(time(nullptr));
//
//    // Размер массива
//    const int SIZE = 15;
//
//    // Создаем и заполняем массив случайными числами
//    int arr[SIZE];
//    cout << "Исходный массив: ";
//    for (int i = 0; i < SIZE; i++) {
//        arr[i] = rand() % 30;  // случайные числа от 0 до 29
//        cout << arr[i] << " ";
//    }
//    cout << endl << endl;
//
//    // Список указателей на первые элементы пар с нарушенным порядком
//    TList<int*> badPairs;
//
//    // Поиск пар с нарушенным порядком
//    cout << "Анализ пар соседних элементов:" << endl;
//    for (int i = 0; i < SIZE - 1; i++) {
//        cout << "  Пара (" << arr[i] << ", " << arr[i + 1] << "): ";
//
//        if (arr[i] > arr[i + 1]) {  // порядок нарушен
//            badPairs.push_back(&arr[i]);
//            cout << "НАРУШЕНИЕ! (" << arr[i] << " > " << arr[i + 1] << ")" << endl;
//        }
//        else {
//            cout << "порядок соблюден (" << arr[i] << " <= " << arr[i + 1] << ")" << endl;
//        }
//    }
//
//    // Вывод результатов
//    cout << "\n=== РЕЗУЛЬТАТ ===" << endl;
//    cout << "Всего нарушений: " << badPairs.size() << endl;
//
//    if (badPairs.empty()) {
//        cout << "Массив полностью упорядочен по возрастанию!" << endl;
//    }
//    else {
//        cout << "Указатели на первые элементы нарушенных пар:" << endl;
//
//        // Создаем копию списка для обхода (чтобы не разрушать оригинал)
//        TList<int*> temp = badPairs;
//        int pairNum = 1;
//
//        while (!temp.empty()) {
//            int* ptr = temp.pop_front();
//            cout << "  Пара #" << pairNum++ << ": указатель " << ptr
//                << " (значение " << *ptr << ")" << endl;
//        }
//
//        // Вывод значений для наглядности
//        cout << "\nЗначения элементов в нарушенных парах:" << endl;
//        temp = badPairs;
//        pairNum = 1;
//
//        while (!temp.empty()) {
//            int* ptr = temp.pop_front();
//            cout << "  Пара #" << pairNum++ << ": " << *ptr << " > " << *(ptr + 1) << endl;
//        }
//    }
//
//    return 0;
//}