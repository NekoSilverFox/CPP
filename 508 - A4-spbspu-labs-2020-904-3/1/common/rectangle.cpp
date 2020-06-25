#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"

samokhin::Rectangle::Rectangle(double width, double height, const samokhin::point_t &pos):
  vertices_{{pos.x - width / 2.0, pos.y - height / 2.0},
            {pos.x - width / 2.0, pos.y + height / 2.0},
            {pos.x + width / 2.0, pos.y + height / 2.0},
            {pos.x + width / 2.0, pos.y - height / 2.0}}
{
  if (width < 0)
  {
    throw std::invalid_argument("Invalid width: rectangle's width can't be less then zero");
  }
  if (height < 0)
  {
    throw std::invalid_argument("Invalid height: rectangle's height can't be less then zero");
  }
}

double samokhin::Rectangle::getArea() const
{
  return samokhin::getDistanceBetweenPoints(vertices_[0], vertices_[1]) *
         samokhin::getDistanceBetweenPoints(vertices_[1], vertices_[2]);
}

samokhin::rectangle_t samokhin::Rectangle::getFrameRect() const
{
  double maxX = std::max(std::max(vertices_[0].x, vertices_[1].x), std::max(vertices_[2].x, vertices_[3].x));
  double maxY = std::max(std::max(vertices_[0].y, vertices_[1].y), std::max(vertices_[2].y, vertices_[3].y));
  double minX = std::min(std::min(vertices_[0].x, vertices_[1].x), std::min(vertices_[2].x, vertices_[3].x));
  double minY = std::min(std::min(vertices_[0].y, vertices_[1].y), std::min(vertices_[2].y, vertices_[3].y));

  double width = maxX - minX;
  double height = maxY - minY;
  return samokhin::rectangle_t{{minX + (width) / 2.0, minY + (height) / 2.0}, width, height};
}

void samokhin::Rectangle::move(const samokhin::point_t &pos)
{
  point_t thisCenter = getCenter();
  double dx = pos.x - thisCenter.x;
  double dy = pos.y - thisCenter.y;
  move(dx, dy);
}

void samokhin::Rectangle::move(double x, double y)
{
  for (size_t i = 0; i < 4; i++)
  {
    vertices_[i].x += x;
    vertices_[i].y += y;
  }
}

void samokhin::Rectangle::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Invalid scale coefficient: coefficient can't be less then zero");
  }
  point_t thisCenter = getCenter();
  for (size_t i = 0; i < 4; i++)
  {
    point_t currVertex = vertices_[i];
    vertices_[i] = {thisCenter.x + (currVertex.x - thisCenter.x) * k,
                    thisCenter.y + (currVertex.y - thisCenter.y) * k};
  }
}

void samokhin::Rectangle::rotate(double angle)
{
  double angleInRad = angle * M_PI / 180.0;
  double angleCos = cos(angleInRad);
  double angleSin = sin(angleInRad);
  point_t thisCenter = getCenter();
  for (size_t i = 0; i < 4; i++)
  {
    point_t currVertex = vertices_[i];

    double localX = currVertex.x - thisCenter.x;
    double localY = currVertex.y - thisCenter.y;

    double dx = localX * angleCos - localY * angleSin - localX;
    double dy = localX * angleSin + localY * angleCos - localY;
    vertices_[i] = {currVertex.x + dx, currVertex.y + dy};
  }
}

samokhin::point_t samokhin::Rectangle::getCenter() const
{
  double maxX = std::max(std::max(vertices_[0].x, vertices_[1].x), std::max(vertices_[2].x, vertices_[3].x));
  double maxY = std::max(std::max(vertices_[0].y, vertices_[1].y), std::max(vertices_[2].y, vertices_[3].y));
  double minX = std::min(std::min(vertices_[0].x, vertices_[1].x), std::min(vertices_[2].x, vertices_[3].x));
  double minY = std::min(std::min(vertices_[0].y, vertices_[1].y), std::min(vertices_[2].y, vertices_[3].y));
  return {(maxX + minX) / 2.0, (maxY + minY) / 2.0};
}
