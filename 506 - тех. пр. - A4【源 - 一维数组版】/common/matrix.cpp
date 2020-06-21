#include "matrix.hpp"
#include <iostream>
#include <algorithm>
#include <exception>
#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

jianing::Matrix::Layer::Layer(jianing::Shape::ShapePtr* shape, size_t size) :
  size_(size),
  layer_(shape)
{}

jianing::Shape::ShapePtr& jianing::Matrix::Layer::operator[](size_t index)
{
  if (!layer_)
  {
    throw std::domain_error("The current layer is empty!");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Index can not be "
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(size_) + " !\n");
  }

  return layer_[index];
}

const jianing::Shape::ShapePtr& jianing::Matrix::Layer::operator[](size_t index) const
{
  if (!layer_)
  {
    throw std::domain_error("The current layer is empty!");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Index can not be "
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(size_) + " !\n");
  }

  return layer_[index];
}

jianing::Matrix::Matrix() :
  rows_(0),
  columns_(0),
  matrix_(std::make_unique<Shape::ShapePtrArr>(0))
{}

jianing::Matrix::Matrix(const Matrix& copied_object) :
  rows_(copied_object.rows_),
  columns_(copied_object.columns_),
  matrix_(std::make_unique<Shape::ShapePtrArr>(copied_object.rows_ * copied_object.columns_))
{
  if (!copied_object.matrix_)
  {
    throw std::invalid_argument("The matrix for copy constructor can not be empty!");
  }

  for (size_t i = 0; i < copied_object.rows_ * copied_object.columns_; ++i)
  {
    if (copied_object.matrix_[i])
    {
      matrix_[i] = copied_object.matrix_[i];
    }
  }
}

jianing::Matrix::Matrix(Matrix&& moved_object) :
  rows_(moved_object.rows_),
  columns_(moved_object.columns_),
  matrix_(std::move(moved_object.matrix_))
{
  moved_object.rows_ = 0;
  moved_object.columns_ = 0;
}

jianing::Matrix& jianing::Matrix::operator=(const jianing::Matrix& copied_object)
{
  if (this != &copied_object)
  {
    matrix_.reset();
    rows_ = copied_object.rows_;
    columns_ = copied_object.columns_;
    matrix_ = std::make_unique<Shape::ShapePtrArr>(columns_ * rows_);

    for (size_t i = 0; i < columns_ * rows_; i++)
    {
      if (!copied_object.matrix_[i])
      {
        matrix_[i] = copied_object.matrix_[i];
      }
    }
  }

  return *this;
}

jianing::Matrix& jianing::Matrix::operator=(jianing::Matrix&& moved_object)
{
  if (this != &moved_object)
  {
    rows_ = moved_object.rows_;
    columns_ = moved_object.columns_;
    matrix_ = std::move(moved_object.matrix_);

    moved_object.rows_ = 0;
    moved_object.columns_ = 0;
    moved_object.matrix_.reset();
  }

  return *this;
}

jianing::Matrix::Layer jianing::Matrix::operator[](const size_t index)
{
  if (!matrix_)
  {
    throw std::domain_error("The matrix is empty!");
  }

  if (index >= rows_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(rows_) + " !\n");
  }

  return Layer(&matrix_[index * columns_], columns_);
}

const jianing::Matrix::Layer jianing::Matrix::operator[](size_t index) const
{
  if (!matrix_)
  {
    throw std::domain_error("The matrix is empty!");
  }

  if (index >= rows_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(rows_) + " !\n");
  }

  return Layer(&matrix_[index * columns_], columns_);
}

size_t jianing::Matrix::getRowSize() const
{
  return rows_;
}

size_t jianing::Matrix::getColumnsSize() const
{
  return columns_;
}

std::pair<size_t, size_t> jianing::Matrix::findPlaceForInsert(const Shape::ShapePtr& shape) const
{
  rectangle_t frame_rect = shape->getFrameRect();
  size_t row = 0;
  size_t col = 0;

  while ((row < rows_) && (col < columns_) && matrix_[col * columns_ + row])
  {
    if (isOverlap(matrix_[col * columns_ + row]->getFrameRect(), frame_rect))
    {
      ++row;
      col = 0;
      continue;
    }

    ++col;
  }

  return std::make_pair(row, col);
}

void jianing::Matrix::addNewRow()
{
  std::unique_ptr<Shape::ShapePtrArr> new_matrix = std::make_unique<Shape::ShapePtrArr>((rows_ + 1) * columns_);

  for (size_t i = 0; i < columns_ * rows_; ++i)
  {
    if (!matrix_[i])
    {
      new_matrix[i] = matrix_[i];
    }
  }

  ++rows_;
  matrix_.swap(new_matrix);
}

void jianing::Matrix::addNewCol()
{
  std::unique_ptr<Shape::ShapePtrArr> new_matrix = std::make_unique<Shape::ShapePtrArr>(rows_ * (columns_ + 1));

  for (size_t i = 0; i < rows_; ++i)
  {
    for (size_t j = 0; j < columns_; ++j)
    {
      if (matrix_[i * columns_ + j])
      {
        new_matrix[i * (columns_ + 1) + j] = matrix_[i * columns_ + j];
      }
    }
  }

  ++columns_;
  matrix_.swap(new_matrix);
}

void jianing::Matrix::addShape(const jianing::Shape::ShapePtr& shape_new)
{
  if (!matrix_)
  {
    throw std::domain_error("The matrix is empty!");
  }

  if (!shape_new)
  {
    throw std::domain_error("The shape is empty, which is for insert!");
  }

  size_t row = 0;
  size_t col = 0;
  std::tie(row, col) = findPlaceForInsert(shape_new);

  if (row >= rows_)
  {
    addNewRow();
  }

  if (col >= columns_)
  {
    addNewCol();
  }

  matrix_[row * columns_ + col] = shape_new;
}
