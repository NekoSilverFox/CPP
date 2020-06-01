#include "composite-shape.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
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
  array_(moved_object.array_)
{
  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.construct(&array_[i], moved_object[i]);
  }

  moved_object.size_ = 0;
  moved_object.capacity_ = 0;
  moved_object.array_ = nullptr;
}

jianing::CompositeShape::~CompositeShape()
{
  // Before using "deallocate", the user must use "destroy" for each object created on this memory
  for (size_t i = 0; i < size_; ++i)
  {
    allocator_shape_ptr.destroy(&array_[i]);
  }
  allocator_shape_ptr.deallocate(array_, capacity_);
}

jianing::CompositeShape& jianing::CompositeShape::operator=(jianing::CompositeShape&& moved_object)
{
  if (this != &moved_object)
  {
    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.destroy(&array_[i]);
    }
    allocator_shape_ptr.deallocate(array_, capacity_);

    this->size_ = moved_object.size_;
    this->capacity_ = moved_object.capacity_;
    this->array_ = moved_object.array_;

    moved_object.size_ = 0;
    moved_object.capacity_ = 0;
    moved_object.array_ = nullptr;
  }

  return *this;
}

jianing::CompositeShape& jianing::CompositeShape::operator=(const jianing::CompositeShape& copied_object)
{
  if (this != &copied_object)
  {
    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.destroy(&array_[i]);
    }
    allocator_shape_ptr.deallocate(array_, capacity_);

    this->size_ = copied_object.size_;
    this->capacity_ = copied_object.capacity_;

    for (size_t i = 0; i < size_; ++i)
    {
      allocator_shape_ptr.construct(&array_[i], copied_object[i]);
    }
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
    throw std::logic_error("Dynamic array is emply");
  }

  size_t index = 0;
  rectangle_t current_frame = {0.0, 0.0, 0.0, 0.0};

  for (; index < size_; ++index)
  {
    try
    {
      current_frame = array_[index]->getFrameRect();
      break;
    }
    catch (const std::logic_error& error)
    {
      continue;
    }
  }

  if ((0.0 == current_frame.width) || (0.0 == current_frame.height))
  {
    throw std::logic_error("Empty composite shape doesn't have a rectangle frame");
  }

  double top = current_frame.pos.y + current_frame.height / 2.0;
  double bottom = current_frame.pos.y - current_frame.height / 2.0;
  double left = current_frame.pos.x - current_frame.width / 2.0;
  double right = current_frame.pos.x + current_frame.width / 2.0;

  for (++index; index < size_; ++index) //i start with 1
  {
    try
    {
      current_frame = array_[index]->getFrameRect();
    }
    catch (const std::logic_error& error)
    {
      continue;
    }

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

  if (1.0 == coef)
  {
    return;
  }

  const point_t center = getCenter();
  point_t current_shape_center = {0.0, 0.0};
  double new_x = 0.0;
  double new_y = 0.0;

  for (size_t i = 0; i < size_; ++i)
  {
    try
    {
      current_shape_center = array_[i]->getFrameRect().pos;
    }
    catch (const std::logic_error& error)
    {
      continue;
    }

    new_x = center.x + coef * (array_[i]->getCenter().x - center.x);
    new_y = center.y + coef * (array_[i]->getCenter().y - center.y);

    array_[i]->move({new_x, new_y});
    array_[i]->scale(coef);
  }
}

void jianing::CompositeShape::rotate(double angle)
{
  if (fmod(angle, 360) == 0)
  {
    return;
  }

  const double cos = std::cos(2 * M_PI * angle / 360);
  const double sin = std::sin(2 * M_PI * angle / 360);
  const point_t centre_rotation = getFrameRect().pos;
  point_t current_shape_center = {0.0, 0.0};
  double dx = 0.0;
  double dy = 0.0;

  for (size_t i = 0; i < size_; ++i)
  {
    try
    {
      current_shape_center = array_[i]->getFrameRect().pos;
    }
    catch (const std::logic_error& error)
    {
      continue;
    }

    dx = (current_shape_center.x - centre_rotation.x) * cos - (current_shape_center.y - centre_rotation.y) * sin;
    dy = (current_shape_center.x - centre_rotation.x) * sin + (current_shape_center.y - centre_rotation.y) * cos;

    array_[i]->move({centre_rotation.x + dx, centre_rotation.y + dy});
    array_[i]->rotate(angle);
  }
}
