#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include "shapeDefine.hpp"
#include "shapeFunctions.hpp"
#include "streamFunction.hpp"
#include "errorHandling.hpp"

void jianing::B5::task2(std::istream& istr, std::ostream& ostr)
{
  vec_shape shapes = {shape_istr_iter(istr), shape_istr_iter()};
  sf::istreamNotEofAndFail(istr, errInfoCode.first.c_str());

  ShapeInfo s_info;
  s_info(shapes);
  removePentagons(shapes);

  Shape points;
  for (const auto& i : shapes)
  {
    points.push_back(i.front());
  }

  std::sort(shapes.begin(), shapes.end(), isLess);

  printShapeInfo(ostr, s_info, "\n");

  ostr << "Points: ";
  std::copy(points.begin(), points.end(), point_ostr_iter(ostr, " "));

  ostr << "\n"
       << "Shapes: \n";
  std::copy(shapes.begin(), shapes.end(), shape_ostr_iter(ostr, "\n"));
}
