#include "canvas.hpp"

#include <cmath>
#include <memory>
#include <iostream>
#include <stdexcept>

#include <boost/format.hpp>

#include "layer.hpp"
#include "shape.hpp"
#include "base-types.hpp"

yakovlev::Canvas::Canvas() : 
  size_{ 0 },
  layers_{ nullptr }
{ }

yakovlev::Canvas::Canvas(const Canvas & other) :
  size_{ other.size_ },
  layers_{ std::make_unique<Layer []>(size_) }
{
  for (size_t i = 0u; i < size_; ++i) {
    layers_[i] = other.layers_[i];
  }
}

yakovlev::Canvas::Canvas(Canvas && other) noexcept :
  size_{ other.size_ },
  layers_{ std::move(other.layers_) }
{
  other.size_ = 0;
  other.layers_ = nullptr;
}

yakovlev::Canvas & yakovlev::Canvas::operator=(const Canvas & other)
{
  if (this == &other) {
    return *this;
  }

  size_ = other.size_;
  layers_.reset();
  layers_ = std::make_unique<Layer []>(size_);

  for (size_t i = 0u; i < size_; ++i) {
    layers_[i] = other.layers_[i];
  }

  return *this;
}

yakovlev::Canvas & yakovlev::Canvas::operator=(Canvas && other) noexcept
{
  size_ = other.size_;
  layers_ = std::move(other.layers_);

  other.size_ = 0;
  other.layers_ = nullptr;

  return *this;
}

yakovlev::Layer yakovlev::Canvas::operator[](size_t layer) const
{
  if (layer >= size_) {
    throw std::out_of_range{ (boost::format("Layer %1% is out of canvas layer range (%2%)") % layer % size_).str() };
  }
  return layers_[layer];
}

size_t yakovlev::Canvas::getLayersCount() const noexcept
{
  return size_;
}

size_t yakovlev::Canvas::getLayerSize(size_t layer) const
{
  if (layer >= size_) {
    throw std::out_of_range{ (boost::format("Layer %1% is out of canvas layer range (%2%)") % layer % size_).str() };
  }
  return layers_[layer].getSize();
}

void yakovlev::Canvas::add(const Shape::ShapePtr & shape)
{
  if (!shape) {
    throw std::invalid_argument{ "Only valid shapes can be added to canvas" };
  }

  size_t layer = 0u;
  for (size_t i = 0u; i < size_; ++i) {
    if (layers_[i].contains(shape)) {
      throw std::invalid_argument{ "Can not add the same shape twice to the same canvas" };
    } else if (layers_[i].intersects(*shape)) {
      layer = i + 1;
    }
  }

  if (layer >= size_) {
    std::unique_ptr<Layer []> old = std::move(layers_);
    layers_ = std::make_unique<Layer []>(size_ + 1);
    for (size_t i = 0u; i < size_; ++i) {
      layers_[i] = std::move(old[i]);
    }
    ++size_;
  } 

  layers_[layer].add(shape);
}

void yakovlev::Canvas::print(std::ostream & os) const
{
  os << *this;
}

std::ostream & yakovlev::operator<<(std::ostream & os, const Canvas & canvas)
{
  os << "Canvas with " << canvas.size_ << " layers\n";
  for (size_t i = 0u; i < canvas.size_; ++i) {
    os << "\nLayer " << i + 1 << ":\n" << canvas.layers_[i];
  }
  return os;
}
