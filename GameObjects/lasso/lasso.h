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
    bool is_boomed;

    Lasso(double speed = INIT_RELEASE_SPEED, double angle_deg = INIT_RELEASE_ANGLE_DEG,
          Vector2D _acceleration = {0, LASSO_G}, bool isPaused = true) : MovingObject({0, 0}, {0, 0}, {0, 0},
                                                                                      isPaused) {
        release_speed = speed;
        release_angle_deg = angle_deg;
        releaseVelocity = fromPolar(speed, angle_deg * PI / 180.0);
        startPosition = {(PLAY_X_START + LASSO_X_OFFSET), (PLAY_Y_HEIGHT - LASSO_Y_HEIGHT)};


        is_boomed = false;
        lasso_looped = false;
        acceleration = _acceleration;
        Lasso::init();
    }

    //binds game state to lasso
    void bindState(GameState *_state) {
        state = _state;
    }

    void draw_lasso_band();

    void yank();

    void loopit();

    void addAngle(double angle_deg);

    void addSpeed(double speed);

    void nextStep(double t);

    void check_for_coin(Coin *coin);

    void check_for_bomb(Bomb *bomb);

    bool isLassoLoped();


}; // End class Lasso

#endif
