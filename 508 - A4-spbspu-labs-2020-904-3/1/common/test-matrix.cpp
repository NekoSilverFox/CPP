#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "matrix.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

const double EPSILON = 0.00000001;

BOOST_AUTO_TEST_SUITE(Matrix)

  BOOST_AUTO_TEST_SUITE(Matrix_Constructor)

    BOOST_AUTO_TEST_CASE(Matrix_NoParameters_NoException)
    {
      BOOST_CHECK_NO_THROW(samokhin::Matrix{});
    }

    BOOST_AUTO_TEST_CASE(Matrix_EmptyMatrixAsParameter_ExceptionThrown)
    {
      samokhin::Matrix matrix{};
      BOOST_CHECK_THROW(samokhin::Matrix{matrix}, std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(Matrix_ValidMatrixAsParameter_NoException)
    {
      samokhin::Matrix matrix{};
      double radius = 1.1;
      double x = 4.1;
      double y = 6.1;
      matrix.add(std::make_shared<samokhin::Circle>(samokhin::Circle{radius, {x, y}}));
      BOOST_CHECK_NO_THROW(samokhin::Matrix{matrix});
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Matrix_Add)

    BOOST_AUTO_TEST_CASE(Add_ValidShapeAsParameter_NoException)
    {
      double radius = 1.0;
      double x = -1.0;
      double y = 2.1;
      std::shared_ptr<samokhin::Circle> circle = std::make_shared<samokhin::Circle>(samokhin::Circle{radius, {x, y}});

      samokhin::Matrix matrix{};
      BOOST_CHECK_NO_THROW(matrix.add(circle));
    }

    BOOST_AUTO_TEST_CASE(Add_EmptyShapeAsParameter_ExceptionThrown)
    {
      std::shared_ptr<samokhin::CompositeShape> emptyCompositeShape{};
      samokhin::Matrix matrix{};

      BOOST_CHECK_THROW(matrix.add(emptyCompositeShape), std::invalid_argument);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Matrix_IndexOperator)

    BOOST_AUTO_TEST_CASE(IndexOperator_ValidIndexesAsParameters_NoException)
    {
      double radius = 2.1;
      double x = 9.1;
      double y = 2.1;
      std::shared_ptr<samokhin::Circle> circle = std::make_shared<samokhin::Circle>(samokhin::Circle{radius, {x, y}});

      samokhin::Matrix matrix{};
      matrix.add(circle);

      BOOST_CHECK_NO_THROW(matrix[0][0]);
    }

    BOOST_AUTO_TEST_CASE(IndexOperator_ValidIndexesAsParameters_RightShape)
    {
      double radius = 2.1;
      double x = 9.1;
      double y = 2.1;
      std::shared_ptr<samokhin::Circle> circle = std::make_shared<samokhin::Circle>(samokhin::Circle{radius, {x, y}});

      double width = 4.0;
      double height = 3.1;

      std::shared_ptr<samokhin::Rectangle> rectangle = std::make_shared<samokhin::Rectangle>(
        samokhin::Rectangle{width, height, {x, y}});

      samokhin::Matrix matrix{};
      matrix.add(circle);
      matrix.add(rectangle);

      std::shared_ptr<samokhin::Shape> shape = matrix[1][0];
      samokhin::rectangle_t frame = shape->getFrameRect();

      BOOST_CHECK_CLOSE(frame.height, height, EPSILON);
      BOOST_CHECK_CLOSE(frame.width, width, EPSILON);
      BOOST_CHECK_CLOSE(frame.pos.x, x, EPSILON);
      BOOST_CHECK_CLOSE(frame.pos.y, y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(IndexOperator_InvalidIndexesAsParameters_ExceptionThrown)
    {
      double radius = 6.1;
      double x = -2.1;
      double y = 2.3;
      std::shared_ptr<samokhin::Circle> circle = std::make_shared<samokhin::Circle>(samokhin::Circle{radius, {x, y}});

      samokhin::Matrix matrix{};
      matrix.add(circle);

      BOOST_CHECK_THROW(matrix[1][0], std::out_of_range);
      BOOST_CHECK_THROW(matrix[0][1], std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(IndexOperator_GetFromEmptyMatrix_ExceptionThrown)
    {
      samokhin::Matrix matrix{};
      BOOST_CHECK_THROW(matrix[0][0], std::logic_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Matrix_GetRowSize)

    BOOST_AUTO_TEST_CASE(GetRowSize_RightRowSize)
    {
      double radius = 1.5;
      double x = 0.0;
      double y = 0.0;
      std::shared_ptr<samokhin::Circle> circle = std::make_shared<samokhin::Circle>(samokhin::Circle{radius, {x, y}});

      double width = 1.74;
      double height = 3.2;

      std::shared_ptr<samokhin::Rectangle> rectangle = std::make_shared<samokhin::Rectangle>(
        samokhin::Rectangle{width, height, {x, y}});

      samokhin::Matrix matrix{};
      matrix.add(circle);
      matrix.add(rectangle);

      BOOST_CHECK_EQUAL(matrix.getRowSize(), 2);
    }

  BOOST_AUTO_TEST_SUITE_END()
  BOOST_AUTO_TEST_SUITE(Matrix_GetColumnSize)

    BOOST_AUTO_TEST_CASE(Matrix_RightColumnSize)
    {
      double radius = 1.5;
      double x = 7.4;
      double y = 9.2;
      std::shared_ptr<samokhin::Circle> circle = std::make_shared<samokhin::Circle>(samokhin::Circle{radius, {x, y}});

      double width = 1.74;
      double height = 3.2;
      x = 0.0;
      y = 0.0;
      std::shared_ptr<samokhin::Rectangle> rectangle = std::make_shared<samokhin::Rectangle>(
        samokhin::Rectangle{width, height, {x, y}});

      samokhin::Matrix matrix{};
      matrix.add(circle);
      matrix.add(rectangle);

      BOOST_CHECK_EQUAL(matrix.getColumnSize(), 2);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Matrix_Remove)

    BOOST_AUTO_TEST_CASE(Remove_TooBigIndexAsParameter_ExceptionThrown)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::Matrix matrix{};
      matrix.add(circle);

      BOOST_CHECK_THROW(matrix.remove(0, 1), std::out_of_range);
      BOOST_CHECK_THROW(matrix.remove(1, 0), std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(Remove_RemoveFromEmptyMatrix_ExceptionThrown)
    {
      samokhin::Matrix matrix{};
      BOOST_CHECK_THROW(matrix.remove(0, 0), std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(Remove_ValidIndexAsParameter_NoException)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::Matrix matrix{};
      matrix.add(circle);

      BOOST_CHECK_NO_THROW(matrix.remove(0, 0));
    }

    BOOST_AUTO_TEST_CASE(Remove_ValidIndexAsParameter_CorrectRemove)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::Matrix matrix{};
      matrix.add(circle);
      matrix.remove(0, 0);

      BOOST_CHECK_EQUAL(matrix.getRowSize(), 0);
      BOOST_CHECK_EQUAL(matrix.getColumnSize(), 0);
    }

    BOOST_AUTO_TEST_CASE(Remove_DeletingNonexistElement_ExceptionThrown)
    {
      double radius = 10.9;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::Matrix matrix{};
      matrix.add(circle);

      radius = 1.0;
      std::shared_ptr<samokhin::Circle> circle2(new samokhin::Circle(radius, {x, y}));
      matrix.add(circle2);

      x = 100.0;
      std::shared_ptr<samokhin::Circle> circle3(new samokhin::Circle(radius, {x, y}));
      matrix.add(circle3);

      BOOST_CHECK_THROW(matrix.remove(1, 1), std::domain_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
