#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include <memory>
#include "base-types.hpp"
#include "shape.hpp"

namespace jianing
{

  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& copied_object);
    CompositeShape(CompositeShape&& moved_object);
    ~CompositeShape();

    CompositeShape& operator=(CompositeShape&& moved_object);
    CompositeShape& operator=(const CompositeShape& copied_object);
    ShapePtr operator[](const size_t index) const;

    void pushShape(const ShapePtr& shape_new);
    size_t getSize() const;
    size_t getCapacity() const;
    void reserve(const size_t new_capacity);
    bool empty() const;
    void removeShape(const size_t index);
    void printShape();

    point_t getCenter() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(double x_move, double y_move) override;
    void move(const point_t& point_new) override;
    void scale(double coef) override;
    void rotate(double angle) override;

  private:
    std::allocator<ShapePtr> allocator_shape_ptr;
    size_t size_;
    size_t capacity_;
    ShapePtr* array_;
  };

}

#endif // !COMPOSITESHAPE_HPP
