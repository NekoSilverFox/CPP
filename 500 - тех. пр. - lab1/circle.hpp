#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(point_t point, double r_circle);
  Circle(double x_circle, double y_circle, double r_circle);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double x_move, const double  y_move) override;
  void move(const point_t& point_new) override;
  void printInfo() const override;

private:
  point_t pointCircle_;
  double rCircle_;
};
#endif // !CIRCLE_HPP
