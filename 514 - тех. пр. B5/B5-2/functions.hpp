#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <set>
#include "details.hpp"
#include <algorithm>

namespace jianing
{
  namespace B5
  {
    Shape readPoints(std::string& str_line, size_t vertices);
    void readShape(std::istream& istr, std::vector<Shape>& vec, std::string& str_line);

    int getLengthToCompare(const Point_t& l_point, const Point_t& r_point);
    void removePentagons(std::vector<Shape>& shapes);

    bool isLess(const Shape& l_shape, const Shape& r_shape);
    bool isRectangle(const Shape& shape);
    bool isSquare(const Shape& shape);
  }
}



#endif
