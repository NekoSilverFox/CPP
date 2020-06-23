#include "composite-shape.hpp"

#include <cmath>
#include <memory>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <initializer_list>

#include <boost/format.hpp>

#include "base-types.hpp"
#include "shape.hpp"

yakovlev::CompositeShape::CompositeShape(const CompositeShape & other) :
  size_{ other.size_ },
  shapes_{ nullptr }
{
  assert((other.shapes_ != nullptr, "Can not copy a Composite Shape that has been moved by C++ move semantics"));

  shapes_ = std::make_unique<ShapePtr []>(size_);
  for (size_t i = 0u; i < size_; ++i) {
    shapes_[i] = other.shapes_[i];
  }
}

yakovlev::CompositeShape::CompositeShape(const ShapePtr & shape) :
  size_{ 1u },
  shapes_{ nullptr }
{
  if (!shape) {
    throw std::invalid_argument{ "Composite shape has to be provided with an initialized non-null shape pointer to be constructed" };
  }

  shapes_ = std::make_unique<ShapePtr []>(size_);
  shapes_[0u] = shape;
}

yakovlev::CompositeShape::CompositeShape(const std::initializer_list<ShapePtr> & shapes) :
  size_{ shapes.size() },
  shapes_{ nullptr }
{
  if (!size_) {
    throw std::invalid_argument{ "Composite shape has to be provided with at least one valid shape pointer" };
  }

  shapes_ = std::make_unique<ShapePtr []>(size_);

  size_t i = 0u;
  for(const ShapePtr & shape : shapes) {
    if (!shape) {
      throw std::invalid_argument{ "Composite shape has to be provided only with initialized non-null shape pointers to be constructed" };
    }
    shapes_[i++] = shape;
  }  
}

yakovlev::CompositeShape & yakovlev::CompositeShape::operator=(const CompositeShape & other)
{
  assert((other.shapes_ != nullptr, "Can not copy a Composite Shape that has been moved by C++ move semantics"));

  if (this == &other) {
    return *this;
  }

  shapes_.reset();
  size_ = other.size_;

  shapes_ = std::make_unique<ShapePtr []>(size_);
  for (size_t i = 0u; i < size_; ++i) {
    shapes_[i] = other.shapes_[i];
  }
  return *this;
}

yakovlev::Shape::ShapePtr yakovlev::CompositeShape::operator[](size_t index)
{
  assert((shapes_ != nullptr, "Can not access a Composite Shape that has been moved by C++ move semantics"));
  if (index >= size_) {
    throw std::out_of_range{ (boost::format("Index %1% is out of Composite Shape range (%2%)") % index % size_).str() };
  }
  return shapes_[index];
}

yakovlev::Shape::ConstShapePtr yakovlev::CompositeShape::operator[](size_t index) const
{
  assert((shapes_ != nullptr, "Can not access a Composite Shape that has been moved by C++ move semantics"));
  if (index >= size_) {
    throw std::out_of_range{ (boost::format("Index %1% is out of Composite Shape range (%2%)") % index % size_).str() };
  }
  return shapes_[index];
}

size_t yakovlev::CompositeShape::getSize() const noexcept
{
  assert((shapes_ != nullptr, "Can not get size of a Composite Shape that has been moved by C++ move semantics"));
  return size_;
}

yakovlev::point_t yakovlev::CompositeShape::getCenter() const noexcept
{
  assert((shapes_ != nullptr, "Can not get center of a Composite Shape that has been moved by C++ move semantics"));
  return getFrameRect().pos;
}

double yakovlev::CompositeShape::getArea() const noexcept
{
  assert((shapes_ != nullptr, "Can not get area of a Composite Shape that has been moved by C++ move semantics"));

  double area = 0.0;
  for (size_t i = 0u; i < size_; ++i) {
    area += shapes_[i]->getArea();
  }
  return area;
}

yakovlev::rectangle_t yakovlev::CompositeShape::getFrameRect() const noexcept
{
  assert((shapes_ != nullptr, "Can not get frame of a Composite Shape that has been moved by C++ move semantics"));

  rectangle_t frame = shapes_[0u]->getFrameRect();
  double halfWidth = frame.width / 2.0, halfHeight = frame.height / 2.0;
  
  double minX = frame.pos.x - halfWidth, maxX = frame.pos.x + halfWidth;
  double minY = frame.pos.y - halfHeight, maxY = frame.pos.y + halfHeight;
  for (size_t i = 1u; i < size_; ++i) {
    frame = shapes_[i]->getFrameRect();

    halfWidth = frame.width / 2.0;

    minX = std::min(frame.pos.x - halfWidth, minX);
    maxX = std::max(frame.pos.x + halfWidth, maxX);

    halfHeight = frame.height / 2.0;

    minY = std::min(frame.pos.y - halfHeight, minY);
    maxY = std::max(frame.pos.y + halfHeight, maxY);
  }

  double width = maxX - minX, height = maxY - minY;
  return { width, height, { minX + width / 2.0, minY + height / 2.0 } };
}

