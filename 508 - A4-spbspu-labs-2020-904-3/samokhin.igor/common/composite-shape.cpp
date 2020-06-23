#include "composite-shape.hpp"
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include "base-types.hpp"
#include "shape.hpp"

samokhin::CompositeShape::CompositeShape():
  array_(std::make_unique<SharedShapeArray>(0)),
  size_(0)
{}

samokhin::CompositeShape::CompositeShape(const samokhin::CompositeShape &compositeShape):
  array_(std::make_unique<SharedShapeArray>(compositeShape.size_)),
  size_(compositeShape.size_)
{
  for (size_t i = 0; i < size_; i++)
  {
    array_[i] = compositeShape.array_[i];
  }
}

samokhin::CompositeShape &samokhin::CompositeShape::operator=(const samokhin::CompositeShape &compositeShape)
{
  if (&compositeShape == this)
  {
    return *this;
  }

  size_ = compositeShape.size_;
  array_.reset();
  array_ = std::make_unique<SharedShapeArray>(compositeShape.size_);

  for (size_t i = 0; i < size_; i++)
  {
    array_[i] = compositeShape.array_[i];
  }

  return *this;
}

samokhin::Shape::SharedShape samokhin::CompositeShape::operator[](size_t index)
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't get element of moved shape");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Out of range error: index out of bounds of composite shape");
  }

  return array_[index];
}

const samokhin::Shape::SharedShape samokhin::CompositeShape::operator[](size_t index) const
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't get element of moved shape");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Out of range error: index out of bounds of composite shape");
  }

  return array_[index];
}

double samokhin::CompositeShape::getArea() const
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't get area of moved shape");
  }

  double returnArea = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    returnArea += array_[i]->getArea();
  }

  return returnArea;
}

samokhin::rectangle_t samokhin::CompositeShape::getFrameRect() const
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't get frame rect of moved shape");
  }

  if (size_ == 0)
  {
    return samokhin::rectangle_t{{0, 0}, -1, -1};
  }

  double maxX = 0, maxY = 0, minX = 0, minY = 0;
  bool wasFirstFigureFound = false;
  size_t i = 0;
  for (i = 0; i < size_; i++)
  {
    rectangle_t figureFrame = array_[i]->getFrameRect();
    if ((figureFrame.width >= 0) && (figureFrame.height >= 0))
    {
      maxX = figureFrame.pos.x + figureFrame.width / 2.0;
      maxY = figureFrame.pos.y + figureFrame.height / 2.0;
      minX = figureFrame.pos.x - figureFrame.width / 2.0;
      minY = figureFrame.pos.y - figureFrame.height / 2.0;

      wasFirstFigureFound = true;
      break;
    }
  }

  if (!wasFirstFigureFound)
  {
    return samokhin::rectangle_t{{0, 0}, -1, -1};
  }

  for (size_t j = i + 1; j < size_; j++)
  {
    rectangle_t frame = array_[j]->getFrameRect();
    if ((frame.width != -1) && (frame.height != -1))
    {
      maxX = std::max(maxX, frame.pos.x + frame.width / 2.0);
      maxY = std::max(maxY, frame.pos.y + frame.height / 2.0);
      minX = std::min(minX, frame.pos.x - frame.width / 2.0);
      minY = std::min(minY, frame.pos.y - frame.height / 2.0);
    }
  }

  return {{(maxX + minX) / 2.0, (maxY + minY) / 2.0}, maxX - minX, maxY - minY};
}

void samokhin::CompositeShape::move(double x, double y)
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't move moved shape");
  }

  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->move(x, y);
  }

}

void samokhin::CompositeShape::move(const samokhin::point_t &pos)
{
  samokhin::point_t centre = getFrameRect().pos;
  move(pos.x - centre.x, pos.y - centre.y);
}

void samokhin::CompositeShape::scale(double k)
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't scale moved shape");
  }

  if (k < 0.0)
  {
    throw std::invalid_argument("Invalid scale coefficient: coefficient can't be less then zero");
  }

  point_t centre = getFrameRect().pos;

  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t frame = array_[i]->getFrameRect();

    double dx = (frame.pos.x - centre.x) * k;
    double dy = (frame.pos.y - centre.y) * k;

    array_[i]->scale(k);
    array_[i]->move(dx, dy);
  }
}

void samokhin::CompositeShape::add(const SharedShape &shape)
{
  if (!shape)
  {
    throw std::invalid_argument("Invalid argument: composite shape can't be initialize with nullptr object");
  }

  if (array_)
  {
    std::unique_ptr<SharedShapeArray> newCompositeShape = std::make_unique<SharedShapeArray>(size_ + 1);

    for (size_t i = 0; i < size_; i++)
    {
      newCompositeShape[i] = array_[i];
    }

    newCompositeShape[size_] = shape;
    newCompositeShape.swap(array_);
    size_++;
  }
  else
  {
    size_ = 1;
    array_ = std::make_unique<SharedShapeArray>(1);
    array_[0] = shape;
  }
}

void samokhin::CompositeShape::remove(size_t index)
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't remove shape from empty composite shape");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Out of range error: index out of bounds of composite shape");
  }

  std::unique_ptr<SharedShapeArray> newCompositeShape = std::make_unique<SharedShapeArray>(size_ - 1);

  for (size_t i = 0; i < index; i++)
  {
    newCompositeShape[i] = array_[i];
  }

  for (size_t i = index + 1; i < size_; i++)
  {
    newCompositeShape[i - 1] = array_[i];
  }

  array_[index].reset();
  size_--;
  array_.swap(newCompositeShape);
}

size_t samokhin::CompositeShape::getSize()
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't get size of moved shape");
  }

  return size_;
}

void samokhin::CompositeShape::rotate(double angle)
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't rotate of moved shape");
  }

  double angleInRad = angle * M_PI / 180.0;
  double angleCos = cos(angleInRad);
  double angleSin = sin(angleInRad);

  point_t thisCenter = getCenter();
  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->rotate(angle);

    point_t figureCenter = array_[i]->getCenter();
    double localX = figureCenter.x - thisCenter.x;
    double localY = figureCenter.y - thisCenter.y;

    double dx = localX * angleCos - localY * angleSin - localX;
    double dy = localX * angleSin + localY * angleCos - localY;

    array_[i]->move(dx, dy);
  }
}

samokhin::point_t samokhin::CompositeShape::getCenter() const
{
  if (!array_)
  {
    throw std::domain_error("Domain error: you can't get center of moved shape");
  }

  if (size_ == 0)
  {
    throw std::domain_error("Domain error: you can't get center of empty shape");
  }

  return getFrameRect().pos;
}
