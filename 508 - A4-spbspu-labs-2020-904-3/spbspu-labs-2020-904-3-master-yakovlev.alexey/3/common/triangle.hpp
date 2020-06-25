#ifndef YAKOVLEV_TRIANGLE
#define YAKOVLEV_TRIANGLE

#include <iosfwd>

#include "shape.hpp"
#include "base-types.hpp"

namespace yakovlev
{

  class Triangle : public Shape
  {

  public:

    Triangle(
      const point_t & vertice1,
      const point_t & vertice2,
      const point_t & vertice3,
      double rotation = 0.0
    );

    bool operator==(const Triangle & other) const noexcept;

    bool operator!=(const Triangle & other) const noexcept;

    virtual point_t getCenter() const noexcept override;

    virtual double getArea() const noexcept override;

    virtual rectangle_t getFrameRect() const noexcept override;

    virtual void move(const point_t & pos) noexcept override;

    virtual void move(double x, double y) noexcept override;

    virtual void rotate(double rotation) noexcept override;

    virtual void scale(double coef) override;

    virtual void print(std::ostream & os) const override;

  private:

    point_t vertices_[3];
    point_t pos_;

  };

}

#endif
