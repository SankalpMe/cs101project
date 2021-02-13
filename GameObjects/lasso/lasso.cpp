#include "lasso.h"

using namespace simplecpp;

void Lasso::draw_lasso_band() {
    double len = (release_speed / MAX_RELEASE_SPEED) * LASSO_BAND_LENGTH;
    double arad = release_angle_deg * PI / 180.0;
    double xlen = len * cos(arad);
    double ylen = len * sin(arad);
    lasso_band.reset(startPosition.x, startPosition.y, (startPosition.x - xlen), (startPosition.y - ylen));
    lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::init() {


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

    if (!coins.empty()) {

        state->score.GoldCoin += coins.size(); //tally score to the main scoreboard

        for (auto coin : coins) {
            coin->hide();
            coin->reset();
            coin->pause();
            coin->destroyed = true;
        }
        coins.clear();
    }

    state->bombingInfo.bombNo = bombs.size();

    if (!bombs.empty()) {

        for (auto &bomb : bombs) {
            bomb->reset();
            bomb->hide();
            bomb->pause();
            bomb->destroyed = true;
        }



        cout << "It's a BOMB AND BOOM" << endl;
        bombs.clear();
    }
} // End Lasso::yank()

void Lasso::loopit() {
    if (lasso_looped) { return; } // Already looped
    lasso_loop.reset(getXPosition(), getYPosition(), LASSO_RADIUS);
    lasso_loop.setFill(false);
    lasso_looped = true;
} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg) {
    release_angle_deg += angle_deg;
    if (release_angle_deg < 0) { release_angle_deg += 360; }
    if (release_angle_deg > 360) { release_angle_deg -= 360; }

    releaseVelocity = fromPolar(release_speed, release_angle_deg * PI / 180.0);

    reset(startPosition, releaseVelocity, acceleration, true);
} // End Lasso::addAngle()

void Lasso::addSpeed(double speed) {
    release_speed += speed;
    if (release_speed < MIN_RELEASE_SPEED) { release_speed = MIN_RELEASE_SPEED; }
    if (release_speed > MAX_RELEASE_SPEED) { release_speed = MAX_RELEASE_SPEED; }

    releaseVelocity = fromPolar(release_speed, release_angle_deg * PI / 180.0);
    reset(startPosition, releaseVelocity, acceleration, true);
} // End Lasso::addSpeed()

void Lasso::nextStep(double stepTime) {
    draw_lasso_band();
    MovingObject::nextStep(stepTime);
    if (getYPosition() > PLAY_Y_HEIGHT) { yank(); }
    lasso_line.reset(startPosition.x, startPosition.y, getXPosition(), getYPosition());
} // End Lasso::nextStep()

void Lasso::check_for_coin(Coin *coinPtr) {
    double distance = (getPosition() - coinPtr->getPosition()).magnitude();
    if (distance <= LASSO_RADIUS) {
        coins.push_back(coinPtr);
        coinPtr->getAttachedTo(this);
    }
} // End Lasso::check_for_coin()

void Lasso::check_for_bomb(Bomb *bombPtr) {
    double distance = (getPosition() - bombPtr->getPosition()).magnitude();
    if (distance <= LASSO_RADIUS) {

        bombPtr->getAttachedTo(this);
        bombs.push_back(bombPtr);
    }
} // End Lasso::check_for_bomb()

bool Lasso::isLassoLoped() {
    return lasso_looped;
}