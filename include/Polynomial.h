#pragma once
#include "TList.h"
#include "Monom.h"
#include <cmath>
#include <iostream>

class Polynomial {
	TList<Monom> monoms;

	void sortMonoms() {
        if (monoms.size() <= 1) return;

        // Простая сортировка пузырьком для списка
        bool swapped;
        do {
            swapped = false;
            auto it1 = monoms.begin();
            auto it2 = monoms.begin();
            ++it2;

            while (it2 != monoms.end()) {
                if ((*it2).getPackDeg() < (*it1).getPackDeg()) {
                    // Меняем местами значения
                    Monom temp = *it1;
                    *it1 = *it2;
                    *it2 = temp;
                    swapped = true;
                }
                ++it1;
                ++it2;
            }
        } while (swapped);
	}
    // Приведение подобных мономов
    void combineLikeTerms() {
        if (monoms.size() <= 1) return;

        sortMonoms();  // сначала сортируем

        // Создаем временный список для результата
        TList<Monom> result;

        auto it = monoms.begin();
        Monom current = *it;
        ++it;

        while (it != monoms.end()) {
            if (current.getPackDeg() == (*it).getPackDeg()) {
                // Одинаковые степени - складываем
                current = current + *it;
            }
            else {
                // Разные степени - сохраняем текущий и переходим к следующему
                if (!current.isZero()) {
                    result.push_back(current);
                }
                current = *it;
            }
            ++it;
        }

        // Добавляем последний моном
        if (!current.isZero()) {
            result.push_back(current);
        }

        monoms = result;
    }
public:
    // Конструкторы
    Polynomial() = default;

    Polynomial(const Monom& m) {
        if (!m.isZero()) {
            monoms.push_back(m);
        }
    }

    Polynomial(const Polynomial& other) = default;

    // Оператор присваивания
    Polynomial& operator=(const Polynomial& other) = default;

    // Добавление монома
    void addMonom(const Monom& m) {
        if (!m.isZero()) {
            monoms.push_back(m);
            combineLikeTerms();  // автоматическое приведение подобных
        }
    }

    void clear() {
        monoms.clear();
    }
    // Количество мономов
    int getSize() const {
        return monoms.size();
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return monoms.empty();
    }

    // Оператор сложения полиномов
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;

        // Добавляем все мономы из other
        TList<Monom> temp = other.monoms;
        while (!temp.empty()) {
            result.monoms.push_back(temp.pop_front());
        }

        result.combineLikeTerms();
        return result;
    }

    // Оператор вычитания полиномов
    Polynomial operator-(const Polynomial& other) const {
        Polynomial result = *this;

        // Добавляем все мономы из other с противоположным знаком
        TList<Monom> temp = other.monoms;
        while (!temp.empty()) {
            Monom m = temp.pop_front();
            result.monoms.push_back(Monom(-m.getCoef(),
                m.getXDeg(),
                m.getYDeg(),
                m.getZDeg()));
        }

        result.combineLikeTerms();
        return result;
    }

    // Оператор умножения полиномов
    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;

        TList<Monom> temp1 = monoms;
        while (!temp1.empty()) {
            Monom m1 = temp1.pop_front();

            TList<Monom> temp2 = other.monoms;
            while (!temp2.empty()) {
                Monom m2 = temp2.pop_front();
                result.monoms.push_back(m1 * m2);
            }
        }

        result.combineLikeTerms();
        return result;
    }
    Polynomial operator*(double scalar) const {
        Polynomial result;

        TList<Monom> temp = monoms;
        while (!temp.empty()) {
            Monom m = temp.pop_front();
            result.monoms.push_back(Monom(m.getCoef() * scalar,
                m.getXDeg(),
                m.getYDeg(),
                m.getZDeg()));
        }

        return result;
    }
    double evaluate(double x, double y, double z) const {
        double result = 0.0;

        TList<Monom> temp = monoms;
        while (!temp.empty()) {
            result += temp.pop_front().evaluate(x, y, z);
        }

        return result;
    }
    // Печать полинома
    void print() const {
        if (monoms.empty()) {
            std::cout << "0";
            return;
        }

        TList<Monom> temp = monoms;
        bool first = true;

        while (!temp.empty()) {
            Monom m = temp.pop_front();

            if (m.getCoef() > 0 && !first) {
                std::cout << "+";
            }

            m.printMonom();
            first = false;
        }
    }

};