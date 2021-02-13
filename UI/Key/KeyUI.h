//
// Created by sankalp on 13/02/21.
//

#ifndef LASSOPROJECT_KEYUI_H
#define LASSOPROJECT_KEYUI_H

#include <simplecpp>
#include <Misc/GameConstants.h>

class KeyUI {
    Rectangle bdrop; // bg rect for key ui
    Text t; // text for rendering
    char key;
    int prevShow ;
public:
    KeyUI() {
        bdrop.setFill(true);
        bdrop.setColor(COLOR("black"));
        t.setColor(COLOR("white"));
        bdrop.reset(WINDOW_X-60,30,30,30);
        t.reset(WINDOW_X-60,30," ");
        prevShow = 0;
    }
    void setKey(char _key){
        key = _key;

    }

    void step(){
        string disp = "";
        disp+= key;
        if(key != '_' && key != ' '){
            t.show();
            bdrop.show();
            t.setMessage(disp);
            prevShow = 10;
        }else{
            prevShow--;
            if(prevShow <= 0){
                prevShow = 0;
                t.hide();
                bdrop.hide();
            }

        }


    }
};


#endif //LASSOPROJECT_KEYUI_H
