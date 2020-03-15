#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double mX, double mY) = 0;
  virtual void move(const point_t &point) = 0;
  virtual void printInfo() const = 0;
};

#endif
