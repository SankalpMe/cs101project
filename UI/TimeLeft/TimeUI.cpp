//
// Created by sankalp on 16/02/21.
//

#include "TimeUI.h"

TimeUI::TimeUI() {
    title.reset(WINDOW_X / 2, PLAY_Y_HEIGHT + 50, "TICKS LEFT");
    title.setColor(COLOR("white"));
    ttext.reset(WINDOW_X / 2, PLAY_Y_HEIGHT + 50 + textHeight() + 5, "50");
    ttext.setColor(COLOR("white"));

}

void TimeUI::step(int trem) {
    ttext.setMessage(to_string(trem / 10));

    if (trem == -10) {
        title.hide();
        ttext.hide();
    } else {
        title.show();
        ttext.show();
    }
}