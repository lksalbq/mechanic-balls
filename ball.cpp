/** file: ball.cpp
 ** brief: Ball class - implementation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"

#include <iostream>

Ball::Ball()
: r(0.1), x(0), y(0), vx(0.3), vy(-0.1), g(9.8), m(1),
xmin(-1), xmax(1), ymin(-1), ymax(1)
{ }

Ball::Ball(double x, double y){
  this->setPosition(x,y);
}

void Ball::setPosition(double x, double y){
  this->x = x;
  this->y = y;
}

void Ball::setPositionX(double x){
  this->x = x;
}

void Ball::setPositionY(double y){
  this->y = y;
}

double Ball::getPositionX(){
  return this->x;
}


double Ball::getPositionY(){
  return this->y;
}

void Ball::step(double dt)
{
  double xp = x + vx * dt ;
  double yp = y + vy * dt - 0.5 * g * dt * dt ;
  if (xmin + r <= xp && xp <= xmax - r) {
    x = xp ;
  } else {
    vx = -vx ;
  }
  if (ymin + r <= yp && yp <= ymax - r) {
    y = yp ;
    vy = vy - g * dt ;
  } else {
    vy = -vy ;
  }
}

void Ball::display()
{
  std::cout<<x<<" "<<y<<std::endl ;
}
