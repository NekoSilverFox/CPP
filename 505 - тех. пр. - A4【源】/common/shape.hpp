#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>

namespace jianing
{

  struct point_t;
  struct rectangle_t;

  class Shape
  {
  public:
    using ShapePtr = std::shared_ptr<Shape>;

    virtual ~Shape() = default;

    virtual point_t getCenter() const = 0;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(double x_move, double y_move) = 0;

    virtual void move(const point_t& point_new) = 0;

    virtual void scale(double coef) = 0;

    virtual void rotate(double angle) = 0; // 新增
  };

}

#endif
