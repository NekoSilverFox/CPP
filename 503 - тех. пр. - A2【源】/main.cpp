#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printCircleInfo(const jianing::Circle& circle);

void printRectangleInfo(const jianing::Rectangle& rectangle);

void moveShapeToPointXY(jianing::Shape& shape, const double x, const double y);

void moveShapeByDisplacement(jianing::Shape& shape, const double dx, const double dy);

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

void moveShapeToPointXY(jianing::Shape& shape, const double x, const double y)
{
  shape.move({x, y});
}

void moveShapeByDisplacement(jianing::Shape& shape, const double dx, const double dy)
{
  shape.move(dx, dy);
}


void scaleShape(jianing::Shape& shape, const double coefficient)
{
  shape.scale(coefficient);
}

int main()
{
//==================CIRCLE====================
  jianing::Circle circle {{3.6, 7.0}, 6.7};

  std::cout << "=============CIRCLE=============\n";
  printCircleInfo(circle);

  std::cout << "Move cirle to (12.4, 3.0):\n";
  moveShapeToPointXY(circle, 12.4, 3.0);
  printCircleInfo(circle);

  std::cout << "Move cirle left 7.3, down 9.2:\n";
  moveShapeByDisplacement(circle, 7.3, -9.2);
  printCircleInfo(circle);

  std::cout << "Scale circle (x2.0):\n";
  scaleShape(circle, 2);
  printCircleInfo(circle);

//===================RECTANGLE===================
  jianing::Rectangle rectangle {{5.1, 9.3, 13.6, 21.3}};

  std::cout << "=============RECTANGLE=============\n";
  printRectangleInfo(rectangle);

  std::cout << "Move cirle to (13.4, 7.7):\n";
  moveShapeToPointXY(rectangle, 13.4, 7.7);
  printRectangleInfo(rectangle);

  std::cout << "Move cirle right 9.2, up 5.0:\n";
  moveShapeByDisplacement(rectangle, -9.2, 5.0);
  printRectangleInfo(rectangle);

  std::cout << "Scale rectangle (x2.0):\n";
  scaleShape(rectangle, 2);
  printRectangleInfo(rectangle);

  return 0;
}
