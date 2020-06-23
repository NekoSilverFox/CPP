#include <memory>
#include <iostream>
#include <stdexcept>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

yakovlev::rectangle_t getBoundingBox(const yakovlev::Shape &sh);

void moveShapeTo(yakovlev::Shape &sh);

void moveShapeBy(yakovlev::Shape &sh);

void scaleFigure(yakovlev::Shape &sh);

int main(int, char *[])
{

  //=================================================================================================

  std::cout << "\nExpecting a rectangle " << 2.354 << " wide, " << 5.63 << " high"
      << " placed on (" << -432.324 << ", " << 65943.4333 << ")\n";

  std::unique_ptr<yakovlev::Rectangle> rectptr{nullptr}; 

  try {
    rectptr = std::make_unique<yakovlev::Rectangle>(2.354, 5.63, yakovlev::point_t{-432.324, 65943.4333});
  } catch (const std::invalid_argument &exc) {
    std::cerr << exc.what();
    return 1;
  }

  std::cout << "Created a rectangle " << rectptr->getWidth() << " wide, " << rectptr->getHeight() << " high"
      << " placed on " << rectptr->getCenter() << '\n' << "Rectangle's area is " << rectptr->getArea() << '\n';

  moveShapeTo(*rectptr);
  moveShapeBy(*rectptr);

  try {
    scaleFigure(*rectptr);
  } catch (const std::invalid_argument &exc) {
    std::cerr << exc.what();
    return 1;
  }

  yakovlev::rectangle_t boundingBox{getBoundingBox(*rectptr)};
  std::cout << "Rectangle's bounding box center coordinates are " << boundingBox.pos << '\n'
      << "Rectangle's bounding box area is " << boundingBox.height * boundingBox.width << '\n';

  //=================================================================================================

  std::cout << "\nExpecting a triangle with vertices on (" << 0.0 << ", " << 1.0 << ") ("
      << 4.0 << ", " << -1.0 << ") (" << 2.0 << ", " << 5.0 << ")\n";

  std::unique_ptr<yakovlev::Triangle> triptr{nullptr};

  try {
    triptr = std::make_unique<yakovlev::Triangle>(yakovlev::point_t{0.0, 1.0},
        yakovlev::point_t{4.0, -1.0}, yakovlev::point_t{2.0, 5.0});
  } catch (const std::invalid_argument &exc) {
    std::cerr << exc.what();
    return 1;
  }

  std::cout << "Created a triangle placed on " << triptr->getCenter() << '\n'
      << "Triangle's area is " << triptr->getArea() << '\n';

  moveShapeBy(*triptr);
  moveShapeTo(*triptr);

  try {
    scaleFigure(*triptr);
  } catch (const std::invalid_argument &exc) {
    std::cerr << exc.what();
    return 1;
  }

  boundingBox = getBoundingBox(*triptr);
  std::cout << "Triangle's bounding box center coordinates are " << boundingBox.pos << '\n'
      << "Triangle's bounding box area is " << boundingBox.height * boundingBox.width << '\n';

  //=================================================================================================

  std::cout << "\nExpecting a circle with radius of " << 8.5634
      << " placed on (" << 3.214 << ", " << -32456.876 << ")\n";

  std::unique_ptr<yakovlev::Circle> circleptr{nullptr};

  try {
    circleptr = std::make_unique<yakovlev::Circle>(8.5634, yakovlev::point_t{3.214, -32456.876});
  } catch (const std::invalid_argument &exc) {
    std::cerr << exc.what();
    return 1;
  }
  
  std::cout << "Created a circle with radius of " << circleptr->getRadius() << " placed on " 
      << circleptr->getCenter() << '\n' << "Circle's area is " << circleptr->getArea() << '\n';

  moveShapeTo(*circleptr);
  moveShapeBy(*circleptr);

  try {
    scaleFigure(*circleptr);
  } catch (const std::invalid_argument &exc) {
    std::cerr << exc.what();
    return 1;
  }

  boundingBox = getBoundingBox(*circleptr);
  std::cout << "Circle's bounding box center coordinates are " << boundingBox.pos << '\n'
      << "Circle's bounding box area is " << boundingBox.height * boundingBox.width << '\n';

  //=================================================================================================

  yakovlev::point_t position{4.2, -23.6};

  try {
    std::cout << "\nTrying to create a rectangle with invalid width\n";
    yakovlev::Rectangle invalidRectangle{-3.0, 2.3, position};
    std::cerr << "Created rectangle with invalid width";
    return 2;
  } catch (const std::invalid_argument &exc) {
    std::cout << "Invalid rectangle not initialized with exception message:\n" << exc.what() << '\n';
  }

  try {
    std::cout << "\nTrying to create a rectangle with invalid height\n";
    yakovlev::Rectangle invalidRectangle{3.0, -2.3, position};
    std::cerr << "Created rectangle with invalid height";
    return 2;
  } catch (const std::invalid_argument &exc) {
    std::cout << "Invalid rectangle not initialized with exception message:\n" << exc.what() << '\n';
  }

  //=================================================================================================

  try {
    std::cout << "\nTrying to create a circle with invalid radius\n";
    yakovlev::Circle invalidCircle{0.0, position};
    std::cerr << "Created circle with invalid radius";
    return 2;
  } catch (const std::invalid_argument &exc) {
    std::cout << "Invalid circle not initialized with exception message:\n" << exc.what() << '\n';
  }

  //=================================================================================================

  try {
    std::cout << "\nTrying to create a degenerate triangle\n";
    yakovlev::Triangle invalidTriangle{{0.0, 0.0}, {0.0, 3.0}, {0.0, -235.4}};
    std::cerr << "Created degenerate triangle";
    return 2;
  } catch (const std::invalid_argument &exc) {
    std::cout << "Degenerate triangle not initialized with exception message:\n" << exc.what() << '\n';
  }

  return 0;

}

yakovlev::rectangle_t getBoundingBox(const yakovlev::Shape &sh)
{
  return sh.getFrameRect();
}

void moveShapeTo(yakovlev::Shape &sh)
{

  yakovlev::point_t position = {-654.54321, 68438.7865};
  std::cout << "Expecting to move shape to " << position << '\n';

  sh.move(position);

  std::cout << "New center is " << sh.getCenter() << '\n';
}

void moveShapeBy(yakovlev::Shape &sh)
{
  std::cout << "Expecting to move shape by " << 89534.23 << " on x axis and " << 0.0 << " on y axis\n";

  sh.move(89534.23, 0.0);

  std::cout << "New center is " << sh.getCenter() << '\n';
}

void scaleFigure(yakovlev::Shape &sh)
{
  std::cout << "Scaling shape with a coefficient of " << 2.5 << '\n';

  sh.scale(2.5);

  std::cout << "Shape area after scaling: " << sh.getArea() << '\n';
}
