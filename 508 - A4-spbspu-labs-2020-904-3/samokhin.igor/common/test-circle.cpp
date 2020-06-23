#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "circle.hpp"
#include "base-types.hpp"

const double EPSILON = 0.00000001;

BOOST_AUTO_TEST_SUITE(CircleTest)

  BOOST_AUTO_TEST_SUITE(Circle_CircleConstructor)

    BOOST_AUTO_TEST_CASE(Circle_NegativeNumberAsRadiusParameter_ExceptionThrown)
    {
      double invalidRadius = -4.0;
      double x = 9.8;
      double y = 1.4;
      BOOST_CHECK_THROW(samokhin::Circle(invalidRadius, {x, y}), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(Circle_PositiveNumberAsRadiusParameter_NoException)
    {
      double validRadius = 8.5;
      double x = 1.0;
      double y = 3.4;
      BOOST_CHECK_NO_THROW(samokhin::Circle(validRadius, {x, y}));
    }

    BOOST_AUTO_TEST_CASE(Circle_ZeroAsRadiusParameter_NoException)
    {
      double validRadius = 0.0;
      double x = 1.0;
      double y = 3.4;
      BOOST_CHECK_NO_THROW(samokhin::Circle(validRadius, {x, y}));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Circle_Scale)

    BOOST_AUTO_TEST_CASE(Scale_NegativeNumberAsScaleCoefficient_ExceptionThrown)
    {
      double radius = 9.1;
      double x = 4.1;
      double y = 3.8;
      samokhin::Circle circle(radius, {x, y});
      double k = -4.0;
      BOOST_CHECK_THROW(circle.scale(k), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(Scale_PositiveNumberAsScaleCoefficient_NoException)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      samokhin::Circle circle(radius, {x, y});
      double k = 6.0;
      BOOST_CHECK_NO_THROW(circle.scale(k));
    }

    BOOST_AUTO_TEST_CASE(Scale_ZeroAsScaleCoefficient_NoException)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      samokhin::Circle circle(radius, {x, y});
      double k = 0.0;
      BOOST_CHECK_NO_THROW(circle.scale(k));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Circle_Move_ByCords)

    BOOST_AUTO_TEST_CASE(Move_CirclesRectangleFrameAtMovingByCords_ConstantFrame)
    {
      double radius = 7.2;
      samokhin::point_t centre = {2.4, 9.6};
      samokhin::Circle circle(radius, centre);
      double dx = 3.0;
      double dy = 2.6;
      samokhin::rectangle_t frame = circle.getFrameRect();
      circle.move(dx, dy);

      samokhin::point_t newCentre = circle.getFrameRect().pos;
      samokhin::rectangle_t newFrame = circle.getFrameRect();

      BOOST_CHECK_CLOSE(frame.width, newFrame.width, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.height, EPSILON);

      BOOST_CHECK_CLOSE(newCentre.x, newFrame.pos.x, EPSILON);
      BOOST_CHECK_CLOSE(newCentre.y, newFrame.pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_CirclesAreaAtMovingByCords_ConstantArea)
    {
      double radius = 6.3;
      double x = 5.7;
      double y = 1.9;
      samokhin::Circle circle(radius, {x, y});
      double area = circle.getArea();
      double dx = 2.0;
      double dy = 9.1;
      circle.move(dx, dy);
      BOOST_CHECK_CLOSE(circle.getArea(), area, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Circle_Move_AtPoint)

    BOOST_AUTO_TEST_CASE(Move_CirclesRectangleFrameAtMovingAtPoint_ConstantFrame)
    {
      double radius = 7.2;
      double x = 2.4;
      double y = -9.6;
      samokhin::Circle circle(radius, {x, y});
      samokhin::point_t newCentre = {3.0, 2.6};
      samokhin::rectangle_t frame = circle.getFrameRect();
      circle.move(newCentre);
      samokhin::rectangle_t newFrame = circle.getFrameRect();

      BOOST_CHECK_CLOSE(frame.width, newFrame.width, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.height, EPSILON);

      BOOST_CHECK_CLOSE(newCentre.x, newFrame.pos.x, EPSILON);
      BOOST_CHECK_CLOSE(newCentre.y, newFrame.pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_CirclesAreaAtMovingAtPoint_ConstantArea)
    {
      double radius = 6.3;
      double x = 5.7;
      double y = 1.9;
      samokhin::Circle circle(radius, {x, y});
      double area = circle.getArea();
      samokhin::point_t newCentre = {2.0, 9.1};
      circle.move(newCentre);
      BOOST_CHECK_CLOSE(circle.getArea(), area, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Circle_Scale)

    BOOST_AUTO_TEST_CASE(Scale_CirclesArea_SquareAreaChange)
    {
      double radius = 6.3;
      double x = 5.7;
      double y = 1.9;
      samokhin::Circle circle(radius, {x, y});
      double area = circle.getArea();
      double k = 1.4;
      circle.scale(k);

      BOOST_CHECK_CLOSE(circle.getArea(), area * k * k, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(Circle_Rotate)

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_ConstantArea)
    {
      double radius = 2.3;
      double x = 3.1;
      double y = 6.9;
      samokhin::Circle circle(radius, {x, y});
      double area = circle.getArea();
      double angle = 33;
      circle.rotate(angle);

      BOOST_CHECK_CLOSE(circle.getArea(), area, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_ConstantCenter)
    {
      double radius = 1.3;
      double x = 5.4;
      double y = 1.1;
      samokhin::Circle circle(radius, {x, y});
      double angle = -33;

      samokhin::point_t center = circle.getCenter();
      circle.rotate(angle);
      samokhin::point_t newCenter = circle.getCenter();
      BOOST_CHECK_CLOSE(center.x, newCenter.x, EPSILON);
      BOOST_CHECK_CLOSE(center.y, newCenter.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_ConstantRadius)
    {
      double radius = 1.3;
      double x = 5.4;
      double y = 1.1;
      samokhin::Circle circle(radius, {x, y});
      double angle = 13;

      circle.rotate(angle);
      samokhin::rectangle_t frame = circle.getFrameRect();
      BOOST_CHECK_CLOSE(radius, frame.width / 2.0, EPSILON);
      BOOST_CHECK_CLOSE(radius, frame.height / 2.0, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
