#include "layer.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <exception>
#include <memory>
#include "base-types.hpp"
const size_t INITCAPACITY = 3;

jianing::Layer::Layer() :
  size_(0),
  capacity_(INITCAPACITY),
  array_(allocator_shape_ptr.allocate(INITCAPACITY))
{}

jianing::Layer::Layer(const Layer& copied_object) :
  size_(copied_object.size_),
  capacity_(copied_object.capacity_),
  array_(allocator_shape_ptr.allocate(copied_object.capacity_))
{
  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.construct(&array_[i], copied_object[i]);
  }
}

jianing::Layer::Layer(jianing::Layer&& moved_object) :
  size_(moved_object.size_),
  capacity_(moved_object.capacity_),
  array_(moved_object.array_)
{
  moved_object.size_ = 0;
  moved_object.capacity_ = 0;
  moved_object.array_ = nullptr;
}

jianing::Layer::~Layer()
{
  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.destroy(&array_[i]);
  }
  allocator_shape_ptr.deallocate(array_, capacity_);
}

jianing::Layer& jianing::Layer::operator=(const jianing::Layer& copied_object)
{
  if (this != &copied_object)
  {
    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.destroy(&array_[i]);
    }
    allocator_shape_ptr.deallocate(array_, capacity_);

    size_ = copied_object.size_;
    capacity_ = copied_object.capacity_;
    array_ = allocator_shape_ptr.allocate(capacity_);

    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.construct(&array_[i], copied_object[i]);
    }
  }

  return *this;
}

jianing::Layer& jianing::Layer::operator=(jianing::Layer&& moved_object)
{
  if (this != &moved_object)
  {
    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.destroy(&array_[i]);
    }
    allocator_shape_ptr.deallocate(array_, capacity_);

    size_ = moved_object.size_;
    capacity_ = moved_object.capacity_;
    array_ = moved_object.array_;

    moved_object.size_ = 0;
    moved_object.capacity_ = 0;
    moved_object.array_ = nullptr;
  }

  return *this;
}

jianing::Shape::ShapePtr jianing::Layer::operator[](const size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(size_) + " !\n");
  }

  return array_[index];
}

void jianing::Layer::addShape(const jianing::Shape::ShapePtr& shape_new)
{
  if (shape_new == nullptr)
  {
    throw std::invalid_argument("Can not add shape which is null!\n");
  }

  if (size_ == capacity_)
  {
    reserve(2 * size_);
  }

  allocator_shape_ptr.construct(&array_[size_], shape_new);
  ++size_;
}

// Determine whether the given shape intersects the shape in the current layer
bool jianing::Layer::isOverlap(const Shape::ShapePtr& shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("The shape is null!\n");
  }

  rectangle_t current_rec = {0.0, 0.0, 0.0, 0.0};
  const rectangle_t judgment_rec = shape->getFrameRect();

  for (size_t i = 0; i < size_; ++i)
  {
    try
    {
      current_rec = array_[i]->getFrameRect();
    }
    catch (const std::logic_error& error)
    {
      continue;
    }

    if ((abs(current_rec.pos.x - judgment_rec.pos.x) < ((current_rec.width + judgment_rec.width) / 2.0))
        && (abs(current_rec.pos.y - judgment_rec.pos.y) < ((current_rec.height + judgment_rec.height) / 2.0)))
    {
      return true;
    }
  }

  return false;
}

size_t jianing::Layer::getSize() const
{
  return size_;
}

bool jianing::Layer::empty() const
{
  return size_ == 0;
}

void jianing::Layer::reserve(const size_t new_capacity)
{
  jianing::Shape::ShapePtr* new_array = allocator_shape_ptr.allocate(new_capacity);

  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.construct(&new_array[i], array_[i]);
  }

  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.destroy(&array_[i]);
  }
  allocator_shape_ptr.deallocate(array_, capacity_);

  array_ = new_array;
  capacity_ = new_capacity;
}
