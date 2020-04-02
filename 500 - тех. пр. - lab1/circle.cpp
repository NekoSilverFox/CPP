#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t& point, double r_circle):
  pointCircle_(point),
  rCircle_(r_circle)
{
  assert(r_circle > 0);
}

double Circle::getArea() const
{
  return 3.14 * rCircle_ * rCircle_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * rCircle_, 2 * rCircle_, pointCircle_};
}

void Circle::move(const double x_move, const double y_move)
{
  pointCircle_.x += x_move;
  pointCircle_.y += y_move;
}

void Circle::move(const point_t& point_new)
{
  pointCircle_ = point_new;
}
