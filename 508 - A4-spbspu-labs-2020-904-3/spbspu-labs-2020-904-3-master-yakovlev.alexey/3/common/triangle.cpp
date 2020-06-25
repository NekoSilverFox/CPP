#include "triangle.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

#include <boost/format.hpp>

#include "base-types.hpp"

namespace
{
  bool areValidVertices(const yakovlev::point_t vertices[3]);
}

yakovlev::Triangle::Triangle(
    const point_t & vertice1,
    const point_t & vertice2,
    const point_t & vertice3,
    double rotation
) :
  vertices_{ vertice1, vertice2, vertice3 },
  pos_{ (vertice1.x + vertice2.x + vertice3.x) / 3.0, (vertice1.y + vertice2.y + vertice3.y) / 3.0 }
{
  if (!areValidVertices(vertices_)) {
    throw std::invalid_argument{ "Triangle must not be degenerate" };
  }
  rotate(rotation);
}

bool yakovlev::Triangle::operator==(const Triangle & other) const noexcept
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

bool yakovlev::Triangle::operator!=(const Triangle & other) const noexcept
{
  return !(*this == other);
}

yakovlev::point_t yakovlev::Triangle::getCenter() const noexcept
{
  return pos_;
}

double yakovlev::Triangle::getArea() const noexcept
{
  return std::abs(vertices_[0].x * (vertices_[1].y - vertices_[2].y)
        + vertices_[1].x * (vertices_[2].y - vertices_[0].y)
        + vertices_[2].x * (vertices_[0].y - vertices_[1].y))
      / 2.0;
}

yakovlev::rectangle_t yakovlev::Triangle::getFrameRect() const noexcept
{
  double maxX = vertices_[0].x, maxY = vertices_[0].y;
  double minX = vertices_[0].x, minY = vertices_[0].y;
  for (int i = 1; i < 3; ++i) {
    minX = std::min(vertices_[i].x, minX);
    maxX = std::max(vertices_[i].x, maxX);
    minY = std::min(vertices_[i].y, minY);
    maxY = std::max(vertices_[i].y, maxY);
  }
  
  double width = maxX - minX, height = maxY - minY;
  return { width, height, { minX + (width / 2.0), minY + (height / 2.0) } };
}

void yakovlev::Triangle::move(const point_t & pos) noexcept
{
  move(pos.x - pos_.x, pos.y - pos_.y);
}

void yakovlev::Triangle::move(double x, double y) noexcept
{
  for (point_t &vert : vertices_) {
    vert.x += x;
    vert.y += y;
  }
  pos_.x += x;
  pos_.y += y;
}

void yakovlev::Triangle::rotate(double rotation) noexcept
{
  double rad = rotation * M_PI / 180.0;
  double rotSin = sin(rad);
  double rotCos = cos(rad);
  for (point_t & vert : vertices_) {
    point_t local = { vert.x - pos_.x, vert.y - pos_.y };
    vert = {
        pos_.x + local.x * rotCos - local.y * rotSin,
        pos_.y + local.x * rotSin + local.y * rotCos
    };
  }
}

void yakovlev::Triangle::scale(double coef)
{
  if (coef <= 0.0) {
    throw std::invalid_argument{ (boost::format("Invalid rectangle scale coefficient %1% - can not be negative or zero") % coef ).str() };
  }
  for (point_t & vert : vertices_) {
    vert = {
        pos_.x + (vert.x - pos_.x) * coef,
        pos_.y + (vert.y - pos_.y) * coef
    };
  }
}

void yakovlev::Triangle::print(std::ostream & os) const
{
  os << "Triangle with verticies on " << vertices_[0] << ", " << vertices_[1]
      << ", " << vertices_[2] << '\n';
}

namespace
{
  bool areValidVertices(const yakovlev::point_t vertices[3])
  {
    double sides[3] = { 
        yakovlev::getDistanceBetweenPoints(vertices[0], vertices[1]),
        yakovlev::getDistanceBetweenPoints(vertices[1], vertices[2]),
        yakovlev::getDistanceBetweenPoints(vertices[0], vertices[2])
    };
    return ((sides[0] + sides[1]) > sides[2]) 
        && ((sides[0] + sides[2]) > sides[1]) 
        && ((sides[1] + sides[2]) > sides[0]); 
  }
}
