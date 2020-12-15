#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace jianing
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

  bool isOverlap(const rectangle_t& first_rec, const rectangle_t& second_rec);

}

#endif
