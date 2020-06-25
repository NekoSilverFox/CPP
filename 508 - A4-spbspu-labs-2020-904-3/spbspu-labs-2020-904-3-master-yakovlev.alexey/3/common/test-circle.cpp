#include <stdexcept>

#include <boost/test/unit_test.hpp>

#include "base-types.hpp"
#include "circle.hpp"

namespace
{
  const double eps = 1e-10;
}

BOOST_AUTO_TEST_SUITE(CircleConstructor)

BOOST_AUTO_TEST_CASE(ValidArguments_ValidInitialization)
{
  double radius = 4.3;
  yakovlev::point_t pos = { 2.3, -93.2 };
  yakovlev::Circle circle = { radius, pos };
  BOOST_CHECK_CLOSE(circle.getRadius(), radius, eps);
  BOOST_CHECK_CLOSE(circle.getCenter().x, pos.x, eps);
  BOOST_CHECK_CLOSE(circle.getCenter().y, pos.y, eps);
}

BOOST_AUTO_TEST_CASE(InvalidRadius_ThrowsInvalidArgument)
{
  BOOST_CHECK_THROW(yakovlev::Circle(-3.2, { 2.3, -93.2 }), std::invalid_argument);
  BOOST_CHECK_THROW(yakovlev::Circle(0.0, { 2.3, -93.2 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CircleFrame)

BOOST_AUTO_TEST_CASE(ValidCircle_ValidFraming)
{
  double radius = 43.2;
  yakovlev::point_t pos = { 0.23, 213.12 };
  yakovlev::Circle circle = { radius, pos };
  yakovlev::rectangle_t frame = circle.getFrameRect();
  BOOST_CHECK_CLOSE(frame.width, radius * 2.0, eps);
  BOOST_CHECK_CLOSE(frame.height, radius * 2.0, eps);
  BOOST_CHECK_CLOSE(frame.pos.x, pos.x, eps);
  BOOST_CHECK_CLOSE(frame.pos.y, pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CircleMove)

BOOST_AUTO_TEST_CASE(By_ValidArguments_CenterMoved)
{
  yakovlev::point_t center = { 543.3, 693.2 };
  yakovlev::Circle circle = { 543.3, center };
  double moveX = -85.23, moveY = -74.27;
  circle.move(moveX, moveY);
  yakovlev::point_t movedCenter = circle.getCenter();
  BOOST_CHECK_CLOSE(movedCenter.x, center.x + moveX, eps);
  BOOST_CHECK_CLOSE(movedCenter.y, center.y + moveY, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_CenterMoved)
{
  yakovlev::Circle circle = { 12.43, { 2.3, -93.2 } };
  yakovlev::point_t newCenter = { 53.2, 0.04327 };
  circle.move(newCenter);
  BOOST_CHECK_CLOSE(circle.getCenter().x, newCenter.x, eps);
  BOOST_CHECK_CLOSE(circle.getCenter().y, newCenter.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CircleMovePersistence)

BOOST_AUTO_TEST_CASE(By_ValidArguments_RadiusPersists)
{
  double radius = 4.3;
  yakovlev::Circle circle = { radius, { 2.3, -93.2 } };
  circle.move(23.4, -123.5432);
  BOOST_CHECK_CLOSE(circle.getRadius(), radius, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_RadiusPersists)
{
  double radius = 5.4;
  yakovlev::Circle circle = { radius, { 2.3, -93.2 } };
  circle.move({ 234.21, 0.0 });
  BOOST_CHECK_CLOSE(circle.getRadius(), radius, eps);
}

BOOST_AUTO_TEST_CASE(By_ValidArguments_AreaPersists)
{
  yakovlev::Circle circle = { 543.2, { 2.3, -93.2 } };
  double area = circle.getArea();
  circle.move(23.4, -123.5432);
  BOOST_CHECK_CLOSE(circle.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_AreaPersists)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  double area = circle.getArea();
  circle.move({ 234.21, 0.0 });
  BOOST_CHECK_CLOSE(circle.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(By_ValidArguments_FramePersists)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  yakovlev::rectangle_t frame = circle.getFrameRect();
  circle.move(43.4, 23.5432);
  yakovlev::rectangle_t movedFrame = circle.getFrameRect();
  BOOST_CHECK_CLOSE(movedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(movedFrame.height, frame.height, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.x, circle.getCenter().x, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.y, circle.getCenter().y, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_FramePersists)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  yakovlev::rectangle_t frame = circle.getFrameRect();
  circle.move({ 23.2, 64.2 });
  yakovlev::rectangle_t movedFrame = circle.getFrameRect();
  BOOST_CHECK_CLOSE(movedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(movedFrame.height, frame.height, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.x, circle.getCenter().x, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.y, circle.getCenter().y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CircleRotate)

BOOST_AUTO_TEST_CASE(AnyAngle_AreaPersists)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  double area = circle.getArea();
  circle.rotate(12);
  BOOST_CHECK_CLOSE(circle.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(AnyAngle_CenterPersists)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  yakovlev::point_t center = circle.getCenter();
  circle.rotate(-12);
  BOOST_CHECK_CLOSE(circle.getCenter().x, center.x, eps);
  BOOST_CHECK_CLOSE(circle.getCenter().y, center.y, eps);
}

BOOST_AUTO_TEST_CASE(AnyAngle_FrameIsStatic)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  yakovlev::rectangle_t frame = circle.getFrameRect();
  circle.rotate(23);
  yakovlev::rectangle_t updatedFrame = circle.getFrameRect();
  BOOST_CHECK_CLOSE(updatedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(updatedFrame.height, frame.height, eps);
  BOOST_CHECK_CLOSE(updatedFrame.pos.x, frame.pos.x, eps);
  BOOST_CHECK_CLOSE(updatedFrame.pos.y, frame.pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CircleScale)

BOOST_AUTO_TEST_CASE(ValidCoefficient_AreaScales)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  double area = circle.getArea();
  double coef = 2.34;
  circle.scale(coef);
  BOOST_CHECK_CLOSE(circle.getArea(), area * coef * coef, eps);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient_ThrowsInvalidArgument)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  BOOST_CHECK_THROW(circle.scale(-3.4), std::invalid_argument);
  BOOST_CHECK_THROW(circle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ValidCoefficient_FramePersists)
{
  yakovlev::Circle circle = { 23.634, { 2.3, -93.2 } };
  yakovlev::rectangle_t frame = circle.getFrameRect();
  double coef = 23.3;
  circle.scale(coef);
  yakovlev::rectangle_t scaledFrame{ circle.getFrameRect() };
  BOOST_CHECK_CLOSE(scaledFrame.width, frame.width * coef, eps);
  BOOST_CHECK_CLOSE(scaledFrame.height, frame.height * coef, eps);
  BOOST_CHECK_CLOSE(scaledFrame.pos.x, frame.pos.x, eps);
  BOOST_CHECK_CLOSE(scaledFrame.pos.y, frame.pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()
