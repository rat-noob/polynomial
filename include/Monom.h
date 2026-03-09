#pragma once
#include <iostream>
#include <cmath>


using namespace std;
class Monom {
	double coef;
	unsigned int degrees;

	static constexpr unsigned int Mask = 1023;
	static constexpr int Y_Shift = 10;
	static constexpr int Z_Shift = 20;


	unsigned int pack(int xDeg, int yDeg, int zDeg);
public:
	Monom():coef(0.0), degrees(0){}
	Monom(double _coef, int xDeg = 0, int yDeg = 0, int zDeg = 0) : coef(_coef), degrees(pack(xDeg, yDeg, zDeg)) {}
	Monom(const Monom& other) = default;


	double getCoef() const;
	int getXDeg()const;
	int getYDeg()const;
	int getZDeg()const;
	int getPackDeg()const;

	void setCoef(double cf);
	void setDeg(int xDeg, int yDeg, int zDeg);

	bool operator==(const Monom& other) const;
	bool operator!=(const Monom& other)const;
	bool operator<(const Monom& other)const;
	bool operator>(const Monom& other)const;

	Monom operator*(const Monom& other)const;
	Monom operator+(const Monom& other)const;
	Monom operator-(const Monom& other)const;

	Monom& operator=(const Monom& other) = default;

	double evaluate (double x, double y, double z)const;
	bool isZero()const;

	void printMonom()const;
};