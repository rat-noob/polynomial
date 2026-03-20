#pragma once
#include "TList.h"
#include "Monom.h"
#include <cmath>
#include <iostream>

class Polynomial {
	TList<Monom> monoms;

	void sortMonoms() {
        if (monoms.size() <= 1) return;

        bool swapped;
        do {
            swapped = false;
            auto it1 = monoms.begin();
            auto it2 = monoms.begin();
            ++it2;

            while (it2 != monoms.end()) {
                if ((*it2).getPackDeg() < (*it1).getPackDeg()) {
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
  
    /*void combineLikeTerms() {
        if (monoms.size() <= 1) return;

        sortMonoms(); 
        TList<Monom> result;

        auto it = monoms.begin();
        Monom current = *it;
        ++it;

        while (it != monoms.end()) {
            if (current.getPackDeg() == (*it).getPackDeg()) {
                current = current + *it;
            }
            else {
                if (!current.isZero()) {
                    result.push_back(current);
                }
                current = *it;
            }
            ++it;
        }

        
        if (!current.isZero()) {
            result.push_back(current);
        }

        monoms = result;
    }*/
public:
   
    Polynomial() = default;

    Polynomial(const Monom& m) {
        if (!m.isZero()) {
            monoms.push_back(m);
        }
    }

    Polynomial(const Polynomial& other) = default;

    Polynomial& operator=(const Polynomial& other) = default;

    
    void addMonom(const Monom& m) {
        if (m.isZero()) return;
        if (monoms.empty()) {
            monoms.push_back(m);
            return;
        }
        unsigned int packedDeg = m.getPackDeg();

        auto it = monoms.begin();
        size_t index = 0;

        while (it != monoms.end()) {
            unsigned int currentPacked = (*it).getPackDeg();
            if (packedDeg == currentPacked) {
                Monom newMonom = *it + m;  

                if (newMonom.isZero()) {
                    monoms.remove(index);
                }
                else {
                    *it = newMonom;
                }
                return;
            }
            else if (packedDeg < currentPacked) {
                monoms.insert(index, m);
                return;
            }
            ++it;
            ++index;
        }
        monoms.push_back(m);

        
        
        
        
        
       /* if (!m.isZero()) {
            monoms.push_back(m);
            combineLikeTerms();  
        }*/
    }

    void clear() {
        monoms.clear();
    }
 
    int getSize() const {
        return monoms.size();
    }

    
    bool isEmpty() const {
        return monoms.empty();
    }

    Polynomial operator+( Polynomial& other)  {
        
        Polynomial result;

        auto it1 = monoms.begin();
        auto it2 = other.monoms.begin();

        while (it1 != monoms.end() && it2 != other.monoms.end()) {
            if ((*it1).getPackDeg() < (*it2).getPackDeg()) {
                result.monoms.push_back(*it1);
                ++it1;
            }
            else if ((*it1).getPackDeg() > (*it2).getPackDeg()) {
                result.monoms.push_back(*it2);
                ++it2;
            }
            else {
                Monom sum = *it1 + *it2;
                if (!sum.isZero()) {
                    result.monoms.push_back(sum);
                }
                ++it1;
                ++it2;
            }
        }
        while (it1 != monoms.end()) {
            result.monoms.push_back(*it1);
            ++it1;
        }
        while (it2 != other.monoms.end()) {
            result.monoms.push_back(*it2);
            ++it2;
        }

        return result;
    }

    Polynomial operator-( Polynomial& other)  {
        
        return *this + (-other);
 
    }

    Polynomial operator*(const Polynomial& other) const {
        
        Polynomial result;

        TList<Monom> temp1 = monoms;
        while (!temp1.empty()) {
            Monom m1 = temp1.pop_front();

            TList<Monom> temp2 = other.monoms;
            while (!temp2.empty()) {
                Monom m2 = temp2.pop_front();
                result.addMonom(m1*m2);
            }
        }
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
    Polynomial operator-() const {
        Polynomial result;

        TList<Monom> temp = monoms;
        while (!temp.empty()) {
            Monom m = temp.pop_front();
            result.monoms.push_back(Monom(-m.getCoef(),
                m.getXDeg(),
                m.getYDeg(),
                m.getZDeg()));
        }

        return result;
    }
    bool operator==(const Polynomial& other) const {
        if (monoms.size() != other.monoms.size()) return false;

        TList<Monom> temp1 = monoms;
        TList<Monom> temp2 = other.monoms;

        while (!temp1.empty() && !temp2.empty()) {
            Monom m1 = temp1.pop_front();
            Monom m2 = temp2.pop_front();

            if (m1.getPackDeg() != m2.getPackDeg() ||
                std::abs(m1.getCoef() - m2.getCoef()) > 1e-10) {
                return false;
            }
        }

        return temp1.empty() && temp2.empty();
    }

    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }
    double evaluate(double x, double y, double z) const {
        double result = 0.0;

        TList<Monom> temp = monoms;
        while (!temp.empty()) {
            result += temp.pop_front().evaluate(x, y, z);
        }

        return result;
    }
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
        cout << "\n";
    }

};