#include <simplecpp>

#include "Misc/GameConstants.h"
#include "GameHandlers/Engine/GameEngine.h"
using namespace simplecpp;


int main() {
    XInitThreads();
    initCanvas("Loop 'n Loops", WINDOW_X, WINDOW_Y); //this line cant be avoided.

    GameEngine engine;
    engine.init(); // engine startup
    showStartMessage("Brace Your Self!");
    engine.loop(); // main game loop

    cout << "Graceful End" << endl;
    return 0;
} // End main_program
