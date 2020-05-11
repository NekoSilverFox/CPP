#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

jianing::Rectangle::Rectangle(const rectangle_t& rectangle) :
  rectangle_(rectangle)
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
  return rectangle_;
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
