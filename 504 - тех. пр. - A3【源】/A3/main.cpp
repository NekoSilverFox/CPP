#include <iostream>
#include <memory>
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
    return -1;
  }
  catch (const std::invalid_argument& exc)
  {
    std::cerr << "Catch error[invalid_argument] and the error message is：\n"
        << exc.what();
    return -2;
  }
  catch (const std::out_of_range& exc)
  {
    std::cerr << "Catch error[out_of_range] and the error message is：\n"
        << exc.what();
    return -3;
  }
  catch (const std::runtime_error& exc)
  {
    std::cerr << "Catch error[runtime_error] and the error message is：\n"
        << exc.what();
    return -4;
  }
  catch (...)
  {
    std::cerr << "Something going wrong in the program!\n";
    return -5;
  }

  return 0;
}

void testCompositeShape()
{
  jianing::point_t center_cirle {1.1, 2.2};
  double r_cirle = 3.3;
  jianing::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

  jianing::rectangle_t center_width_height_rec {5.1, 9.3, 13.6, 21.3};
  jianing::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

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
