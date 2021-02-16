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
    MagnetGiver() {
        magnetSprite = new MagnetSprite({300,300});
        magnetSprite->init();
        magnetSprite->nextStep(0);
        disabled = false;
    }
    void setPosition(Vector2D pos){
        magnetSprite->setPosition(pos);
    }
    bool step(Lasso *lasso,GameState *state){
        magnetSprite->nextStep(0);
            if( !disabled && (lasso->getPosition() - magnetSprite->getPosition()).magnitude() <= LASSO_RADIUS  ){
                state->isMagnetized = true;
                state->magnetStepRemaining = MAGNET_DURATION*10;
                return true;
            }else{
                return false;
            }
    }

    void disable() {
        disabled =true;
        magnetSprite->hide();
    }

    void enable(Vector2D position={300,300}){
        magnetSprite->setPosition(position);
        disabled = false;
        magnetSprite->show();
    }

}; // End class Coin


#endif //LASSOPROJECT_MAGNETGIVER_H
