#ifndef YAKOVLEV_RECTANGLE
#define YAKOVLEV_RECTANGLE

#include <iosfwd>

#include "shape.hpp"
#include "base-types.hpp"

namespace yakovlev
{

  class Rectangle : public Shape
  {

  public:

    Rectangle(double width, double height, const point_t & pos, double rotation = 0.0);

    bool operator==(const Rectangle & other) const noexcept;

    bool operator!=(const Rectangle & other) const noexcept;

    double getWidth() const noexcept;

    double getHeight() const noexcept;

    virtual point_t getCenter() const noexcept override;

    virtual double getArea() const noexcept override;

    virtual rectangle_t getFrameRect() const noexcept override;

    virtual void move(const point_t & pos) noexcept override;

    virtual void move(double x, double y) noexcept override;

    virtual void rotate(double rotation) noexcept override;

    virtual void scale(double coef) override;

    virtual void print(std::ostream & os) const override;

  private:

    point_t vertices_[4];

  };

}

#endif
