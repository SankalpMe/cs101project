#ifndef __COIN_H__
#define __COIN_H__

#include "MovingObject.h"
#include "Vector2D.h"

class Coin : public MovingObject {
    Vector2D startPosition;
    Vector2D startVelocity;
    Vector2D acceleration;

    // Moving parts
    Circle coin_circle;

public:
    Coin(const Vector2D &_position, const Vector2D &_velocity = {0, 0}, const Vector2D &_acceleration = {0, 0},
         bool isPaused = true) : MovingObject(_position, _velocity, _acceleration, isPaused) {
        startPosition = _position;
        startVelocity = _velocity;
        acceleration = _acceleration;
        if (isPaused) {
            pause();
        } else {
            unpause();
        }

        Coin::init();
    }

    void init();
    void buildObject();

    void reset();

}; // End class Coin

#endif
