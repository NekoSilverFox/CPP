#ifndef COPMOSITE_SHAPES_H
#define COPMOSITE_SHAPES_H

#include <memory>
#include <initializer_list>
#include "base-types.hpp"
#include "shape.hpp"

namespace gadzhiev
{
  class CompositeShape : public Shape
  {
  public:

    CompositeShape(const CompositeShape& otherCompositeShape);
    CompositeShape(CompositeShape&& otherCompositeShape) = default;
    explicit CompositeShape(const ShapePtr& shape);
    explicit CompositeShape(const std::initializer_list<ShapePtr>& shapes);

    ~CompositeShape() = default;

    CompositeShape& operator=(const CompositeShape& otherCompositeShape);
    CompositeShape& operator=(CompositeShape&& otherCompositeShape) = default;

    ConstShapePtr operator[](size_t index) const;
    ShapePtr operator[](size_t index);
    void add(const ShapePtr& shape);
    void remove(size_t index);
    size_t getSize() const;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
    void rotate(double degrees) override;
    point_t getCenter() const override;
    void printNameAndParametersOfShape() const override;

  private:

    size_t size_;
    std::unique_ptr<ShapePtr []> arrayOfFigure_;
    
  };
}

#endif
