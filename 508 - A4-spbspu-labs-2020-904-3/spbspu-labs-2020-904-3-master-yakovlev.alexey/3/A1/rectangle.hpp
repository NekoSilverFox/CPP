#ifndef YAKOVLEV_RECTANGLE
#define YAKOVLEV_RECTANGLE

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{

public:

  Rectangle(double width, double height, const point_t &pos);

  bool operator==(const Rectangle &other) const;

  bool operator!=(const Rectangle &other) const;

  double getWidth() const;

  double getHeight() const;

  virtual point_t getCenter() const override;

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const override;

  virtual void move(const point_t &pos) override;

  virtual void move(double x, double y) override;

private:

  rectangle_t rec_;

};

#endif
