#ifndef SAMOKHIN_IGOR_RECTANGLE_HPP
#define SAMOKHIN_IGOR_RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace samokhin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, const point_t &pos);

    virtual double getArea() const override;

    virtual rectangle_t getFrameRect() const override;

    virtual void move(double x, double y) override;

    virtual void move(const point_t &pos) override;

    virtual void scale(double k) override;

    virtual void rotate(double angle) override;

    virtual point_t getCenter() const override;

  private:
    point_t vertices_[4];
  };
}

#endif //SAMOKHIN_IGOR_RECTANGLE_HP
