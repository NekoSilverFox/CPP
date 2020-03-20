#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
class Circle : public Shape
{
public:
  Circle(point_t point, double r_circle);
  Circle(double x_circle, double y_circle, double r_circle);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double x_move, double y_move);
  void move(const point_t& point_new);
  void printInfo() const;
private:
  point_t pointCircle_;
  double rCircle_;
};
#endif // !CIRCLE_HPP
