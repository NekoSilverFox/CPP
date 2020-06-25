#ifndef YAKOVLEV_TRIANGLE
#define YAKOVLEV_TRIANGLE

#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{

public:

  Triangle(const point_t &vertice1, const point_t &vertice2, const point_t &vertice3);

  bool operator==(const Triangle &other) const;

  bool operator!=(const Triangle &other) const;

  virtual point_t getCenter() const override;

  virtual double getArea() const override;

  virtual rectangle_t getFrameRect() const override;

  virtual void move(const point_t &pos) override;

  virtual void move(double x, double y) override;

private:

  point_t vertices_[3];
  point_t pos_;

};

#endif
