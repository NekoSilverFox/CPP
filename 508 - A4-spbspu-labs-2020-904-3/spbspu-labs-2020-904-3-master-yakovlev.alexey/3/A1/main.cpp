#include <iostream>
#include <stdexcept>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

rectangle_t getBoundingBox(const Shape &sh);

void moveShapeTo(Shape &sh);

void moveShapeBy(Shape &sh);

int main(int, char *[])
{
  try {

    //=================================================================================================

    point_t position{-432.324, 65943.4333};

    std::cout << "\nExpecting a rectangle " << 2.354 << " wide, " << 5.63 << " high"
        << " placed on " << position << '\n';

    Rectangle rect{2.354, 5.63, position};

    std::cout << "Created a rectangle " << rect.getWidth() << " wide, " << rect.getHeight() << " high"
        << " placed on " << rect.getCenter() << '\n' << "Rectangle's area is " << rect.getArea() << '\n';

    moveShapeTo(rect);
    moveShapeBy(rect);

    rectangle_t boundingBox{getBoundingBox(rect)};
    std::cout << "Rectangle's bounding box center coordinates are " << boundingBox.pos << '\n'
        << "Rectangle's bounding box area is " << boundingBox.height * boundingBox.width << '\n';

    //=================================================================================================

    std::cout << "\nExpecting a triangle with vertices on (" << 0.0 << ", " << 1.0 << ") ("
        << 4.0 << ", " << -1.0 << ") (" << 2.0 << ", " << 5.0 << ")\n";

    Triangle tri{{0.0, 1.0}, {4.0, -1.0}, {2.0, 5.0}};

    std::cout << "Created a triangle placed on " << tri.getCenter() 
        << "Triangle's area is " << tri.getArea() << '\n';

    moveShapeBy(tri);
    moveShapeTo(tri);

    boundingBox = getBoundingBox(tri);
    std::cout << "Triangle's bounding box center coordinates are " << boundingBox.pos << '\n'
        << "Triangle's bounding box area is " << boundingBox.height * boundingBox.width << '\n';

    //=================================================================================================

    position = {3.214, -32456.876};

    std::cout << "\nExpecting a circle with radius of " << 8.5634
        << " placed on " << position << '\n';

    Circle circle{8.5634, position};
    
    std::cout << "Created a circle with radius of " << circle.getRadius() << " placed on " 
        << circle.getCenter() << '\n' << "Circle's area is " << circle.getArea() << '\n';

    moveShapeTo(circle);
    moveShapeBy(circle);

    boundingBox = getBoundingBox(circle);
    std::cout << "Circle's bounding box center coordinates are " << boundingBox.pos << '\n'
        << "Circle's bounding box area is " << boundingBox.height * boundingBox.width << '\n';

    //=================================================================================================

    try {
      std::cout << "\nTrying to create a rectangle with invalid width\n";
      Rectangle invalidRectangle{-3.0, 2.3, position};
      std::cerr << "Created rectangle with invalid width";
      return 2;
    } catch (const std::invalid_argument &exc) {
      std::cout << "Invalid rectangle not initialized with exception message:\n" << exc.what() << '\n';
    }

    try {
      std::cout << "\nTrying to create a rectangle with invalid height\n";
      Rectangle invalidRectangle{3.0, -2.3, position};
      std::cerr << "Created rectangle with invalid height";
      return 2;
    } catch (const std::invalid_argument &exc) {
      std::cout << "Invalid rectangle not initialized with exception message:\n" << exc.what() << '\n';
    }

    //=================================================================================================

    try {
      std::cout << "\nTrying to create a circle with invalid radius\n";
      Circle invalidCircle{0.0, position};
      std::cerr << "Created circle with invalid radius";
      return 2;
    } catch (const std::invalid_argument &exc) {
      std::cout << "Invalid circle not initialized with exception message:\n" << exc.what() << '\n';
    }

    //=================================================================================================

    try {
      std::cout << "\nTrying to create a degenerate triangle\n";
      Triangle invalidTriangle{{0.0, 0.0}, {0.0, 3.0}, {0.0, -235.4}};
      std::cerr << "Created degenerate triangle";
      return 2;
    } catch (const std::invalid_argument &exc) {
      std::cout << "Degenerate triangle not initialized with exception message:\n" << exc.what() << '\n';
    }

  } catch (const std::invalid_argument &exc) {
    std::cerr << exc.what();
    return 1;
  }
  return 0;
}

rectangle_t getBoundingBox(const Shape &sh)
{
  return sh.getFrameRect();
}

void moveShapeTo(Shape &sh)
{

  point_t position = {-654.54321, 68438.7865};
  std::cout << "Expecting to move shape to " << position << '\n';

  sh.move(position);

  std::cout << "New center is " << sh.getCenter() << '\n';
}

void moveShapeBy(Shape &sh)
{
  std::cout << "Expecting to move shape by " << 89534.23 << " on x axis and " << 0.0 << " on y axis\n";

  sh.move(89534.23, 0.0);

  std::cout << "New center is " << sh.getCenter() << '\n';
}
