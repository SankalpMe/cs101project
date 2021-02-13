#ifndef _MOVINGOBJECT_INCLUDED_
#define _MOVINGOBJECT_INCLUDED_

#include <simplecpp>
#include <vector>
#include <composite.h>
#include <sprite.h>
#include "Misc/Vector2D/Vector2D.h"
#include "Misc/GameConstants.h"

using namespace simplecpp;

struct MovingSprite {
    Sprite *sprite;
    Vector2D offset;
};

class MovingObject : public Sprite {
    vector<MovingSprite> parts;
    Vector2D velocity;
    Vector2D acceleration;
    Vector2D position;
    Vector2D parentOffset;
    MovingObject *parent;


    bool paused;

    void init(Vector2D _position, Vector2D _velocity, Vector2D _acceleration, bool isPaused = true) {
        position = _position;
        velocity = _velocity;
        acceleration = _acceleration;
        paused = isPaused;
        parent = nullptr;

    }

public:
    MovingObject(const Vector2D &position, const Vector2D &velocity, const Vector2D &acceleration, bool isPaused = true)
            : Sprite() {
        init(position, velocity, acceleration, isPaused);
    }

    MovingObject(double speed, double angle, Vector2D &acceleration, bool isPaused = true) : Sprite() {
        double angle_rad = angle * PI / 180.0;
        Vector2D velocity = fromPolar(speed, angle_rad);
        init(position, velocity, acceleration, isPaused);
    }

    // Velocity Helper Functions
    Vector2D getVelocity() {
        return velocity;
    }

    void setVelocity(const Vector2D &_velocity) {
        velocity = _velocity;
    }

    void setXVelocity(double x) { velocity.x = x; }

    void setYVelocity(double y) { velocity.y = y; }

    // Acceleration Helper Functions
    Vector2D getAcceleration() {
        return acceleration;
    }

    void setAcceleration(const Vector2D &_acceleration) {
        acceleration = _acceleration;
    }

    void setXAcceleration(double x) { acceleration.x = x; }

    void setYAcceleration(double y) { acceleration.y = y; }

    // Position Helper Functions
    Vector2D getPosition() { return position; }

    double getXPosition() { return position.x; }

    double getYPosition() { return position.y; }

    void setPosition(const Vector2D &_position) { position = _position; }

    void
    reset(const Vector2D &_position, const Vector2D &_velocity, const Vector2D &_acceleration, bool isPaused = true);

    void pause() { paused = true; }

    void unpause() { paused = false; }

    bool isPaused() { return paused; }

    void addPart(Sprite *p, Vector2D offset = {0, 0}) {
        parts.push_back({p, offset});
    }

    void nextStep(double t);

    void getAttachedTo(MovingObject *m, Vector2D offset = {0, 0});

    void getDetached() { parent = nullptr; }
};

#endif
