//
// Created by sankalp on 27/02/21.
//

#ifndef LASSOPROJECT_SCORESUBMIT_H
#define LASSOPROJECT_SCORESUBMIT_H
#include <simplecpp>
#include "Misc/GameConstants.h"

// simple ui to take user name input for score submission
class ScoreUI {
    Rectangle bg;
    Text title[4];
    Rectangle fg;
    Text input;
    Text placeholder;
    double  score;
    string name;
    bool capOn;
    void init(); // inits all the ui elements
public:


    string read(double score=0); // runs the input ui
};


// the class to process ui creation and input .
class ScoreSubmit{
    ScoreUI *ui;
public:
    string read(double  score=0){
        ui = new ScoreUI;
        string name = ui->read(score);
        delete ui;

        return name;
    }
};


#endif //LASSOPROJECT_SCORESUBMIT_H
