#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <set>
#include "shapeDefine.hpp"
#include <algorithm>

namespace jianing
{
  namespace B5
  {
    int lengthForCompare(const Point_t& l_point, const Point_t& r_point);
    void printShapeInfo(std::ostream& ostr, const ShapeInfo& s_info, const char* delimiter);
    ShaptType getShapeType(const Shape& shape);

    bool isLess(const Shape& l_shape, const Shape& r_shape);
    bool isRectangle(const Shape& shape);
    bool isSquare(const Shape& shape);

    std::istream& operator>>(std::istream& istr, Point_t& point);
    std::ostream& operator<<(std::ostream& ostr, const Point_t& point);

    std::istream& operator>>(std::istream& istr, Shape& shape);
    std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
  }
}

#endif
