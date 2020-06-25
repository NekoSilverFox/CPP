#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "base-types.hpp"

const double EPSILON = 0.00000001;

BOOST_AUTO_TEST_SUITE(RectangleTest)

  BOOST_AUTO_TEST_SUITE(Rectangle_RectangleConstructor)

    BOOST_AUTO_TEST_CASE(Rectangle_NegativeNumberAsWidth_ExceptionThrown)
    {
      double invalidWidth = -4.8;
      double height = 9.5;
      samokhin::point_t center = {2.1, 3.2};
      BOOST_CHECK_THROW(samokhin::Rectangle(invalidWidth, height, center), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(Rectangle_NegativeNumberAsHeight_ExceptionThrown)
    {
      double width = 2.13;
      double invalidHeight = -9.0;
      samokhin::point_t center = {2.1, 3.2};
      BOOST_CHECK_THROW(samokhin::Rectangle(width, invalidHeight, center), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(Rectangle_PositiveNumbersAsHeightAndWidth_NoException)
    {
      double width = 1.4;
      double height = 8.9;
      samokhin::point_t center = {2.1, 3.2};
      BOOST_CHECK_NO_THROW(samokhin::Rectangle(width, height, center));
    }

    BOOST_AUTO_TEST_CASE(Rectangle_ZeroAsHeightAndWidth_NoException)
    {
      double width = 0.0;
      double height = 0.0;
      samokhin::point_t center = {2.1, 3.2};
      BOOST_CHECK_NO_THROW(samokhin::Rectangle(width, height, center));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Rectangle_Scale)

    BOOST_AUTO_TEST_CASE(Rectangle_NegativeNumberAsScaleCoefficient_ExceptionThrown)
    {
      double width = 2.5;
      double height = 9.2;
      samokhin::point_t center = {2.0, 2.4};
      samokhin::Rectangle rectangle(width, height, center);
      double k = -4;
      BOOST_CHECK_THROW(rectangle.scale(k), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(Rectangle_PositiveNumberAsScaleCoefficient_NoException)
    {
      double width = 1.5;
      double height = 9.8;
      samokhin::point_t center = {2.4, 2.44};
      samokhin::Rectangle rectangle(width, height, center);
      double k = 6.1;
      BOOST_CHECK_NO_THROW(rectangle.scale(k));
    }

    BOOST_AUTO_TEST_CASE(Rectangle_ZeroAsScaleCoefficient_NoException)
    {
      double width = 1.5;
      double height = 9.8;
      samokhin::point_t center = {2.4, 2.44};
      samokhin::Rectangle rectangle(width, height, center);
      double k = 0.0;
      BOOST_CHECK_NO_THROW(rectangle.scale(k));
    }

    BOOST_AUTO_TEST_CASE(Scale_RectangleArea_SquareAreaChange)
    {
      double width = 6.3;
      double height = 5.7;
      samokhin::point_t center = {1.9, 8.33};
      samokhin::Rectangle rectangle(width, height, center);

      double area = rectangle.getArea();
      double k = 1.4;
      rectangle.scale(k);

      BOOST_CHECK_CLOSE(rectangle.getArea(), area * k * k, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Rectangle_Move_ByCords)

    BOOST_AUTO_TEST_CASE(Move_RectanglesFrameAtMovingByCords_ConstantFrame)
    {
      double width = 2.4;
      double height = 9.6;
      samokhin::point_t center = {1.4, 5.24};
      samokhin::Rectangle rectangle(width, height, center);
      double dx = 3.0;
      double dy = 2.6;
      samokhin::rectangle_t frame = rectangle.getFrameRect();
      rectangle.move(dx, dy);
      samokhin::rectangle_t newFrame = rectangle.getFrameRect();
      samokhin::point_t newCentre = {frame.pos.x + dx, frame.pos.y + dy};

      BOOST_CHECK_CLOSE(frame.width, newFrame.width, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.height, EPSILON);

      BOOST_CHECK_CLOSE(newCentre.x, newFrame.pos.x, EPSILON);
      BOOST_CHECK_CLOSE(newCentre.y, newFrame.pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_RectanglesAreaAtMovingByCords_ConstantArea)
    {
      double width = 6.3;
      double height = 5.7;
      samokhin::point_t center = {1.9, 4.11};
      samokhin::Rectangle rectangle(width, height, center);
      double area = rectangle.getArea();
      double dx = 2.0;
      double dy = 9.1;
      rectangle.move(dx, dy);
      BOOST_CHECK_CLOSE(rectangle.getArea(), area, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Rectangle_Move_AtPoint)

    BOOST_AUTO_TEST_CASE(Move_RectanglesFrameAtMovingAtPoint_ConstantFrame)
    {
      double width = 7.2;
      double height = 2.4;
      samokhin::point_t center = {-9.6, -8.1};
      samokhin::Rectangle rectangle(width, height, center);

      samokhin::point_t newCentre = {3.0, 2.6};
      samokhin::rectangle_t frame = rectangle.getFrameRect();
      rectangle.move(newCentre);
      samokhin::rectangle_t newFrame = rectangle.getFrameRect();

      BOOST_CHECK_CLOSE(frame.width, newFrame.width, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.height, EPSILON);

      BOOST_CHECK_CLOSE(newCentre.x, newFrame.pos.x, EPSILON);
      BOOST_CHECK_CLOSE(newCentre.y, newFrame.pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_RectanglesAreaAtMovingAtPoint_ConstantArea)
    {
      double width = 6.3;
      double height = 5.7;
      samokhin::point_t center = {1.9, 9.1};
      samokhin::Rectangle rectangle(width, height, center);

      double area = rectangle.getArea();
      samokhin::point_t newCentre = {2.0, 9.1};
      rectangle.move(newCentre);
      BOOST_CHECK_CLOSE(rectangle.getArea(), area, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Rectangle_Rotate)

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_ConstantArea)
    {
      double width = 7.3;
      double height = 1.7;
      samokhin::point_t center = {8.9, 1.1};
      samokhin::Rectangle rectangle(width, height, center);

      double area = rectangle.getArea();
      double angle = 15;
      rectangle.rotate(angle);
      BOOST_CHECK_CLOSE(rectangle.getArea(), area, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_ConstantCenter)
    {
      double width = 5.3;
      double height = 2.7;
      samokhin::point_t center = {8.0, 2.1};
      samokhin::Rectangle rectangle(width, height, center);

      double angle = 15;
      rectangle.rotate(angle);
      samokhin::point_t newCenter = rectangle.getCenter();
      BOOST_CHECK_CLOSE(newCenter.x, center.x, EPSILON);
      BOOST_CHECK_CLOSE(newCenter.y, center.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_RightFrameChange)
    {
      double width = 7.1;
      double height = 2.3;
      samokhin::point_t center = {5.0, -1.1};
      samokhin::Rectangle rectangle(width, height, center);

      double angle = 90;
      samokhin::rectangle_t frame = rectangle.getFrameRect();
      rectangle.rotate(angle);
      samokhin::rectangle_t newFrame = rectangle.getFrameRect();
      BOOST_CHECK_CLOSE(frame.width, newFrame.height, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.width, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
