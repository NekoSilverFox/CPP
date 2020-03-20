#include<iostream>
#include<cassert>

#include"rectangle.hpp"

Rectangle::Rectangle(rectangle_t rec)
{
  assert((rectangle_.width > 0) && (rectangle_.height > 0));
  rectangle_.width = rec.width;
  rectangle_.height = rec.height;
  rectangle_.pos = rec.pos;
}

Rectangle::Rectangle(double width_rec, double height_rec, double x_rec, double y_rec)
{
  assert((rectangle_.width > 0) && (rectangle_.height > 0));
  rectangle_.width = width_rec;
  rectangle_.height = height_rec;
  rectangle_.pos.x = x_rec;
  rectangle_.pos.y = y_rec;
}

Rectangle::Rectangle(double width_rec, double height_rec, const point_t& point_rec)
{
  assert((rectangle_.width > 0) && (rectangle_.height > 0));
  rectangle_.width = width_rec;
  rectangle_.height = height_rec;
  rectangle_.pos.x = point_rec.x;
  rectangle_.pos.y = point_rec.y;
}

double Rectangle::getArea() const
{
  return this->rectangle_.width * this->rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return this->rectangle_;
}

void Rectangle::move(double x_move, double y_move) 
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
