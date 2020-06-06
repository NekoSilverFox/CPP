#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <memory>
#include "base-types.hpp"
#include "shape.hpp"
#include "layer.hpp"

namespace jianing
{
  class Layer;

  class Maxtrix
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

    void addShape(const Shape::ShapePtr& shape_new);
    size_t getRowNumber() const;
    size_t getColumnsNumber(size_t row_index) const;
    Shape::ShapePtr getShape(size_t row_index, size_t col_index) const;
    bool isOverlap(const LayerPtr& layer,const Shape::ShapePtr& shape) const;

  private:
    void addNewLayer();

    size_t row_; // number of the layers
    std::unique_ptr<LayerPtr[]> layer_array_;
  };

}

#endif // MATRIX_HPP
