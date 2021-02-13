#include <simplecpp>

#include "Misc/GameConstants.h"
#include "GameHandlers/Engine/GameEngine.h"
using namespace simplecpp;


int main() {
    initCanvas("Loop 'n Loops", WINDOW_X, WINDOW_Y); //this line cant be avoided.

    GameEngine engine;
    engine.init(); // engine startup
    showStartMessage("Brace Your Self!");
    engine.loop(); // main game loop
    return 0;
} // End main_program
