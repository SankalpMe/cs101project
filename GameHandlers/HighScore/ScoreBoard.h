//
// Created by sankalp on 27/02/21.
//

#ifndef LASSOPROJECT_SCOREBOARD_H
#define LASSOPROJECT_SCOREBOARD_H

#include "GameHandlers/HighScore/HighScoreData.h"
#include "GameHandlers/HighScore/ScoreSubmit.h"

class ScoreBoardUI{
    void init(){

    }
};
class ScoreBoard {
    ScoreBoardUI *ui;
    HighScoreData hsd;
public:

    ScoreBoard(){
        ui = nullptr;
    }
    void init(){
        hsd.loadEntries(); // load entries from files
    }

    void showScoreBoard(){
        ui = new ScoreBoardUI();
        hsd.loadEntries();
        for(auto i : hsd.getList()){
            cerr << i.name << ", " << i.score << endl;
        }

        delete ui;
    }
    void runPublisher(double score);
};
static  ScoreBoard scoreBoard;
void publishScore(double score);

#endif //LASSOPROJECT_SCOREBOARD_H
