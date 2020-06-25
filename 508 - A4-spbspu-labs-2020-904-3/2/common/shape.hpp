#ifndef SHAPE_H
#define SHAPE_H

#include <memory>

namespace gadzhiev
{
  struct point_t;
  struct rectangle_t;

  class Shape
  {
  public:   

    typedef std::shared_ptr<const Shape> ConstShapePtr;
    typedef std::shared_ptr<Shape> ShapePtr;
    

    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double coefficient) = 0;
    virtual void rotate(double degrees) = 0;
    virtual point_t getCenter() const = 0;
    virtual void printNameAndParametersOfShape() const = 0;
  };
}

#endif
