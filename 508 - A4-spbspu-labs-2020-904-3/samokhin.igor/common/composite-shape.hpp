#ifndef SAMOKHIN_IGOR_COMPOSITE_SHAPE_HPP
#define SAMOKHIN_IGOR_COMPOSITE_SHAPE_HPP

#include <memory>

#include "shape.hpp"
#include "base-types.hpp"

namespace samokhin
{
  class CompositeShape: public Shape
  {
  public:
    CompositeShape();

    CompositeShape(const CompositeShape &compositeShape);

    CompositeShape(CompositeShape &&compositeShape) = default;

    ~CompositeShape() = default;

    CompositeShape &operator=(const CompositeShape &compositeShape);

    CompositeShape &operator=(CompositeShape &&compositeShape) = default;

    SharedShape operator[](size_t index);

    const SharedShape operator[](size_t index) const;

    virtual double getArea() const override;

    virtual rectangle_t getFrameRect() const override;

    virtual void move(double x, double y) override;

    virtual void move(const point_t &pos) override;

    virtual void scale(double k) override;

    void add(const SharedShape &shape);

    void remove(size_t index);

    size_t getSize();

    virtual void rotate(double angle);

    virtual point_t getCenter() const override;

  private:
    std::unique_ptr<SharedShapeArray> array_;
    size_t size_;
  };

}
#endif //SAMOKHIN_IGOR_COMPOSITE_SHAPE_HPP
