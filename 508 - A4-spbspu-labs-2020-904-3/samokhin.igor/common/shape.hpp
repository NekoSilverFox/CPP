#ifndef SAMOKHIN_IGOR_SHAPE_HPP
#define SAMOKHIN_IGOR_SHAPE_HPP

#include <memory>

namespace samokhin
{
  struct rectangle_t;
  struct point_t;

  class Shape
  {
  public:
    using SharedShapeArray = std::shared_ptr<Shape>[];
    using SharedShape = std::shared_ptr<Shape>;

    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(double x, double y) = 0;

    virtual void move(const point_t &pos) = 0;

    virtual void scale(double k) = 0;

    virtual void rotate(double angle) = 0;

    virtual point_t getCenter() const = 0;
  };
}

#endif //SAMOKHIN_IGOR_SHAPE_HPP
