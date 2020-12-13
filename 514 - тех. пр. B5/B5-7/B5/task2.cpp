#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include "details.hpp"
#include "functions.hpp"
#include "streamFunction.hpp"

void jianing::B5::task2(std::istream& istr, std::ostream& ostr)
{
  std::vector<Shape> shapes = {sig::shape_istr_iter(istr), sig::shape_istr_iter()};
  sf::istreamNotEofAndFail(istr, "ERROR! Input stream anomalies. Reading failed, incorrect shape data in task2!\n");

  ShapeInfo s_info = countShapeInfo(shapes);
  removePentagons(shapes);

  Shape points;
  for (const auto& i : shapes)
  {
    points.push_back(i.front());
  }

  std::sort(shapes.begin(), shapes.end(), isLess);

  printShapeInfo(ostr, s_info, "\n");

  ostr << "Points: ";
  std::copy(points.begin(), points.end(), sig::point_ostr_iter(ostr, " "));

  ostr << "\n"
       << "Shapes: \n";
  std::copy(shapes.begin(), shapes.end(), sig::shape_ostr_iter(ostr, "\n"));
}
