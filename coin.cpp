#include "coin.h"
#include "lasso.h"

void Coin::init() {

  coin_circle.reset(0, 0, COIN_SIZE);
  coin_circle.setColor(COLOR("gold"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
  MovingObject::reset(startPosition, startVelocity,acceleration, isPaused());
}

void Coin::reset() {
  MovingObject::reset(startPosition, startVelocity,acceleration, isPaused());
}
