//
// Created by sankalp on 16/02/21.
//

#ifndef LASSOPROJECT_TIMEUI_H
#define LASSOPROJECT_TIMEUI_H

#include <simplecpp>
#include "Misc/GameConstants.h"

class TimeUI {
    Text title;
    Text ttext;
public:
    TimeUI() {
        title.reset(WINDOW_X / 2, PLAY_Y_HEIGHT + 50, "TICKS LEFT");
        title.setColor(COLOR("white"));
        ttext.reset(WINDOW_X / 2, PLAY_Y_HEIGHT + 50 + textHeight() + 5, "50");
        ttext.setColor(COLOR("white"));

    }

    void step(int trem) {
        ttext.setMessage(to_string(trem / 10));

        if (trem == -10) {
            title.hide();
            ttext.hide();
        } else {
            title.show();
            ttext.show();
        }
    }
};


#endif //LASSOPROJECT_TIMEUI_H
