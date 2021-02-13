//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_MAGNETGIVER_H
#define LASSOPROJECT_MAGNETGIVER_H


#include "GameObjects/MO/MovingObject.h"
#include "Misc/Vector2D/Vector2D.h"
#include "Misc/GameConstants.h"



class MagnetGiver : public MovingObject {


public:
    Circle coin_circle;
    Vector2D startPosition;
    Vector2D startVelocity;
    Vector2D acceleration;
    bool destroyed;
    MagnetGiver(const Vector2D &_position, const Vector2D &_velocity = {0, 0}, const Vector2D &_acceleration = {0, 0},
         bool isPaused = true) : MovingObject(_position, _velocity, _acceleration, isPaused) {
        startPosition = _position;
        startVelocity = _velocity;
        acceleration = _acceleration;
        if (isPaused) {
            pause();
        } else {
            unpause();
        }
        destroyed = false;
        MagnetGiver::init();
    }

    virtual void init();

    virtual void buildObject();

    void reset();
    virtual void hide(){
        coin_circle.hide();
    }
    virtual void show(){
        coin_circle.show();
    }
}; // End class Coin


#endif //LASSOPROJECT_MAGNETGIVER_H
