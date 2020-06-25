#include "circle.hpp"

#include <cmath>
#include <string>
#include <stdexcept>

Circle::Circle(double radius, const point_t &center) :
  radius_{radius},
  center_{center}
{
  if (radius <= 0.0) {
    throw std::invalid_argument(std::string("Invalid circle radius " 
        + std::to_string(radius) + " - can't be negative or zero"));
  }
}

bool Circle::operator==(const Circle &other) const
{
  return (center_ == other.center_) && (radius_ == other.radius_);
}

bool Circle::operator!=(const Circle &other) const
{
  return !(*this == other);
}

double Circle::getRadius() const
{
  return radius_;
}

point_t Circle::getCenter() const
{
  return center_;
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2.0, radius_ * 2.0, center_};
}

void Circle::move(const point_t &pos)
{
  center_ = pos;
}

void Circle::move(double x, double y)
{
  center_.x += x;
  center_.y += y;
}
