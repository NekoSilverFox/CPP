#ifndef YAKOVLEV_BASE
#define YAKOVLEV_BASE

#include <iosfwd>

namespace yakovlev
{

  struct point_t
  {
    double x;
    double y;
  };

  bool operator==(const point_t & lhs, const point_t & rhs) noexcept;

  bool operator!=(const point_t & lhs, const point_t & rhs) noexcept;

  std::ostream & operator<<(std::ostream & os, const point_t & point);

  double getDistanceBetweenPoints(const point_t & p1, const point_t & p2) noexcept;

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

  bool areOverlapping(const rectangle_t & lhs, const rectangle_t & rhs) noexcept;

  bool operator==(const rectangle_t & lhs, const rectangle_t & rhs) noexcept;

  bool operator!=(const rectangle_t & lhs, const rectangle_t & rhs) noexcept;

}

#endif
