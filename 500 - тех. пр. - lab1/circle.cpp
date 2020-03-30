#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t point, const double r_circle):
  pointCircle_(point),
  rCircle_(r_circle)
{
  assert(r_circle > 0);
}

double Circle::getArea() const
{
  return M_PI * this->rCircle_ * this->rCircle_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * this->rCircle_, 2 * this->rCircle_, this->pointCircle_};
}

void Circle::move(const double x_move, const double y_move)
{
  this->pointCircle_.x += x_move;
  this->pointCircle_.y += y_move;
}

void Circle::move(const point_t& point_new)
{
  this->pointCircle_ = point_new;
}