void yakovlev::CompositeShape::add(const ShapePtr & shape)
{
  assert((shapes_ != nullptr, "Can not add to a Composite Shape that has been moved by C++ move semantics"));

  if (!shape) {
    throw std::invalid_argument{ "Composite shape has to be provided with an initialized non-null shape pointer to be appended" };
  } else if (this == shape.get()) {
    throw std::invalid_argument{ "Composite shape can not be added into itself" };
  }

  std::unique_ptr<ShapePtr []> old = std::move(shapes_);
  shapes_ = std::make_unique<ShapePtr []>(size_ + 1);
  for (size_t i = 0u; i < size_; ++i) {
    if (shape == old[i]) {
      old.swap(shapes_);
      throw std::invalid_argument{ "Can not add the same shape twice to Composite Shape" };
    }
    shapes_[i] = old[i];
  }
  shapes_[size_++] = shape;
}

void yakovlev::CompositeShape::remove(size_t index)
{
  assert((shapes_ != nullptr, "Can not remove from a Composite Shape that has been moved by C++ move semantics"));

  if (index >= size_) {
    throw std::out_of_range{ (boost::format("Index %1% is out of Composite Shape range (%2%)") % index % size_).str() };
  } else if (size_ < 2) {
    throw std::invalid_argument{ "Can not remove composite shape's last shape"};
  } 

  std::unique_ptr<ShapePtr []> old = std::move(shapes_);
  shapes_ = std::make_unique<ShapePtr []>(size_ - 1);
  for (size_t i = 0u; i < size_; ++i) {
    if (i != index) {
      shapes_[(i > index) ? (i - 1) : i] = old[i];
    }
  }
  --size_;
}

void yakovlev::CompositeShape::move(const point_t & pos) noexcept
{
  assert((shapes_ != nullptr, "Can not move a Composite Shape that has been moved by C++ move semantics"));

  point_t center = getCenter();
  move(pos.x - center.x, pos.y - center.y);
}

void yakovlev::CompositeShape::move(double x, double y) noexcept
{
  assert((shapes_ != nullptr, "Can not move a Composite Shape that has been moved by C++ move semantics"));

  for (size_t i = 0u; i < size_; ++i) {
    shapes_[i]->move(x, y);
  }
}

void yakovlev::CompositeShape::rotate(double rotation) noexcept
{
  assert((shapes_ != nullptr, "Can not rotate a Composite Shape that has been moved by C++ move semantics"));

  double rad = rotation * M_PI / 180.0;
  double rotSin = sin(rad);
  double rotCos = cos(rad);

  point_t center = getCenter();
  for (size_t i = 0u; i < size_; ++i) {
    shapes_[i]->rotate(rotation);
    point_t shapeCenter = shapes_[i]->getCenter();
    point_t local = { shapeCenter.x - center.x, shapeCenter.y - center.y };
    shapes_[i]->move({
        center.x + local.x * rotCos - local.y * rotSin,
        center.y + local.x * rotSin + local.y * rotCos
    });
  }
}

void yakovlev::CompositeShape::scale(double coef)
{
  assert((shapes_ != nullptr, "Can not scale a Composite Shape that has been moved by C++ move semantics"));

  if (coef <= 0.0) {
    throw std::invalid_argument{ (boost::format("Invalid rectangle scale coefficient %1% - can not be negative or zero") % coef ).str() };
  }

  point_t center = getCenter();
  double difference = coef - 1.0;
  for (size_t i = 0u; i < size_; ++i) {
    shapes_[i]->scale(coef);
    point_t shapeCenter = shapes_[i]->getCenter();
    shapes_[i]->move(
        (shapeCenter.x - center.x) * difference,
        (shapeCenter.y - center.y) * difference
    );
  }
}

void yakovlev::CompositeShape::print(std::ostream & os) const
{
  assert((shapes_ != nullptr, "Can not print a Composite Shape that has been moved by C++ move semantics"));

  os << "Composite shape on " << getCenter() << " with " << size_ << " shapes:\n";
  for (size_t i = 0u; i < size_; ++i) {
    os << '\t';
    shapes_[i]->print(os);
  }
}
