#include <cmath>
#include <iostream>
#include <cassert>
#include "circle.hpp"

#define _USE_MATH_DEFINES

Circle::Circle(point_t point, double r_circle)
{
  assert(r_circle > 0);
  this->pointCircle_ = point;
  this->rCircle_ = r_circle;
}

Circle::Circle(double x_circle, double y_circle, double r_circle)
{
  assert(r_circle > 0);
  this->pointCircle_.x = x_circle;
  this->pointCircle_.y = y_circle;
  this->rCircle_ = r_circle;
}

double Circle::getArea() const
{
  return M_PI * this->rCircle_ * this->rCircle_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t rec;
  rec.pos = this->pointCircle_;
  rec.height = 2 * this->rCircle_;
  rec.width = 2 * this->rCircle_;
  return rec;
}

void Circle::move(double x_move, double y_move)
{
  this->pointCircle_.x += x_move;
  this->pointCircle_.y += y_move;
}

void Circle::move(const point_t& point_new)
{
  this->pointCircle_ = point_new;
}

void Circle::printInfo() const
{
  std::cout << "Circle - x --> " << this->pointCircle_.x << "\n"
            << "Circle - y --> " << this->pointCircle_.y << "\n"
            << "Circle - r --> " << this->rCircle_ << "\n"
            << "Circle - area --> " << this->getArea() << "\n";
}
