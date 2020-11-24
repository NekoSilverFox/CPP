#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>
#include <iostream>
#include <iterator>

namespace jianing { namespace B5
{
    struct Point_t
    {
      int x;
      int y;
    };
    using Shape = std::vector<Point_t>;
} }

namespace jianing { namespace B5 { namespace info
{
  const std::size_t TRIANGLE_VERTICES = 3;
  const std::size_t RECTANGLE_VERTICES = 4;
  const std::size_t PENTAGON_VERTICES = 5;
} } }

/*
 * sig - sigillum
 */
namespace jianing { namespace B5 { namespace sig
{
  using str_istr_iter = std::istream_iterator<std::string>;
  using str_ostr_iter = std::ostream_iterator<std::string>;

  using shape_istr_iter = std::istream_iterator<Shape>;
  using shape_ostr_iter = std::ostream_iterator<Shape>;

  using point_istr_iter = std::istream_iterator<Point_t>;
  using point_ostr_iter = std::ostream_iterator<Point_t>;
} } }

#endif
