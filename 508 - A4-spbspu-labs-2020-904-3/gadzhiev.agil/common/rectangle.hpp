#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base-types.hpp"
#include "shape.hpp"
 
namespace gadzhiev
{
  class Rectangle : public Shape
  {
  public:

    Rectangle(double width, double height, const point_t& point, double degrees = 0);

    double getArea() const noexcept override;
    gadzhiev::rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& point) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double coefficient) override;
    void rotate(double degrees) noexcept override;
    point_t getCenter() const noexcept override;
    double getWidth() const noexcept;
    double getHeight() const noexcept;
    void printCorners() const noexcept;
    void printNameAndParametersOfShape() const noexcept override;

  private:

    point_t corners_[4];

  };
}

#endif
