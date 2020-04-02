#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t& rec):
  rectangle_(rec)
{
  assert(rec.width > 0 && rec.height > 0);
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const double x_move, const double y_move) 
{
  rectangle_.pos.x += x_move;
  rectangle_.pos.y += y_move;
}

void Rectangle::move(const point_t& point_new) 
{
  rectangle_.pos = point_new;
}
