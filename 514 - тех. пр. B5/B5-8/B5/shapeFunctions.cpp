#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "shapeDefine.hpp"
#include "shapeFunctions.hpp"
#include "streamFunction.hpp"
#include "errorHandling.hpp"

jianing::B5::ShapeInfo::ShapeInfo() :
  num_vertice(0),
  num_triangle(0),
  num_square(0),
  num_rectangle(0)
{}

void jianing::B5::ShapeInfo::operator()(const vec_shape& shapes)
{
  num_vertice = countVertice(shapes);
  num_triangle = countTriangle(shapes);
  num_rectangle = countRectangle(shapes);
  num_square = countSquare(shapes);
}

int jianing::B5::lengthForCompare(const Point_t& l_point, const Point_t& r_point)
{
  return (l_point.x - r_point.x) * (l_point.x - r_point.x)
       + (l_point.y - r_point.y) * (l_point.y - r_point.y);
}

void jianing::B5::removePentagons(vec_shape& shapes)
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

bool jianing::B5::isSquare(const Shape& shape)
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

size_t jianing::B5::countVertice(const vec_shape& shapes)
{
  size_t count = 0;
  for (const Shape& shape : shapes)
  {
    count += shape.size();
  }
  return count;
}

size_t jianing::B5::countTriangle(const vec_shape& shapes)
{
  size_t count = 0;
  for (const Shape& shape : shapes)
  {
    if (shape.size() == TRIANGLE_VERTICES)
    {
      ++count;
    }
  }
  return count;
}

size_t jianing::B5::countRectangle(const vec_shape& shapes)
{
  size_t count = 0;
  for (const Shape& shape : shapes)
  {
    if ((shape.size() == RECTANGLE_VERTICES) && isRectangle(shape))
    {
      ++count;
    }
  }
  return count;
}

size_t jianing::B5::countSquare(const vec_shape& shapes)
{
  size_t count = 0;
  for (const Shape& shape : shapes)
  {
    if ((shape.size() == RECTANGLE_VERTICES) && isSquare(shape))
    {
      ++count;
    }
  }
  return count;
}

void jianing::B5::printShapeInfo(std::ostream& ostr, const ShapeInfo& s_info, const char* delimiter)
{
  if (ostr.good())
  {
    ostr << "Vertices: " << s_info.num_vertice << delimiter
         << "Triangles: " << s_info.num_triangle << delimiter
         << "Squares: " << s_info.num_square << delimiter
         << "Rectangles: " << s_info.num_rectangle << delimiter;
  }
}

std::istream& jianing::B5::operator>>(std::istream& istr, Point_t& point)
{
  auto old_state = istr.rdstate();
  std::istream::sentry istr_sentry(istr);
  if (!istr_sentry)
  {
    return istr;
  }

  char c_sign = '\0';
  istr >> std::noskipws >> sf::rmw >> c_sign;
  if (c_sign != '(')
  {
    errInfoCode.first = "Can not match `(`";
    errInfoCode.second = 1;
    istr.setstate(std::istream::failbit);
    return istr;
  }

  /*
   * The reason for using `tmp_point` is to provide the possibility for future
   * rollback operations (allowing the user to re-enter the correct values)
   */
  Point_t tmp_point = {0, 0};
  istr >> sf::rmw >> tmp_point.x
       >> sf::rmw >> c_sign
       >> sf::rmw >> tmp_point.y;
  if (c_sign != ';' || !istr.good())
  {
    errInfoCode.first = "Can not match `;`";
    errInfoCode.second = 1;
    istr.setstate(std::istream::failbit);
    return istr;
  }

  istr >> sf::rmw >> c_sign;
  if (c_sign != ')')
  {
    errInfoCode.first = "Can not match `)`";
    errInfoCode.second = 1;
    istr.setstate(std::istream::failbit);
    return istr;
  }

  point = tmp_point;
  istr.setstate(old_state);
  return istr;
}

std::istream& jianing::B5::operator>>(std::istream& istr, Shape& shape)
{
  std::istream::sentry istr_sentry(istr);
  if (!istr_sentry)
  {
    return istr;
  }

  size_t num_pt = 0;
  istr >> std::ws >> num_pt;
  if (istr.fail() || num_pt < 3)
  {
    errInfoCode = {"Wrong input number point, number of point should greater than 2", 1};
    istr.setstate(std::istream::failbit);
    return istr;
  }

  shape.resize(num_pt);

  for (Point_t& point : shape)
  {
    istr >> point;
    if (errInfoCode.second != 0)
    {
      istr.setstate(std::istream::failbit);
      return istr;
    }
  }

  return istr;
}

std::ostream& jianing::B5::operator<<(std::ostream& ostr, const Point_t& point)
{
  std::ostream::sentry ostr_sentry(ostr);
  if (ostr_sentry)
  {
    ostr << '(' << point.x << ';' << point.y << ')';
  }

  return ostr;
}

std::ostream& jianing::B5::operator<<(std::ostream& ostr, const Shape& shape)
{
  std::ostream::sentry ostr_sentry(ostr);
  if (ostr_sentry)
  {
    ostr << shape.size() << " ";
    std::copy(shape.begin(), shape.end(), point_ostr_iter(ostr, " "));
  }

  return ostr;
}
