//
// Created by sankalp on 19/02/21.
//

#ifndef LASSOPROJECT_LEVELMANAGER_H
#define LASSOPROJECT_LEVELMANAGER_H


// Game Level INCLUDES
#include "GameHandlers/Levels/Level1/Level1.h"
#include "GameHandlers/Levels/Level2/Level2.h"
#include "GameHandlers/Levels/Level3/Level3.h"
#include "GameHandlers/Levels/Level4/Level4.h"
#include "GameHandlers/Levels/Level5/Level5.h"
#include "GameHandlers/Levels/Level6/Level6.h"
#include "GameHandlers/Levels/Level7/Level7.h"
#include "GameHandlers/Levels/Level8/Level8.h"
#include "GameHandlers/Levels/Level9/Level9.h"
// END : LEVEL INCLUDES


enum LevelStatus {
    COMPLETED,
    QUITED,
    FAILED
};

class LevelManager {
public:
    int levelCount; // holds count of total levels
    int currentLevel; // the current level.
    double totalScore; // totalScore
    LevelManager() {
        levelCount = 9;
        currentLevel = 1;
        totalScore = 0;

    }

    //getLevel(int) : fetches the required level ptr.
    GameLevel *getLevel(int level);


    // runLevel(int) : handles init and running of a given level.
    LevelStatus runLevel(int level, double *score = nullptr);

    void run(); // running the entire gamelevel system starting from level 1- > n
};


#endif //LASSOPROJECT_LEVELMANAGER_H
