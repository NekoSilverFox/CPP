#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include "details.hpp"
#include "functions.hpp"

void jianing::B5::task2(std::istream& istr, std::ostream& ostr)
{
  std::vector<Shape> shapes = {sig::shape_istr_iter(std::cin), sig::shape_istr_iter()};

  if (!istr.eof() && istr.fail())
  {
    throw std::invalid_argument("[invalid_argument] ERROR! Input stream anomalies. Reading failed, incorrect shape data in task2!\n");
  }

  size_t num_vertices = 0;
  size_t num_triangles = 0;
  size_t num_squares = 0;
  size_t num_rectangles = 0;

  std::for_each(shapes.begin(), shapes.end(), [&](const Shape& shape)
  {
    num_vertices += shape.size();
    if (shape.size() == info::TRIANGLE_VERTICES)
    {
      num_triangles++;
    }
    else if (shape.size() == info::RECTANGLE_VERTICES)
    {
      if (isRectangle(shape))
      {
        num_rectangles++;
        if (isSquare(shape))
        {
          num_squares++;
        }
      }
    }
  });

  removePentagons(shapes);

  Shape points;
  for (const auto& i : shapes)
  {
    points.push_back(i.front());
  }

  std::sort(shapes.begin(), shapes.end(), isLess);

  ostr << "Vertices: " << num_vertices << "\n"
       << "Triangles: " << num_triangles << "\n"
       << "Squares: " << num_squares << "\n"
       << "Rectangles: " << num_rectangles << "\n"
       << "Points: ";

  std::copy(points.begin(), points.end(), sig::point_ostr_iter(ostr, " "));
  ostr << "\nShapes: \n";
  std::copy(shapes.begin(), shapes.end(), sig::shape_ostr_iter(ostr, "\n"));
}
