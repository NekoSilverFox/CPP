#include <cmath>
#include "base-types.hpp"

bool jianing::isOverlap(const jianing::rectangle_t& first_rec, const jianing::rectangle_t& second_rec)
{
  if ((first_rec.width == 0.0) || (first_rec.height == 0.0))
  {
    return false;
  }

  if ((second_rec.width == 0.0) || (second_rec.height == 0.0))
  {
    return false;
  }

  double difference_x = std::fabs(first_rec.pos.x - second_rec.pos.x);
  double difference_y = std::fabs(first_rec.pos.y - second_rec.pos.y);
  double min_range_x = (first_rec.width + second_rec.width) / 2.0;
  double min_range_y = (first_rec.height + second_rec.height) / 2.0;

  return (difference_x < min_range_x) && (difference_y < min_range_y);
}
