#include "layer.hpp"
#include <algorithm>
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

void jianing::Layer::addShape(const ShapePtr& shape_new)
{
  if (nullptr == shape_new)
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
  ShapePtr* new_array = allocator_shape_ptr.allocate(new_capacity);

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

