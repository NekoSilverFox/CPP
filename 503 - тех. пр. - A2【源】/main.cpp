#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printCircleInfo(const jianing::Circle& circle);

void printRectangleInfo(const jianing::Rectangle& rectangle);

void printShapeInfo(const jianing::Shape& shape);

void moveShapeToPointXY(jianing::Shape& shape, const double x, const double y);

void moveShapeByDisplacement(jianing::Shape& shape const double dx, const double dx);

void scaleShape(jianing::Shape& shape, const double coefficient);

// =================================================

void printCircleInfo(const jianing::Circle& circle)
{
  std::cout << "------Circle Info------\n"
      << "Center: (" << circle.getCenter().x << ", " << circle.getCenter().y << ")\n"
      << "Radius: " << circle.getRadius() << "\n"
      << "Area: " << circle.getArea() << "\n\n";
}

void printRectangleInfo(const jianing::Rectangle& rectangle)
{
  std::cout << "------Rectangle Info------\n"
      << "Center: (" << rectangle.getCenter().x << ", " << rectangle.getCenter().y << ")\n"
      << "Width: " << rectangle.getWidth() << "\n"
      << "Height: " << rectangle.getHeight() << "\n"
      << "Area: " << rectangle.getArea() << "\n\n";
}

void printShapeInfo(const jianing::Shape& shape)
{
  std::cout << "------Shape Info------\n"
      << "Center: (" << shape.getCenter().x << ", " << shape.getCenter().y << ")\n"
      << "Area: " << shape.getArea() << "\n\n";
}

void moveShapeToPointXY(jianing::Shape& shape, const double x, const double y)
{
  shape.move({x, y});
}

void moveShapeByDisplacement(jianing::Shape& shape const double dx, const double dx)
{
  shape.move(dx, dx);
}


void scaleShape(jianing::Shape& shape, const double coefficient)
{
  shape.scale(coefficient);
}

int main()
{
  Rectangle rectangle({5.0, 9.0, 13.0, 21.0});
  testShape(&rectangle);

  Circle circle(, );
  testShape(&circle);
//======================================

  jianing::Circle circle {{3.0, 7.0}, 6.0}
  
  std::cout << "CIRCLE:\n";
  printCircleInfo(circle);
  return 0;
}
