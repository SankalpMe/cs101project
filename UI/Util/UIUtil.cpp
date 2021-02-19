//
// Created by sankalp on 07/02/21.
//

#include "UIUtil.h"

//simple functions to show alerts
void showBombBoom(string msg) {
    endFrame();
    Rectangle box(WINDOW_X / 2, WINDOW_Y / 2, textWidth(msg) + 200, textHeight() + 100);
    box.setFill(true);
    box.setColor(COLOR("red"));

    Text t;
    t.reset(WINDOW_X / 2, WINDOW_Y / 2, msg);
    t.setColor(COLOR("black"));

    int i = 0;

    repeat(26) {
        i++;
        if (i % 2) {
            box.setColor(COLOR("yellow"));
        } else {
            box.setColor(COLOR("red"));

        }
        box.scale(1.2);
        box.rotate(0.1);
        wait(STEP_TIME * 0.1);


    }

    wait(1.5);

}//end : show BombBoom


void showStartMessage(string msg) {
    endFrame();
    Rectangle box;
    box.reset(WINDOW_X / 2, WINDOW_Y / 2, WINDOW_X, WINDOW_Y);
    box.setFill(true);
    box.setColor(COLOR("yellow"));

    Text t;
    t.reset(WINDOW_X / 2, WINDOW_Y / 2, msg);
    t.setColor(COLOR("black"));

    int i = 0;
    wait(1);
    repeat(100) {
        t.move(0, -WINDOW_Y / 100);
        box.move(0, -WINDOW_Y / 100);
        box.scale(0.99);
        wait(STEP_TIME * 0.1);
    }

    wait(0.5);

}

void showAlert(string msg) {
    endFrame();
    Rectangle box;
    box.reset(WINDOW_X / 2, WINDOW_Y / 2, WINDOW_X, WINDOW_Y);
    box.setFill(true);
    box.setColor(COLOR("yellow"));

    Text t;
    t.reset(WINDOW_X / 2, WINDOW_Y / 2, msg);

    Text clco(WINDOW_X / 2, WINDOW_Y / 2 + 30, "CLICK TO CONTINUE");
    t.setColor(COLOR("black"));
    box.show();
    t.show();

    getClick();
}

void showSmartAlert(string msg) {
    endFrame();
    Rectangle box;
    box.reset(WINDOW_X / 2, WINDOW_Y / 2, WINDOW_X, WINDOW_Y);
    box.setFill(true);
    box.setColor(COLOR("yellow"));
    box.show();
    msg += "\n\nClick To Continue\n";
    int start = 0;
    vector<Text> rows;
    int rowi = 0;
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == '\n') {
            Text t;
            t.reset(WINDOW_X / 2, WINDOW_Y / 2 + rowi * textHeight(), msg.substr(start, i - start));
            rows.push_back(t);
            rowi++;
            start = i + 1;
        }
    }

    getClick();
}

void showControls() {
    showSmartAlert(
            "CONTROLS\n [W] : INCREASE LASSO PROJECTION SPEED \n[S] : DECREASE LASSO PROJECTION SPEED\n[A] / [D] : TILT THE PROJECTION ANGLE\n[K] : THROW THE LASSO\n[L]: LOOP THE LASSO (OR CATCH COIN WHEN IN RANGE)\n[M]: YANK / PULL BACK THE LASSO. ");

}