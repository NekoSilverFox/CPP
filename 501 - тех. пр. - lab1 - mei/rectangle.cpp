#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  pos_(center)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(double mX, double mY)
{
  pos_.x += mX;
  pos_.y += mY;
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void Rectangle::printInfo() const
{
  std::cout << "\n Width is:   " << width_  << std::endl;
  std::cout << "\n Height is:  " << height_ << std::endl;
  std::cout << "\n X center is:" << pos_.x << std::endl;
  std::cout << "\n Y center is:" << pos_.y << std::endl;
}
