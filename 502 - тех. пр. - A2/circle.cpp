#include "circle.hpp"
#include <cmath>
#include <cassert>
#include "base-types.hpp"

double jianing::Circle::getRadius() const
{
  return r_circle_;
}

jianing::point_t jianing::Circle::getCenter() const
{
  return point_circle_;
}

jianing::Circle::Circle(double r_circle, const point_t& point):
  point_circle_(point),
  r_circle_(r_circle)
{
  assert(r_circle > 0);
}

double jianing::Circle::getArea() const
{
  return 3.14 * r_circle_ * r_circle_;
}

jianing::rectangle_t jianing::Circle::getFrameRect() const
{
  return {2 * r_circle_, 2 * r_circle_, point_circle_};
}

void jianing::Circle::move(const double x_move, const double y_move)
{
  point_circle_.x += x_move;
  point_circle_.y += y_move;
}

void jianing::Circle::move(const point_t& point_new)
{
  point_circle_ = point_new;
}

void jianing::Circle::scale(double coef)
{
  assert(r_circle_ > 0);
  r_circle_ *= coef;
}
