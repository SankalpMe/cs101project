//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_MAGNETGIVER_H
#define LASSOPROJECT_MAGNETGIVER_H


#include "GameObjects/MO/MovingObject.h"
#include "Misc/Vector2D/Vector2D.h"
#include "Misc/GameConstants.h"
#include "Misc/Magnet/Sprite/MagnetSprite.h"
#include "GameHandlers/State/GameState.h"
#include "GameObjects/lasso/lasso.h"

class MagnetGiver {


public:
    MagnetSprite *magnetSprite;
    bool disabled;

    MagnetGiver();

    void setPosition(Vector2D pos); // setPosition of magnetGiver

    bool step(Lasso *lasso, GameState *state); // step / update magnetGiver

    void disable(); // disable magnet Giver

    void enable(Vector2D position = {300, 300}); // enables magnet giver + does setup.

}; // End class Coin


#endif //LASSOPROJECT_MAGNETGIVER_H
