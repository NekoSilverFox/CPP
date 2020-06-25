#ifndef YAKOVLEV_LAYER
#define YAKOVLEV_LAYER

#include <iosfwd>
#include <memory>

#include "shape.hpp"

namespace yakovlev
{

  class Layer
  {

  public:

    Layer();

    Layer(const Layer & other);

    Layer(Layer && other) noexcept;

    Layer & operator=(const Layer & other);

    Layer & operator=(Layer && other) noexcept; 

    Shape::ShapePtr operator[](size_t index);

    Shape::ConstShapePtr operator[](size_t index) const;

    size_t getSize() const noexcept;

    bool isEmpty() const noexcept;

    void add(const Shape::ShapePtr & shape);

    void remove(size_t index);

    bool contains(const Shape::ConstShapePtr & shape) const;

    bool intersects(const Shape & shape) const noexcept;

    void print(std::ostream & os) const;

    friend std::ostream & operator<<(std::ostream & os, const Layer layer);

  private:

    size_t size_;
    std::unique_ptr<Shape::ShapePtr []> shapes_;

  };

  std::ostream & operator<<(std::ostream & os, const Layer layer);

} 

#endif
