#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>

struct Point_t
{
  int x, y;
};

const std::size_t TRIANGLE_VERTICES = 3;
const std::size_t RECTANGLE_VERTICES = 4;
const std::size_t PENTAGON_VERTICES = 5;

using Shape = std::vector<Point_t>;

#endif