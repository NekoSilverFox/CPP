#include "matrix.hpp"
#include <iostream>
#include <algorithm>
#include <exception>
#include <memory>
#include "base-types.hpp"
#include "layer.hpp"

jianing::Maxtrix::Maxtrix() :
  row_(0),
  layer_array_(nullptr)
{}

jianing::Maxtrix::Maxtrix(const Maxtrix& copied_object) :
  row_(copied_object.row_),
  layer_array_(std::make_unique<LayerPtr[]>(copied_object.row_))
{
  for (size_t i = 0; i < row_; ++i)
  {
    layer_array_[i] = copied_object.layer_array_[i];
  }
}

jianing::Maxtrix::Maxtrix(Maxtrix&& moved_object) :
  row_(moved_object.row_),
  layer_array_(std::move(moved_object.layer_array_))
{
  moved_object.row_ = 0;
  moved_object.layer_array_.reset();
}

jianing::Maxtrix::~Maxtrix()
{
  row_ = 0;
  layer_array_.reset();
}

jianing::Maxtrix& jianing::Maxtrix::operator=(const jianing::Maxtrix& copied_object)
{
  if (this != &copied_object)
  {
    row_ = copied_object.row_;
    layer_array_ = std::make_unique<LayerPtr[]>(copied_object.row_);

    for (size_t i = 0; i < row_; ++i)
    {
      layer_array_[i] = copied_object.layer_array_[i];
    }
  }

  return *this;
}

jianing::Maxtrix& jianing::Maxtrix::operator=(jianing::Maxtrix&& moved_object)
{
  if (this != &moved_object)
  {
    row_ = moved_object.row_;
    layer_array_ = std::move(moved_object.layer_array_);

    moved_object.row_ = 0;
    moved_object.layer_array_.reset();
  }

  return *this;
}

jianing::Layer& jianing::Maxtrix::operator[](const size_t index_layer) const
{
  if (index_layer >= row_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index_layer) + " ! Must smaller than"
        + std::to_string(row_) + " !\n");
  }

  return *layer_array_[index_layer];
}

void jianing::Maxtrix::addShape(const jianing::Shape::ShapePtr& shape_new)
{
  if (shape_new == nullptr)
  {
    throw std::invalid_argument("Can not add shape which is null!\n");
  }

  for (size_t i = 0; i < row_; ++i)
  {
    if (layer_array_[i]->isOverlap(shape_new) == false)
    {
      layer_array_[i]->addShape(shape_new);

      return;
    }
  }

  addNewLayer();

  layer_array_[row_ - 1]->addShape(shape_new);
}

size_t jianing::Maxtrix::getRowNumber() const
{
  return row_;
}

size_t jianing::Maxtrix::getColumnsNumber(size_t row_index) const
{
  if (row_index >= row_)
  {
    throw std::out_of_range("Index row can not be"
        + std::to_string(row_index) + " ! Must smaller than"
        + std::to_string(row_) + " !\n");
  }

  return layer_array_[row_index]->getSize();
}

void jianing::Maxtrix::addNewLayer()
{
  ++row_;
  std::unique_ptr<LayerPtr[]> new_layer_array = std::make_unique<LayerPtr[]>(row_);

  for (size_t i = 0; i < row_ - 1; ++i)
  {
    new_layer_array[i] = layer_array_[i];
  }
  new_layer_array[row_ - 1] = std::move(LayerPtr(new Layer));

  layer_array_ = std::move(new_layer_array);
  new_layer_array.reset();
}

jianing::Maxtrix::LayerPtr jianing::Maxtrix::getLayerPtr(const size_t index_layer) const
{
  if (index_layer >= row_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index_layer) + " ! Must smaller than"
        + std::to_string(row_) + " !\n");
  }

  return layer_array_[index_layer];
}
