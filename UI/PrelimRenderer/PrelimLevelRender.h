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
    PrelimLevelRender(): heartUI(), coinUI(), keyUI(),timeUI() {

    }
    void init(){
        //ybar.reset(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
        xbar.reset(WINDOW_X/2,(PLAY_Y_HEIGHT+WINDOW_Y)/2,WINDOW_X,WINDOW_Y-PLAY_Y_HEIGHT);
        xbar.setFill(true);
        xbar.setColor(COLOR("brown"));

        MagText.hide();
        MagString = "Magtime: 0";
        MagText.reset(20+(textWidth(MagString))/2,50+10,MagString);
        MagText.setColor(COLOR("red"));

    } // end : init()

    //bind game state
    void bindState(GameState *_state){
        state = _state;
        heartUI.setMaxHearts(state->health.maxHearts);
    } //end : bindState(GameState *_state)
    void step();
};


#endif //LASSOPROJECT_PRELIMLEVELRENDER_H
