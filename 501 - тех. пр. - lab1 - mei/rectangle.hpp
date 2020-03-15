#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double heigh, const point_t &center);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double mX, double mY) override;
  void move(const point_t &point) override;
  void printInfo() const override;
  
private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
