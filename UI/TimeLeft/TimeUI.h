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
    TimeUI();

    void step(int trem); // update the time ui
};


#endif //LASSOPROJECT_TIMEUI_H
