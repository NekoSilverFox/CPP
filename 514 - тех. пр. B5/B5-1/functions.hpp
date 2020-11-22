#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <set>
#include "details.hpp"
#include <algorithm>

Shape readPoints(std::string& line, size_t vertices);
void readShape(std::vector<Shape>& vector, std::string& line);
bool isLess(const Shape& shape1, const Shape& shape2);
int getLengthToCompare(const Point_t&, const Point_t&);
bool isRectangle(const Shape& shape);
bool isSquare(const Shape& shape);
void removePentagons(std::vector<Shape> &shapes);

#endif