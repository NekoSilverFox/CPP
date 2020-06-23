#include "base-types.hpp"

#include <ostream>
#include <cmath>

bool operator==(const point_t &lhs, const point_t &rhs)
{
  return (lhs.x == rhs.x) && (lhs.y == rhs.y); 
}

bool operator!=(const point_t &lhs, const point_t &rhs)
{
  return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream &os, const point_t &point)
{
  return os << '(' << point.x << ", " << point.y << ')';
}

namespace
{
  double square(double x);
}

double getDistanceBetweenPoints(const point_t &p1, const point_t &p2)
{
  return sqrt(square(p1.x - p2.x) + square(p1.y - p2.y));
}

bool operator==(const rectangle_t &lhs, const rectangle_t &rhs)
{
  return (lhs.width == rhs.width)
      && (lhs.height == rhs.height)
      && (lhs.pos == rhs.pos);
}

bool operator!=(const rectangle_t &lhs, const rectangle_t &rhs)
{
    return !(lhs == rhs);
}

namespace
{
  double square(double x) 
  {
    return x * x;
  }
}
