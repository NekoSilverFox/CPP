#include"rectangle.hpp"
Rectangle::Rectangle(rectangle_t rec)
{
  if (rec.height <= 0 || rec.width <= 0) throw MyErrorInfo("domain_error");
  rectangle_.width = rec.width;
  rectangle_.height = rec.height;
  rectangle_.pos = rec.pos;
}
Rectangle::Rectangle(double width_rec, double height_rec, double x_rec, double y_rec)
{
  if (width_rec <= 0 || height_rec <= 0) throw MyErrorInfo("domain_error");
  rectangle_.width = width_rec;
  rectangle_.height = height_rec;
  rectangle_.pos.x = x_rec;
  rectangle_.pos.y = y_rec;
}
Rectangle::Rectangle(double width_rec, double height_rec, const point_t& point_rec)
{
  if (width_rec <= 0 || height_rec <= 0) throw MyErrorInfo("domain_error");
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
  cout << "Rectangle - center - x --> " << this->rectangle_.pos.x << endl;
  cout << "Rectangle - center - y --> " << this->rectangle_.pos.y << endl;
  cout << "Rectangle - height --> " << this->rectangle_.height << endl;
  cout << "Rectangle - width --> " << this->rectangle_.width << endl;
  cout << "Rectangle - area --> " << this->getArea() << endl;
}
