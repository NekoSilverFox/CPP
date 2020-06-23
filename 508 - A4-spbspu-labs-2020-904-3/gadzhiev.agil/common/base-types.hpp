#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace gadzhiev
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

  bool isShapesIntersect(const rectangle_t& firstFrameRect, const rectangle_t& secondFrameRect) noexcept;
  double getDistance(const point_t& firstPoint, const point_t& secondPoint) noexcept;

}

#endif
