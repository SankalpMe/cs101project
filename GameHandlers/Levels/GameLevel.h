//
// Created by sankalp on 06/02/21.
//

#ifndef LASSOPROJECT_GAMELEVEL_H
#define LASSOPROJECT_GAMELEVEL_H

#include "Misc/GameConstants.h"
#include "GameHandlers/Engine/GameEngine.h"

class GameLevel {
    GameEngine *engine;

    void init(){
        engine = new GameEngine();
    }

};


#endif //LASSOPROJECT_GAMELEVEL_H
