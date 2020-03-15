#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "shape.hpp"

void actions(Shape * usingShape)
{
  usingShape->printInfo();
  std::cout << "shape move for 5 right, 6 up" << std::endl;
  usingShape->move(5, 6);
  usingShape->printInfo();
  std::cout << "shape move  to (4,7)" << std::endl;
  usingShape->move({4, 7 });
  usingShape->printInfo();
}

int main()
{
  Rectangle rectangle(10.0, 5.0, {15.0, 15.0 });
  Circle circle(2.5, {3.14, 2.71});
  
  actions(&circle);
  actions(&rectangle);
  
  return 0;
}
