#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <memory>
#include "base-types.hpp"
#include "shape.hpp"
#include "layer.hpp"

namespace jianing
{
  class Layer;

  class Maxtrix : public Shape
  {
  public:
    using LayerPtr = std::shared_ptr<Layer>;

    Maxtrix();
    Maxtrix(const Maxtrix& copied_object);
    Maxtrix(Maxtrix&& moved_object);
    ~Maxtrix();

    Maxtrix& operator=(const Maxtrix& copied_object);
    Maxtrix& operator=(Maxtrix&& moved_object);
    LayerPtr operator[](const size_t index_layer) const;

    void addShape(const ShapePtr& shape_new);
    bool isOverlap(const LayerPtr& layer,const ShapePtr& shape) const;
    size_t getNumberLayer() const;
    void addNewLayer();

  private:
    void reserve(const size_t new_capacity);

    std::allocator<LayerPtr> allocator_layer_ptr;
    size_t size_; // number of the layers
    size_t capacity_;
    LayerPtr* layer_array_;
  };

}

#endif // MATRIX_HPP
