#ifndef __COIN_H__
#define __COIN_H__

#include "GameObjects/MO/MovingObject.h"
#include "Misc/Vector2D/Vector2D.h"
#include "Misc/GameConstants.h"

class Coin : public MovingObject {

protected:
    Circle coin_circle;
    Vector2D startPosition;
    Vector2D startVelocity;
    Vector2D acceleration;
public:
    bool destroyed;

    Coin(const Vector2D &_position, const Vector2D &_velocity = {0, 0}, const Vector2D &_acceleration = {0, 0},
         bool isPaused = true);

    virtual void init(); // init coin and MO ( MovingObject )

    virtual void buildObject(); // creates coin sprite

    void reset(); // reset coin


    // functions below toggle visibility of coins

    virtual void hide() {
        coin_circle.hide();
    }

    virtual void show() {
        coin_circle.show();
    }
}; // End class Coin

#endif
