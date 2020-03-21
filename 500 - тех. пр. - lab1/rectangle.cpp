#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(rectangle_t rec)
{
  assert(rec.width > 0 && rec.height > 0);
  this->rectangle_.width = rec.width;
  this->rectangle_.height = rec.height;
  this->rectangle_.pos = rec.pos;
}

Rectangle::Rectangle(double width_rec, double height_rec, double x_rec, double y_rec)
{
  assert(width_rec > 0 && height_rec > 0);
  this->rectangle_.width = width_rec;
  this->rectangle_.height = height_rec;
  this->rectangle_.pos.x = x_rec;
  this->rectangle_.pos.y = y_rec;
}

Rectangle::Rectangle(double width_rec, double height_rec, const point_t& point_rec)
{
  assert(width_rec > 0 && height_rec > 0);
  this->rectangle_.width = width_rec;
  this->rectangle_.height = height_rec;
  this->rectangle_.pos = point_rec;
}

double Rectangle::getArea() const
{
  return this->rectangle_.width * this->rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return this->rectangle_;
}

void Rectangle::move(const double x_move, const double y_move) 
{
  this->rectangle_.pos.x += x_move;
  this->rectangle_.pos.y += y_move;
}

void Rectangle::move(const point_t& point_new) 
{
  this->rectangle_.pos = point_new;
}

void Rectangle::printInfo() const
{
  std::cout << "Rectangle - center - x --> " << this->rectangle_.pos.x << "\n"
            << "Rectangle - center - y --> " << this->rectangle_.pos.y << "\n"
            << "Rectangle - height --> " << this->rectangle_.height << "\n"
            << "Rectangle - width --> " << this->rectangle_.width << "\n"
            << "Rectangle - area --> " << this->getArea() << "\n";
}
