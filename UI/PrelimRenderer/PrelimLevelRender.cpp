//
// Created by sankalp on 06/02/21.
//

#include "PrelimLevelRender.h"

void PrelimLevelRender::step(){
    heartUI.render(state->health.heartLeft,state->health.maxHearts);

    coinUI.setCoins(state->score.GoldCoin);

    coinUI.step();

    keyUI.setKey(state->charInput);
    keyUI.step();
    if(state->isMagnetized){

        MagString = "MagTime: ";
        MagString += to_string(state->magnetStepRemaining/10);
        MagText.reset(20+(textWidth(MagString))/2,50+30,MagString);
        MagText.show();
    }else{
        MagText.hide();
    }

    timeUI.step(state->stepRemaining);

}