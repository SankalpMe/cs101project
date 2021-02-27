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
    char key; // key to render
    int prevShow; // timeStamp of previous update
public:
    KeyUI();

    void setKey(char _key) {
        key = _key;

    }

    void step();
};


#endif //LASSOPROJECT_KEYUI_H
