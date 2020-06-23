#include "rectangle.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm> 
#include <stdexcept>
#include "base-types.hpp"

gadzhiev::Rectangle::Rectangle(double width, double height, const point_t& point, double degrees) :
  corners_{ { point.x - width / 2, point.y + height / 2 }, { point.x + width / 2, point.y + height / 2 },
            { point.x + width / 2, point.y - height / 2 }, { point.x +- width / 2, point.y - height / 2 } }
{
  if (width <= 0)
  {
    throw std::invalid_argument("Invalid width (width > 0), width = " + std::to_string(width));
  }

  if (height <= 0)
  {
    throw std::invalid_argument("Invalid height (height > 0), height = " + std::to_string(height));
  }

  if (degrees != 0)
  {
    this->rotate(degrees);
  }
}

double gadzhiev::Rectangle::getArea() const noexcept
{
  return getDistance(corners_[0], corners_[1]) * getDistance(corners_[1], corners_[2]);
}

gadzhiev::rectangle_t gadzhiev::Rectangle::getFrameRect() const noexcept
{

  const double finalLeftXPosition = std::min(std::min(corners_[0].x, corners_[1].x), std::min(corners_[2].x, corners_[3].x));
  const double finalRightXPosition = std::max(std::max(corners_[0].x, corners_[1].x), std::max(corners_[2].x, corners_[3].x));
  const double finalBottomYPosition = std::min(std::min(corners_[0].y, corners_[1].y), std::min(corners_[2].y, corners_[3].y));
  const double finalTopYPosition = std::max(std::max(corners_[0].y, corners_[1].y), std::max(corners_[2].y, corners_[3].y));

  const double frameRectWidth = finalRightXPosition - finalLeftXPosition;
  const double frameRectHeight = finalTopYPosition - finalBottomYPosition;

  return { frameRectWidth, frameRectHeight, { finalLeftXPosition + frameRectWidth / 2, finalBottomYPosition + frameRectHeight / 2 } };

}

void gadzhiev::Rectangle::move(const gadzhiev::point_t& point) noexcept
{
  point_t center { getCenter() };

  this->move(point.x - center.x, point.y - center.y);

}

void gadzhiev::Rectangle::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < 4; ++i)
  {
    corners_[i].x += dx;
    corners_[i].y += dy;
  }
}

void gadzhiev::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient, coef > 0, your coef: " + std::to_string(coefficient));
  }

  point_t center{ getCenter() };

  for (size_t i = 0; i < 4; ++i)
  {
    corners_[i].x = (corners_[i].x - center.x) * coefficient + center.x;
    corners_[i].y = (corners_[i].y - center.y) * coefficient + center.y;
  }
}

void gadzhiev::Rectangle::rotate(double degrees) noexcept
{
  const double a = degrees / 180 * M_PI;
  const double cosA = cos(a);
  const double sinA = sin(a);

  point_t center{ getCenter() };

  for (size_t i = 0; i < 4; ++i)
  {
    corners_[i] = { center.x + (corners_[i].x - center.x) * cosA - (corners_[i].y - center.y) * sinA,
                    center.y + (corners_[i].x - center.x) * sinA + (corners_[i].y - center.y) * cosA };
  }
}

gadzhiev::point_t gadzhiev::Rectangle::getCenter() const noexcept
{
  return getFrameRect().pos;
}

double gadzhiev::Rectangle::getWidth() const noexcept
{
  return getDistance(corners_[0], corners_[1]);
}

double gadzhiev::Rectangle::getHeight() const noexcept
{
  return getDistance(corners_[1], corners_[2]);
}

void gadzhiev::Rectangle::printCorners() const noexcept
{
  for (size_t i = 0; i < 4; ++i)
  {
    std::cout << '(' << corners_[i].x << " ; " << corners_[i].y << ")\n";
  }
}

void gadzhiev::Rectangle::printNameAndParametersOfShape() const noexcept
{
  point_t center{ getCenter() };
  double width = getWidth();
  double height = getHeight();

  std::cout << "Rectangle(" << width << ", " << height << ", { " << center.x << ", " << center.y << " }) ";
}
