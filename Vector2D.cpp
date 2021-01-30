#include "Vector2D.h"

Vector2D fromPolar(double r,double theta) {
    Vector2D x = {r * cos(theta),r*sin(theta) };
    
    return x;
}

Vector2D operator * (const Vector2D &lhs,double a) {
    Vector2D res = lhs;
    res.x *= a;
    res.y *= a;
    return move(res);
}

Vector2D operator* ( double a, const Vector2D &rhs){
    return move(rhs * a);
}

Vector2D operator+ (const Vector2D &lhs, const Vector2D &rhs){
    Vector2D res = lhs;
    res.x += rhs.x;
    res.y += rhs.y;
    return move(res);
}

Vector2D operator- (const Vector2D &lhs, const Vector2D &rhs){
    Vector2D res = lhs;
    res.x -= rhs.x;
    res.y -= rhs.y;
    return move(res);
}
