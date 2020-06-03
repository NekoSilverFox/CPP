#ifndef LAYER_HPP
#define LAYER_HPP
#include <memory>
#include "base-types.hpp"
#include "shape.hpp"
#include "matrix.hpp"

namespace jianing
{

  class Layer
  {
    friend class Maxtrix;

  public:
    Layer();
    Layer(const Layer& copied_object);
    Layer(Layer&& moved_object);
    ~Layer();

    Layer& operator=(const Layer& copied_object);
    Layer& operator=(Layer&& moved_object);
    jianing::Shape::ShapePtr operator[](const size_t index) const;

    void addShape(const jianing::Shape::ShapePtr& shape_new);
    jianing::Shape::ShapePtr getShape(size_t index) const;
    size_t getSize() const;
    bool empty() const;

  private:
    void reserve(const size_t new_capacity);

    std::allocator<jianing::Shape::ShapePtr> allocator_shape_ptr;
    size_t size_; // number of the shapes
    size_t capacity_;
    jianing::Shape::ShapePtr* array_;
  };

}

#endif // LAYER_HPP
