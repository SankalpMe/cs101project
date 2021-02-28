//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_PRELIMLEVELRENDER_H
#define LASSOPROJECT_PRELIMLEVELRENDER_H

#include <simplecpp>
#include "Misc/GameConstants.h"
#include "GameHandlers/State/GameState.h"
#include "UI/Heart/HeartUI.h"
#include "UI/Coin/CoinUI.h"
#include "UI/Key/KeyUI.h"
#include "UI/TimeLeft/TimeUI.h"

// the complete UI Of the game this is class is responsible for all ui elements we see in this game.
class PrelimLevelRender {
    Rectangle ybar;
    Rectangle xbar;


    GameState *state;
    HeartUI heartUI;
    CoinUI coinUI;
    KeyUI keyUI;
    Text MagText;
    string MagString;
    TimeUI timeUI;
public:
    PrelimLevelRender() : heartUI(), coinUI(), keyUI(), timeUI() {

    }

    void init(); // initializes all ui subcomponents

    //bind game state
    void bindState(GameState *_state) {
        state = _state;
        heartUI.setMaxHearts(state->health.maxHearts);
    } //end : bindState(GameState *_state)

    void step(); // step() ui ahead with time
};


#endif //LASSOPROJECT_PRELIMLEVELRENDER_H
