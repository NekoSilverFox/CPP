#include <iostream>
#include "matrix.hpp"
#include "base-types.hpp"

samokhin::Matrix::Layer::Layer(samokhin::Shape::SharedShape *array, size_t size):
  size_(size),
  layer_(array)
{
}

samokhin::Shape::SharedShape &samokhin::Matrix::Layer::operator[](size_t index)
{
  if (!layer_)
  {
    throw std::domain_error("Domain error: you can't get element of empty layer");
  }

  if (index >= getAmountOfShapes())
  {
    throw std::out_of_range("Out of range error: index out of bounds of layer");
  }

  return layer_[index];
}

const samokhin::Shape::SharedShape &samokhin::Matrix::Layer::operator[](size_t index) const
{
  if (!layer_)
  {
    throw std::domain_error("Domain error: you can't get element of empty layer");
  }

  if (index >= getAmountOfShapes())
  {
    throw std::out_of_range("Out of range error: index out of bounds of layer");
  }

  return layer_[index];
}

size_t samokhin::Matrix::Layer::getAmountOfShapes() const
{
  if (!layer_)
  {
    return 0;
  }

  size_t amount = 0;
  for (size_t i = 0; i < size_; i++)
  {
    if (!layer_[i])
    {
      return amount;
    }

    amount++;
  }

  return amount;
}

samokhin::Matrix::Matrix():
  rows_(0),
  columns_(0),
  matrix_(std::make_unique<Shape::SharedShapeArray>(0))
{
}

samokhin::Matrix::Matrix(const samokhin::Matrix &matrix):
  rows_(matrix.rows_),
  columns_(matrix.columns_),
  matrix_(std::make_unique<Shape::SharedShapeArray>(matrix.rows_ * matrix.columns_))
{
  if ((matrix.rows_ == 0) || (matrix.columns_ == 0))
  {
    throw std::invalid_argument("Invalid argument: matrix can't be initialize with empty matrix");
  }

  for (size_t i = 0; i < rows_ * columns_; i++)
  {
    if (matrix.matrix_[i])
    {
      matrix_[i] = matrix.matrix_[i];
    }
  }
}

samokhin::Matrix &samokhin::Matrix::operator=(const samokhin::Matrix &matrix)
{
  if (&matrix == this)
  {
    return *this;
  }

  rows_ = matrix.rows_;
  columns_ = matrix.columns_;
  matrix_.reset();
  matrix_ = std::make_unique<Shape::SharedShapeArray>(columns_ * rows_);

  for (size_t i = 0; i < columns_ * rows_; i++)
  {
    if (matrix.matrix_[i])
    {
      matrix_[i] = matrix.matrix_[i];
    }
  }

  return *this;
}

samokhin::Matrix::Layer samokhin::Matrix::operator[](size_t index)
{
  if (!matrix_)
  {
    throw std::domain_error("Domain error: you can't get shape from moved matrix");
  }

  if (index >= rows_)
  {
    throw std::out_of_range("Out of range error: row out of bounds of matrix");
  }
  return samokhin::Matrix::Layer{&(matrix_[index * columns_]), columns_};
}

const samokhin::Matrix::Layer samokhin::Matrix::operator[](size_t index) const
{
  if (!matrix_)
  {
    throw std::domain_error("Domain error: you can't get shape from moved matrix");
  }

  if (index >= rows_)
  {
    throw std::out_of_range("Out of range error: row out of bounds of matrix");
  }

  return samokhin::Matrix::Layer{&matrix_[index * columns_], columns_};
}

void samokhin::Matrix::add(const samokhin::Shape::SharedShape &shape)
{
  if (!shape)
  {
    throw std::invalid_argument("Invalid argument: empty shape can't be added in matrix");
  }

  rectangle_t rectangle = shape->getFrameRect();

  size_t i = 0;
  size_t j = 0;
  if (matrix_)
  {
    while ((i < rows_) && (j < columns_) && matrix_[i * columns_ + j])
    {
      if (areRectanglesCollides(rectangle, matrix_[i * columns_ + j]->getFrameRect()))
      {
        i++;
        j = 0;
        continue;
      }
      j++;
    }
  }

  if ((i == 0) && (j == 0))
  {
    rows_ = 1;
    columns_ = 1;
    matrix_.reset();
    matrix_ = std::make_unique<Shape::SharedShapeArray>(1);
  }
  else if (i >= rows_)
  {
    std::unique_ptr<Shape::SharedShapeArray> newM = std::make_unique<Shape::SharedShapeArray>((rows_ + 1) * columns_);

    for (size_t k = 0; k < (columns_ * rows_); k++)
    {
      if (matrix_[k])
      {
        newM[k] = matrix_[k];
      }
    }

    rows_++;

    matrix_.reset();
    matrix_.swap(newM);
  }
  else if (j >= columns_)
  {
    std::unique_ptr<Shape::SharedShapeArray> newM = std::make_unique<Shape::SharedShapeArray>(rows_ * (columns_ + 1));

    for (size_t f = 0; f < rows_; f++)
    {
      for (size_t g = 0; g < columns_; g++)
      {
        if (matrix_[f * columns_ + g])
        {
          newM[f * (columns_ + 1) + g] = matrix_[f * columns_ + g];
        }
      }
    }

    columns_++;

    matrix_.reset();
    matrix_.swap(newM);
  }

  matrix_[i * columns_ + j] = shape;
}

void samokhin::Matrix::remove(size_t row, size_t column)
{
  if (!matrix_)
  {
    throw std::domain_error("Domain error: you can't delete shape from moved matrix");
  }
  if (row >= rows_)
  {
    throw std::out_of_range("Out of range error: row out of bounds of matrix");
  }
  if (column >= columns_)
  {
    throw std::out_of_range("Out of range error: column out of bounds of layer");
  }
  if (!matrix_[row * columns_ + column])
  {
    throw std::domain_error("Domain error: you can't delete empty place");
  }

  std::unique_ptr<Shape::SharedShapeArray> oldMatrix = std::move(matrix_);
  size_t oldColumns = columns_;
  size_t oldRows = rows_;
  rows_ = 0;
  columns_ = 0;

  for (size_t i = 0; i < row * oldColumns + column; i++)
  {
    add(oldMatrix[i]);
  }

  for (size_t i = row * oldColumns + column + 1; i < oldRows * oldColumns; i++)
  {
    add(oldMatrix[i]);
  }
}

size_t samokhin::Matrix::getRowSize() const
{
  if (!matrix_)
  {
    return 0;
  }
  return rows_;
}

size_t samokhin::Matrix::getColumnSize() const
{
  if (!matrix_)
  {
    return 0;
  }
  return columns_;
}
