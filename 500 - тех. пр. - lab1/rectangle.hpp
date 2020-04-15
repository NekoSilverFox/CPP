#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const rectangle_t& rec);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double x_move, const double y_move) override;
  void move(const point_t& point_new) override;

private:
  rectangle_t rectangle_;
};
#endif // !RECTANGLE_HPP
