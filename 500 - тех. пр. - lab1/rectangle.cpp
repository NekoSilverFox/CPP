#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t rec):
  rectangle_(rec)
{
  assert(rec.width > 0 && rec.height > 0);
}

double Rectangle::getArea() const
{
  return this->rectangle_.width * this->rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return this->rectangle_;
}

void Rectangle::move(const double x_move, const double y_move) 
{
  this->rectangle_.pos.x += x_move;
  this->rectangle_.pos.y += y_move;
}

void Rectangle::move(const point_t& point_new) 
{
  this->rectangle_.pos = point_new;
}
