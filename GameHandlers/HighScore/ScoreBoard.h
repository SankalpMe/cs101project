//
// Created by sankalp on 27/02/21.
//

#ifndef LASSOPROJECT_SCOREBOARD_H
#define LASSOPROJECT_SCOREBOARD_H
#include "GameHandlers/HighScore/HighScoreData.h"

class ScoreBoardUI{
    void init(){

    }
};
class ScoreBoard {
    HighScoreData hsd;
    ScoreBoardUI *ui;
public:
    ScoreBoard(){
        ui = nullptr;
    }
    void init(){
        hsd.loadEntries(); // load entries from files
    }

    void showScoreBoard(){
        ui = new ScoreBoardUI();
        wait(40);
        delete ui;
    }
};
static  ScoreBoard scoreBoard;
void publishScore(double score);

#endif //LASSOPROJECT_SCOREBOARD_H
