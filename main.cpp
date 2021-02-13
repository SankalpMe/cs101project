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
//    GameEngine engine; // the oil and gas for the game
//    engine.init(); // engine ignition
//    showStartMessage("Level 1");
//    engine.loop(); // engine run
//    engine.cleanup();
    GameLevel gl;
    gl.run();




    cout << "Graceful End" << endl;
    return 0;
} // End main_program
