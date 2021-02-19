//
// Created by sankalp on 19/02/21.
//

#ifndef LASSOPROJECT_LEVELMANAGER_H
#define LASSOPROJECT_LEVELMANAGER_H


// LEVEL INCLUDES
#include "GameHandlers/LevelClass/Level1/Level1.h"
#include "GameHandlers/LevelClass/Level2/Level2.h"
// END : LEVEL INCLUDES
enum LevelStatus{
    COMPLETED,
    QUITED,
    FAILED
};
class LevelManager {
public:
    int levelCount;

    LevelManager(){
        levelCount = 2;
    }
    GameLevel* getLevel(int level){
        switch (level) {
            case 1:
                return new Level1();
                break;
            case 2:
                return new Level2();
            default:
                cerr << "Level Not Found." << endl;
                return nullptr;
        }

    }

    LevelStatus runLevel(int level){
        GameLevel *gl = getLevel(level);

        bool result = gl->run();

        if(result){
            cerr << "Completed Level : " << level << endl;
            return COMPLETED;
        }else {
            if(gl->userQuit) {
                cerr << "User Quited Level." << endl;
                return QUITED;
            }else{
                cerr << "Failed To Complete Level" << endl;
                return FAILED;
            }

        }

        delete gl;
    }
};


#endif //LASSOPROJECT_LEVELMANAGER_H
