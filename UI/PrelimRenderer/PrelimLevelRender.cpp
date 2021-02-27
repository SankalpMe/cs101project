//
// Created by sankalp on 06/02/21.
//

#include "PrelimLevelRender.h"

void PrelimLevelRender::init() {
    //ybar.reset(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    xbar.reset(WINDOW_X / 2, (PLAY_Y_HEIGHT + WINDOW_Y) / 2, WINDOW_X, WINDOW_Y - PLAY_Y_HEIGHT);
    xbar.setFill(true);
    xbar.setColor(COLOR("brown"));

    MagText.hide();
    MagString = "Magtime: 0";
    MagText.reset(20 + (textWidth(MagString)) / 2, 50 + 10, MagString);
    MagText.setColor(COLOR("red"));

} // end : init()
void PrelimLevelRender::step() {
    //call step / render / update function of individual ui subcomponents

    heartUI.render(state->health.heartLeft, state->health.maxHearts);

    coinUI.setCoins(state->score.GoldCoin);

    coinUI.step();

    keyUI.setKey(state->charInput);
    keyUI.step();

    if (state->isMagnetized) {

        MagString = "MagTime: ";
        MagString += to_string(state->magnetStepRemaining / 10);
        MagText.reset(20 + (textWidth(MagString)) / 2, 50 + 30, MagString);
        MagText.show();
    } else {
        MagText.hide();
    }

    timeUI.step(state->stepRemaining);

}

