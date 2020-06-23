#ifndef CIRCLE_H
#define CIRCLE_H

#include "base-types.hpp"
#include "shape.hpp"

namespace gadzhiev
{
  class Circle : public Shape
  {
  public:

    Circle(double radius, const point_t& point);

    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& point) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double coefficient) override;
    void rotate(double degrees) noexcept override;
    point_t getCenter() const noexcept override;
    double getRadius() const noexcept;
    void printNameAndParametersOfShape() const noexcept override;

  private:

    double radius_;
    point_t center_;
  };
}

#endif 
