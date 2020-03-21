#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(rectangle_t rec);
  Rectangle(double width_rec, double height_rec, double x_rec, double y_rec);
  Rectangle(double width_rec, double height_rec, const point_t& point_rec);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double x_move, double y_move) override;
  void move(const point_t& point_new) override;
  void printInfo() const override;

private:
  rectangle_t rectangle_;
};
#endif // !RECTANGLE_HPP
