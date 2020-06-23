#include "matrix.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <cmath>
#include "shape.hpp"
#include "base-types.hpp"

gadzhiev::Matrix::Layer::Layer(Shape::ShapePtr* shape, size_t countOfFiguresInLayer) noexcept :
  size_{ countOfFiguresInLayer },
  layer_{ shape }
{}

gadzhiev::Shape::ConstShapePtr gadzhiev::Matrix::Layer::operator[](size_t index) const
{
  
  if (index >= size_)
  {
    throw std::out_of_range("Invalid index, your index " + std::to_string(index));
  }

  return layer_[index];
}

gadzhiev::Shape::ShapePtr gadzhiev::Matrix::Layer::operator[](size_t index)
{
  if (!layer_)
  {
    throw std::invalid_argument("Layer is nullptr");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Invalid index, your index " + std::to_string(index));
  }

  return layer_[index];
}

gadzhiev::Matrix::Matrix() noexcept :
  countOfShapes_{ 0 },
  countOfLayers_{ 0 },
  matrix_{ nullptr },
  layers_{ nullptr }   
{}

gadzhiev::Matrix::Matrix(const Matrix& otherMatrix) noexcept :
  countOfShapes_{ otherMatrix.countOfShapes_ },
  countOfLayers_{ otherMatrix.countOfLayers_ },
  matrix_{ std::make_unique<Shape::ShapePtr[]>(countOfShapes_) },
  layers_{ std::make_unique<size_t[]>(countOfLayers_) }
{
  for (size_t i = 0; i < countOfShapes_; ++i)
  {
    matrix_[i] = otherMatrix.matrix_[i];
  }

  for (size_t i = 0; i < countOfLayers_; ++i)
  {
    layers_[i] = otherMatrix.layers_[i];
  }
}

gadzhiev::Matrix::Matrix(Matrix&& otherMatrix) noexcept:
  countOfShapes_{ otherMatrix.countOfShapes_ },
  countOfLayers_{ otherMatrix.countOfLayers_ },
  matrix_{ std::move(otherMatrix.matrix_) },
  layers_{ std::move(otherMatrix.layers_) }
{
  otherMatrix.countOfLayers_ = 0;
  otherMatrix.countOfShapes_ = 0;
}

gadzhiev::Matrix& gadzhiev::Matrix::operator=(const Matrix& otherMatrix) noexcept
{
  if (this == &otherMatrix)
  {
    return *this;
  }

  countOfLayers_ = otherMatrix.countOfLayers_;
  countOfShapes_ = otherMatrix.countOfShapes_;

  matrix_ = std::make_unique<Shape::ShapePtr[]>(countOfShapes_);

  for (size_t i = 0; i < countOfShapes_; ++i)
  {
    matrix_[i] = otherMatrix.matrix_[i];
  }

  for (size_t i = 0; i < countOfLayers_; ++i)
  {
    layers_[i] = otherMatrix.layers_[i];
  }

  return *this;
}

gadzhiev::Matrix& gadzhiev::Matrix::operator=(Matrix&& otherMatrix) noexcept
{
  if (this == &otherMatrix)
  {
    return *this;
  }

  countOfShapes_ = otherMatrix.countOfShapes_;
  countOfLayers_ = otherMatrix.countOfLayers_;

  matrix_ = std::move(otherMatrix.matrix_);
  layers_ = std::move(otherMatrix.layers_);

  otherMatrix.countOfLayers_ = 0;
  otherMatrix.countOfShapes_ = 0;

  return *this;

}

const gadzhiev::Matrix::Layer gadzhiev::Matrix::operator[](size_t index) const
{
  if (countOfShapes_ == 0)
  {
    throw std::length_error("Matrix is empty");
  }

  if (index >= countOfLayers_)
  {
    throw std::out_of_range("Invalid index of layer, your index " + std::to_string(index));
  }

  size_t indexOfShapeInEssentialLayer = getIndexOfFirstShapeInEssentialLayer(index);

  return Layer(&matrix_[indexOfShapeInEssentialLayer], layers_[index]);
}

gadzhiev::Matrix::Layer gadzhiev::Matrix::operator[](size_t index)
{
  if (countOfShapes_ == 0)
  {
    throw std::length_error("Matrix is empty");
  }

  if (index >= countOfLayers_)
  {
    throw std::out_of_range("Invalid index of layer, your index " + std::to_string(index));
  }

  size_t indexOfShapeInEssentialLayer = getIndexOfFirstShapeInEssentialLayer(index);

  return Layer(&matrix_[indexOfShapeInEssentialLayer], layers_[index]);
}

