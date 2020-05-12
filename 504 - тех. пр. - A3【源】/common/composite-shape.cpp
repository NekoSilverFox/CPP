#include "composite-shape.hpp"
#include <iostream>
#include <exception>
#include <memory>
#include "base-types.hpp"

jianing::CompositeShape::CompositeShape() :
  size_(0),
  array_(nullptr)
{}

jianing::CompositeShape::CompositeShape(const std::shared_ptr<Shape>& init_shape) :
  size_(1),
  array_(new std::shared_ptr<Shape>[1])
{
  if (nullptr == init_shape)
  {
    throw std::invalid_argument("init_shape can not be null!\n");
  }

  array_[0] = init_shape;
}

jianing::CompositeShape::CompositeShape(const jianing::CompositeShape& copied_object) :
  size_(copied_object.size_),
  array_(new std::shared_ptr<Shape>[copied_object.size_])
{
  if (this->size_ != copied_object.size_)
  {
    throw std::invalid_argument("Copy object failed!\n");
  }

  for (size_t i = 0; i < size_; ++i)
  {
    array_[i] = copied_object[i];
  }
}

jianing::CompositeShape::CompositeShape(jianing::CompositeShape&& moved_object) :
  size_(moved_object.size_),
  array_(std::move(moved_object.array_))
{
  if (this->size_ != moved_object.size_)
  {
    throw std::invalid_argument("Move object failed!\n");
  }

  moved_object.size_ = 0;
  moved_object.array_ = nullptr;
}

jianing::CompositeShape::~CompositeShape()
{
  size_ = 0;
  array_ = nullptr;
}

jianing::CompositeShape& jianing::CompositeShape::operator=(const jianing::CompositeShape& copied_object)
{
  if (this != &copied_object)
  {
    this->size_ = copied_object.size_;
    std::unique_ptr<std::shared_ptr<Shape>[]> new_shape_for_copy(new std::shared_ptr<Shape>[size_]);

    if (this->size_ != copied_object.size_)
    {
      throw std::invalid_argument("Copy object failed!\n");
    }

    for (size_t i = 0; i < size_; ++i)
    {
      new_shape_for_copy[i] = copied_object.array_[i];
    }
  }

  return *this;
}

bool jianing::CompositeShape::operator==(const CompositeShape& comparison_object)
{
  if (this->size_ != comparison_object.size_)
  {
    return false;
  }

  for (size_t i = 0; i < size_; ++i)
  {
    if (this->array_[i] != comparison_object.array_[i])
    {
      return false;
    }
  }

  return true;
}

std::shared_ptr<jianing::Shape> jianing::CompositeShape::operator[](const size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("Index can not be"
        + std::to_string(index) + " ! Must smaller than"
        + std::to_string(size_) + " !\n");
  }

  return array_[index];
}

void jianing::CompositeShape::pushShape(const std::shared_ptr<Shape>& shape_new)
{
  if (nullptr == shape_new)
  {
    throw std::invalid_argument("Can not push shape which is null!\n");
  }

  std::unique_ptr<std::shared_ptr<Shape>[]> array_new(new std::shared_ptr<Shape>[size_ + 1]);

  for (size_t i = 0; i < size_; ++i)
  {
    array_new[i] = array_[i];
  }

  array_new[size_] = shape_new;
  ++size_;
  array_ = std::move(array_new);
}

size_t jianing::CompositeShape::getSize() const
{
  return size_;
}

bool jianing::CompositeShape::empty() const
{
  return (0 == size_);
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

  array_[index] = nullptr;

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
    shape_printing = (array_[i])->getFrameRect();

    std::cout << "Shape No." << i + 1 <<"\n"
        << "Center: (" << shape_printing.pos.x << ", " << shape_printing.pos.y << ")\n"
        << "Width: " << shape_printing.width << "\n"
        << "Height: " << shape_printing.height << "\n"
        << "Area: " << (array_[i])->getArea() << "\n\n";
  }

  shape_printing = getFrameRect();

  std::cout << "------Mixed shape------\n"
      << "Size: " << this->getSize() << "\n"
      << "Center: (" << shape_printing.pos.x << ", " << shape_printing.pos.y << ")\n"
      << "Width: " << shape_printing.width << "\n"
      << "Height: " << shape_printing.height << "\n"
      << "Area: " << this->getArea() << "\n\n";
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
    area += (array_[i])->getArea();
  }

  return area;
}

jianing::rectangle_t jianing::CompositeShape::getFrameRect() const
{
  if (0 == size_)
  {
    return {0.0, 0.0, {0.0, 0.0}};
  }

  rectangle_t current_frame = (array_[0])->getFrameRect();
  double top = current_frame.pos.y + current_frame.height / 2.0;
  double bottom = current_frame.pos.y - current_frame.height / 2.0;
  double left = current_frame.pos.x - current_frame.width / 2.0;
  double right = current_frame.pos.x + current_frame.width / 2.0;

  for (size_t i = 1; i < size_; ++i) //i start with 1 !!!
  {
    current_frame = (array_[i])->getFrameRect();

    if ((current_frame.pos.x + current_frame.height / 2.0) > top)
    {
      top = current_frame.pos.x + current_frame.height / 2.0;
    }

    if ((current_frame.pos.y - current_frame.height / 2.0) < bottom)
    {
      bottom = current_frame.pos.y - current_frame.height / 2.0;
    }

    if ((current_frame.pos.x - current_frame.width / 2.0) < left)
    {
      left = current_frame.pos.x - current_frame.width / 2.0;
    }

    if ((current_frame.pos.x + current_frame.width / 2.0) > right)
    {
      right = current_frame.pos.x + current_frame.width / 2.0;
    }
  }

  return {(right - left), (top - bottom), {((right - left) / 2.0 + left), ((top - bottom) / 2.0 + bottom)}};
}

void jianing::CompositeShape::move(double x_move, double y_move)
{
  for (size_t i = 0; i < size_; ++i)
  {
    (array_[i])->move(x_move, y_move);
  }
}

void jianing::CompositeShape::move(const point_t& point_new)
{
  for (size_t i = 0; i < size_; ++i)
  {
    (array_[i])->move(point_new);
  }
}

void jianing::CompositeShape::scale(double coef)
{
  if (coef <= 0.0)
  {
    throw std::domain_error("Error: Coefficient can not be"
        + std::to_string(coef) + " ! Must be positive!\n");
  }

  const point_t center = getCenter();
  double new_x = 0.0;
  double new_y = 0.0;

  for (size_t i = 0; i < size_; ++i)
  {
    new_x = center.x + coef * ((array_[i])->getCenter().x - center.x);
    new_y = center.y + coef * ((array_[i])->getCenter().y - center.y);

    (array_[i])->move({new_x, new_y});
    (array_[i])->scale(coef);
  }
}
