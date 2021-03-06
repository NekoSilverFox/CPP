#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace jianing
{

  class Rectangle : public Shape
  {
  public:
    Rectangle(const rectangle_t& rectangle);

    Rectangle(const rectangle_t& rectangle, double angle);

    double getWidth() const;

    double getHeight() const;

    point_t getCenter() const override;

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void printShape() override;

    void printFrameRect() const override;

    void move(double x_move, double y_move) override;

    void move(const point_t& point_new) override;

    void scale(double coef) override;

    void rotate(double angle) override;

  private:
    rectangle_t rectangle_;

    double angle_;

  };

}

#endif
