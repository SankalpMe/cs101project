//
// Created by sankalp on 27/02/21.
//

#include "ScoreSubmit.h"
void ScoreUI::init(){
    // state initialization
    capOn = false;
    bg.reset(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y);
    bg.setFill(true);
    bg.setColor(COLOR("yellow"));

    // code to set up the ui elements
    title[0].reset(WINDOW_X/2,WINDOW_Y/2- textHeight()*3-30,"- SUBMIT YOUR SCORE -");
    title[1].reset(WINDOW_X/2,WINDOW_Y/2- textHeight()*2-30,"- 80 -");
    title[1].setColor(COLOR("blue"));
    title[2].reset(WINDOW_X/2,WINDOW_Y/2+ textHeight()*1+30,"Only Alphabets and Numbers Allowed.");
    title[2].setColor(COLOR("red"));
    title[3].reset(WINDOW_X/2,WINDOW_Y/2+ textHeight()*2+40,"(USE CAPSLOCK TO TOGGLE CASE)");
    title[3].setColor(COLOR("red"));
    fg.reset(WINDOW_X/2,WINDOW_Y/2,150,textHeight()*3);
    fg.setFill(true);
    fg.setColor(COLOR("white"));

    input.reset(WINDOW_X/2,WINDOW_Y/2,"");
    placeholder.reset(WINDOW_X/2,WINDOW_Y/2,"Enter Your Name");
    placeholder.setColor(COLOR("gray"));

}

string ScoreUI::read(double _score){
    init(); // init the ui
    score = _score;
    char scorestring[100];
    sprintf(scorestring,"- %.2f -",score);
    title[1].setMessage(scorestring); // update ui to score string

    //event loop
    while (true){


        XEvent e;
        bool pendingEv = checkEvent(e);

        //handle key codes
        if(pendingEv){

            if(e.type == KeyPress){
                char c = charFromEvent(e);

                // adds only alphabets/letters to string.
                if(isalnum(c)){
                    if(!capOn || !isalpha(c))
                        name+=c;
                    else
                        name+=toupper(c);
                }else{
                    if(c == 13){
                        cerr << "Recieved Name:" << name;
                        return name;
                    }else
                    if(c == 8){
                        name = name.substr(0,name.length()-1);
                    }else
                    if( c== ' '){
                        name += ' ';
                    }else
                    if ( c == -27){
                        capOn = !capOn;
                    }
                }

            }
        }

        if(name.length() > 0 ){
            placeholder.hide();
            input.show();
            string  rdr = name+"_";
            input.setMessage(rdr);

            fg.reset(WINDOW_X/2,WINDOW_Y/2,max(textWidth(rdr)+40,150),fg.getHeight());

        }else{
            input.hide();
            placeholder.show();
        }
    }
}