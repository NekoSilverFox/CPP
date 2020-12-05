#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "details.hpp"
#include "functions.hpp"
#include "streamFunction.hpp"

int jianing::B5::lengthForCompare(const Point_t& l_point, const Point_t& r_point)
{
  return (l_point.x - r_point.x) * (l_point.x - r_point.x)
       + (l_point.y - r_point.y) * (l_point.y - r_point.y);
}

void jianing::B5::removePentagons(std::vector<Shape>& shapes)
{
  auto temp = remove_if(shapes.begin(), shapes.end(), [](const Shape& shape)
  {
    return (shape.size() == PENTAGON_VERTICES);
  });

  shapes.erase(temp, shapes.end());
}

bool jianing::B5::isLess(const Shape& l_shape, const Shape& r_shape)
{
  if (l_shape.size() < r_shape.size())
  {
    return true;
  }

  if (
         (l_shape.size() == RECTANGLE_VERTICES)
      && (r_shape.size() == RECTANGLE_VERTICES)
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
            (lengthForCompare(shape[0], shape[1]) == lengthForCompare(shape[2], shape[3]))
         && (lengthForCompare(shape[1], shape[2]) == lengthForCompare(shape[3], shape[0]))
         && (lengthForCompare(shape[0], shape[2]) == lengthForCompare(shape[1], shape[3]))
         );
}

bool jianing::B5::isSquare(const Shape &shape)
{
  if (isRectangle(shape))
  {
    if (lengthForCompare(shape[0], shape[1]) == lengthForCompare(shape[1], shape[2]))
    {
      return true;
    }
  }
  return false;
}

jianing::B5::Point_t jianing::B5::readPoint(std::istream& istr)
{
  if (!istr.good())
  {
    return {0, 0};
  }

  Point_t point = {0, 0};
  char c_sign = '\0';
  istr >> jianing::sf::rmw >> c_sign;

  if (c_sign != '(')
  {
    istr.setstate(std::istream::failbit);
    return {0, 0};
  }

  istr >> jianing::sf::rmw >> point.x
       >> jianing::sf::rmw >> c_sign
       >> jianing::sf::rmw >> point.y;

  if (c_sign != ';')
  {
    istr.setstate(std::istream::failbit);
    return {0, 0};
  }

  istr >> jianing::sf::rmw >> c_sign;

  if (c_sign != ')')
  {
    istr.setstate(std::istream::failbit);
    return {0, 0};
  }

  return point;
}

std::istream& jianing::B5::operator>>(std::istream& istr, Point_t& point)
{
  if (!istr.good())
  {
    return istr;
  }

  Point_t tmp_point = {0, 0};
  tmp_point = readPoint(istr);

  if (istr.good())
  {
    point = tmp_point;
  }

  return istr;
}

std::istream& jianing::B5::operator>>(std::istream& istr, Shape& shape)
{
  size_t num_pt = 0;
  istr >> num_pt;

  if (istr.fail() || num_pt < 3)
  {
    istr.setstate(std::istream::failbit);
    return istr;
  }

  shape.resize(num_pt);

  for (Point_t& point : shape)
  {
    if (istr.peek() == '\n')
    {
      istr.setstate(std::istream::failbit);
      return istr;
    }

    istr >> point;

    if (istr.fail())
    {
      istr.setstate(std::istream::failbit);
      return istr;
    }
  }

  return istr;
}

std::ostream& jianing::B5::operator<<(std::ostream& ostr, const Point_t& point)
{
  if (ostr.good())
  {
    ostr << '(' << point.x << ';' << point.y << ')';
  }

  return ostr;
}

std::ostream& jianing::B5::operator<<(std::ostream& ostr, const Shape& shape)
{
  if (ostr.good())
  {
    ostr << shape.size() << " ";
    std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point_t>(ostr, " "));
  }

  return ostr;
}
