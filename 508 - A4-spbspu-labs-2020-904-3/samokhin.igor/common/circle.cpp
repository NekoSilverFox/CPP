#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

samokhin::Circle::Circle(double radius, const samokhin::point_t &center):
  center_(center),
  radius_(radius)
{
  if (radius < 0)
  {
    throw std::invalid_argument("Invalid radius: circle's radius can't be less then zero");
  }
}

double samokhin::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

samokhin::rectangle_t samokhin::Circle::getFrameRect() const
{
  return {center_, radius_ * 2.0, radius_ * 2.0};
}

void samokhin::Circle::move(double x, double y)
{
  center_.x += x;
  center_.y += y;
}

void samokhin::Circle::move(const samokhin::point_t &pos)
{
  center_ = pos;
}

void samokhin::Circle::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Invalid coefficient: coefficient can't be less then zero");
  }

  radius_ *= k;
}

void samokhin::Circle::rotate(double)
{}

samokhin::point_t samokhin::Circle::getCenter() const
{
  return center_;
}

