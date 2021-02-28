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



void ScoreBoardUI::_render(double yoffset){

    bg.reset(WINDOW_X/2,yoffset+(140+entries.size()*3*textHeight() )/2,WINDOW_X-300,120+entries.size()*3*textHeight());
    bg.setFill(true);
    bg.setColor(COLOR("yellow"));
    title.reset(WINDOW_X/2,yoffset+40,">   Score Board   <");
    title.setColor(COLOR("red"));
    scoreText = vector<Text>();

    for(int i = 0 ; i < entries.size();i++){
        stringstream ss;

        ss <<  to_string(i+1) + ". " + entries[i].name + " - ";
        ss << std::fixed << setprecision(2) << entries[i].score;

        scoreText.push_back(Text(WINDOW_X/2,yoffset+80+i*3*textHeight(),ss.str()));

    }


    clck.reset(WINDOW_X/2,yoffset+100+entries.size()*3*textHeight(),"- Click To Continue -");


}

void ScoreBoardUI::render(){
    if(entries.size() == 0){
            showSmartAlert("> NO HIGHSCORE REGISTERED <\nWITH SYSTEM");
            return;
    }
    double yoffset = 90;
    double  a;
    while(true){
        beginFrame();
        _render(yoffset + 10*sin(a));
        endFrame();
        wait(STEP_TIME);
        a+=0.1;
        XEvent e;
        bool event = checkEvent(e);
        if(event){
            if(e.type == KeyPress || e.type == ButtonPress){
                break;
            }
        }
    }
}