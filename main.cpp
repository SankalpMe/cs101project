#include <simplecpp>

#include "Misc/GameConstants.h"
#include "GameHandlers/Engine/GameEngine.h"

using namespace simplecpp;


int main() {
    XInitThreads(); // multi thread support
    initCanvas("Loop 'n Loops", WINDOW_X, WINDOW_Y); //this line cant be avoided.

    GameEngine engine; // the oil and gas for the game
    engine.init(); // engine ignition
    showStartMessage("Level 1");
    engine.loop(); // engine run
    engine.cleanup();




    cout << "Graceful End" << endl;
    return 0;
} // End main_program
