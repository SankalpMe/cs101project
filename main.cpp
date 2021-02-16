#include <simplecpp>

#include "Misc/GameConstants.h"
#include "GameHandlers/Levels//GameLevel.h"

using namespace simplecpp;

void initRoot(){
    XInitThreads(); // multi thread support
    initCanvas("Loop 'n Loops", WINDOW_X, WINDOW_Y); //this line cant be avoided.
}
int main() {

    initRoot();

    showSmartAlert("LOOP N' LOOPS\nA SimpleCPP Game Developed\nby\nSANKALP BHAMARE");
    showSmartAlert("INTRO\nJust toss the lasso and catch the coins.\n\nBeware Of Bombs");
    showSmartAlert("CONTROLS\n [W] : INCREASE LASSO PROJECTION SPEED \n[S] : DECREASE LASSO PROJECTION SPEED\n[A] / [D] : TILT THE PROJECTION ANGLE\n\n ");
    showSmartAlert("TIP: \n KEEP LEFT HAND FINGERS ON WASD!\n ");

    showSmartAlert("CONTROLS: \n KEEP THREE RIGHT HAND FINGERS ON\n [M] - [K] - [L]\n[K] : THROW THE LASSO\n[L]: LOOP THE LASSO (OR CATCH COIN WHEN IN RANGE)\n[M]: YANK / PULL BACK THE LASSO. ");

    showSmartAlert("ANYTIME YOU FORGET THE CONTROLS\n PRESS [C] IN-GAME.\n ENJOY!");
    GameLevel gl;
    gl.run();




    cout << "Graceful End" << endl;
    return 0;
} // End main_program
