#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t point, const double r_circle);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double x_move, const double  y_move) override;
  void move(const point_t& point_new) override;

private:
  point_t pointCircle_;
  double rCircle_;
};
#endif // !CIRCLE_HPP
