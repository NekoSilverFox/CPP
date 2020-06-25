#include "base-types.hpp"

#include <ostream>
#include <cmath>

bool yakovlev::operator==(const point_t & lhs, const point_t & rhs) noexcept
{
  return (lhs.x == rhs.x) && (lhs.y == rhs.y); 
}

bool yakovlev::operator!=(const point_t & lhs, const point_t & rhs) noexcept
{
  return !(lhs == rhs);
}

std::ostream& yakovlev::operator<<(std::ostream & os, const point_t & point)
{
  return os << '(' << point.x << ", " << point.y << ')';
}

namespace
{
  double square(double x) noexcept;
}

double yakovlev::getDistanceBetweenPoints(const point_t & p1, const point_t & p2) noexcept
{
  return sqrt(square(p1.x - p2.x) + square(p1.y - p2.y));
}

bool yakovlev::areOverlapping(const rectangle_t & lhs, const rectangle_t & rhs) noexcept
{
  return (abs(lhs.pos.x - rhs.pos.x) < ((lhs.width + rhs.width) / 2.0))
      && (abs(lhs.pos.y - rhs.pos.y) < ((lhs.height + rhs.height) / 2.0));  
}

bool yakovlev::operator==(const rectangle_t & lhs, const rectangle_t & rhs) noexcept
{
  return (lhs.width == rhs.width)
      && (lhs.height == rhs.height)
      && (lhs.pos == rhs.pos);
}

bool yakovlev::operator!=(const rectangle_t & lhs, const rectangle_t & rhs) noexcept
{
    return !(lhs == rhs);
}

namespace
{
  double square(double x) noexcept
  {
    return x * x;
  }
}
