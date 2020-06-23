#include "composite-shape.hpp"
#include <memory>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <utility>
#include "base-types.hpp"
#include "shape.hpp"

gadzhiev::CompositeShape::CompositeShape(const gadzhiev::CompositeShape& otherCompositeShape) :
  size_{ otherCompositeShape.size_ },
  arrayOfFigure_{ std::make_unique<ShapePtr[]>(size_) }  
{

  if (!otherCompositeShape.arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  for (size_t i = 0; i < size_; ++i)
  {
    arrayOfFigure_[i] = otherCompositeShape.arrayOfFigure_[i];
  }
}

gadzhiev::CompositeShape& gadzhiev::CompositeShape::operator=(const CompositeShape& otherCompositeShape)
{

  if (!otherCompositeShape.arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  if (this == &otherCompositeShape)
  {
    return *this;
  }

  size_ = otherCompositeShape.size_;

  arrayOfFigure_ = std::make_unique<ShapePtr []> (otherCompositeShape.size_);

  for (size_t i = 0; i < size_; ++i)
  {
    arrayOfFigure_[i] = otherCompositeShape.arrayOfFigure_[i];
  }

  return *this;
}

gadzhiev::CompositeShape::CompositeShape(const gadzhiev::Shape::ShapePtr& shape) :
  size_{ 1 },
  arrayOfFigure_{ std::make_unique <ShapePtr[]>(size_) }
{

  if (!shape)
  {
    throw std::invalid_argument("Object is nullptr");
  }

  arrayOfFigure_[0] = shape;
}

gadzhiev::CompositeShape::CompositeShape(const std::initializer_list<ShapePtr>& shapes) :
  size_{ shapes.size() },
  arrayOfFigure_{ std::make_unique <ShapePtr[]>(size_) }
{
  size_t i = 0;
  for (const ShapePtr element : shapes)
  {
    if (!element)
    {
      throw std::invalid_argument("Object is nullptr");
    }
    arrayOfFigure_[i] = element;
    ++i;
  }
}

gadzhiev::Shape::ConstShapePtr gadzhiev::CompositeShape::operator[](size_t index) const
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Invalid index, your index " + std::to_string(index));
  }

  return arrayOfFigure_[index];
}

gadzhiev::Shape::ShapePtr gadzhiev::CompositeShape::operator[](size_t index)
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Invalid index, your index " + std::to_string(index));
  }

  return arrayOfFigure_[index];
}

void gadzhiev::CompositeShape::add(const gadzhiev::Shape::ShapePtr& shape)
{
  for (size_t i = 0; i < size_; ++i)
  {
    if (arrayOfFigure_[i] == shape)
    {
      throw std::invalid_argument("Adding shape already in cmp shape");
    }
  }

  if (!shape)
  {
    throw std::invalid_argument("Adding shape is nullptr");
  }

  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  std::unique_ptr<ShapePtr[]> tempArrayOfFigure = std::make_unique<ShapePtr[]>(this->size_ + 1);

  for (size_t i = 0; i < size_; ++i)
  {
    tempArrayOfFigure[i] = arrayOfFigure_[i];
  }
  tempArrayOfFigure[size_] = shape;

  ++size_;
  arrayOfFigure_.swap(tempArrayOfFigure);
}

void gadzhiev::CompositeShape::remove(size_t index)
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  if (index >= size_)
  {
    throw std::out_of_range("Invalid index to remove, your index out of range " + std::to_string(index));
  }

  if (size_ == 1)
  {
    throw std::length_error("You can't delete last shape of composite shapes");
  }

  for(; index < (size_ - 1); ++index)
  {
    std::swap(arrayOfFigure_[index], arrayOfFigure_[index + 1]);
  }

  arrayOfFigure_[index].reset();
  --size_;
}

size_t gadzhiev::CompositeShape::getSize() const
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  return size_;
}

double gadzhiev::CompositeShape::getArea() const
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  double areaOfAllFigures = 0;

  for (size_t i = 0; i < size_; ++i)
  {
    areaOfAllFigures += arrayOfFigure_[i]->getArea();
  }

  return areaOfAllFigures;
}

