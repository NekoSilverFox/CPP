#include <cmath>
#include "base-types.hpp"

bool samokhin::areRectanglesCollides(const samokhin::rectangle_t &firstRect, const samokhin::rectangle_t &secondRect)
{
  double dx = std::abs(firstRect.pos.x - secondRect.pos.x);
  double dy = std::abs(firstRect.pos.y - secondRect.pos.y);

  double minRangeX = (firstRect.width + secondRect.width) / 2.0;
  double minRangeY = (firstRect.height + secondRect.height) / 2.0;

  return (dx < minRangeX) && (dy < minRangeY);
}

double samokhin::getDistanceBetweenPoints(const samokhin::point_t &firstPoint, const samokhin::point_t &secondPoint)
{
  return std::sqrt(std::pow(firstPoint.x - secondPoint.x, 2) + std::pow(firstPoint.y - secondPoint.y, 2));
}
