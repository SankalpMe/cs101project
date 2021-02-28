//
// Created by sankalp on 27/02/21.
//

#ifndef LASSOPROJECT_SCOREBOARD_H
#define LASSOPROJECT_SCOREBOARD_H

#include "GameHandlers/HighScore/HighScoreData.h"
#include "GameHandlers/HighScore/ScoreSubmit.h"
#include <sstream>
#include <iomanip>
#include "UI/Util/UIUtil.h"

class ScoreBoardUI{
    vector<Text> scoreText;
    vector<ScoreEntry> entries;
    Rectangle bg;
    Text title;
    Text clck;
public:
    void init(const vector<ScoreEntry> &_entries){
        entries = _entries;
    }

    void _render(double yoffset = 90); // internal rendering with yoffset for bobbling

    void render(); // render with bobbling animation
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
        hsd.loadEntries();
        ui = new ScoreBoardUI();
        ui->init(hsd.getList());
        ui->render();

        delete ui;
    }
    void runPublisher(double score);
};
static  ScoreBoard scoreBoard;
void publishScore(double score);

#endif //LASSOPROJECT_SCOREBOARD_H
