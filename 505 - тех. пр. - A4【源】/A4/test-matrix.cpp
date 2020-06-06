#include <boost/test/unit_test.hpp>
#include "matrix.hpp"
#include <memory>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <cmath>


const double accuracy = 0.00001;

// =====================test initialization matrix=====================
BOOST_AUTO_TEST_SUITE(InitializeMatrix)

    BOOST_AUTO_TEST_CASE(InitializeMatrix_DefaultConstructors)
    {
      jianing::Maxtrix maxtrix;

      BOOST_REQUIRE_EQUAL(0, maxtrix.getRowNumber());
      BOOST_REQUIRE_THROW(maxtrix.getColumnsNumber(0), std::out_of_range);
      BOOST_REQUIRE_THROW(maxtrix.getColumnsNumber(5), std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(InitializeMatrix_TestCopyConstructor_NoError)
    {
      jianing::point_t center = {1.1, 2.2};
      double r_cirle = 3.3;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Maxtrix old_maxtrix;

      old_maxtrix.addShape(circle);

      jianing::Maxtrix new_maxtrix = old_maxtrix;

      BOOST_REQUIRE_EQUAL(1, new_maxtrix.getRowNumber());
      BOOST_REQUIRE_CLOSE(1.1, new_maxtrix[0]->getShape(0)->getCenter().x, accuracy);
      BOOST_REQUIRE_CLOSE(2.2, new_maxtrix[0]->getShape(0)->getCenter().y, accuracy);
      BOOST_REQUIRE_CLOSE(M_PI * 3.3 * 3.3, new_maxtrix[0]->getShape(0)->getArea(), accuracy);

      BOOST_REQUIRE_EQUAL(1, old_maxtrix.getRowNumber());
      BOOST_REQUIRE_CLOSE(1.1, old_maxtrix[0]->getShape(0)->getCenter().x, accuracy);
      BOOST_REQUIRE_CLOSE(2.2, old_maxtrix[0]->getShape(0)->getCenter().y, accuracy);
      BOOST_REQUIRE_CLOSE(M_PI * 3.3 * 3.3, old_maxtrix[0]->getShape(0)->getArea(), accuracy);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test get shape in matrix=====================
BOOST_AUTO_TEST_SUITE(GetShapeinMatrix)
    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_GetFirstShape_NoError)
    {
      jianing::point_t center = {3.1, 4.5};
      double r_cirle = 9.2;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Maxtrix maxtrix;

      maxtrix.addShape(circle);

      jianing::Shape::ShapePtr get_circle = maxtrix[0]->getShape(0);

      BOOST_CHECK_CLOSE(3.1, get_circle->getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(4.5, get_circle->getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 9.2 * 9.2, get_circle->getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_UseFunctiongetShape_NoError)
    {
      jianing::Maxtrix maxtrix;

      // Shape No.1 - on layer No.1
      jianing::point_t center = {3.1, 4.5};
      double r_cirle = 4.2;
      jianing::Shape::ShapePtr first_circle = std::make_shared<jianing::Circle>(center, r_cirle);

      maxtrix.addShape(first_circle);

      // Shape No.2 - on layer No.2
      jianing::rectangle_t center_width_height_rec = {1.0, 5.0, 3.0, 4.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      maxtrix.addShape(rectangle);

      // Shape No.3 - on layer No.1
      center = {-3.1, -9.5};
      r_cirle = 2.3;
      jianing::Shape::ShapePtr sec_circle = std::make_shared<jianing::Circle>(center, r_cirle);

      maxtrix.addShape(sec_circle);

      BOOST_CHECK_EQUAL(2, maxtrix.getRowNumber());
      BOOST_CHECK_EQUAL(2, maxtrix[0]->getSize());
      BOOST_CHECK_EQUAL(1, maxtrix[1]->getSize());

      BOOST_CHECK_EQUAL(first_circle, maxtrix.getShape(0, 0));
      BOOST_CHECK_EQUAL(rectangle, maxtrix.getShape(1, 0));
      BOOST_CHECK_EQUAL(sec_circle, maxtrix.getShape(0, 1));
    }

    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_UseFunctiongetShapeOnWrongValue_ThrowError)
    {
      jianing::Maxtrix maxtrix;

      // Shape No.1 - on layer No.1
      jianing::point_t center = {5.2, 2.1};
      double r_cirle = 5.1;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      maxtrix.addShape(circle);

      BOOST_CHECK_THROW(maxtrix.getShape(0, 2), std::out_of_range);
      BOOST_CHECK_THROW(maxtrix.getShape(1, 0), std::out_of_range);
      BOOST_CHECK_THROW(maxtrix.getShape(1, 2), std::out_of_range);
    }

BOOST_AUTO_TEST_SUITE_END()


// =====================test add shape in matrix=====================
BOOST_AUTO_TEST_SUITE(AddShapeinMatrix)
    BOOST_AUTO_TEST_CASE(AddShapeinMatrix_AddCorrectShape_NoError)
    {
      jianing::point_t center = {1.1, 2.2};
      double r_cirle = 3.3;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Maxtrix maxtrix;

      maxtrix.addShape(circle);

      BOOST_CHECK_EQUAL(1, maxtrix.getRowNumber());
      BOOST_CHECK_CLOSE(1.1, maxtrix.getShape(0, 0)->getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, maxtrix.getShape(0, 0)->getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, maxtrix.getShape(0, 0)->getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(AddShapeinMatrix_AddNullptr_ThrowError)
    {
      jianing::Maxtrix maxtrix;

      BOOST_CHECK_THROW(maxtrix.addShape(nullptr), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(AddShapeinMatrix_AddCompositeShape_NoError)
    {
      // Make a composite shape
      jianing::CompositeShape com_shape;

      // push first shape
      jianing::point_t circle_center = {1.0, 1.0};
      double r_cirle = 1.0;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(circle_center, r_cirle);

      com_shape.pushShape(circle);

      // push second shape
      jianing::rectangle_t center_width_height_rec = {2.0, 4.0, 2.0, 2.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      com_shape.pushShape(rectangle);

      // add composite shape in matrix (on first layer)
      jianing::Maxtrix matrix;

      // add in matrix
      matrix.addShape(std::make_shared<jianing::CompositeShape>(com_shape));

      BOOST_CHECK_CLOSE((2.0 + 1.0) / 2.0, matrix.getShape(0, 0)->getFrameRect().pos.x, accuracy);
      BOOST_CHECK_CLOSE((2.0 + 2.0) / 2.0, matrix.getShape(0, 0)->getFrameRect().pos.y, accuracy);
      BOOST_CHECK_CLOSE(1.0 + 2.0, matrix.getShape(0, 0)->getFrameRect().width, accuracy);
      BOOST_CHECK_CLOSE(4.0, matrix.getShape(0, 0)->getFrameRect().height, accuracy);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test overlap=====================
BOOST_AUTO_TEST_SUITE(TestOverlap)
    BOOST_AUTO_TEST_CASE(TestOverlap_Overlap_NoError)
    {
      jianing::Maxtrix matrix;

      // Shape No.1 - On layer No.1
      jianing::point_t center_cirle = {1.0, 1.0};
      double r_cirle = 2.0;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

      matrix.addShape(circle);

      // Shape No.2
      jianing::rectangle_t center_width_height_rec = {2.0, 4.0, 2.0, 2.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      BOOST_CHECK_EQUAL(matrix.isOverlap(matrix[0], rectangle), true);
    }

    BOOST_AUTO_TEST_CASE(TestOverlap_DoNotOverlap_NoError)
    {
      jianing::Maxtrix matrix;

      // Shape No.1 - On layer No.1
      jianing::point_t center_cirle = {1.0, 1.0};
      double r_cirle = 2.0;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

      matrix.addShape(circle);

      // Shape No.2
      jianing::rectangle_t center_width_height_rec = {1.0, 1.0, 6.0, 1.0};
      jianing::Shape::ShapePtr first_rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      BOOST_CHECK_EQUAL(matrix.isOverlap(matrix[0], first_rectangle), false);
    }

    BOOST_AUTO_TEST_CASE(TestOverlap_CompositeShapeOverlap_NoError)
    {
      // Make a composite shape
      jianing::CompositeShape com_shape;

      // push first shape
      jianing::point_t circle_center = {1.0, 1.0};
      double r_cirle = 2.0;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(circle_center, r_cirle);

      com_shape.pushShape(circle);

      // push second shape
      jianing::rectangle_t center_width_height_rec = {2.0, 4.0, 2.0, 2.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      com_shape.pushShape(rectangle);

      // add composite shape in matrix (on first layer)
      jianing::Maxtrix matrix;

      // Shape No.1 - On layer No.1
      matrix.addShape(std::make_shared<jianing::CompositeShape>(com_shape));

      BOOST_CHECK_EQUAL(1, matrix[0]->getSize());
      BOOST_CHECK_EQUAL(matrix[0]->empty(), false);

      // Shape No.2
      circle_center = {7.2, 1.1};
      r_cirle = 1.0;
      jianing::Shape::ShapePtr sec_circle = std::make_shared<jianing::Circle>(circle_center, r_cirle);

      BOOST_CHECK_EQUAL(matrix.isOverlap(matrix[0], sec_circle), false);
    }

    BOOST_AUTO_TEST_CASE(TestOverlap_AddNullptr_ThrowError)
    {
      jianing::Maxtrix matrix;

      // Shape No.1 - On layer No.1
      jianing::point_t center_cirle = {1.2, 1.3};
      double r_cirle = 2.8;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

      matrix.addShape(circle);

      jianing::rectangle_t center_width_height_rec = {2.2, 3.9, 2.1, 2.2};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      BOOST_CHECK_THROW(matrix.isOverlap(matrix[0], nullptr), std::invalid_argument);
      BOOST_CHECK_THROW(matrix.isOverlap(nullptr, rectangle), std::invalid_argument);
      BOOST_CHECK_THROW(matrix.isOverlap(nullptr, nullptr), std::invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()
