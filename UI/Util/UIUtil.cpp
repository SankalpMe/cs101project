//
// Created by sankalp on 07/02/21.
//

#include "UIUtil.h"


bool waitForKeyAndMouse() {
    XEvent e;
    bool event = checkEvent(e);
    if (event) {
        if (e.type == KeyPress || e.type == ButtonPress) {
            return true;
        }
    }
    return false;
}

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


    // boom animation effect
    repeat(26) {
        i++;

        //flickering violent colours
        if (i % 2) {
            box.setColor(COLOR("yellow"));
        } else {
            box.setColor(COLOR("red"));

        }

        // boom transition effect
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
    showSmartAlert(msg); // similar functionality
}

void showSmartAlert(string msg) {

    endFrame(); // to enable canvas repaint
    Rectangle box;
    box.reset(WINDOW_X / 2, WINDOW_Y / 2, WINDOW_X, WINDOW_Y);
    box.setFill(true);
    box.setColor(COLOR("yellow"));
    box.show();
    msg += "\n\nClick To Continue\n";
    int start = 0;
    vector<Text> rows; // rows of text to render
    int rowi = 0;

    // display multiline message on screen
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == '\n') {
            Text t;
            t.reset(WINDOW_X / 2, WINDOW_Y / 2 + rowi * textHeight(), msg.substr(start, i - start));
            rows.push_back(t);
            rowi++;
            start = i + 1;

            if (i == msg.length() - 1)
                wait(1);
        }
    }


    // mouse / key hold - wait for user response.
    while (!waitForKeyAndMouse()) {

    }
}

void showControls() {
    showSmartAlert(
            "CONTROLS\n [W] : INCREASE LASSO PROJECTION SPEED \n[S] : DECREASE LASSO PROJECTION SPEED\n[A] / [D] : TILT THE PROJECTION ANGLE\n[K] : THROW THE LASSO\n[L]: LOOP THE LASSO (OR CATCH COIN WHEN IN RANGE)\n[M]: YANK / PULL BACK THE LASSO. ");

}

bool showConfirmAlert(string msg) {
    endFrame(); // to enable canvas repaint
    Rectangle box;
    box.reset(WINDOW_X / 2, WINDOW_Y / 2, WINDOW_X, WINDOW_Y);
    box.setFill(true);
    box.setColor(COLOR("yellow"));
    box.show();
    msg += "\n\n[Y] : TO CONFIRM\n[N]: TO REJECT\n"; // user action row
    int start = 0;
    vector<Text> rows;
    int rowi = 0;

    // display multiline message on screen
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == '\n') {
            Text t;
            t.reset(WINDOW_X / 2, WINDOW_Y / 2 + rowi * textHeight(), msg.substr(start, i - start));
            rows.push_back(t);
            rowi++;
            start = i + 1;


        }
    }

    wait(1);

    //handle y/n input
    while (true) {
        XEvent e;
        bool pendingEv = checkEvent(e);
        if (pendingEv) {
            if (e.type == KeyPress) {
                char c = charFromEvent(e);
                c = tolower(c);

                if (c == 'y') {
                    return true;
                }

                if (c == 'n') {
                    return false;
                }
            }
        }

    }
}

bool showStartScreen() {
    endFrame(); // to enable canvas repaint
    Rectangle box;
    box.reset(WINDOW_X / 2, WINDOW_Y / 2, WINDOW_X, WINDOW_Y);
    box.setFill(true);
    box.setColor(COLOR("yellow"));
    box.show();
    string msg = "Loop n' Loops\n\n--MAIN MENU--\n\nPRESS";

    msg += "\n\n[P] : TO START THE GAME\n[H]: TO SHOW SCOREBOARD\n"; // user action row
    int start = 0;
    vector<Text> rows;
    int rowi = 0;

    // display multiline message on screen
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] == '\n') {
            Text t;
            t.reset(WINDOW_X / 2, WINDOW_Y / 2 + rowi * textHeight(), msg.substr(start, i - start));
            rows.push_back(t);
            rowi++;
            start = i + 1;
        }
    }

    wait(1);

    //handle y/n input
    while (true) {
        XEvent e;
        bool pendingEv = checkEvent(e);
        if (pendingEv) {
            if (e.type == KeyPress) {
                char c = charFromEvent(e);
                c = tolower(c);

                if (c == 'p') {
                    return true;
                }

                if (c == 'h') {

                    return false;
                }
            }
        }

    }
}