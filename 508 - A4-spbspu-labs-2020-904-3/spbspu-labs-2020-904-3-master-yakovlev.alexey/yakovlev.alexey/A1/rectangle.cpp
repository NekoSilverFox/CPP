#include "rectangle.hpp"

#include <string>
#include <stdexcept>

Rectangle::Rectangle(double width, double height, const point_t &pos) :
  rec_{width, height, pos}
{
  if (width <= 0.0) {
    throw std::invalid_argument(std::string("Invalid rectangle width " 
        + std::to_string(width) + " - can't be negative or zero"));
  }
  if (height <= 0.0) {
    throw std::invalid_argument(std::string("Invalid rectangle height " 
        + std::to_string(height) + " - can't be negative or zero"));
  }
}

bool Rectangle::operator==(const Rectangle &other) const
{
  return rec_ == other.rec_;
}

bool Rectangle::operator!=(const Rectangle &other) const
{
  return !(*this == other);
}

double Rectangle::getWidth() const
{
  return rec_.width;
}

double  Rectangle::getHeight() const
{
  return rec_.height;
}

point_t Rectangle::getCenter() const
{
  return rec_.pos;
}

double Rectangle::getArea() const
{
  return rec_.width * rec_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rec_;
}

void Rectangle::move(const point_t &pos)
{
  rec_.pos = pos;
}

void Rectangle::move(double x, double y)
{
  rec_.pos.x += x;
  rec_.pos.y += y;
}
