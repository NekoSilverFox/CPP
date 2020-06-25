#include <stdexcept>
#include <cmath>
#include <boost/test/unit_test.hpp>
#include "circle.hpp"
#include "base-types.hpp"

BOOST_AUTO_TEST_SUITE(circle_constructor)

BOOST_AUTO_TEST_CASE(ValidParameters_ValidShapeConstructed)
{
  gadzhiev::Circle circle(34, { 1, 5 });
  BOOST_CHECK_CLOSE(circle.getRadius(), 34, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().x, 1, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().y, 5, 0.0000001);
}

BOOST_AUTO_TEST_CASE(InvalidParameters_ThrownInvalidArument)
{
  BOOST_CHECK_THROW(gadzhiev::Circle circle(-34, { 1, 5 }), std::invalid_argument);
  BOOST_CHECK_THROW(gadzhiev::Circle circle(0, { 1, 5 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circle_move)

BOOST_AUTO_TEST_CASE(ValidMoveDxDy_CircleCenterValidMoved)
{
  gadzhiev::Circle circle(23, { -3, 8 });
  const int dx = 4;
  const int dy = 9;
  circle.move(dx, dy);
  BOOST_CHECK_EQUAL(circle.getCenter().x, -3 + dx);
  BOOST_CHECK_EQUAL(circle.getCenter().y, 8 + dy);

  const int dxZero = 0;
  const int dyZero = 0;
  const gadzhiev::point_t previousCenter = circle.getCenter();
  circle.move(dxZero, dyZero);
  BOOST_CHECK_EQUAL(circle.getCenter().x, previousCenter.x);
  BOOST_CHECK_EQUAL(circle.getCenter().y, previousCenter.y);
}

BOOST_AUTO_TEST_CASE(ValidMoveToPoint_CircleCenterValidMoved)
{
  gadzhiev::Circle circle(23, { -3, 8 });

  const gadzhiev::point_t NewCenter{ 11, -9 };
  circle.move(NewCenter);
  BOOST_CHECK_EQUAL(circle.getCenter().x, NewCenter.x);
  BOOST_CHECK_EQUAL(circle.getCenter().y, NewCenter.y);

  const gadzhiev::point_t NewCenterInZero{ 0, 0 };
  circle.move(NewCenterInZero);
  BOOST_CHECK_EQUAL(circle.getCenter().x, NewCenterInZero.x);
  BOOST_CHECK_EQUAL(circle.getCenter().y, NewCenterInZero.y);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circle_frame_rectangle)

BOOST_AUTO_TEST_CASE(FrameRectangle_ValidWidthHeightCenterOfRectangle)
{
  gadzhiev::Circle circle(11, { 3, 10 });

  gadzhiev::rectangle_t rectangleStruct = circle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangleStruct.height, 2 * circle.getRadius(), 0.0000001);
  BOOST_CHECK_CLOSE(rectangleStruct.width, 2 * circle.getRadius(), 0.0000001);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.x, circle.getCenter().x, 0.0000001);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.y, circle.getCenter().y, 0.0000001);
}

BOOST_AUTO_TEST_CASE(FrameRectangleAfterScale_ValidWidthHeightCenterOfRectangle)
{
  gadzhiev::Circle circle(11, { 3, 10 });
  const double scaleCoef = 3.2;
  circle.scale(scaleCoef);

  gadzhiev::rectangle_t rectangleStruct = circle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangleStruct.height, 2 * 11 * scaleCoef, 0.0000001);
  BOOST_CHECK_CLOSE(rectangleStruct.width, 2 * 11 * scaleCoef, 0.0000001);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.x, circle.getCenter().x, 0.0000001);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.y, circle.getCenter().y, 0.0000001);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circle_scale)

BOOST_AUTO_TEST_CASE(InvalidScale_CoefLessThanZero_ThrownInvalidArgument)
{
  gadzhiev::Circle circle(14, { -3, 5 });
  BOOST_CHECK_THROW(circle.scale(-64.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidScale_CoefZero_ThrownInvalidArgument)
{
  gadzhiev::Circle circle(14, { -3, 5 });
  BOOST_CHECK_THROW(circle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ValidScale_CoefMoreThanOne_CircleValidScaled)
{
  gadzhiev::Circle circle(23, { 8, -15 });
  const double scaleCoef = 14;
  circle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(circle.getRadius(), 23 * scaleCoef, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().x, 8, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().y, -15, 0.0000001);
}

BOOST_AUTO_TEST_CASE(ValidScale_CoefMoreLessThanOneMoreThanZero_CircleValidScaled)
{
  gadzhiev::Circle circle(13, { -8, -2 });
  const double scaleCoef = 0.34;
  circle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(circle.getRadius(), 13 * scaleCoef, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().x, -8, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().y, -2, 0.0000001);
}

BOOST_AUTO_TEST_CASE(ValidScale_CoefOne_CircleValidScaled)
{
  gadzhiev::Circle circle(185, { 86, -15 });
  const double scaleCoef = 1;
  circle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(circle.getRadius(), 185, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().x, 86, 0.0000001);
  BOOST_CHECK_CLOSE(circle.getCenter().y, -15, 0.0000001);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circle_area)

BOOST_AUTO_TEST_CASE(DefaultArea_ValidGetArea)
{
  gadzhiev::Circle circle(12.4, { -2, 7 });
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 12.4 * 12.4, 0.0000001);
}

BOOST_AUTO_TEST_CASE(AreaAfterMoving_AreaNotChanged)
{
  gadzhiev::Circle circle(3.8, { 9, -13 });
  const double dx = 1;
  const double dy = 43;

  circle.move(dx, dy);
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 3.8 * 3.8, 0.0000001);

  const double dxToZero = 0;
  const double dyToZero = 0;
  circle.move(dxToZero, dyToZero);                        
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 3.8 * 3.8, 0.0000001);

  const gadzhiev::point_t NewCenter{ 56, -26 };
  circle.move(NewCenter);                  
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 3.8 * 3.8, 0.0000001);

  const gadzhiev::point_t NewCenterTwo{ 0, 0 };
  circle.move(NewCenterTwo);             
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 3.8 * 3.8, 0.0000001);
}

BOOST_AUTO_TEST_CASE(AreaAfterScale_AreaChangedToSquaredCoef)
{
  gadzhiev::Circle circle(46, { -12, 76 });
  const double scaleCoef = 3.4;
  circle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(circle.getArea(), M_PI * 46 * scaleCoef * 46 * scaleCoef, 0.0000001);                  
}

BOOST_AUTO_TEST_SUITE_END()
