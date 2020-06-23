#ifndef YAKOVLEV_SHAPE
#define YAKOVLEV_SHAPE

#include <iosfwd>
#include <memory>

namespace yakovlev
{

  struct point_t;
  struct rectangle_t;

  class Shape
  {

  public:

    typedef std::shared_ptr<Shape> ShapePtr;

    typedef std::shared_ptr<const Shape> ConstShapePtr;

    virtual ~Shape() = default;

    virtual point_t getCenter() const = 0;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(const point_t &pos) = 0;

    virtual void move(double x, double y) = 0;

    virtual void rotate(double rotation) = 0;

    virtual void scale(double coef) = 0;

    virtual void print(std::ostream& os) const = 0;

  };

}

#endif
