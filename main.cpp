#include <simplecpp>

#include "Misc/GameConstants.h"
#include "GameHandlers/Levels//GameLevel.h"
#include "GameHandlers/LevelClass/Level1/Level1.h"
#include <time.h>
using namespace simplecpp;

void initRoot(){
    srand(time(0));
    XInitThreads(); // multi thread support
    initCanvas("Loop 'n Loops", WINDOW_X, WINDOW_Y); //this line cant be avoided.
}

void runIntro(){

    showSmartAlert("LOOP N' LOOPS\nA SimpleCPP Game Developed\nby\nSANKALP BHAMARE");
    showSmartAlert("INTRO\nJust toss the lasso and catch the coins.\n\nBeware Of Bombs");
    showSmartAlert("CONTROLS\n [W] : INCREASE LASSO PROJECTION SPEED \n[S] : DECREASE LASSO PROJECTION SPEED\n[A] / [D] : TILT THE PROJECTION ANGLE\n\n ");
    showSmartAlert("TIP: \n KEEP LEFT HAND FINGERS ON WASD!\n ");

    showSmartAlert("CONTROLS: \n KEEP THREE RIGHT HAND FINGERS ON\n [M] - [K] - [L]\n[K] : THROW THE LASSO\n[L]: LOOP THE LASSO (OR CATCH COIN WHEN IN RANGE)\n[M]: YANK / PULL BACK THE LASSO. ");

    showSmartAlert("ANYTIME YOU FORGET THE CONTROLS\n PRESS [C] IN-GAME.\n ENJOY!");

    showSmartAlert("REVISION\n [W] : INCREASE LASSO PROJECTION SPEED \n[S] : DECREASE LASSO PROJECTION SPEED\n[A] / [D] : TILT THE PROJECTION ANGLE\n[K] : THROW THE LASSO\n[L]: LOOP THE LASSO (OR CATCH COIN WHEN IN RANGE)\n[M]: YANK / PULL BACK THE LASSO. ");
    showSmartAlert("NOTE:\n The Gold Circles are the gold coins in this game. \n and the brown rod and red circle is the lasso\n the black circle with a fuse is a bomb \n A timer is shown in the bottom portion of the screen if the level is timed.");

}
int main() {
    initRoot();
    //runIntro();
    Level1 *a = new Level1;
    bool conti = a->run();
    cout << conti << endl;
    return 0;
} // End main_program
