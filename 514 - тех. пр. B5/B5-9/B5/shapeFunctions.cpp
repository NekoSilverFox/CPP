#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "shapeDefine.hpp"
#include "shapeFunctions.hpp"
#include "streamFunction.hpp"
#include "errorHandling.hpp"

namespace jianing
{
  namespace B5
  {
    const char* ERR_NO_RIGHT_BRACKET = "-> point: expected `(`";
    const char* ERR_NO_LEFT_BRACKET = "-> point: expected `)`";
    const char* ERR_NO_SEMICOLON = "-> point: expected `;`";
    const char* ERR_NOT_NUMBER = "-> point: expected `number`";
    const char* ERR_WRONG_POINT_NUM = "-> shape: Wrong input number point, number of point should greater than 2";
    const char* ERR_EXPECTED_SHAPE = "-> shape: incorrect point. Right format like: 3 (1;2) (2;3) (3;1)";
  }
}

jianing::B5::ShapeInfo::ShapeInfo() :
  num_vertice(0),
  num_triangle(0),
  num_square(0),
  num_rectangle(0)
{}

void jianing::B5::ShapeInfo::operator()(const vec_shape& shapes)
{
  std::for_each(shapes.begin(), shapes.end(), [&](const Shape& shape)
  {
    num_vertice += shape.size();

    switch (getShapeType(shape))
    {
    case TRIANGLE:
      ++num_triangle;
      break;

    case SQUARE:
      ++num_square;
      ++num_rectangle;
      break;

    case RECTANGLE:
      ++num_rectangle;
      break;

    case OTHER:
      break;
    }
  });
}

int jianing::B5::lengthForCompare(const Point_t& l_point, const Point_t& r_point)
{
  return (l_point.x - r_point.x) * (l_point.x - r_point.x)
       + (l_point.y - r_point.y) * (l_point.y - r_point.y);
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

jianing::B5::ShaptType jianing::B5::getShapeType(const Shape& shape)
{
  if (shape.size() == TRIANGLE_VERTICES)
  {
    return TRIANGLE;
  }
  else if (isSquare(shape))
  {
    return SQUARE;
  }
  else if (isRectangle(shape))
  {
    return RECTANGLE;
  }
  else
  {
    return OTHER;
  }
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
    err_msg.insertErrorMsg(ERR_NO_RIGHT_BRACKET);
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
  if (c_sign != ';')
  {
    err_msg.insertErrorMsg(ERR_NO_SEMICOLON);
    istr.setstate(std::istream::failbit);
    return istr;
  }
  else if (!istr.good())
  {
    err_msg.insertErrorMsg(ERR_NOT_NUMBER);
    istr.setstate(std::istream::failbit);
    return istr;
  }

  istr >> sf::rmw >> c_sign;
  if (c_sign != ')')
  {
    err_msg.insertErrorMsg(ERR_NO_LEFT_BRACKET);
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
    err_msg.insertErrorMsg(ERR_WRONG_POINT_NUM);
    istr.setstate(std::istream::failbit);
    return istr;
  }

  shape.resize(num_pt);

  for (Point_t& point : shape)
  {
    istr >> point;
    if (!istr.good())
    {
      err_msg.insertErrorMsg(ERR_EXPECTED_SHAPE);
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
