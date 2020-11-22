#include <iostream>
#include <sstream>
#include "details.hpp"
#include "functions.hpp"

void readShape(std::vector<Shape> &vector, std::string &str)
{
  while (std::getline(std::cin, str))
  {
    if (std::cin.fail())
    {
      throw std::ios_base::failure("Error occured while reading data \n");
    }

    while (str.find_first_of(" \t") == 0)
    {
      str.erase(0, 1);
    }

    if (str.empty())
    {
      continue;
    }

    size_t position = str.find_first_of('(');
    if (position == std::string::npos)
    {
      throw std::invalid_argument("Wrong shape input!\n");
    }

    size_t numberOfVert = std::stoi(str.substr(0, position));
    str.erase(0, position);
    if (numberOfVert < 1)
    {
      throw std::invalid_argument("Wrong number of vertices!\n");
    }

    Shape shape = readPoints(str, numberOfVert);

    vector.push_back(shape);
  }
}

Shape readPoints(std::string &str, size_t vertices)
{
  Shape shape;
  size_t lBracket;
  size_t semicolon;
  size_t rBracket;

  for (size_t i = 0; i < vertices; i++)
  {
    if (str.empty())
    {
      throw std::invalid_argument("Wrong number of vertices. \n");
    }

    while (str.find_first_of(" \t") == 0)
    {
      str.erase(0, 1);
    }

    lBracket = str.find_first_of('(');
    semicolon = str.find_first_of(';');
    rBracket = str.find_first_of(')');

    if ((lBracket == std::string::npos) || (semicolon == std::string::npos) || (rBracket == std::string::npos))
    {
      throw std::invalid_argument("Wrong point declaration! \n");
    }

    Point_t point
    {
      std::stoi(str.substr(lBracket + 1, semicolon - lBracket - 1)),
      std::stoi(str.substr(semicolon + 1, rBracket - semicolon - 1))
    };

    str.erase(0, rBracket + 1);

    shape.push_back(point);
  }

  while (str.find_first_of(" \t") == 0)
  {
    str.erase(0, 1);
  }

  if (!str.empty())
  {
    throw std::invalid_argument("Too many points. \n");
  }

  return shape;
}

bool isLess(const Shape& shape1, const Shape& shape2)
{
  if (shape1.size() < shape2.size())
  {
    return true;
  }
  if ((shape1.size() == RECTANGLE_VERTICES) && (shape2.size() == RECTANGLE_VERTICES))
  {
    if (isSquare(shape1))
    {
      if (isSquare(shape2))
      {
        return (shape1[0].x < shape2[0].x);
      }
      return true;
    }
  }
  return false;
}

int getLengthToCompare(const Point_t &point1, const Point_t &point2)
{
  return (point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y);
}

bool isRectangle(const Shape &shape)
{
  int diag1 = getLengthToCompare(shape[0], shape[2]);
  int diag2 = getLengthToCompare(shape[1], shape[3]);

  int vert1 = getLengthToCompare(shape[0], shape[1]);
  int vert2 = getLengthToCompare(shape[1], shape[2]);
  int vert3 = getLengthToCompare(shape[2], shape[3]);
  int vert4 = getLengthToCompare(shape[3], shape[0]);

  return ((vert1 == vert3) && (vert2 == vert4) && (diag1 == diag2));
}

bool isSquare(const Shape &shape)
{
  if (isRectangle(shape))
  {
    int side1 = getLengthToCompare(shape[0], shape[1]);
    int side2 = getLengthToCompare(shape[1], shape[2]);

    if (side1 == side2)
    {
      return true;
    }
  }
  return false;
}

void removePentagons(std::vector<Shape> &shapes)
{
  auto temp = remove_if(shapes.begin(), shapes.end(), [](const Shape &shape) { return (shape.size() == PENTAGON_VERTICES); });

  shapes.erase(temp, shapes.end());
}