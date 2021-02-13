//
// Created by sankalp on 07/02/21.
//

#include "UIUtil.h"

//simple functions to show alerts
void showBombBoom(string msg){
    endFrame();
    Rectangle box(WINDOW_X/2,WINDOW_Y/2, textWidth(msg) + 200, textHeight() + 100);
    box.setFill(true);
    box.setColor(COLOR("red"));

    Text t;
    t.reset(WINDOW_X/2,WINDOW_Y/2, msg);
    t.setColor(COLOR("black"));

    int i = 0;

    repeat(26){
        i++;
        if(i%2 ){
            box.setColor(COLOR("yellow"));
        }else{
            box.setColor(COLOR("red"));

        }
        box.scale(1.2);
        box.rotate(0.1);
        wait(STEP_TIME*0.1);


    }

    wait(1.5);

}//end : show BombBoom


void showStartMessage(string msg){
    Rectangle box;
    box.reset(WINDOW_X/2,WINDOW_Y/2, WINDOW_X, WINDOW_Y);
    box.setFill(true);
    box.setColor(COLOR("yellow"));

    Text t;
    t.reset(WINDOW_X/2,WINDOW_Y/2, msg);
    t.setColor(COLOR("black"));

    int i = 0;
    wait(1);
    repeat(100){
        t.move(0,-WINDOW_Y/100);
        box.move(0,-WINDOW_Y/100);
        box.scale(0.99);
        wait(STEP_TIME*0.1);
    }

    wait(0.5);

}