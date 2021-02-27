//
// Created by sankalp on 27/02/21.
//

#include "ScoreBoard.h"

void ScoreBoard::runPublisher(double score) {
    ScoreSubmit ss;
    string name = ss.read(score);
    hsd.addEntry(name,score);
    hsd.saveEntries();
}
void publishScore(double score){
    scoreBoard.runPublisher(score);
}