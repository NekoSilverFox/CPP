#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double rCircle, const point_t &cpoint);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double mX, double mY) override;
  void move(const point_t &point) override;
  void printInfo() const override;
  
private:
  double rCircle_;
  point_t pos_;
};

#endif //CIRCLE_HPP
