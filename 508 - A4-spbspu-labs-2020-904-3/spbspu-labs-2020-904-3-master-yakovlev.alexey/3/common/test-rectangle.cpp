#include <stdexcept>

#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "base-types.hpp"

namespace
{
  const double eps = 1e-10;
}

BOOST_AUTO_TEST_SUITE(RectangleConstructor)

BOOST_AUTO_TEST_CASE(ValidArguments_ValidInitialization)
{
  double width = 5.6, height = 43.1;
  yakovlev::point_t pos = { 2.3, -93.2 };
  yakovlev::Rectangle rect = { width, height, pos };
  BOOST_CHECK_CLOSE(rect.getWidth(), width, eps);
  BOOST_CHECK_CLOSE(rect.getHeight(), height, eps);
  BOOST_CHECK_CLOSE(rect.getCenter().x, pos.x, eps);
  BOOST_CHECK_CLOSE(rect.getCenter().y, pos.y, eps);
}

BOOST_AUTO_TEST_CASE(InvalidWidth_ThrowsInvalidArgument)
{
  BOOST_CHECK_THROW(yakovlev::Rectangle(-3.2, 3.2, { 0.0, 0.0 }), std::invalid_argument);
  BOOST_CHECK_THROW(yakovlev::Rectangle(0.0, 3.2, { 0.0, 0.0 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidHeight_ThrowsInvalidArgument)
{
  BOOST_CHECK_THROW(yakovlev::Rectangle(3.2, -432.12, { 0.0, 0.0 }), std::invalid_argument);
  BOOST_CHECK_THROW(yakovlev::Rectangle(243.2, 0.0, { 0.0, 0.0 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(RectangleFrame)

BOOST_AUTO_TEST_CASE(ValidRectangle_ValidFraming)
{
  double width = 3.42, height = 1.23;
  yakovlev::point_t pos = { 0.00312783, 323.2 };
  yakovlev::Rectangle rect = { width, height, pos };
  yakovlev::rectangle_t frame = rect.getFrameRect();
  BOOST_CHECK_CLOSE(frame.width, width, eps);
  BOOST_CHECK_CLOSE(frame.height, height, eps);
  BOOST_CHECK_CLOSE(frame.pos.x, pos.x, eps);
  BOOST_CHECK_CLOSE(frame.pos.y, pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(RectangleMove)

BOOST_AUTO_TEST_CASE(By_ValidArguments_CenterMoved)
{  
  yakovlev::point_t center = { 83.3, -93.2 };
  yakovlev::Rectangle rect = { 423.3, 23.4, center };
  double moveX = 312.4, moveY = 434.27;
  rect.move(moveX, moveY);
  yakovlev::point_t movedCenter = rect.getCenter();
  BOOST_CHECK_CLOSE(movedCenter.x, center.x + moveX, eps);
  BOOST_CHECK_CLOSE(movedCenter.y, center.y + moveY, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_CenterMoved)
{
  yakovlev::Rectangle rect = { 53.2, 312.43, { 2.3, -93.2 } };
  yakovlev::point_t newCenter = { 84.2, -1.4043 };
  rect.move(newCenter);
  BOOST_CHECK_CLOSE(rect.getCenter().x, newCenter.x, eps);
  BOOST_CHECK_CLOSE(rect.getCenter().y, newCenter.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(RectangleMovePersistence)

BOOST_AUTO_TEST_CASE(By_ValidArguments_WidthPersists)
{
  double width = 4.3;
  yakovlev::Rectangle rect = { width, 312.43, { 2.3, -93.2 } };
  rect.move(3245.4, -154.532432);
  BOOST_CHECK_CLOSE(rect.getWidth(), width, eps);
}

BOOST_AUTO_TEST_CASE(By_ValidArguments_HeightPersists)
{
  double height = 342.3;
  yakovlev::Rectangle rect = { 12345.123, height, { -223.3, -93.2 } };
  rect.move(-954345.4, 354.532432);
  BOOST_CHECK_CLOSE(rect.getHeight(), height, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_WidthPersists)
{
  double width = 5.323;
  yakovlev::Rectangle rect = { width, 952.43, { 2.3, -9433.2 } };
  rect.move({ 213.432, -2321.2 });
  BOOST_CHECK_CLOSE(rect.getWidth(), width, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_HeightPersists)
{
  double height = 6754.2;
  yakovlev::Rectangle rect = { 17645.123, height, { 0.0, -93.2 } };
  rect.move({ -93.2, 0.0 });
  BOOST_CHECK_CLOSE(rect.getHeight(), height, eps);
}

BOOST_AUTO_TEST_CASE(By_ValidArguments_AreaPersists)
{
  yakovlev::Rectangle rect = { 543.1, 832.2, { 536.2, 953.2 } };
  double area = rect.getArea();
  rect.move(482.2, -645.5432);
  BOOST_CHECK_CLOSE(rect.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_AreaPersists)
{
  yakovlev::Rectangle rect = { 34.3, 9.2, { 536.2, 953.2 } };
  double area = rect.getArea();
  rect.move({ 432.3, 4523.21 });
  BOOST_CHECK_CLOSE(rect.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(By_ValidArguments_FramePersists)
{
  yakovlev::Rectangle rect = { 34.3, 9.2, { 536.2, 953.2 } };
  yakovlev::rectangle_t frame = rect.getFrameRect();
  rect.move(3.2, 45.532);
  yakovlev::rectangle_t movedFrame = rect.getFrameRect();
  BOOST_CHECK_CLOSE(movedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(movedFrame.height, frame.height, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.x, rect.getCenter().x, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.y, rect.getCenter().y, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_FramePersists)
{
  yakovlev::Rectangle rect = { 34.3, 9.2, { 536.2, 953.2 } };
  yakovlev::rectangle_t frame = rect.getFrameRect();
  rect.move({ -43.2, 5.532 });
  yakovlev::rectangle_t movedFrame = rect.getFrameRect();
  BOOST_CHECK_CLOSE(movedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(movedFrame.height, frame.height, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.x, rect.getCenter().x, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.y, rect.getCenter().y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(RectangleRotate)

BOOST_AUTO_TEST_CASE(AnyAngle_AreaPersists)
{
  yakovlev::Rectangle rect = { 543.1, 832.2, { 536.2, 953.2 } };
  double area = rect.getArea();
  rect.rotate(12);
  BOOST_CHECK_CLOSE(rect.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(AnyAngle_CenterPersists)
{
  yakovlev::Rectangle rect = { 543.1, 832.2, { 536.2, 953.2 } };
  yakovlev::point_t center = rect.getCenter();
  rect.rotate(-12);
  BOOST_CHECK_CLOSE(rect.getCenter().x, center.x, eps);
  BOOST_CHECK_CLOSE(rect.getCenter().y, center.y, eps);
}

BOOST_AUTO_TEST_CASE(AnyAngle_FrameUpdates)
{
  yakovlev::Rectangle rect = { 543.1, 832.2, { 536.2, 953.2 } };
  yakovlev::rectangle_t frame = rect.getFrameRect();
  rect.rotate(90);
  yakovlev::rectangle_t updatedFrame = rect.getFrameRect();
  BOOST_CHECK_CLOSE(updatedFrame.height, frame.width, eps);
  BOOST_CHECK_CLOSE(updatedFrame.width, frame.height, eps);
  BOOST_CHECK_CLOSE(updatedFrame.pos.x, frame.pos.x, eps);
  BOOST_CHECK_CLOSE(updatedFrame.pos.y, frame.pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(RectangleScale)

BOOST_AUTO_TEST_CASE(ValidCoefficient_AreaScales)
{
  yakovlev::Rectangle rect = { 423.12, 312.2, { -324.1, 93.2 } };
  double area = rect.getArea();
  double coef = 1.534;
  rect.scale(coef);
  BOOST_CHECK_CLOSE(rect.getArea(), area * coef * coef, eps);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient_ThrowsInvalidArgument)
{
  yakovlev::Rectangle rect = { 5.0, 3.2, { 0.0, 5.4 } };
  BOOST_CHECK_THROW(rect.scale(-3.4), std::invalid_argument);
  BOOST_CHECK_THROW(rect.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ValidCoefficient_FramePersists)
{
  yakovlev::Rectangle rect = { 5.0, 3.2, { 0.0, 5.4 } };
  yakovlev::rectangle_t frame = rect.getFrameRect();
  double coef = 432.32;
  rect.scale(coef);
  yakovlev::rectangle_t scaledFrame = rect.getFrameRect();
  BOOST_CHECK_CLOSE(scaledFrame.width, frame.width * coef, eps);
  BOOST_CHECK_CLOSE(scaledFrame.height, frame.height * coef, eps);
  BOOST_CHECK_CLOSE(scaledFrame.pos.x, frame.pos.x, eps);
  BOOST_CHECK_CLOSE(scaledFrame.pos.y, frame.pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()
