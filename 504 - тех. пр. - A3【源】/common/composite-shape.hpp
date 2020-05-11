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
    CompositeShape(const std::shared_ptr<Shape>& init_shape);
    CompositeShape(const CompositeShape& copied_object);
    CompositeShape(CompositeShape&& moved_object);
    ~CompositeShape();

    CompositeShape& operator=(const CompositeShape& copied_object);
    bool operator==(const CompositeShape& comparison_object);
    std::shared_ptr<Shape> operator[](const size_t index) const;

    void pushShape(const std::shared_ptr<Shape>& shape_new);
    size_t getSize() const;
    bool empty() const;
    void removeShape(const size_t index);
    void printShape();

    point_t getCenter() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(double x_move, double y_move) override;
    void move(const point_t& point_new) override;
    void scale(double coef) override;

  private:
    size_t size_;
    std::unique_ptr<std::shared_ptr<Shape>[]> array_;
  };

}

#endif // !COMPOSITESHAPE_HPP
