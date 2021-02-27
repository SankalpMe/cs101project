//
// Created by sankalp on 19/02/21.
//

#include "LevelManager.h"
GameLevel   *LevelManager::getLevel(int level) {
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


LevelStatus LevelManager::runLevel(int level,double *score) {
    GameLevel *gl = getLevel(level); //fetch the level

    bool result = gl->run();

    double pointScored = gl->grade();

    if(score != nullptr){
        *score = pointScored;
    }

    bool userQuit = gl->userQuit;


    delete gl;

    //handle level completion status
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


void LevelManager::run() {
    currentLevel = 5;
    while (currentLevel <= levelCount){
        double levelScore;
        LevelStatus stat = runLevel(currentLevel,&levelScore); //fetch the level score.

        cerr << "Scored: " << levelScore << endl;

        switch (stat) {
            case QUITED:{
                cerr << "Publishing Your HighScore" << endl;
                break;
            }
            case COMPLETED: {
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