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

jianing::Maxtrix::LayerPtr jianing::Maxtrix::operator[](const size_t index_layer) const
{
  if (index_layer >= row_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index_layer) + " ! Must smaller than"
        + std::to_string(row_) + " !\n");
  }

  return layer_array_[index_layer];
}

void jianing::Maxtrix::addShape(const jianing::Shape::ShapePtr& shape_new)
{
  if (shape_new == nullptr)
  {
    throw std::invalid_argument("Can not add shape which is null!\n");
  }

  for (size_t i = 0; i < row_; ++i)
  {
    if (isOverlap(layer_array_[i], shape_new) == false)
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

jianing::Shape::ShapePtr jianing::Maxtrix::getShape(size_t row_index, size_t col_index) const
{
  if (row_index >= row_)
  {
    throw std::out_of_range("Index row can not be"
        + std::to_string(row_index) + " ! Must smaller than"
        + std::to_string(row_) + " !\n");
  }

  if (col_index >= layer_array_[row_index]->getSize())
  {
    throw std::out_of_range("Index col can not be"
        + std::to_string(col_index) + " ! Must smaller than"
        + std::to_string(layer_array_[row_index]->getSize()) + " !\n");
  }

  return layer_array_[row_index]->getShape(col_index);
}

// Determine whether the given shape intersects the shape in the current layer
bool jianing::Maxtrix::isOverlap(const LayerPtr& layer,const jianing::Shape::ShapePtr& shape) const
{
  if (layer == nullptr)
  {
    throw std::invalid_argument("The layer is null!\n");
  }

  if (shape == nullptr)
  {
    throw std::invalid_argument("The shape is null!\n");
  }

  double top_current = 0.0;
  double bottom_current = 0.0;
  double left_current = 0.0;
  double right_current = 0.0;
  const double top_judgment = shape->getFrameRect().pos.x + shape->getFrameRect().height / 2.0;
  const double bottom_judgment = shape->getFrameRect().pos.y - shape->getFrameRect().height / 2.0;
  const double left_judgment = shape->getFrameRect().pos.x - shape->getFrameRect().width / 2.0;
  const double right_judgment = shape->getFrameRect().pos.x + shape->getFrameRect().width / 2.0;
  rectangle_t current_layer_frame = {0.0, 0.0, 0.0, 0.0};
  bool overlap = false;

  for (size_t i = 0; i < layer->size_; ++i)
  {
    try
    {
      current_layer_frame = layer->array_[i]->getFrameRect();
    }
    catch (const std::logic_error& error)
    {
      continue;
    }

    top_current = current_layer_frame.pos.y + current_layer_frame.height / 2.0;
    bottom_current = current_layer_frame.pos.y - current_layer_frame.height / 2.0;
    left_current = current_layer_frame.pos.x - current_layer_frame.width / 2.0;
    right_current = current_layer_frame.pos.x + current_layer_frame.width / 2.0;

    if (((top_judgment > top_current) || (bottom_judgment < bottom_current)) && ((left_judgment < left_current) || (right_judgment > right_current)))
    {
      continue;
    }
    else if (((left_judgment < left_current) || (right_judgment > right_current)) && ((top_judgment > top_current) || (bottom_judgment < bottom_current)))
    {
      continue;
    }
    // one small shape inside other big shape
    else if ((top_judgment <= top_current) && (bottom_judgment >= bottom_current) && (left_judgment >= left_current) && (right_judgment <= right_current))
    {
      overlap = true;
    }
    else
    {
      overlap = true;
      break;
    }
  }

  return overlap;
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
