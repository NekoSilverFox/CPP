#ifndef SHAPE_MATRIX_HPP
#define SHAPE_MATRIX_HPP

#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace gadzhiev
{
 
  class Matrix
  {
  public:

    class Layer
    {
    public:
      

      Shape::ConstShapePtr operator[](size_t index) const;
      Shape::ShapePtr operator[](size_t index);
      
    private:

      friend class Matrix;

      size_t size_;
      Shape::ShapePtr* layer_;

      Layer(Shape::ShapePtr* shape, size_t countOfFiguresInLayer) noexcept;
    };

    Matrix() noexcept;
    Matrix(const Matrix& otherMatrix) noexcept;
    Matrix(Matrix&& otherMatrix) noexcept;

    Matrix& operator=(const Matrix& otherMatrix) noexcept;
    Matrix& operator=(Matrix&& otherMatrix) noexcept;

    const Layer operator[](size_t index) const;
    Layer operator[](size_t index);
    void add(const Shape::ShapePtr& shape);

    size_t getNumberOfLayerToAddNewShape(const Shape::ShapePtr& shape) const;
    size_t getIndexOfFirstShapeInEssentialLayer(size_t figureNumber) const;
    size_t getIndexOfEssentialPositionToAdd(size_t layerNumber) const;
    size_t getLayersNumber(size_t layerNumber) const;
    size_t getCountOfLayers() const noexcept;
    size_t getCountOfShapesInMatrix() const noexcept;
    size_t getCountOfShapeInLayer(size_t layer) const noexcept;

  private:

    size_t countOfShapes_;
    size_t countOfLayers_;

    std::unique_ptr<Shape::ShapePtr[]> matrix_;
    std::unique_ptr<size_t[]> layers_;

  };
}

#endif
