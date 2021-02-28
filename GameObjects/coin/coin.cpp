#include "coin.h"
#include "GameObjects/lasso/lasso.h"


Coin::Coin(const Vector2D &_position, const Vector2D &_velocity, const Vector2D &_acceleration,
           bool isPaused) : MovingObject(_position, _velocity, _acceleration, isPaused) {

    // setup all dynamics of coin (x,v,d)
    startPosition = _position;
    startVelocity = _velocity;
    acceleration = _acceleration;

    if (isPaused) {
        pause();
    } else {
        unpause();
    }
    destroyed = false;
    Coin::init();
}

void Coin::init() {
    buildObject();
    MovingObject::reset(startPosition, startVelocity, acceleration, isPaused()); // reset MO
}

//coin sprite building
void Coin::buildObject() {
    coin_circle.reset(0, 0, COIN_SIZE);
    coin_circle.setColor(COLOR("gold"));
    coin_circle.setFill(true);
    addPart(&coin_circle);
}

void Coin::reset() {
    MovingObject::reset(startPosition, startVelocity, acceleration, isPaused());
}
