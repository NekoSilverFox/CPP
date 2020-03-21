#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

void command_lab1(Shape& shape)
{
  std::cout << "Before move : " << "\n"; shape.printInfo();
  std::cout << "\n>> Move the shape to (12, 7)\n"; shape.move({12, 7});
  std::cout << "\nAfter move :\n"; shape.printInfo();

  std::cout << "\n-----------------------------------------\n\n";

  std::cout << "Before move : \n"; shape.printInfo();
  std::cout << "\n>> Move the shape [up 4 & left 9]\n"; shape.move(4, -9);
  std::cout << "\nAfter move :\n"; shape.printInfo();

  std::cout << "\n===================================================================\n\n";
}

int main()
{
  Rectangle rectangle_1(5.0, 9.0, 13.0, 21.0);
  Circle circle_1(3.0, 7.0, 6.0);

  std::cout << "-------------------------- Rectangle --------------------------\n";
  command_lab1(rectangle_1);

  std::cout << "---------------------------- Circle ----------------------------\n";
  command_lab1(circle_1);
  return 0;
}
