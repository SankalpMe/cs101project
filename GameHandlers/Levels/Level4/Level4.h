//
// Created by sankalp on 20/02/21.
//

#ifndef LASSOPROJECT_LEVEL4_H
#define LASSOPROJECT_LEVEL4_H
#include "GameHandlers/LevelClass/GameLevel.h"

class Level4 : public GameLevel {
    Text t;

    void sceneSettings(CoinManager *cmg, BombManager *bmg) {

        cmg->allowCoinRespawn = true;
        bmg->deadlyMode = true;
        addRandomBombs(1);
    }

    void _init() {
        beginnerPrompt();

        maxHearts = 1;

        levelInstructions();
    }

    void levelInstructions() {
        showSmartAlert(
                "LEVEL 4\nBeware Of The Bombs\nNow This Time A Bomb Will Spawn\nThere is no objective to this level\njust collect the bomb and the level will end\n\nNOTE: BOMB CAUSE HEALTH DAMAGE YOU WILL SEE A HEALTH BAR ABOVE");
        showSmartAlert(
                "I HOPE YOU REMEMBER THE CONTROLS NOW\nIF YOU FORGET YOU KNOW WHAT TO DO\nNOTE: [C] KEY IN GAME DOES THE JOB");
    }
    bool checkAchievements() {
        return engine->died;
    };
};


#endif //LASSOPROJECT_LEVEL4_H
