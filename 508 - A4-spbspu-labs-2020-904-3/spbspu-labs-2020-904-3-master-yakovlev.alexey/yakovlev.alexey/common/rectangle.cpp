#include "rectangle.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

#include <boost/format.hpp>

#include "base-types.hpp"

yakovlev::Rectangle::Rectangle(double width, double height, const point_t & pos, double rotation) :
  vertices_{
    { pos.x + width / 2.0, pos.y + height / 2.0 },
    { pos.x + width / 2.0, pos.y - height / 2.0 },
    { pos.x - width / 2.0, pos.y - height / 2.0 },
    { pos.x - width / 2.0, pos.y + height / 2.0 }
  }
{
  if (width <= 0.0) {
    throw std::invalid_argument{ (boost::format("Invalid rectangle width %1% - can not be negative or zero") % width ).str() };
  }
  if (height <= 0.0) {
    throw std::invalid_argument{ (boost::format("Invalid rectangle height %1% - can not be negative or zero") % height ).str() };
  }
  rotate(rotation);
}

bool yakovlev::Rectangle::operator==(const Rectangle & other) const noexcept
{
  for (const point_t & vert : vertices_) {
    bool hasEqual = false;
    for (const point_t & othervert : other.vertices_) {
      if (vert == othervert) {
        hasEqual = true;
      }
    }
    if (!hasEqual) {
      return false;
    }
  }
  return true;
}

bool yakovlev::Rectangle::operator!=(const Rectangle & other) const noexcept
{
  return !(*this == other);
}

double yakovlev::Rectangle::getWidth() const noexcept
{
  return getDistanceBetweenPoints(vertices_[1], vertices_[2]);
}

double  yakovlev::Rectangle::getHeight() const noexcept
{
  return getDistanceBetweenPoints(vertices_[0], vertices_[1]);
}

yakovlev::point_t yakovlev::Rectangle::getCenter() const noexcept
{
  double sumX = vertices_[0].x;
  double sumY = vertices_[0].y;
  for (size_t i = 1u; i < 4u; ++i) {
    sumX += vertices_[i].x;
    sumY += vertices_[i].y;
  }
  return { sumX / 4.0, sumY / 4.0 };
}

double yakovlev::Rectangle::getArea() const noexcept
{
  return getWidth() * getHeight();
}

yakovlev::rectangle_t yakovlev::Rectangle::getFrameRect() const noexcept
{
  double maxX = vertices_[0].x, maxY = vertices_[0].y;
  double minX = vertices_[0].x, minY = vertices_[0].y;
  for (int i = 1; i < 4; ++i) {
    minX = std::min(vertices_[i].x, minX);
    maxX = std::max(vertices_[i].x, maxX);
    minY = std::min(vertices_[i].y, minY);
    maxY = std::max(vertices_[i].y, maxY);
  }
  
  double width = maxX - minX, height = maxY - minY;
  return { width, height, { minX + (width / 2.0), minY + (height / 2.0) } };
}

void yakovlev::Rectangle::move(const point_t & pos) noexcept
{
  point_t center = getCenter();
  move(pos.x - center.x, pos.y - center.y);
}

void yakovlev::Rectangle::move(double x, double y) noexcept
{
  for (point_t & vert : vertices_) {
    vert.x += x;
    vert.y += y;
  }
}

void yakovlev::Rectangle::rotate(double rotation) noexcept
{
  double rad = rotation * M_PI / 180.0;
  double rotSin = sin(rad);
  double rotCos = cos(rad);
  point_t pos = getCenter();
  for (point_t & vert : vertices_) {
    point_t local = { vert.x - pos.x, vert.y - pos.y };
    vert = {
        pos.x + local.x * rotCos - local.y * rotSin,
        pos.y + local.x * rotSin + local.y * rotCos
    };
  }
}

void yakovlev::Rectangle::scale(double coef)
{
  if (coef <= 0.0) {
    throw std::invalid_argument{ (boost::format("Invalid rectangle scale coefficient %1% - can not be negative or zero") % coef ).str() };
  }
  point_t pos = getCenter();
  for (point_t & vert : vertices_) {
    vert = {
        pos.x + (vert.x - pos.x) * coef,
        pos.y + (vert.y - pos.y) * coef
    };
  }
} 

void yakovlev::Rectangle::print(std::ostream & os) const
{
  os << "Rectangle " << getWidth() << " wide, " << getHeight()
      << " high placed on " << getCenter() << '\n';
}
