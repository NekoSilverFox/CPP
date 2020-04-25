#include "circle.hpp"
#include <cmath>
#include <cassert>
#include "base-types.hpp"

Circle::Circle(double r_circle, const point_t& point):
  point_circle_(point),
  r_circle_(r_circle)
{
  assert(r_circle > 0);
}

double Circle::getArea() const
{
  return M_PI * r_circle_ * r_circle_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * r_circle_, 2 * r_circle_, point_circle_};
}

void Circle::move(const double x_move, const double y_move)
{
  point_circle_.x += x_move;
  point_circle_.y += y_move;
}

void Circle::move(const point_t& point_new)
{
  point_circle_ = point_new;
}
