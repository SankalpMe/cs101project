#ifndef __LASSO_H__
#define __LASSO_H__

#include "GameObjects/MO/MovingObject.h"
#include "GameObjects/coin/coin.h"
#include "Misc/Vector2D/Vector2D.h"
#include "GameObjects/bomb/bomb.h"
#include "GameHandlers/State/GameState.h"
//#define WINDOW_X 1200
//#define WINDOW_Y 960
#include "Misc/GameConstants.h"

class Lasso : public MovingObject {
    Vector2D startPosition;

    double release_speed;
    double release_angle_deg;
    Vector2D releaseVelocity;

    Vector2D acceleration;

    // Moving parts
    Circle lasso_circle;
    Circle lasso_loop;

    // Non-moving parts
    Line lasso_line;
    Line lasso_band;

    // State info
    bool lasso_looped;


    void init();

public:
    GameState *state;

    vector<Coin *> coins;
    vector<Bomb *> bombs;


    Lasso(double speed = INIT_RELEASE_SPEED, double angle_deg = INIT_RELEASE_ANGLE_DEG,
          Vector2D _acceleration = {0, LASSO_G}, bool isPaused = true);

    //binds game state to lasso
    void bindState(GameState *_state) {
        state = _state;
    }

    void draw_lasso_band(); // render the lasso_band

    void yank(); // handles the pullback of lasso

    void loopit(); // handles lasso looping

    void addAngle(double angle_deg); // handles the projection angles

    void addSpeed(double speed); // handles the project speed

    void nextStep(double t); // perform next step update

    void check_for_coin(Coin *coin); // checks out a given coin ptr and catches it if in range

    void check_for_bomb(Bomb *bomb);// checks out a given bomb ptr and catches it if in range

    bool isLassoLoped(); // return if lasso is looped


}; // End class Lasso

#endif
