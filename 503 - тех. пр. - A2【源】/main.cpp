#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printCircleInfo(const jianing::Circle& circle);

void printRectangleInfo(const jianing::Rectangle& rectangle);

int main()
{
//==================CIRCLE====================
  try
  {
    jianing::Circle circle {{3.6, 7.0}, 6.7};

    std::cout << "=============CIRCLE=============\n";
    printCircleInfo(circle);

    std::cout << "Move cirle to (12.4, 3.0):\n";
    circle.move({12.4, 3.0});
    printCircleInfo(circle);

    std::cout << "Move cirle left 7.3, down 9.2:\n";
    circle.move(7.3, -9.2);
    printCircleInfo(circle);

    std::cout << "Scale circle (x2.0):\n";
    circle.scale(2);
    printCircleInfo(circle);
  }
  catch (const std::domain_error& exc)
  {
    std::cerr << exc.what();
    return 1;
  }

//===================RECTANGLE===================
  try
  {
  jianing::Rectangle rectangle {{5.1, 9.3, 13.6, 21.3}};

  std::cout << "=============RECTANGLE=============\n";
  printRectangleInfo(rectangle);

  std::cout << "Move cirle to (13.4, 7.7):\n";
  rectangle.move({13.4, 7.7});
  printRectangleInfo(rectangle);

  std::cout << "Move cirle right 9.2, up 5.0:\n";
  rectangle.move(-9.2, 5.0);
  printRectangleInfo(rectangle);

  std::cout << "Scale rectangle (x2.0):\n";
  rectangle.scale(2);
  printRectangleInfo(rectangle);
  }
  catch (const std::domain_error& exc)
  {
    std::cerr << exc.what();
    return 1;
  }

  return 0;
}

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
