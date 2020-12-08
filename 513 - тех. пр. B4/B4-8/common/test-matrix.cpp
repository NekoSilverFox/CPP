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
      jianing::Matrix Matrix;

      BOOST_REQUIRE_EQUAL(0, Matrix.getRowSize());
      BOOST_REQUIRE_EQUAL(0, Matrix.getColumnsSize());
    }

    BOOST_AUTO_TEST_CASE(InitializeMatrix_TestCopyConstructor_NoError)
    {
      jianing::point_t center = {1.1, 2.2};
      double r_cirle = 3.3;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Matrix old_Matrix;

      old_Matrix.addShape(circle);

      jianing::Matrix new_Matrix = old_Matrix;

      BOOST_REQUIRE_EQUAL(1, new_Matrix.getRowSize());
      BOOST_REQUIRE_CLOSE(1.1, new_Matrix[0][0]->getCenter().x, accuracy);
      BOOST_REQUIRE_CLOSE(2.2, new_Matrix[0][0]->getCenter().y, accuracy);
      BOOST_REQUIRE_CLOSE(M_PI * 3.3 * 3.3, new_Matrix[0][0]->getArea(), accuracy);

      BOOST_REQUIRE_EQUAL(1, old_Matrix.getRowSize());
      BOOST_REQUIRE_CLOSE(1.1, old_Matrix[0][0]->getCenter().x, accuracy);
      BOOST_REQUIRE_CLOSE(2.2, old_Matrix[0][0]->getCenter().y, accuracy);
      BOOST_REQUIRE_CLOSE(M_PI * 3.3 * 3.3, old_Matrix[0][0]->getArea(), accuracy);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test get shape in matrix=====================
BOOST_AUTO_TEST_SUITE(GetShapeinMatrix)
    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_GetFirstShape_NoError)
    {
      jianing::point_t center = {3.1, 4.5};
      double r_cirle = 9.2;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Matrix Matrix;

      Matrix.addShape(circle);

      jianing::Shape::ShapePtr get_circle = Matrix[0][0];

      BOOST_CHECK_CLOSE(3.1, get_circle->getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(4.5, get_circle->getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 9.2 * 9.2, get_circle->getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_UseFunctiongetShape_NoError)
    {
      jianing::Matrix Matrix;

      // Shape No.1 - on layer No.1
      jianing::point_t center = {3.1, 4.5};
      double r_cirle = 4.2;
      jianing::Shape::ShapePtr first_circle = std::make_shared<jianing::Circle>(center, r_cirle);

      Matrix.addShape(first_circle);

      // Shape No.2 - on layer No.2
      jianing::rectangle_t center_width_height_rec = {1.0, 5.0, 3.0, 4.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      Matrix.addShape(rectangle);

      // Shape No.3 - on layer No.1
      center = {-3.1, -9.5};
      r_cirle = 2.3;
      jianing::Shape::ShapePtr sec_circle = std::make_shared<jianing::Circle>(center, r_cirle);

      Matrix.addShape(sec_circle);

      BOOST_CHECK_EQUAL(2, Matrix.getRowSize());
      BOOST_CHECK_EQUAL(2, Matrix.getColumnsSize());

      BOOST_CHECK_EQUAL(first_circle, Matrix[0][0]);
      BOOST_CHECK_EQUAL(rectangle, Matrix[1][0]);
      BOOST_CHECK_EQUAL(sec_circle, Matrix[0][1]);
    }

    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_UseSquareBrackets_NoError)
    {
      jianing::Matrix Matrix;

      // Shape No.1 - on layer No.1
      jianing::point_t center = {3.1, 4.5};
      double r_cirle = 4.2;
      jianing::Shape::ShapePtr first_circle = std::make_shared<jianing::Circle>(center, r_cirle);

      Matrix.addShape(first_circle);

      // Shape No.2 - on layer No.2
      jianing::rectangle_t center_width_height_rec = {1.0, 5.0, 3.0, 4.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      Matrix.addShape(rectangle);

      // Shape No.3 - on layer No.1
      center = {-3.1, -9.5};
      r_cirle = 2.3;
      jianing::Shape::ShapePtr sec_circle = std::make_shared<jianing::Circle>(center, r_cirle);

      Matrix.addShape(sec_circle);

      BOOST_CHECK_EQUAL(2, Matrix.getRowSize());
      BOOST_CHECK_EQUAL(2, Matrix.getColumnsSize());

      BOOST_CHECK_EQUAL(first_circle, Matrix[0][0]);
      BOOST_CHECK_EQUAL(rectangle, Matrix[1][0]);
      BOOST_CHECK_EQUAL(sec_circle, Matrix[0][1]);
    }

    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_UseFunctiongetShapeOnWrongValue_ThrowError)
    {
      jianing::Matrix Matrix;

      // Shape No.1 - on layer No.1
      jianing::point_t center = {5.2, 2.1};
      double r_cirle = 5.1;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      Matrix.addShape(circle);

      BOOST_CHECK_THROW(Matrix[0][2], std::out_of_range);
      BOOST_CHECK_THROW(Matrix[1][0], std::out_of_range);
      BOOST_CHECK_THROW(Matrix[1][2], std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(GetShapeinMatrix_UseSquareBracketsOnWrongValue_ThrowError)
    {
      jianing::Matrix Matrix;

      // Shape No.1 - on layer No.1
      jianing::point_t center = {2.2, 7.7};
      double r_cirle = 1.8;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      Matrix.addShape(circle);

      BOOST_CHECK_THROW(Matrix[0][2], std::out_of_range);
      BOOST_CHECK_THROW(Matrix[1][0], std::out_of_range);
      BOOST_CHECK_THROW(Matrix[1][2], std::out_of_range);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test add shape in matrix=====================
BOOST_AUTO_TEST_SUITE(AddShapeinMatrix)
    BOOST_AUTO_TEST_CASE(AddShapeinMatrix_AddCorrectShape_NoError)
    {
      jianing::point_t center = {1.1, 2.2};
      double r_cirle = 3.3;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Matrix Matrix;

      Matrix.addShape(circle);

      BOOST_CHECK_EQUAL(1, Matrix.getRowSize());
      BOOST_CHECK_CLOSE(1.1, Matrix[0][0]->getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, Matrix[0][0]->getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, Matrix[0][0]->getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(AddShapeinMatrix_AddNullptr_ThrowError)
    {
      jianing::Matrix Matrix;

      BOOST_CHECK_THROW(Matrix.addShape(nullptr), std::domain_error);
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
      jianing::Matrix matrix;

      // add in matrix
      matrix.addShape(std::make_shared<jianing::CompositeShape>(com_shape));

      BOOST_CHECK_CLOSE((2.0 + 1.0) / 2.0, matrix[0][0]->getFrameRect().pos.x, accuracy);
      BOOST_CHECK_CLOSE((2.0 + 2.0) / 2.0, matrix[0][0]->getFrameRect().pos.y, accuracy);
      BOOST_CHECK_CLOSE(1.0 + 2.0, matrix[0][0]->getFrameRect().width, accuracy);
      BOOST_CHECK_CLOSE(4.0, matrix[0][0]->getFrameRect().height, accuracy);
    }

BOOST_AUTO_TEST_SUITE_END()
