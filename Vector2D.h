

#ifndef _VECTOR2D_INCLUDED_
#define _VECTOR2D_INCLUDED_

#include <simplecpp>
#include "GameConstants.h"
struct Vector2D {
    double x;
    double y;


    double magnitude() {
        return sqrt(x * x + y * y);
    }

};

Vector2D operator*(const Vector2D &lhs, double a);

Vector2D operator*(double a, const Vector2D &rhs);

Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);

Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);

Vector2D fromPolar(double r, double theta);

#endif
