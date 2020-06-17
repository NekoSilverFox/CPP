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
    Layer& operator[](const size_t index_layer) const;

    void addShape(const Shape::ShapePtr& shape_new);
    size_t getRowNumber() const;
    size_t getColumnsNumber(size_t row_index) const;
    LayerPtr getLayerPtr(const size_t index_layer) const;

    Shape::ShapePtr getShape(size_t row_index, size_t col_index) const;


  private:
    void addNewLayer();

    size_t row_; // number of the layers
    std::unique_ptr<LayerPtr[]> layer_array_;
  };

}

#endif // MATRIX_HPP
