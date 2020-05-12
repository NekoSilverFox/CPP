#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

void testCompositeShape();

int main()
{
  try
  {
    testCompositeShape();
  }
  catch (const std::domain_error& exc)
  {
    std::cerr << "Catch error[domain_error] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::invalid_argument& exc)
  {
    std::cerr << "Catch error[invalid_argument] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::out_of_range& exc)
  {
    std::cerr << "Catch error[out_of_range] and the error message is：\n"
        << exc.what();
    return 1;
  }

  return 0;
}

void testCompositeShape()
{
  std::shared_ptr<jianing::Shape> circle(new jianing::Circle({3.6, 7.0}, 6.7));
  std::shared_ptr<jianing::Shape> rectangle(new jianing::Rectangle({5.1, 9.3, 13.6, 21.3}));

  jianing::CompositeShape comp_shape;

  comp_shape.pushShape(circle);
  comp_shape.pushShape(rectangle);
  comp_shape.printShape();

  comp_shape.move({2.2, 3.3});
  comp_shape.printShape();

  comp_shape.move(-0.2, 0.7);
  comp_shape.printShape();

  comp_shape.scale(2.0);
  comp_shape.printShape();

  comp_shape.removeShape(0);
  comp_shape.printShape();

  (comp_shape[0])->move({6.6, 7.7});
  comp_shape.printShape();

  (comp_shape[0])->move(0.4, 0.3);
  comp_shape.printShape();
}
