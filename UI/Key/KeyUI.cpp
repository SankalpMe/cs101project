//
// Created by sankalp on 13/02/21.
//

#include "KeyUI.h"


KeyUI::KeyUI() {
    bdrop.setFill(true);
    bdrop.setColor(COLOR("black"));
    t.setColor(COLOR("white"));
    bdrop.reset(WINDOW_X - 60, 30, 30, 30);
    t.reset(WINDOW_X - 60, 30, " ");
    prevShow = 0;
}

void KeyUI::step() {
    string disp = "";
    disp += key;
    if (key != '_' && key != ' ') {
        t.show();
        bdrop.show();
        t.setMessage(disp);
        prevShow = 10;
    } else {
        prevShow--;
        if (prevShow <= 0) {
            prevShow = 0;
            t.hide();
            bdrop.hide();
        }

    }


}