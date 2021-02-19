//
// Created by sankalp on 19/02/21.
//

#ifndef LASSOPROJECT_LEVELMANAGER_H
#define LASSOPROJECT_LEVELMANAGER_H


// LEVEL INCLUDES
#include "GameHandlers/Levels/Level1/Level1.h"
#include "GameHandlers/Levels/Level2/Level2.h"
#include "GameHandlers/Levels/Level3/Level3.h"
#include "GameHandlers/Levels/Level4/Level4.h"
#include "GameHandlers/Levels/Level5/Level5.h"

// END : LEVEL INCLUDES
enum LevelStatus {
    COMPLETED,
    QUITED,
    FAILED
};

class LevelManager {
public:
    int levelCount;
    int currentLevel=1;
    LevelManager() {
        levelCount = 5;
    }

    GameLevel *getLevel(int level) {
        switch (level) {
            case 1:
                return new Level1();
            case 2:
                return new Level2();
            case 3:
                return new Level3();
            case 4:
                return new Level4();
            case 5:
                return new Level5();
            default:
                cerr << "Level Not Found" << endl;
                exit(1);
                return nullptr;
        }
    }

    LevelStatus runLevel(int level) {
        GameLevel *gl = getLevel(level);

        bool result = gl->run();

        bool userQuit = gl->userQuit;


        delete gl;
        if (result) {
            cerr << "Completed Level : " << level << endl;
            return COMPLETED;
        } else {
            if (userQuit) {
                cerr << "User Quited Level." << endl;
                return QUITED;
            } else {
                cerr << "Failed To Complete Level" << endl;
                return FAILED;
            }

        }


    }

    void run(){
        currentLevel = 5;
        while (currentLevel <= levelCount){

            LevelStatus stat = runLevel(currentLevel);

            switch (stat) {
                case QUITED:{
                    cerr << "Publishing Your HighScore" << endl;
                    break;
                }
                case COMPLETED:{
                    cerr << "Completed Level Continuing To Next Level" << endl;
                    break;
                }
                case FAILED: {
                    bool resp = showConfirmAlert("DO YOU WANT TO RETRY LEVEL?\nrejecting will quit and submit your score.\n");
                    if(resp){
                        continue;
                    }else{
                        //publishScore
                        exit(1);
                    }
                }
            }
            currentLevel++;
        }
    }
};


#endif //LASSOPROJECT_LEVELMANAGER_H
