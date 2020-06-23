#ifndef SAMOKHIN_IGOR_BASE_TYPES_H
#define SAMOKHIN_IGOR_BASE_TYPES_H

namespace samokhin
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };

  bool areRectanglesCollides(const samokhin::rectangle_t &firstRect, const samokhin::rectangle_t &secondRect);

  double getDistanceBetweenPoints(const samokhin::point_t &firstPoint, const samokhin::point_t &secondPoint);
}

#endif //SAMOKHIN_IGOR_BASE_TYPES_H
