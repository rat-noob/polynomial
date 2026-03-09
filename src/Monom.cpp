#include "Monom.h"

using namespace std;

unsigned int Monom::pack(int xDeg, int yDeg, int zDeg) {
		unsigned int res = 0;
		res = ((unsigned int)xDeg) | res;//x
		res = ((unsigned int)yDeg << 10) | res;//y
		res = ((unsigned int)zDeg << 20) | res;//z

		return res;
};
double Monom::getCoef() const { return coef; }

int Monom::getXDeg()const { return degrees & Mask; }
int Monom::getYDeg() const { return (degrees>>Y_Shift) & Mask; }
int Monom::getZDeg()const { return (degrees >> Z_Shift) & Mask; }
int Monom::getPackDeg()const { return degrees; }


void Monom::setCoef(double cf) { coef = cf; }
void Monom::setDeg(int xDeg, int yDeg, int zDeg) { degrees = pack(xDeg, yDeg, zDeg); }

bool Monom::operator==(const Monom& other) const { return degrees == other.degrees; }
bool Monom::operator!=(const Monom& other)const { return !(*this == other);/*доделать пон€ть*/  }

bool Monom::operator<(const Monom& other)const { return degrees < other.degrees; }
bool Monom::operator>(const Monom& other)const { return other < *this; }

Monom Monom::operator*(const Monom& other)const { return Monom(coef * other.coef, getXDeg() + other.getXDeg(), getYDeg() + other.getYDeg(), getZDeg() + other.getZDeg()); }
Monom Monom::operator+(const Monom& other) const {
	if (*this != other) throw std::invalid_argument("Cannot add monoms with different degrees");
	return Monom(
		coef + other.coef,
		getXDeg(), getYDeg(), getZDeg()
	);
}
Monom Monom::operator-(const Monom& other) const {
	if (*this != other) throw std::invalid_argument("Cannot sub monoms with different degrees");
	return Monom(
		coef - other.coef,
		getXDeg(), getYDeg(), getZDeg()
	);
}

double Monom::evaluate(double x, double y, double z) const {
	return coef *
		pow(x, getXDeg()) *
		pow(y, getYDeg()) *
		pow(z, getZDeg());
}
bool Monom::isZero() const { return coef == 0.0;}

void Monom::printMonom() const {
    if (coef == 0) {
        cout << "0";
        return;
    }

    int xDeg = getXDeg();
    int yDeg = getYDeg();
    int zDeg = getZDeg();

    if (coef != 1 || (xDeg == 0 && yDeg == 0 && zDeg == 0)) {
        cout << coef;
    }
    else if (coef == -1) {
        cout << "-";
    }

    // ¬ывод переменных со степен€ми
    if (xDeg > 0) {
        cout << "x";
        if (xDeg > 1) cout << "^" << xDeg;
    }
    if (yDeg > 0) {
        cout << "y";
        if (yDeg > 1) cout << "^" << yDeg;
    }
    if (zDeg > 0) {
        cout << "z";
        if (zDeg > 1) cout << "^" << zDeg;
    }
}






