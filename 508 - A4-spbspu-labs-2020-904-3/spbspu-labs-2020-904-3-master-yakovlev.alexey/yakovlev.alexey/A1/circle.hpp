#ifndef YAKOVLEV_CIRCLE
#define YAKOVLEV_CIRCLE

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{

public:

  Circle(double radius, const point_t &center);

  bool operator==(const Circle &other) const;

  bool operator!=(const Circle &other) const;
  
  double getRadius() const;

  virtual point_t getCenter() const override;

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const override;

  virtual void move(const point_t &pos_) override;

  virtual void move(double x, double y) override;

private:

  double radius_;
  point_t center_;

};

#endif
