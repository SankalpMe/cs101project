//
// Created by sankalp on 19/02/21.
//

#include "LevelManager.h"
#include "GameHandlers/HighScore/ScoreBoard.h"
// getLevel(int) : fetches the level ptr for the required level
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
        case 6:
            return new Level6();
        default:
            cerr << "Level Not Found" << endl;
            exit(1);
    }
}


// function to run and evaluate the given level
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

// run () : begin the main level run manager which sequentially runs each level
void LevelManager::run() {

    while (currentLevel <= levelCount){
        double levelScore;
        LevelStatus stat = runLevel(currentLevel,&levelScore); //fetch the level score.

        cerr << "Scored: " << levelScore << endl;
        totalScore += levelScore;

        switch (stat) {
            case QUITED:{
                cerr << "...Publishing Your HighScore..." << endl;
                publishScore(totalScore);
                exit(0);
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
                    publishScore(totalScore);
                    exit(0);
                }
            }
        }
        currentLevel++; // proceed to next level
    }

    publishScore(totalScore);


}