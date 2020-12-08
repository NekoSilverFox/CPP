#include "rectangle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
const double INITANGLE = 0.0;

jianing::Rectangle::Rectangle(const rectangle_t& rectangle) :
  rectangle_(rectangle),
  angle_(INITANGLE)
{
  if (rectangle.width <= 0.0)
  {
    throw std::domain_error("Error: Width can not be "
        + std::to_string(rectangle.width) + " ! Must be positive!\n");
  }

  if (rectangle.height <= 0.0)
  {
    throw std::domain_error("Error: Height can not be "
        + std::to_string(rectangle.height) + " ! Must be positive!\n");
  }
}

jianing::Rectangle::Rectangle(const rectangle_t& rectangle, double angle) :
  rectangle_(rectangle),
  angle_(angle)
{
  if (rectangle.width <= 0.0)
  {
    throw std::domain_error("Error: Width can not be "
        + std::to_string(rectangle.width) + " ! Must be positive!\n");
  }

  if (rectangle.height <= 0.0)
  {
    throw std::domain_error("Error: Height can not be "
        + std::to_string(rectangle.height) + " ! Must be positive!\n");
  }
}

double jianing::Rectangle::getWidth() const
{
  return rectangle_.width;
}

double jianing::Rectangle::getHeight() const
{
  return rectangle_.height;
}

jianing::point_t jianing::Rectangle::getCenter() const
{
  return rectangle_.pos;
}

double jianing::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

jianing::rectangle_t jianing::Rectangle::getFrameRect() const
{
  double width = rectangle_.width * std::fabs(cos(M_PI * angle_ / 180)) + rectangle_.height * std::fabs(sin(M_PI * angle_ / 180));
  double height = rectangle_.height * std::fabs(cos(M_PI * angle_ / 180)) + rectangle_.width * std::fabs(sin(M_PI * angle_ / 180));

  return {width, height, rectangle_.pos};
}

void jianing::Rectangle::printShape()
{
  std::cout << "------Rectangle------\n"
      << "Center: (" << rectangle_.pos.x << ", " << rectangle_.pos.y << ")\n"
      << "Width: " << rectangle_.width << "\n"
      << "Height: " << rectangle_.height << "\n"
      << "Area: " << getArea() << "\n"
      << "-------------------" << "\n\n";
}

void jianing::Rectangle::printFrameRect() const
{
  std::cout << "------ Frame rect of rectangle------\n"
      << "Center: (" << getFrameRect().pos.x << ", " << getFrameRect().pos.y << ")\n"
      << "Width: " << getFrameRect().width << "\n"
      << "Height: " << getFrameRect().height << "\n"
      << "-------------------\n\n";
}

void jianing::Rectangle::move(double x_move, double y_move)
{
  rectangle_.pos.x += x_move;
  rectangle_.pos.y += y_move;
}

void jianing::Rectangle::move(const point_t& point_new) 
{
  rectangle_.pos = point_new;
}

void jianing::Rectangle::scale(double coef)
{
  if (coef <= 0.0)
  {
    throw std::domain_error("Error: Coefficient can not be"
        + std::to_string(coef) + " ! Must be positive!\n");
  }
  rectangle_.width *= coef;
  rectangle_.height *= coef;
}

void jianing::Rectangle::rotate(double angle)
{
  angle_ += angle;

  if (angle_ < 0)
  {
    angle_ = 360 + fmod(angle_, 360);
  }
}