gadzhiev::rectangle_t gadzhiev::CompositeShape::getFrameRect() const
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  gadzhiev::rectangle_t rectangleFrameOfFirstFigure = arrayOfFigure_[0]->getFrameRect();
  double finalLeftXPosition = rectangleFrameOfFirstFigure.pos.x - (rectangleFrameOfFirstFigure.width / 2);
  double finalRightXPosition = rectangleFrameOfFirstFigure.pos.x + (rectangleFrameOfFirstFigure.width / 2);
  double finalTopYPosition = rectangleFrameOfFirstFigure.pos.y + (rectangleFrameOfFirstFigure.height / 2);
  double finalBottomYPosition = rectangleFrameOfFirstFigure.pos.y - (rectangleFrameOfFirstFigure.height / 2);

  for (size_t i = 1; i < size_; ++i)
  {
    gadzhiev::rectangle_t frameRectangle = arrayOfFigure_[i]->getFrameRect();

    double shapeLeftXPosition = frameRectangle.pos.x - (frameRectangle.width / 2);
    double shapeRightXPosition = frameRectangle.pos.x + (frameRectangle.width / 2);
    double shapeTopYPosition = frameRectangle.pos.y + (frameRectangle.height / 2);
    double shapeBottomYPosition = frameRectangle.pos.y - (frameRectangle.height / 2);

    finalLeftXPosition = std::min(finalLeftXPosition, shapeLeftXPosition);
    finalBottomYPosition = std::min(finalBottomYPosition, shapeBottomYPosition);

    finalRightXPosition = std::max(finalRightXPosition, shapeRightXPosition);
    finalTopYPosition = std::max(finalTopYPosition, shapeTopYPosition);
  }

  const double width = finalRightXPosition - finalLeftXPosition;
  const double height = finalTopYPosition - finalBottomYPosition;

  return { width, height, {finalLeftXPosition + width / 2, finalBottomYPosition + height / 2 } };
}

void gadzhiev::CompositeShape::move(const gadzhiev::point_t& point)
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  const gadzhiev::point_t center{ this->getCenter() };

  for (size_t i = 0; i < size_; ++i)
  {
    arrayOfFigure_[i]->move(point.x - center.x, point.y - center.y); 
  }
}

void gadzhiev::CompositeShape::move(double dx, double dy)
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  for (size_t i = 0; i < size_; ++i)
  {
    arrayOfFigure_[i]->move(dx, dy);
  }
}

void gadzhiev::CompositeShape::scale(double coefficient)
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient, coef > 0, your coef: " + std::to_string(coefficient));
  }

  const gadzhiev::point_t center { this->getCenter() };

  for (size_t i = 0; i < size_; ++i)
  {
    const point_t centerOfShape = arrayOfFigure_[i]->getCenter();

    const double moveXPos = (centerOfShape.x - center.x) * coefficient + center.x;
    const double moveYPos = (centerOfShape.y - center.y) * coefficient + center.y;

    arrayOfFigure_[i]->move({ moveXPos, moveYPos });
    arrayOfFigure_[i]->scale(coefficient);
  } 
}

void gadzhiev::CompositeShape::rotate(double degrees)
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  const double a = degrees / 180 * M_PI;
  const double cosA = cos(a);
  const double sinA = sin(a);

  const point_t center{ this->getCenter() };

  for (size_t i = 0; i < size_; ++i)
  {
    const point_t shapeCenter{ arrayOfFigure_[i]->getCenter() };

    double posX = center.x + (shapeCenter.x - center.x) * cosA - (shapeCenter.y - center.y) * sinA;
    double posY = center.y + (shapeCenter.x - center.x) * sinA + (shapeCenter.y - center.y) * cosA;

    arrayOfFigure_[i]->move({ posX, posY });
    arrayOfFigure_[i]->rotate(degrees);
  }
}

gadzhiev::point_t gadzhiev::CompositeShape::getCenter() const
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  return this->getFrameRect().pos;
}

void gadzhiev::CompositeShape::printNameAndParametersOfShape() const
{
  if (!arrayOfFigure_)
  {
    throw std::invalid_argument("Cmp Shape is nullptr");
  }

  std::cout << "Composite Shape(size:" << getSize() <<  ", { "
      << getCenter().x << ", " << getCenter().y << " }) ";
}
