#include "circle.hpp"
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>
#include "base-types.hpp"


gadzhiev::Circle::Circle(double radius, const point_t& point) :
  radius_ { radius },
  center_ { point.x, point.y }
{
  if (radius <= 0)
  {   
    throw std::invalid_argument("Invalid radius (radius > 0), radius = " + std::to_string(radius));
  }
}
double gadzhiev::Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

gadzhiev::rectangle_t gadzhiev::Circle::getFrameRect() const noexcept
{
  return { 2 * radius_ , 2 * radius_, center_ }; 
}

void gadzhiev::Circle::move(const point_t& point) noexcept
{
  center_ = point;
}

void gadzhiev::Circle::move(double dx, double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void gadzhiev::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient, coef > 0, your coef: " + std::to_string(coefficient));
  }

  radius_ *= coefficient;
}

double gadzhiev::Circle::getRadius() const noexcept
{
  return radius_;
}

gadzhiev::point_t gadzhiev::Circle::getCenter() const noexcept
{
  return center_;
}

void gadzhiev::Circle::rotate(double) noexcept
{}

void gadzhiev::Circle::printNameAndParametersOfShape() const noexcept
{
  std::cout << "Circle(" << radius_ << ", { " << center_.x << ", " << center_.y << " }) ";
}
