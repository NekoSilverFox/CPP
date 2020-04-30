#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

double jianing::Circle::getRadius() const
{
  return r_circle_;
}

jianing::point_t jianing::Circle::getCenter() const
{
  return point_circle_;
}

jianing::Circle::Circle(const point_t& point, double r_circle):
  point_circle_(point),
  r_circle_(r_circle)
{
  if(r_circle <= 0)
  {
    throw std::domain_error("Error: Radius must be positive!\n");
  }
}

double jianing::Circle::getArea() const
{
  return 3 * r_circle_ * r_circle_;
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
  if(coef <= 0)
  {
    throw std::domain_error("Error: Coefficient must be positive!\n");
  }
  r_circle_ *= coef;
}
