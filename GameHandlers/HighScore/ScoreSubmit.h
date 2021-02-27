//
// Created by sankalp on 27/02/21.
//

#ifndef LASSOPROJECT_SCORESUBMIT_H
#define LASSOPROJECT_SCORESUBMIT_H
#include <simplecpp>
#include "Misc/GameConstants.h"

class ScoreSubmit {
    Rectangle bg;
    Text title[3];
    Text input;
    Text placeholder;
    Rectangle fg;
    void init(){
        bg.reset(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y);
        bg.setFill(true);
        bg.setColor(COLOR("yellow"));

        title[0].reset(WINDOW_X/2,WINDOW_Y/2- textHeight()*3-10,"- SUBMIT YOUR SCORE -");
        title[1].reset(WINDOW_X/2,WINDOW_Y/2- textHeight()*2-10,"- 80 -");

        input.reset(WINDOW_X/2,WINDOW_Y/2,"");
        placeholder.reset(WINDOW_X/2,WINDOW_Y/2,"Enter Your Name");
        placeholder.setColor('gray');
        fg.reset(WINDOW_X/2,WINDOW_Y/2,textHeight(),100);
        fg.setFill(true);
        fg.setColor(COLOR("white"));

    }
};


#endif //LASSOPROJECT_SCORESUBMIT_H
