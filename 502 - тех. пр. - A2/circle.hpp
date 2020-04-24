#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace jianing
{

  class Circle : public Shape
  {
  public:
    Circle(double r_circle, const point_t& point);

    double getRadius() const;

    point_t getCenter() const override;

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const double x_move, const double  y_move) override;

    void move(const point_t& point_new) override;

    void scale(double coef) override;

  private:
    point_t point_circle_;

    double r_circle_;
  };

}

#endif // !CIRCLE_HPP
