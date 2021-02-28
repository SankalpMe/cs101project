#include "MagnetGiver.h"


MagnetGiver::MagnetGiver() {

    //init some basic magnetgive functionality
    magnetSprite = new MagnetSprite({300, 300});
    magnetSprite->init();
    magnetSprite->nextStep(0);

    disabled = false;
}

void MagnetGiver::setPosition(Vector2D pos) {
    magnetSprite->setPosition(pos);
}

bool MagnetGiver::step(Lasso *lasso, GameState *state) {

    //handle step update of magnet giver
    magnetSprite->step();

    if(disabled){
        magnetSprite->hide();
    }

    // handle if magnet gets caught
    if (!disabled && (lasso->getPosition() - magnetSprite->getPosition()).magnitude() <= LASSO_RADIUS) {
        //magnet automatically gets stuck to the lasso no need to loop
        state->isMagnetized = true;
        state->magnetStepRemaining = MAGNET_DURATION * 10;
        return true;
    } else {
        return false;
    }
}

void MagnetGiver::disable() {
    disabled = true;
    magnetSprite->hide();
}

void MagnetGiver::enable(Vector2D position) {
    magnetSprite->setPosition(position);
    disabled = false;
    magnetSprite->show();
}