#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include <cmath>
#include "rectangle.hpp"
#include "base-types.hpp"

const double epsilon = 0.0000001;

BOOST_AUTO_TEST_SUITE(rectangle_constructor)

BOOST_AUTO_TEST_CASE(ValidParametersWithRotateAndWithout_ValidShapewithValidParametersConstructed)
{
  gadzhiev::Rectangle rectangle{ 10, 15, {3, 8} };
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 15, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 10, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().x, 3, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, 8, epsilon);

  gadzhiev::Rectangle rectangleTwo(4, 2, { 2, 1 }, 45);

  BOOST_CHECK_CLOSE(rectangleTwo.getWidth(), 4, epsilon);
  BOOST_CHECK_CLOSE(rectangleTwo.getHeight(), 2, epsilon);
  BOOST_CHECK_CLOSE(rectangleTwo.getFrameRect().height, 6 * sqrt(2) / 2, epsilon);
  BOOST_CHECK_CLOSE(rectangleTwo.getFrameRect().width, 6 * sqrt(2) / 2, epsilon);
}

BOOST_AUTO_TEST_CASE(InvalidParameters_ThrownInvalidArument)
{
  BOOST_CHECK_THROW(gadzhiev::Rectangle rectangle(-1, 8, { 1, 8 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidParameterZeroWidth_ThrownInvalidArument)
{
  BOOST_CHECK_THROW(gadzhiev::Rectangle rectangle(0, 8, { 1, 8 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidParameterHeight_ThrownInvalidArument)
{
  BOOST_CHECK_THROW(gadzhiev::Rectangle rectangle(71, -25, { 1, 89 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidParameterZerHeight_ThrownInvalidArument)
{
  BOOST_CHECK_THROW(gadzhiev::Rectangle rectangle(7, 0, { 12, 8 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangle_move)

BOOST_AUTO_TEST_CASE(ValidMoveDxDy_RectangleCenterValidMoved)
{
  gadzhiev::Rectangle rectangle(7, 8, { 12, 11 });
  const double dx = 1;
  const double dy = 43;
  rectangle.move(dx, dy);
  BOOST_CHECK_CLOSE(12 + dx, rectangle.getCenter().x, epsilon);
  BOOST_CHECK_CLOSE(11 + dy, rectangle.getCenter().y, epsilon);
}

BOOST_AUTO_TEST_CASE(ValidMoveDxDyZero_RectangleCenterValidMoved)
{
  gadzhiev::Rectangle rectangle(7, 8, { 12, 8 });
  const double dx = 0;
  const double dy = 0;
  rectangle.move(dx, dy);
  BOOST_CHECK_CLOSE(12, rectangle.getCenter().x, epsilon);
  BOOST_CHECK_CLOSE(8, rectangle.getCenter().y, epsilon);
}

BOOST_AUTO_TEST_CASE(ValidMoveToPoint_RectangleCenterValidMoved)
{
  gadzhiev::Rectangle rectangle(7, 8, { 12, 11 });
  const gadzhiev::point_t point{ -23, 5 };
  rectangle.move(point);
  BOOST_CHECK_CLOSE(rectangle.getCenter().x, point.x, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, point.y, epsilon);
}

BOOST_AUTO_TEST_CASE(ValidMoveToZeroPoint_RectangleCenterValidMoved)
{
  gadzhiev::Rectangle rectangle(7, 8, { 12, 11 });
  const gadzhiev::point_t point{ 0, 0 };
  rectangle.move(point);
  BOOST_CHECK_CLOSE(rectangle.getCenter().x, point.x, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, point.y, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangle_frameRect)

BOOST_AUTO_TEST_CASE(FrameRectangle_ValidWidthHeightCenterOfRectangle)
{
  gadzhiev::Rectangle rectangle(10, 15, {1, 4});
  gadzhiev::rectangle_t rectangleStruct = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangleStruct.width, 10, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.height, 15, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.x, 1, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.y, 4, epsilon);
}

BOOST_AUTO_TEST_CASE(FrameRectangleAfterScale_ValidWidthHeightCenterOfRectangle)
{
  gadzhiev::Rectangle rectangle(10, 15, { 1, 4 });
  const double scaleCoef = 0.4;
  rectangle.scale(scaleCoef);

  gadzhiev::rectangle_t rectangleStruct = rectangle.getFrameRect();
  BOOST_CHECK_CLOSE(rectangleStruct.width, 10 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.height, 15 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.x, 1, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.y, 4, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangle_scale)

BOOST_AUTO_TEST_CASE(ValidScale_CoefMoreThatOne_CmpShapeValidScaled)
{
  gadzhiev::Rectangle rectangle(12, 10, { 12, 8 });
  const double scaleCoef = 3.3;
  rectangle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 12 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 10 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().x, 12, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, 8, epsilon);
}

BOOST_AUTO_TEST_CASE(ValidScale_CoefOne_CmpShapeValidScaledParametersNotChanged)
{
  gadzhiev::Rectangle rectangle(12, 10, { 12, 8 });
  const double scaleCoef = 1;
  rectangle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 12, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 10, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().x, 12, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, 8, epsilon);
}

BOOST_AUTO_TEST_CASE(rectangle_scale_by_valid_coef_less_than_1)
{
  gadzhiev::Rectangle rectangle(12, 10, { 12, 8 });
  const double scaleCoef = 0.4;
  rectangle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 12 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 10 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().x, 12, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, 8, epsilon);
}

BOOST_AUTO_TEST_CASE(InvalidScale_CoefLessThanZero_ThrownInvalidArgument)
{
  gadzhiev::Rectangle rectangle(12, 10, { 12, 8 });
  BOOST_CHECK_THROW(rectangle.scale(-64), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidScale_CoefZero_ThrownInvalidArgument)
{
  gadzhiev::Rectangle rectangle(12, 10, { 12, 8 });
  BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangle_area)

BOOST_AUTO_TEST_CASE(DefaultArea_ValidGetArea)
{
  gadzhiev::Rectangle rectangle(7, 8, { 12, 8 });
  BOOST_CHECK_CLOSE(rectangle.getArea(), 7 * 8, epsilon);
}

BOOST_AUTO_TEST_CASE(AreaAfterMoving_AreaNotChanged)
{
  gadzhiev::Rectangle rectangle(70, 80, { 12, 8 });
  const double dx = -23;
  const double dy = 65;
  rectangle.move(dx, dy);
  BOOST_CHECK_CLOSE(rectangle.getArea(), 70 * 80, epsilon);
}

BOOST_AUTO_TEST_CASE(AreaAfterMovingToPoint_AreaNotChanged)
{
  gadzhiev::Rectangle rectangle(7, 10, { 12, 8 });
  const gadzhiev::point_t NewCenter{ 62, -8 };
  rectangle.move(NewCenter);
  BOOST_CHECK_CLOSE(rectangle.getArea(), 7 * 10, epsilon);
}

BOOST_AUTO_TEST_CASE(AreaAfterScale_AreaNotChanged)
{
  gadzhiev::Rectangle rectangle(7, 10, { 12, 8 });
  const double scaleCoef = 2.4;
  rectangle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(rectangle.getArea(), 7 * 10 * scaleCoef * scaleCoef, epsilon);
}

BOOST_AUTO_TEST_CASE(AreaAfterRotate_AreaNotChanged)
{
  gadzhiev::Rectangle rectangle(4, 2, { 2, 1 });

  double rotateCoef = 45;

  rectangle.rotate(rotateCoef);

  BOOST_CHECK_CLOSE(rectangle.getArea(), 4 * 2, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(rectangle_rotate)

BOOST_AUTO_TEST_CASE(RectangleRotate_ValidParametersOfWidthAndHeightAndValidFrameRect)
{
  gadzhiev::Rectangle rectangle(4, 2, { 2, 1 });

  double rotateCoef = 45;

  rectangle.rotate(rotateCoef);
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 4, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 2, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, 6 * sqrt(2) / 2, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, 6 * sqrt(2) / 2, epsilon);

  rotateCoef = 0;

  rectangle.rotate(rotateCoef);

  BOOST_CHECK_CLOSE(rectangle.getWidth(), 4, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 2, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, 6 * sqrt(2) / 2, epsilon);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, 6 * sqrt(2) / 2, epsilon);

}

BOOST_AUTO_TEST_SUITE_END()
