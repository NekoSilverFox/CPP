#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace jianing
{

  class Rectangle : public Shape
  {
  public:
    Rectangle(const rectangle_t& rec);

    double getWidth() const;

    double getHeight() const;

    point_t getCenter() const override;

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(double x_move, double y_move) override;

    void move(const point_t& point_new) override;

    void scale(double coef) override;

  private:
    rectangle_t rectangle_;
  };

}

#endif
