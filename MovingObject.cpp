#include <simplecpp>
#include "MovingObject.h"

using namespace simplecpp;

void MovingObject::nextStep(double t) {
  
  if(paused) { return; }
  position = position + velocity*t;
  for(size_t i=0; i<parts.size(); i++){
    Vector2D target = position + parts[i].offset;
    parts[i].sprite->moveTo(target.x, target.y);
  }
  velocity =velocity +  acceleration * t;
  
} // End MovingObject::nextStep()

void MovingObject::reset(const Vector2D &_position,const Vector2D &_velocity, const Vector2D &_acceleration, bool isPaused){
	for(size_t i=0; i<parts.size(); i++){
    Vector2D fp = _position + parts[i].offset;
    parts[i].sprite->moveTo(fp.x, fp.y);
  }
  init(_position,_velocity,_acceleration,isPaused);
} // End MovingObject::reset()


void MovingObject::getAttachedTo(MovingObject *m) {
  reset(m->getPosition(),m->getVelocity(),m->getAcceleration(),m->isPaused());
}
