#include "circle.hpp"
#include "rectangle.hpp"

void camelCase(Shape& shape)
{
  shape.getArea();
  shape.getFrameRect();
  shape.move({12, 7});
  shape.move(4, -9);
}

int main()
{
  Rectangle rectangle_1({5.0, 9.0, 13.0, 21.0});
  camelCase(rectangle_1);

  Circle circle_1({3.0, 7.0}, 6.0);
  camelCase(circle_1);
  return 0;
}
