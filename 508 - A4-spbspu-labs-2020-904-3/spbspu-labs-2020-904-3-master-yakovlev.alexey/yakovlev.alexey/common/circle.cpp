#include "circle.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

#include <boost/format.hpp>

#include "base-types.hpp"

yakovlev::Circle::Circle(double radius, const point_t & center, double) :
  radius_{ radius },
  center_{ center }
{
  if (radius <= 0.0) {
    throw std::invalid_argument{ (boost::format("Invalid circle radius %1% - can not be negative or zero") % radius ).str() };
  }
}

bool yakovlev::Circle::operator==(const Circle & other) const noexcept
{
  return (center_ == other.center_) && (radius_ == other.radius_);
}

bool yakovlev::Circle::operator!=(const Circle & other) const noexcept
{
  return !(*this == other);
}

double yakovlev::Circle::getRadius() const noexcept
{
  return radius_;
}

yakovlev::point_t yakovlev::Circle::getCenter() const noexcept
{
  return center_;
}

double yakovlev::Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

yakovlev::rectangle_t yakovlev::Circle::getFrameRect() const noexcept
{
  return { radius_ * 2.0, radius_ * 2.0, center_ };
}

void yakovlev::Circle::move(const point_t & pos) noexcept
{
  center_ = pos;
}

void yakovlev::Circle::move(double x, double y) noexcept
{
  center_.x += x;
  center_.y += y;
}

void yakovlev::Circle::rotate(double) noexcept
{ }

void yakovlev::Circle::scale(double coef)
{
  if (coef <= 0.0) {
    throw std::invalid_argument{ (boost::format("Invalid circle scale coefficient %1% - can not be negative or zero") % coef ).str() };
  }
  radius_ *= coef;
}

void yakovlev::Circle::print(std::ostream & os) const
{
  os << "Circle with a radius of " << radius_ << " placed on " << center_ << '\n';
}
