#include "lasso.h"


Lasso::Lasso(double speed, double angle_deg,
      Vector2D _acceleration, bool isPaused) : MovingObject({0, 0}, {0, 0}, {0, 0},
                                                                                  isPaused) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    releaseVelocity = fromPolar(speed, angle_deg * PI / 180.0);
    startPosition = {(PLAY_X_START + LASSO_X_OFFSET), (PLAY_Y_HEIGHT - LASSO_Y_HEIGHT)};

    lasso_looped = false;
    acceleration = _acceleration;
    Lasso::init();
}


// render the lasso band to screen
void Lasso::draw_lasso_band() {
    double len = (release_speed / MAX_RELEASE_SPEED) * LASSO_BAND_LENGTH;
    double arad = release_angle_deg * PI / 180.0;
    double xlen = len * cos(arad);
    double ylen = len * sin(arad);
    lasso_band.reset(startPosition.x, startPosition.y, (startPosition.x - xlen), (startPosition.y - ylen));
    lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::init() {
    //initialize the lasso state / objects

    lasso_circle.reset(startPosition.x, startPosition.y, LASSO_SIZE);
    lasso_circle.setColor(COLOR("red"));
    lasso_circle.setFill(true);

    lasso_loop.reset(startPosition.x, startPosition.y, LASSO_SIZE / 2);
    lasso_loop.setColor(COLOR("brown"));
    lasso_loop.setFill(true);

    addPart(&lasso_circle);
    addPart(&lasso_loop);

    coins.clear();
    bombs.clear();

    lasso_line.reset(startPosition.x, startPosition.y, startPosition.x, startPosition.y);

    lasso_line.setColor(COLOR("brown"));
    lasso_band.setColor(COLOR("BlueViolet"));

    draw_lasso_band();

    MovingObject::reset(startPosition, releaseVelocity, acceleration, isPaused());

} // End Lasso::initLasso()

void Lasso::yank() {
    MovingObject::reset(startPosition, releaseVelocity, acceleration, true);
    lasso_loop.reset(startPosition.x, startPosition.y, LASSO_SIZE / 2);

    lasso_loop.setFill(true);
    lasso_looped = false;

    // handle the coins caught by lasso
    if (!coins.empty()) {

        state->score.GoldCoin += coins.size(); //tally score to the main scoreboard

        // iterate over each coin
        for (auto coin : coins) {
            coin->hide();
            coin->reset();
            coin->pause();
            coin->destroyed = true;
        }

        coins.clear(); // erase all coins
    }

    state->bombingInfo.bombNo = bombs.size(); // get bomb no of bombs caught

    if (!bombs.empty()) {

        // iterating over each bomb
        for (auto &bomb : bombs) {
            bomb->reset();
            bomb->hide();
            bomb->pause();
            bomb->destroyed = true;
        }

        bombs.clear(); // clear all bombs
    }
} // End Lasso::yank()

// function to loopit lasso
void Lasso::loopit() {
    if (lasso_looped) { return; } // return if lasso already looped.
    lasso_loop.reset(getXPosition(), getYPosition(), LASSO_RADIUS);
    lasso_loop.setFill(false);
    lasso_looped = true;
} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg) {
    release_angle_deg += angle_deg; // rotated lasso angle_deg

    // wrap lasso angle to 360 for smooth control
    if (release_angle_deg < 0) { release_angle_deg += 360; }
    if (release_angle_deg > 360) { release_angle_deg -= 360; }

    releaseVelocity = fromPolar(release_speed, release_angle_deg * PI / 180.0); // calculate projection velocity.

    reset(startPosition, releaseVelocity, acceleration, true); // apply calculated projection values
} // End Lasso::addAngle()

// addSpeed() adjust lasso projection speed.
void Lasso::addSpeed(double speed) {
    release_speed += speed;

    // clamps projection speed to a given range
    if (release_speed < MIN_RELEASE_SPEED) {
        release_speed = MIN_RELEASE_SPEED;
    }
    // clamps projection speed to a given range
    if (release_speed > MAX_RELEASE_SPEED) {
        release_speed = MAX_RELEASE_SPEED;
    }

    releaseVelocity = fromPolar(release_speed, release_angle_deg * PI / 180.0);

    reset(startPosition, releaseVelocity, acceleration, true); // apply computed release values.
} // End Lasso::addSpeed()

// perform lasso updates
void Lasso::nextStep(double stepTime) {
    draw_lasso_band();

    MovingObject::nextStep(stepTime); // step lasso MO.

    // reset lasso if lasso goes below ground
    if (getYPosition() > PLAY_Y_HEIGHT) {
        yank(); // pullback lasso
    }

    lasso_line.reset(startPosition.x, startPosition.y, getXPosition(), getYPosition()); // adjust lassoLine
} // End Lasso::nextStep()

//checks if the given coin can be caught
void Lasso::check_for_coin(Coin *coinPtr) {
    double distance = (getPosition() - coinPtr->getPosition()).magnitude(); // compute distance

    // check the distance + adjust for coin size
    if (distance <= LASSO_RADIUS + COIN_SIZE) {
        coins.push_back(coinPtr); // add coin to vector of caught coins

        coinPtr->getAttachedTo(this); // bind coin MO to lasso ( parent coin motion to lasso )
    }
} // End Lasso::check_for_coin()

//checks if the given bomb can be caught similar to check_for_coins
void Lasso::check_for_bomb(Bomb *bombPtr) {
    double distance = (getPosition() - bombPtr->getPosition()).magnitude();

    // binds the bomb to lasso similar to coin binding
    if (distance <= LASSO_RADIUS + BOMB_SIZE) {
        bombPtr->getAttachedTo(this);

        bombs.push_back(bombPtr);
    }
} // End Lasso::check_for_bomb()

bool Lasso::isLassoLoped() {
    return lasso_looped;
}
