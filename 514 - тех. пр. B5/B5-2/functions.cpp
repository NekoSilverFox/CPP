#include <iostream>
#include <sstream>
#include "details.hpp"
#include "functions.hpp"

jianing::B5::Shape jianing::B5::readPoints(std::string& str_line, size_t vertices)
{
  Shape shape;
  size_t l_bracket;
  size_t r_bracket;
  size_t semicolon;

  for (size_t i = 0; i < vertices; i++)
  {
    if (str_line.empty())
    {
      throw std::invalid_argument("[invalid_argument] ERROR! Wrong number of vertices!\n");
    }

    while (str_line.find_first_of(" \t") == 0)
    {
      str_line.erase(0, 1);
    }

    l_bracket = str_line.find_first_of('(');
    r_bracket = str_line.find_first_of(')');
    semicolon = str_line.find_first_of(';');

    if (
           (l_bracket == std::string::npos)
        || (semicolon == std::string::npos)
        || (r_bracket == std::string::npos)
       )
    {
      throw std::invalid_argument("[invalid_argument] ERROR! Wrong point declaration!\n");
    }

    Point_t point
    {
      std::stoi(str_line.substr(l_bracket + 1, semicolon - l_bracket - 1)),
      std::stoi(str_line.substr(semicolon + 1, r_bracket - semicolon - 1))
    };

    str_line.erase(0, r_bracket + 1);

    shape.push_back(point);
  }

  while (str_line.find_first_of(" \t") == 0)
  {
    str_line.erase(0, 1);
  }

  if (!str_line.empty())
  {
    throw std::invalid_argument("[invalid_argument] ERROR! Too many points!\n");
  }

  return shape;
}

void jianing::B5::readShape(std::istream& istr, std::vector<Shape>& vec, std::string& str_line)
{
  while (std::getline(istr, str_line))
  {
    /*
     * 后期这里可以改成 checkStream
     */
    if (istr.fail())
    {
      throw std::ios_base::failure("[ios_base::failure] ERROR! Occured while reading data!\n");
    }

    while (str_line.find_first_of(" \t") == 0)
    {
      str_line.erase(0, 1);
    }

    if (str_line.empty())
    {
      continue;
    }

    size_t position = str_line.find_first_of('(');
    if (position == std::string::npos)
    {
      throw std::invalid_argument("[invalid_argument] ERROR! Wrong shape input!\n");
    }

    size_t numberOfVert = std::stoi(str_line.substr(0, position));
    str_line.erase(0, position);

    if (numberOfVert < 1)
    {
      throw std::invalid_argument("[invalid_argument] ERROR! Wrong number of vertices!\n");
    }

    vec.push_back(readPoints(str_line, numberOfVert));
  }
}

int jianing::B5::getLengthToCompare(const Point_t& l_point, const Point_t& r_point)
{
  return (l_point.x - r_point.x) * (l_point.x - r_point.x)
       + (l_point.y - r_point.y) * (l_point.y - r_point.y);
}

void jianing::B5::removePentagons(std::vector<Shape> &shapes)
{
  auto temp = remove_if(shapes.begin(), shapes.end(), [](const Shape &shape) { return (shape.size() == info::PENTAGON_VERTICES); });

  shapes.erase(temp, shapes.end());
}

bool jianing::B5::isLess(const Shape& l_shape, const Shape& r_shape)
{
  if (l_shape.size() < r_shape.size())
  {
    return true;
  }

  if (
         (l_shape.size() == info::RECTANGLE_VERTICES)
      && (r_shape.size() == info::RECTANGLE_VERTICES)
     )
  {
    if (isSquare(l_shape))
    {
      if (isSquare(r_shape))
      {
        return (l_shape[0].x < r_shape[0].x);
      }

      return true;
    }
  }

  return false;
}

bool jianing::B5::isRectangle(const Shape& shape)
{
  return (
            (getLengthToCompare(shape[0], shape[1]) == getLengthToCompare(shape[2], shape[3]))
         && (getLengthToCompare(shape[1], shape[2]) == getLengthToCompare(shape[3], shape[0]))
         && (getLengthToCompare(shape[0], shape[2]) == getLengthToCompare(shape[1], shape[3]))
         );
}

bool jianing::B5::isSquare(const Shape &shape)
{
  if (isRectangle(shape))
  {
    if (getLengthToCompare(shape[0], shape[1]) == getLengthToCompare(shape[1], shape[2]))
    {
      return true;
    }
  }
  return false;
}
