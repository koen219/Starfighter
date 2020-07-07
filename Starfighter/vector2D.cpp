#include "vector2D.h"

double vector2D::operator*(vector2D P) {
	return x * P.x + y * P.y;
}

vector2D vector2D::operator+(vector2D P) {
	vector2D Q(x + P.x, y + P.y);
	return Q;
}

double vector2D::magnitude() {
	return sqrt(x * x + y * y);
}

vector2D vector2D::operator*(double c) {
	vector2D Q(c * x, c * y);
	return Q;
}

bool vector2D::operator==(vector2D P) {
	return (P.x == x) and (P.y == y);
}