#include <iostream>
#include <memory>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "layer.hpp"
#include "matrix.hpp"

void testMatrix();

int main()
{
  try
  {
    testMatrix();
  }
  catch (const std::domain_error& exc)
  {
    std::cerr << "Catch error [domain_error] and the error message is：\n"
        << exc.what();
    return 255;
  }
  catch (const std::invalid_argument& exc)
  {
    std::cerr << "Catch error [invalid_argument] and the error message is：\n"
        << exc.what();
    return 1;
  }
  catch (const std::out_of_range& exc)
  {
    std::cerr << "Catch error [out_of_range] and the error message is：\n"
        << exc.what();
    return 128;
  }
  catch (const std::runtime_error& exc)
  {
    std::cerr << "Catch error [runtime_error] and the error message is：\n"
        << exc.what();
    return 126;
  }
  catch (...)
  {
    std::cerr << "Something going wrong in the program!\n";
    return 127;
  }

  return 0;
}

void testMatrix()
{
  jianing::Maxtrix maxtrix;

  // Shape No.1 - On layer No.1
  jianing::point_t center_cirle = {1.0, 1.0};
  double r_cirle = 2.0;
  jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

  std::cout << "aaa";
  maxtrix.addShape(circle);


  // Shape No.2 - On layer No.2
  jianing::rectangle_t center_width_height_rec = {2.0, 4.0, 2.0, 2.0};
  jianing::Shape::ShapePtr first_rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

  maxtrix.addShape(first_rectangle);


  // Shape No.3 - On layer No.1
  center_width_height_rec = {1.0, 1.0, 6.0, 1.0};
  jianing::Shape::ShapePtr sec_rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

  maxtrix.addShape(sec_rectangle);



  std::cout << "The number of the layer is: " << maxtrix.getNumberLayer() << "\n";

  for (size_t i = 0; i < maxtrix.getNumberLayer(); ++i)
  {
    std::cout << "Layer No." << i + 1 << ", Size: " << maxtrix[i]->getSize() << "\n";
  }

  maxtrix[0]->getShape(0)->printShape();
  maxtrix[1]->getShape(0)->printShape();
  maxtrix[0]->getShape(1)->printShape();

}
