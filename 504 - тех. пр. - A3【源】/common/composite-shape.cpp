#include "composite-shape.hpp"
#include <iostream>
#include <algorithm>
#include <exception>
#include <memory>
#include "base-types.hpp"

jianing::CompositeShape::CompositeShape() :
  size_(0),
  capacity_(3),
  array_(allocator_shape_ptr.allocate(3))
{}

jianing::CompositeShape::CompositeShape(const jianing::CompositeShape& copied_object) :
  size_(copied_object.size_),
  capacity_(copied_object.capacity_),
  array_(allocator_shape_ptr.allocate(copied_object.capacity_))
{
  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.construct(&array_[i], copied_object[i]);
  }
}

jianing::CompositeShape::CompositeShape(jianing::CompositeShape&& moved_object) :
  size_(moved_object.size_),
  capacity_(moved_object.capacity_),
  array_(allocator_shape_ptr.allocate(moved_object.capacity_))
{
  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.construct(&array_[i], moved_object[i]);
  }

  moved_object.~CompositeShape();
}

jianing::CompositeShape::~CompositeShape()
{
  // Before using "deallocate", the user must use "destroy" for each object created on this memory
  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.destroy(&array_[i]);
  }

  allocator_shape_ptr.deallocate(array_, capacity_);
  size_ = 0;
  capacity_ = 0;
}

jianing::CompositeShape& jianing::CompositeShape::operator=(jianing::CompositeShape&& moved_object)
{
  if (this != &moved_object)
  {
    this->size_ = moved_object.size_;
    this->capacity_ = moved_object.capacity_;
    array_ = allocator_shape_ptr.allocate(capacity_);

    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.construct(&array_[i], moved_object[i]);
    }

    moved_object.~CompositeShape();
  }

  return *this;
}

jianing::Shape::ShapePtr jianing::CompositeShape::operator[](const size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(size_) + " !\n");
  }

  return array_[index];
}

void jianing::CompositeShape::pushShape(const ShapePtr& shape_new)
{
  if (nullptr == shape_new)
  {
    throw std::invalid_argument("Can not push shape which is null!\n");
  }

  if (size_ == capacity_)
  {
    reserve(2 * size_);
  }

  allocator_shape_ptr.construct(&array_[size_], shape_new);
  ++size_;
}

size_t jianing::CompositeShape::getSize() const
{
  return size_;
}

size_t jianing::CompositeShape::getCapacity() const
{
  return capacity_;
}

void jianing::CompositeShape::reserve(const size_t new_capacity)
{
  if (this->capacity_ == new_capacity)
  {
    return;
  }

  ShapePtr* array_new(allocator_shape_ptr.allocate(new_capacity));

  if ((this->capacity_ < new_capacity) || (size_ < new_capacity))
  {
    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.construct(&array_new[i], this->array_[i]);
    }
  }
  else
  {
    // new_capacity < size_ < this->capacity_
    for (size_t i = 0; i < new_capacity; ++i)
    {
      allocator_shape_ptr.construct(&array_new[i], this->array_[i]);
    }

    size_= new_capacity;
  }

  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.destroy(&array_[i]);
  }
  allocator_shape_ptr.deallocate(array_, capacity_);

  this->array_ = array_new;
  this->capacity_ = new_capacity;
}

bool jianing::CompositeShape::empty() const
{
  return 0 == size_;
}

void jianing::CompositeShape::removeShape(const size_t index)
{
  if (0 == size_)
  {
    throw std::out_of_range("Dynamic array is emply");
  }

  else if (index >= size_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(size_) + " !\n");
  }

  for (size_t i = index; i < size_ - 1; ++i)
  {
    array_[i] = array_[i + 1];
  }

  array_[size_ - 1] = nullptr;
  --size_;
}

void jianing::CompositeShape::printShape()
{
  if (0 == size_)
  {
    throw std::domain_error("The array is empty!\n");
  }

  rectangle_t shape_printing;

  for (size_t i = 0; i < size_; i++)
  {
    shape_printing = array_[i]->getFrameRect();

    std::cout << "------ Shape No." << i + 1 <<" ------\n"
        << "Center: (" << shape_printing.pos.x << ", " << shape_printing.pos.y << ")\n"
        << "Width: " << shape_printing.width << "\n"
        << "Height: " << shape_printing.height << "\n"
        << "Area: " << array_[i]->getArea() << "\n\n";
  }

  shape_printing = getFrameRect();

  std::cout << "------ Mixed shape ------\n"
      << "Size: " << this->getSize() << "\n"
      << "Center: (" << shape_printing.pos.x << ", " << shape_printing.pos.y << ")\n"
      << "Width: " << shape_printing.width << "\n"
      << "Height: " << shape_printing.height << "\n"
      << "Area: " << this->getArea() << "\n"
      << "==========================\n\n";
}

jianing::point_t jianing::CompositeShape::getCenter() const
{
  return getFrameRect().pos;
}

double jianing::CompositeShape::getArea() const
{
  double area = 0.0;

  for (size_t i = 0; i < size_; ++i)
  {
    area += array_[i]->getArea();
  }

  return area;
}

jianing::rectangle_t jianing::CompositeShape::getFrameRect() const
{
  if (0 == size_)
  {
    throw std::out_of_range("Dynamic array is emply");
  }

  rectangle_t current_frame = array_[0]->getFrameRect();
  double top = current_frame.pos.y + current_frame.height / 2.0;
  double bottom = current_frame.pos.y - current_frame.height / 2.0;
  double left = current_frame.pos.x - current_frame.width / 2.0;
  double right = current_frame.pos.x + current_frame.width / 2.0;

  for (size_t i = 1; i < size_; ++i) //i start with 1
  {
    current_frame = array_[i]->getFrameRect();

    top = std::max((current_frame.pos.x + current_frame.height / 2.0), top);

    bottom = std::min((current_frame.pos.y - current_frame.height / 2.0), bottom);

    left = std::min((current_frame.pos.x - current_frame.width / 2.0), left);

    right = std::max((current_frame.pos.x + current_frame.width / 2.0), right);
  }

  return {right - left, top - bottom, {(right - left) / 2.0 + left, (top - bottom) / 2.0 + bottom}};
}

void jianing::CompositeShape::move(double x_move, double y_move)
{
  const point_t point_new = {getCenter().x + x_move, getCenter().y + y_move};

  move(point_new);
}

void jianing::CompositeShape::move(const point_t& point_new)
{
  for (size_t i = 0; i < size_; ++i)
  {
    array_[i]->move(point_new);
  }
}

void jianing::CompositeShape::scale(double coef)
{
  if (coef <= 0.0)
  {
    throw std::domain_error("Error: Coefficient can not be"
        + std::to_string(coef) + " ! Must be positive!\n");
  }

  if (1 == coef)
  {
    return;
  }

  const point_t center = getCenter();
  double new_x = 0.0;
  double new_y = 0.0;

  for (size_t i = 0; i < size_; ++i)
  {
    new_x = center.x + coef * (array_[i]->getCenter().x - center.x);
    new_y = center.y + coef * (array_[i]->getCenter().y - center.y);

    array_[i]->move({new_x, new_y});
    array_[i]->scale(coef);
  }
}
