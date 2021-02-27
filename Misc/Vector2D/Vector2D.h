/*
 * Vector2D
 * the main filling of the game.
 * the true simplification that made many tasks a one liner
 * this game implementes simple Vector calculation model into the game
 * things like updating velocity / acceleration are simple as vel = acel * t;
 * dist = (a - b ).magnitude()
 * old implementation used a_x*b_x + b*b etc, all this complicated code
 */

#ifndef _VECTOR2D_INCLUDED_
#define _VECTOR2D_INCLUDED_

#include <simplecpp>
#include "Misc/GameConstants.h"

struct Vector2D {
    double x;
    double y;


    double magnitude() {
        return sqrt(x * x + y * y); // magnitude computation
    }

};


// operators defined for vectors
Vector2D operator*(const Vector2D &lhs, double a);

Vector2D operator*(double a, const Vector2D &rhs);

Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);

Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);
// end of operators

// creates vector from polar coordinates
Vector2D fromPolar(double r, double theta);

#endif
