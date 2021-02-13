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

class PrelimLevelRender {
    Rectangle ybar;
    Rectangle xbar;

    Text charInput;
    Text coinScore;

    GameState *state;
    HeartUI heartUI;
    CoinUI coinUI;
public:
    PrelimLevelRender(): heartUI(), coinUI() {

    }
    void init(){
        //ybar.reset(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
        xbar.reset(WINDOW_X/2,(PLAY_Y_HEIGHT+WINDOW_Y)/2,WINDOW_X,WINDOW_Y-PLAY_Y_HEIGHT);
        xbar.setFill(true);
        xbar.setColor(COLOR("brown"));

        charInput.reset(PLAY_X_START + 50, PLAY_Y_HEIGHT + 20, "In: _");
        coinScore.reset(PLAY_X_START + 50, PLAY_Y_HEIGHT + 50, "Coins: 0");

    }
    //bind game state
    void bindState(GameState *_state){
        state = _state;
        heartUI.setMaxHearts(state->health.maxHearts);
    }
    void step(){
        heartUI.render(state->health.heartLeft);
        string coinMsg = "Coins: ";
        coinMsg += to_string(state->score.GoldCoin );
        coinScore.setMessage(coinMsg);
        string charMsg = "In: ";
        charMsg += state->charInput;
        charInput.setMessage(charMsg);

        coinUI.setCoins(state->score.GoldCoin);

        coinUI.step();
    }
};


#endif //LASSOPROJECT_PRELIMLEVELRENDER_H
