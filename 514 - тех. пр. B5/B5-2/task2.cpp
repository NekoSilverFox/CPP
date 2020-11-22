#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include "details.hpp"
#include "functions.hpp"

void jianing::B5::task2(std::istream& istr, std::ostream& ostr)
{
  std::string str;
  std::vector<Shape> shapes;
  std::vector<Point_t> points;

  readShape(istr, shapes, str);

  size_t numberOfVertices = 0;
  size_t numberOfTriangles = 0;
  size_t numberOfSquares = 0;
  size_t numberOfRectangle = 0;

  std::for_each(shapes.begin(), shapes.end(), [&](const Shape& shape)
  {
    numberOfVertices += shape.size();
    if (shape.size() == info::TRIANGLE_VERTICES)
    {
      numberOfTriangles++;
    }
    else if (shape.size() == info::RECTANGLE_VERTICES)
    {
      if (isRectangle(shape))
      {
        numberOfRectangle++;
        if (isSquare(shape))
        {
          numberOfSquares++;
        }
      }
    }
  });

  removePentagons(shapes);

  for (auto i = shapes.begin(); i != shapes.end(); i++)
  {
    points.push_back((*i).front());
  }

  std::sort(shapes.begin(), shapes.end(), isLess);

  ostr << "Vertices: " << numberOfVertices << "\n";
  ostr << "Triangles: " << numberOfTriangles << "\n";
  ostr << "Squares: " << numberOfSquares << "\n";
  ostr << "Rectangles: " << numberOfRectangle << "\n";
  ostr << "Points: ";

  for (auto &i : points)
  {
    ostr << '(' << i.x << ';' << i.y << ") ";
  }

  ostr << "\n";
  ostr << "Shapes: " << "\n";

  for (const auto& shape : shapes)
  {
    ostr << shape.size();
    for (const auto point : shape)
    {
      ostr << " (" << point.x << ';' << point.y << ") ";
    }
    ostr << "\n";
  }
}
