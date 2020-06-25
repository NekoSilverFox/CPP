#ifndef SAMOKHIN_IGOR_CIRCLE_HPP
#define SAMOKHIN_IGOR_CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace samokhin
{
  class Circle: public Shape
  {
  public:
    Circle(double radius, const point_t &center);

    virtual double getArea() const override;

    virtual rectangle_t getFrameRect() const override;

    virtual void move(double x, double y) override;

    virtual void move(const point_t &pos) override;

    virtual void scale(double k) override;

    virtual void rotate(double angle) override;

    virtual point_t getCenter() const override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif //SAMOKHIN_IGOR_CIRCLE_HPP
