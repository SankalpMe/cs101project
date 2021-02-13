#include "MagnetGiver.h"


void MagnetGiver::init() {
    buildObject();
    MovingObject::reset(startPosition, startVelocity, acceleration, isPaused());
}
void MagnetGiver::buildObject() {
    coin_circle.reset(0, 0, COIN_SIZE);
    coin_circle.setColor(COLOR("gold"));
    coin_circle.setFill(true);
    addPart(&coin_circle);
}
void MagnetGiver::reset() {
    MovingObject::reset(startPosition, startVelocity, acceleration, isPaused());
}
