#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <memory>
#include "base-types.hpp"
#include "shape.hpp"

namespace jianing
{

  class Matrix
  {
  public:
    class Layer
    {
    public:
      Shape::ShapePtr& operator[](size_t index);
      const Shape::ShapePtr& operator[](size_t index) const;

    private:
      friend class Matrix;
      size_t size_;
      Shape::ShapePtr* layer_;

      Layer(Shape::ShapePtr* shape, size_t size);
    };

    Matrix();
    Matrix(const Matrix& copied_object);
    Matrix(Matrix&& moved_object);
    ~Matrix() = default;

    Matrix& operator=(const Matrix& copied_object);
    Matrix& operator=(Matrix&& moved_object);
    Layer operator[](size_t index);
    const Layer operator[](size_t index) const;

    size_t getRowSize() const;
    size_t getColumnsSize() const;
    void addShape(const Shape::ShapePtr& shape_new);

  private:
    size_t rows_;
    size_t columns_;
    std::unique_ptr<Shape::ShapePtrArr> matrix_;

    /*
    ** This pair save the place, where the new shape should insert
    ** .first - row
    ** .second - columns
    */
    std::pair<size_t, size_t> findPlaceForInsert(const Shape::ShapePtr& shape) const;
    void addNewRow();
    void addNewCol();
  };

}

#endif // MATRIX_HPP
