#include "triangle.hpp"

#include <cmath>
#include <stdexcept>

namespace
{
  bool areValidVertices(const point_t vertices[3]);
}

Triangle::Triangle(const point_t &vertice1, const point_t &vertice2, const point_t &vertice3) :
  vertices_{vertice1, vertice2, vertice3},
  pos_{(vertice1.x + vertice2.x + vertice3.x) / 3.0, (vertice1.y + vertice2.y + vertice3.y) / 3.0}
{
  if (!areValidVertices(vertices_)) {
    throw std::invalid_argument("Triangle must not be degenerate");
  }
}

bool Triangle::operator==(const Triangle &other) const
{
  for (const point_t &vert : vertices_) {
    bool hasEqual{false};
    for (const point_t &othervert : other.vertices_) {
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

bool Triangle::operator!=(const Triangle &other) const
{
  return !(*this == other);
}

point_t Triangle::getCenter() const
{
  return pos_;
}

double Triangle::getArea() const
{
  return std::abs(vertices_[0].x * (vertices_[1].y - vertices_[2].y)
        + vertices_[1].x * (vertices_[2].y - vertices_[0].y)
        + vertices_[2].x * (vertices_[0].y - vertices_[1].y))
      / 2.0;
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX{vertices_[0].x}, maxY{vertices_[0].y};
  double minX{vertices_[0].x}, minY{vertices_[0].y};
  for (int i = 1; i < 3; ++i) {
    if (vertices_[i].x < minX) {
      minX = vertices_[i].x;
    }
    if (vertices_[i].x > maxX) {
      maxX = vertices_[i].x;
    }
    if (vertices_[i].y < minY) {
      minY = vertices_[i].y;
    }
    if (vertices_[i].y > maxY) {
      maxY = vertices_[i].y;
    }
  }
  double width{maxX - minX}, height{maxY - minY};
  return {width, height, {minX + (width / 2.0), minY + (height / 2.0)}};
}

void Triangle::move(const point_t &pos)
{
  move(pos.x - pos_.x, pos.y - pos_.y);
}

void Triangle::move(double x, double y)
{
  for (point_t &vert : vertices_) {
    vert.x += x;
    vert.y += y;
  }
  pos_.x += x;
  pos_.y += y;
}

namespace
{
  bool areValidVertices(const point_t vertices[3])
  {
    double sides[3] = { 
      getDistanceBetweenPoints(vertices[0], vertices[1]),
      getDistanceBetweenPoints(vertices[1], vertices[2]),
      getDistanceBetweenPoints(vertices[0], vertices[2])
    };
    return ((sides[0] + sides[1]) > sides[2]) 
        && ((sides[0] + sides[2]) > sides[1]) 
        && ((sides[1] + sides[2]) > sides[0]); 
  }
}
