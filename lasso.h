#ifndef __LASSO_H__
#define __LASSO_H__

#include "MovingObject.h"
#include "coin.h"
#include "Vector2D.h"

//#define WINDOW_X 1200
//#define WINDOW_Y 960
#define WINDOW_X 800
#define WINDOW_Y 600

#define STEP_TIME 0.05

#define PLAY_X_START 100
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-100)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG (360-RELEASE_ANGLE_STEP_DEG)
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define COIN_SPEED 120
#define COIN_ANGLE_DEG 90

#define LASSO_G 30
#define COIN_G 30

#define LASSO_SIZE 10
#define LASSO_RADIUS 100
//50
#define COIN_SIZE 5

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
 
  int num_coins;

  void init();
 public:
  
  vector<Coin *> coins;
  Lasso(double speed, double angle_deg,Vector2D _acceleration, bool isPaused) : MovingObject({0,0},{0,0},{0,0}, isPaused) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    releaseVelocity = fromPolar(speed,angle_deg*PI/180.0);
    
    acceleration = _acceleration;
    Lasso::init();
  }

  void draw_lasso_band();
  void yank();
  void loopit();
  void addAngle(double angle_deg);
  void addSpeed(double speed);

  void nextStep(double t);
  void check_for_coin(Coin *coin);
  bool isLassoLoped();
  int getNumCoins() { return num_coins; }

}; // End class Lasso

#endif
