#include "layer.hpp"

#include <memory>
#include <stdexcept>

#include <boost/format.hpp>

#include "shape.hpp"
#include "base-types.hpp"

yakovlev::Layer::Layer() :
  size_{ 0 },
  shapes_{ nullptr }
{ }

yakovlev::Layer::Layer(const Layer & other) :
  size_{ other.size_ },
  shapes_{ std::make_unique<Shape::ShapePtr []>(size_) }
{
  for (size_t i = 0u; i < size_; ++i) {
    shapes_[i] = other.shapes_[i];
  }
}

yakovlev::Layer::Layer(Layer && other) noexcept :
  size_{ other.size_ },
  shapes_{ std::move(other.shapes_) }
{
  other.size_ = 0u;
  other.shapes_ = nullptr;
}

yakovlev::Layer & yakovlev::Layer::operator=(const Layer & other)
{
  if (this == &other) {
    return *this;
  }
  size_ = other.size_;
  shapes_.reset();
  shapes_ = std::make_unique<Shape::ShapePtr []>(size_);
  for (size_t i = 0u; i < size_; ++i) {
    shapes_[i] = other.shapes_[i];
  }
  return *this;
}

yakovlev::Layer & yakovlev::Layer::operator=(Layer && other) noexcept
{
  size_ = other.size_;
  shapes_.reset();
  shapes_ = std::move(other.shapes_);
  other.size_ = 0u;
  other.shapes_ = nullptr;
  return *this;
}

yakovlev::Shape::ShapePtr yakovlev::Layer::operator[](size_t index)
{
  if (index >= size_) {
    throw std::out_of_range{ (boost::format("Index %1% is out of canvas layer size range (%2%)") % index % size_).str() };
  }
  return shapes_[index];
}

yakovlev::Shape::ConstShapePtr yakovlev::Layer::operator[](size_t index) const 
{
  if (index >= size_) {
    throw std::out_of_range{ (boost::format("Index %1% is out of canvas layer size range (%2%)") % index % size_).str() };
  }
  return shapes_[index];
}

size_t yakovlev::Layer::getSize() const noexcept
{
  return size_;
}

bool yakovlev::Layer::isEmpty() const noexcept
{
  return size_ == 0;
}

void yakovlev::Layer::add(const Shape::ShapePtr & shape)
{
  if (!shape) {
    throw std::invalid_argument{ "Only valid shapes can be added to layer" };
  } 

  std::unique_ptr<Shape::ShapePtr []> old = std::move(shapes_);
  shapes_ = std::make_unique<Shape::ShapePtr []>(size_ + 1);
  for (size_t i = 0u; i < size_; ++i) {
    if (shape == old[i]) {
      old.swap(shapes_);
      throw std::invalid_argument{ "Can not add the same shape twice to a layer" };
    }
    shapes_[i] = old[i];
  }
  shapes_[size_++] = shape;
}

void yakovlev::Layer::remove(size_t index)
{
  if (index >= size_) {
    throw std::out_of_range{ (boost::format("Index %1% is out of layer size range (%2%)") % index % size_).str() };
  }

  std::unique_ptr<Shape::ShapePtr []> old = std::move(shapes_);
  shapes_ = std::make_unique<Shape::ShapePtr []>(size_ - 1);
  for (size_t i = 0u; i < size_; ++i) {
    if (i != index) {
      shapes_[(i > index) ? (i - 1) : i] = old[i];
    }
  }
  --size_; 
}

bool yakovlev::Layer::contains(const Shape::ConstShapePtr & shape) const
{
  for (size_t i = 0u; i < size_; ++i) {
    if (shapes_[i] == shape) {
      return true;
    }
  }
  return false;
}

bool yakovlev::Layer::intersects(const Shape & shape) const noexcept
{
  rectangle_t frame = shape.getFrameRect();
  for (size_t i = 0u; i < size_; ++i) {
    if (areOverlapping(shapes_[i]->getFrameRect(), frame)) {
      return true;
    }
  }
  return false;
}

void yakovlev::Layer::print(std::ostream & os) const
{
  os << "Layer with " << size_ << " shapes:\n" << *this << '\n';
}

std::ostream & yakovlev::operator<<(std::ostream & os, const Layer layer)
{
  for (size_t i = 0u; i < layer.size_; ++i) {
    layer.shapes_[i]->print(os);
  }
  return os;
}