void gadzhiev::Matrix::add(const Shape::ShapePtr& shape)
{
  if (!shape)
  {
    throw std::invalid_argument("Object is nullptr");
  }

  size_t numberOfEssetialLayer = getNumberOfLayerToAddNewShape(shape);   

  if (numberOfEssetialLayer < countOfLayers_)
  {

    size_t positionOfEssetialShape = getIndexOfEssentialPositionToAdd(numberOfEssetialLayer);

    ++layers_[numberOfEssetialLayer];

    ++countOfShapes_;
    std::unique_ptr<Shape::ShapePtr[]>tempArrayOfFigure = std::make_unique<Shape::ShapePtr[]>(countOfShapes_);

    for (size_t i = 0; i < positionOfEssetialShape; ++i)
    {
      tempArrayOfFigure[i] = matrix_[i];
    }

    tempArrayOfFigure[positionOfEssetialShape] = shape;

    for (size_t i = positionOfEssetialShape + 1; i < countOfShapes_; ++i)
    {
      tempArrayOfFigure[i] = matrix_[i - 1];
    }

    matrix_.swap(tempArrayOfFigure);
  }
  else
  {
    countOfLayers_++;
    std::unique_ptr<size_t[]>tempLayers = std::make_unique<size_t[]>(countOfLayers_);

    for (size_t i = 0; i < (countOfLayers_ - 1); ++i)
    {
      tempLayers[i] = layers_[i];
    }

    ++tempLayers[countOfLayers_ - 1];
    layers_.swap(tempLayers);

    countOfShapes_++;
    std::unique_ptr<Shape::ShapePtr[]>tempArrayOfFigure = std::make_unique<Shape::ShapePtr[]>(countOfShapes_);

    for (size_t i = 0; i < (countOfShapes_ - 1); ++i)
    {
      tempArrayOfFigure[i] = matrix_[i];
    }

    tempArrayOfFigure[countOfShapes_ - 1] = shape;
    matrix_.swap(tempArrayOfFigure);
  }
}

size_t gadzhiev::Matrix::getNumberOfLayerToAddNewShape(const Shape::ShapePtr& shape) const
{
  if (!shape)
  {
    throw std::invalid_argument("Object is nullptr");
  }

  size_t numberOfEssetialLayer = 0;
  for (size_t i = 0; i < countOfShapes_; ++i)
  {
    if (gadzhiev::isShapesIntersect(matrix_[i]->getFrameRect(), shape->getFrameRect()))
    {
      size_t layer = getLayersNumber(i);
      numberOfEssetialLayer += layer + 1;
    }
  }
  return numberOfEssetialLayer;
}

size_t gadzhiev::Matrix::getLayersNumber(size_t figureNumber) const
{
  if (figureNumber >= countOfShapes_)
  {
    throw std::invalid_argument("Invalid index of shape Number, your index " + std::to_string(figureNumber));
  }

  size_t figuresCount = 0;
  size_t j = 0;

  while (figureNumber >= figuresCount)
  {
    figuresCount += layers_[j++];
  }

  return --j;
}

size_t gadzhiev::Matrix::getIndexOfFirstShapeInEssentialLayer(size_t layerNumber) const
{
  if (layerNumber >= countOfLayers_)
  {
    throw std::invalid_argument("Invalid index of layer number, your index " + std::to_string(layerNumber));
  }

  size_t indexOfShapeInEssentialLayer = 0;

  for (size_t i = 0; i < layerNumber; ++i)
  {
    indexOfShapeInEssentialLayer += getCountOfShapeInLayer(i);
  }

  return indexOfShapeInEssentialLayer;
}

size_t gadzhiev::Matrix::getIndexOfEssentialPositionToAdd(size_t layerNumber) const
{
  if (layerNumber >= countOfLayers_)
  {
    throw std::invalid_argument("Invalid index of layer number, your index " + std::to_string(layerNumber));
  }

  size_t indexOfShapeInEssentialLayer = 0;

  for (size_t i = 0; i <= layerNumber; ++i)
  {
    indexOfShapeInEssentialLayer += layers_[i];
  }

  return indexOfShapeInEssentialLayer;
}

size_t gadzhiev::Matrix::getCountOfLayers() const noexcept
{
  return countOfLayers_;
}

size_t gadzhiev::Matrix::getCountOfShapeInLayer(size_t layer) const noexcept
{
  return layers_[layer];
}

size_t gadzhiev::Matrix::getCountOfShapesInMatrix() const noexcept
{
  return countOfShapes_;
}
