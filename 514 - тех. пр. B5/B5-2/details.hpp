#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>

namespace jianing
{
  namespace B5
  {
    struct Point_t
    {
      int x;
      int y;
    };
    using Shape = std::vector<Point_t>;

    namespace info
    {
      const std::size_t TRIANGLE_VERTICES = 3;
      const std::size_t RECTANGLE_VERTICES = 4;
      const std::size_t PENTAGON_VERTICES = 5;
    }
  }
}

#endif
