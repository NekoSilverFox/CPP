#ifndef YAKOVLEV_COMPOSITE_SHAPE
#define YAKOVLEV_COMPOSITE_SHAPE

#include <iosfwd>
#include <memory>
#include <initializer_list>

#include "base-types.hpp"
#include "shape.hpp"

namespace yakovlev
{

  class CompositeShape : public Shape
  {

  public:

    CompositeShape(const CompositeShape & other);

    CompositeShape(CompositeShape && other) = default;
    
    explicit CompositeShape(const ShapePtr & shape);

    CompositeShape(const std::initializer_list<ShapePtr> & shapes);

    ~CompositeShape() = default;

    CompositeShape & operator=(const CompositeShape & other);

    CompositeShape & operator=(CompositeShape && other) = default;

    ShapePtr operator[](size_t index);

    ConstShapePtr operator[](size_t index) const;

    size_t getSize() const noexcept;

    void add(const ShapePtr &shape);

    void remove(size_t index);

    virtual point_t getCenter() const noexcept override;

    virtual double getArea() const noexcept override;

    virtual rectangle_t getFrameRect() const noexcept override;

    virtual void move(const point_t & pos) noexcept override;

    virtual void move(double x, double y) noexcept override;

    virtual void rotate(double rotation) noexcept override;

    virtual void scale(double coef) override;

    virtual void print(std::ostream & os) const override;

  private:

    size_t size_;
    std::unique_ptr<ShapePtr[]> shapes_;

  };

}

#endif
