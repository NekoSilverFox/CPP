#include <iostream>
#include <algorithm>
#include <string>
#include "details.hpp"
#include "functions.hpp"

void task2()
{
  std::string str;
  std::vector<Shape> shapes;
  std::vector<Point_t> points;

  readShape(shapes, str);

  size_t numberOfVertices = 0;
  size_t numberOfTriangles = 0;
  size_t numberOfSquares = 0;
  size_t numberOfRectangle = 0;

  std::for_each(shapes.begin(), shapes.end(), [&](const Shape& shape)
  {
    numberOfVertices += shape.size();
    if (shape.size() == TRIANGLE_VERTICES)
    {
      numberOfTriangles++;
    }
    else if (shape.size() == RECTANGLE_VERTICES)
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

  std::cout << "Vertices: " << numberOfVertices << std::endl;
  std::cout << "Triangles: " << numberOfTriangles << std::endl;
  std::cout << "Squares: " << numberOfSquares << std::endl;
  std::cout << "Rectangles: " << numberOfRectangle << std::endl;
  std::cout << "Points: ";
  for (auto &i : points)
  {
    std::cout << '(' << i.x << ';' << i.y << ") ";
  }
  std::cout << std::endl;
  std::cout << "Shapes: " << std::endl;
  for (const auto &shape : shapes)
  {
    std::cout << shape.size();
    for (const auto point : shape)
    {
      std::cout << " (" << point.x << ';' << point.y << ") ";
    }
    std::cout << std::endl;
  }
}