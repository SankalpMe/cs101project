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

// the scoreboard ui rendering is handled by this class
class ScoreBoardUI{
    vector<Text> scoreText;
    vector<ScoreEntry> entries;
    Rectangle bg;
    Text title;
    Text clck;
public:
    // binds the entries to the class
    void init(const vector<ScoreEntry> &_entries){
        entries = _entries;
    }

    void _render(double yoffset = 90); // internal rendering with yoffset for bobbling

    void render(); // render with bobbling animation
};

class ScoreBoard {
    ScoreBoardUI *ui; // ui handling is done in this class
    HighScoreData hsd; // the scoreboard entries are stored in this file
public:

    ScoreBoard(){
        ui = nullptr;
    }
    void init(){
        hsd.loadEntries(); // load entries from files
    }

    void showScoreBoard(); // displays the scoreboard to the screen
    void runPublisher(double score); // publishes the given score to the score board
};
static  ScoreBoard scoreBoard; // static scoreBoard object available throughout the project for score handling
void publishScore(double score); // simple function to publish the score , just a wrapper around scoreBoard::publishScore

#endif //LASSOPROJECT_SCOREBOARD_H
