

#include <simplecpp>
#include "MovingObject.h"


void MovingObject::nextStep(double t) {

    // check if parented
    if (parent != nullptr) {
        // running parented mode updated i.e move acc. to parent child
        position = parent->getPosition() + parentOffset;
        velocity = parent->getVelocity();
        acceleration = parent->getAcceleration();

        // update individual sprite parts
        for (auto &part : parts) {
            Vector2D target = position + part.offset;
            part.sprite->moveTo(target.x, target.y);
        }
        return;
    }
    // if paused no  step cycle
    if (paused) { return; }


    // compute the position and velocity acc. to  laws of motion
    position = position + velocity * t;

    // update individual sprite parts
    for (auto &part : parts) {
        Vector2D target = position + part.offset;
        part.sprite->moveTo(target.x, target.y);
    }
    velocity = velocity + acceleration * t; // velocity update as per accel.

} // End MovingObject::nextStep()

void MovingObject::reset(const Vector2D &_position, const Vector2D &_velocity, const Vector2D &_acceleration,
                         bool isPaused) {
    init(_position, _velocity, _acceleration, isPaused);

    for (auto &part : parts) {
        Vector2D target = position + part.offset;
        part.sprite->moveTo(target.x, target.y);
    }

} // End MovingObject::reset()


void MovingObject::getAttachedTo(MovingObject *m, Vector2D offset) {
    paused = m->isPaused();
    parent = m;
    parentOffset = offset;
}
