#pragma once
#include<cmath>
#include<iostream>
class vector2D //this is vector
{
public:
	double x;
	double y;

	inline vector2D() {
		x = 0.0; y = 0.0;
	}
	inline vector2D(double xx, double yy) {
		x = xx; y = yy;
	}
	inline void print() {
		std::cout << '(' << x << ',' << y << ')';
	}
	vector2D operator+(vector2D);
	double operator*(vector2D);
	double magnitude();
	vector2D operator*(double);
	bool operator==(vector2D);
};

