#ifndef YAKOVLEV_CIRCLE
#define YAKOVLEV_CIRCLE

#include <iosfwd>

#include "shape.hpp"
#include "base-types.hpp"

namespace yakovlev
{

  class Circle : public Shape
  {

  public:

    Circle(double radius, const point_t & center, double rotation = 0.0);

    bool operator==(const Circle & other) const noexcept;

    bool operator!=(const Circle & other) const noexcept;
    
    double getRadius() const noexcept;

    virtual point_t getCenter() const noexcept override ;

    virtual double getArea() const noexcept override;

    virtual rectangle_t getFrameRect() const noexcept override;

    virtual void move(const point_t & pos_) noexcept override;

    virtual void move(double x, double y) noexcept override;

    virtual void rotate(double rotation) noexcept override;

    virtual void scale(double coef) override;

    virtual void print(std::ostream & os) const override;

  private:

    double radius_;
    point_t center_;

  };

}

#endif
