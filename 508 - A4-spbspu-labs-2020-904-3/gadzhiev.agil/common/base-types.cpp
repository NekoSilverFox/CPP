#include "base-types.hpp"
#include <cmath>

bool gadzhiev::isShapesIntersect(const rectangle_t& firstFrameRect, const rectangle_t& secondFrameRect) noexcept
{
  double distanceX = firstFrameRect.pos.x - secondFrameRect.pos.x;
  double distanceY = firstFrameRect.pos.y - secondFrameRect.pos.y;

  double widthSum = firstFrameRect.width + secondFrameRect.width;
  double heightSum = firstFrameRect.height + secondFrameRect.height;

  return (std::abs(distanceX) < (widthSum / 2.0))
      && (std::abs(distanceY) < (heightSum / 2.0));
}

double gadzhiev::getDistance(const point_t& firstPoint, const point_t& secondPoint) noexcept
{
  return sqrt(pow(firstPoint.x - secondPoint.x, 2) + pow(firstPoint.y - secondPoint.y, 2));
}
