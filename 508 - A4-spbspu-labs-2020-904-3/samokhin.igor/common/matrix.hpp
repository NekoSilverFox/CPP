#ifndef SPBSPU_LABS_2020_904_3_A4_MATRIX_HPP
#define SPBSPU_LABS_2020_904_3_A4_MATRIX_HPP

#include "shape.hpp"

namespace samokhin
{
  class Matrix
  {
  public:
    class Layer
    {
    public:
      Shape::SharedShape &operator[](size_t index);

      const Shape::SharedShape &operator[](size_t index) const;

      size_t getAmountOfShapes() const;

    private:
      friend class Matrix;

      size_t size_;
      samokhin::Shape::SharedShape *layer_;

      Layer(Shape::SharedShape *array, size_t size);

    };

    Matrix();

    Matrix(const Matrix &matrix);

    Matrix(Matrix &&matrix) = default;

    ~Matrix() = default;

    Matrix &operator=(const Matrix &matrix);

    Matrix &operator=(Matrix &&matrix) = default;

    Layer operator[](size_t index);

    const Layer operator[](size_t index) const;

    void add(const Shape::SharedShape &shape);

    void remove(size_t row, size_t column);

    size_t getRowSize() const;

    size_t getColumnSize() const;

  private:
    size_t rows_;
    size_t columns_;
    std::unique_ptr<Shape::SharedShapeArray> matrix_;

  };
}

#endif //SPBSPU_LABS_2020_904_3_A4_MATRIX_HPP
