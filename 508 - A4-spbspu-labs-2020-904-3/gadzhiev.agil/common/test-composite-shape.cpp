#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include <initializer_list>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

const double epsilon = 0.0000001;

BOOST_AUTO_TEST_SUITE(CompositeShapeConstructor)

BOOST_AUTO_TEST_CASE(ValidParameters_ValidShapeConstructed)
{
  const double radius = 34;
  const gadzhiev::point_t point{ 1, 5 };
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(radius, point));
  BOOST_CHECK_EQUAL(cmpShape.getSize(), 1);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().x, point.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().y, point.y, epsilon);
}

BOOST_AUTO_TEST_CASE(ValidInitialisationListParameters_ValidShapeConstructed)
{
  const double radius = 34;
  const gadzhiev::point_t point{ 1, 5 };
  gadzhiev::CompositeShape cmpShape{ std::make_shared<gadzhiev::Circle>(12, gadzhiev::point_t{ -67, 5 }),
      std::make_shared<gadzhiev::Circle>(32, gadzhiev::point_t { 24, 5 }),
      std::make_shared<gadzhiev::Circle>(radius, point),
      std::make_shared<gadzhiev::Circle>(1, gadzhiev::point_t { 33, 54 }) };

  BOOST_CHECK_EQUAL(cmpShape.getSize(), 4);
  BOOST_CHECK_CLOSE(cmpShape[2]->getCenter().x, point.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape[2]->getCenter().y, point.y, epsilon);
}

BOOST_AUTO_TEST_CASE(InValidInitialisationListParameters_ThrownInvalidArgument)
{
  gadzhiev::Shape::ShapePtr nullptrShape{ nullptr };
  const double radius = 34;
  const gadzhiev::point_t point{ 1, 5 };

  BOOST_CHECK_THROW(gadzhiev::CompositeShape cmpShape({ std::make_shared<gadzhiev::Circle>(radius, point),
      std::make_shared<gadzhiev::Circle>(radius, point),
      std::make_shared<gadzhiev::Circle>(radius, point),
      nullptrShape }),
      std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InvalidParameters_ThrownInvalidArument)
{
  BOOST_CHECK_THROW(gadzhiev::CompositeShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CompositeShapeAdd)

BOOST_AUTO_TEST_CASE(AddFigure_FiguresInCmpShape)
{
  gadzhiev::Shape::ShapePtr rectangle = std::make_shared<gadzhiev::Rectangle>(4, 9, gadzhiev::point_t { 3, 7 });

  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(32, gadzhiev::point_t { 1, 76 }));

  cmpShape.add(std::make_shared<gadzhiev::Circle>(1, gadzhiev::point_t { -2, 7 }));
  cmpShape.add(rectangle);

  BOOST_CHECK_EQUAL(cmpShape.getSize(), 3);
  BOOST_CHECK_EQUAL(cmpShape[2], rectangle);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CompositeShapeRemove)

BOOST_AUTO_TEST_CASE(ValidRemoveFigure_ThereIsNoFigureInCmpShape)
{
  gadzhiev::Shape::ShapePtr rectangle = std::make_shared<gadzhiev::Rectangle>(11, 13, gadzhiev::point_t { 3, 7 });

  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(32, gadzhiev::point_t { 1, 76 }));

  cmpShape.add(std::make_shared<gadzhiev::Circle>(1, gadzhiev::point_t{ -2, 7 }));
  cmpShape.add(rectangle);
  cmpShape.remove(0);
  BOOST_CHECK_EQUAL(cmpShape[1], rectangle);
  BOOST_CHECK_EQUAL(cmpShape.getSize(), 2);
}

BOOST_AUTO_TEST_CASE(RemoveLastFigure_ThrownLengthError)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(32, gadzhiev::point_t { 1, 76 }));
  BOOST_CHECK_THROW(cmpShape.remove(0), std::length_error);
}

BOOST_AUTO_TEST_CASE(InvalidIndexToRemove_ThrownOutOfRange)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(32, gadzhiev::point_t{ 1, 76 }));
  BOOST_CHECK_THROW(cmpShape.remove(3), std::out_of_range);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CompositeShapeIndex)

BOOST_AUTO_TEST_CASE(ValidIndex_ValidGetFigureFromCmpShape)
{
  gadzhiev::point_t point{ 3, 7 };

  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(32, point));

  gadzhiev::Shape::ShapePtr rectangle = std::make_shared<gadzhiev::Rectangle>(11, 13, gadzhiev::point_t { 3, 45 });
  cmpShape.add(rectangle);

  BOOST_CHECK_CLOSE(cmpShape[0]->getCenter().x, point.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape[0]->getCenter().y, point.y, epsilon);
  BOOST_CHECK_EQUAL(cmpShape[1], rectangle);
}

BOOST_AUTO_TEST_CASE(InvalidIndex_ThrownOutOfRange)
{
  gadzhiev::point_t point{ 3, 7 };

  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(32, gadzhiev::point_t { 1, 76 }));

  std::shared_ptr<gadzhiev::Shape> rectangle = std::make_shared<gadzhiev::Rectangle>(11, 13, point);
  cmpShape.add(rectangle);

  BOOST_CHECK_THROW(cmpShape[-1], std::out_of_range);
  BOOST_CHECK_THROW(cmpShape[2], std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShapeMove)

BOOST_AUTO_TEST_CASE(ValidMoveDxDy_CmpShapeCenterValidMoved)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(23, gadzhiev::point_t { -3, 8 }));
  const int dx = 4;
  const int dy = 9;
  cmpShape.move(dx, dy);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().x, -3 + dx, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().y, 8 + dy, epsilon);

  const int dxZero = 0;
  const int dyZero = 0;
  const gadzhiev::point_t previousCenter = cmpShape.getCenter();
  cmpShape.move(dxZero, dyZero);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().x, previousCenter.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().y, previousCenter.y, epsilon);
}

BOOST_AUTO_TEST_CASE(ValidMoveToPoint_CmpShapeCenterValidMoved)
{
  const gadzhiev::point_t center{ 2, 2 };
  const gadzhiev::point_t secondCenter{ 4, 4 };

  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(2, center));
  cmpShape.add(std::make_shared<gadzhiev::Circle>(2, secondCenter));

  gadzhiev::point_t previousCenter{ cmpShape.getCenter() };
  gadzhiev::point_t newCenter{ 7, 5 };

  cmpShape.move(newCenter);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().x, newCenter.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().y, newCenter.y, epsilon);
  BOOST_CHECK_CLOSE(cmpShape[0]->getCenter().x, center.x + cmpShape.getCenter().x - previousCenter.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape[0]->getCenter().y, center.y + cmpShape.getCenter().y - previousCenter.y, epsilon);

  gadzhiev::point_t newCenterInZero{ 0, 0 };
  cmpShape.move(newCenterInZero);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().x, newCenterInZero.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getCenter().y, newCenterInZero.y, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CompositeShapeFrameRectangle)

BOOST_AUTO_TEST_CASE(FrameRectangle_ValidWidthHeightCenterOfRectangle)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(10, gadzhiev::point_t { 1, 20 }));

  gadzhiev::rectangle_t rectangleStruct = cmpShape.getFrameRect();
  BOOST_CHECK_CLOSE(rectangleStruct.height, 20, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.width, 20, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.x, 1, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.y, 20, epsilon);
}

BOOST_AUTO_TEST_CASE(FrameRectangleAfterAdd_ValidWidthHeightCenterOfRectangle)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(2, gadzhiev::point_t { 4, 6 }));
  cmpShape.add(std::make_shared<gadzhiev::Rectangle>(7, 5, gadzhiev::point_t { -1, 2 }));

  gadzhiev::rectangle_t rectangleStruct = cmpShape.getFrameRect();
  BOOST_CHECK_CLOSE(rectangleStruct.height, 8.5, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.width, 10.5, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.x, 0.75, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.y, 3.75, epsilon);
}

BOOST_AUTO_TEST_CASE(FrameRectangleAfterScale_ValidWidthHeightCenterOfRectangle)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Circle>(10, gadzhiev::point_t { 1, 32 }));

  const double scaleCoef = 3.7;
  cmpShape.scale(scaleCoef);
  gadzhiev::rectangle_t rectangleStruct = cmpShape.getFrameRect();

  BOOST_CHECK_CLOSE(rectangleStruct.height, 20 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.width, 20 * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.x, 1, epsilon);
  BOOST_CHECK_CLOSE(rectangleStruct.pos.y, 32, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShapeScale)

BOOST_AUTO_TEST_CASE(InvalidScale_CoefLessThanZeroOrZero_ThrownInvalidArgument)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Rectangle>(13, 34, gadzhiev::point_t { -5, 18 }));
  BOOST_CHECK_THROW(cmpShape.scale(0), std::invalid_argument);
  BOOST_CHECK_THROW(cmpShape.scale(-12), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ValidScale_CoefMoreThanZero_CmpShapeValidScaled)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Rectangle>(2, 2, gadzhiev::point_t { 1, 3 }));
  cmpShape.add(std::make_shared<gadzhiev::Rectangle>(4, 4, gadzhiev::point_t{ 3.5, 0.5 }));

  gadzhiev::rectangle_t rectangleStruct = cmpShape.getFrameRect();

  const double scaleCoef = 0.65;
  cmpShape.scale(scaleCoef);

  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().height, rectangleStruct.height * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().width, rectangleStruct.width * scaleCoef, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().pos.x, rectangleStruct.pos.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().pos.y, rectangleStruct.pos.y, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShapeArea)

BOOST_AUTO_TEST_CASE(DefaultArea_ValidGetArea)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Rectangle>(13, 34, gadzhiev::point_t{ -5, 18 }));
  BOOST_CHECK_CLOSE(cmpShape.getArea(), 13 * 34, 0.0000001);
}

BOOST_AUTO_TEST_CASE(AreaAfterAddingFigures_ValidGetArea)
{
  gadzhiev::Shape::ShapePtr rectangle = std::make_shared<gadzhiev::Rectangle>(21, 4, gadzhiev::point_t{ -5, 18 });
  gadzhiev::Shape::ShapePtr circle = std::make_shared<gadzhiev::Circle>(12, gadzhiev::point_t{ 1, 6 });
  gadzhiev::Shape::ShapePtr secondCircle = std::make_shared<gadzhiev::Circle>(10, gadzhiev::point_t{ -1, 3 });

  gadzhiev::CompositeShape cmpShape(rectangle);
  cmpShape.add(circle);
  cmpShape.add(secondCircle);

  const double areaOfFirstFigure = rectangle->getArea();
  const double areaOfSecondFigure = circle->getArea();
  const double areaOfThirdFigure = secondCircle->getArea();

  BOOST_CHECK_CLOSE(cmpShape.getArea(), areaOfFirstFigure + areaOfSecondFigure + areaOfThirdFigure, 0.0000001);
}

BOOST_AUTO_TEST_CASE(AreaAfterMoving_AreaNotChanged)
{
  gadzhiev::Shape::ShapePtr rectangle = std::make_shared<gadzhiev::Rectangle>(21, 4, gadzhiev::point_t{ -5, 18 });
  gadzhiev::CompositeShape cmpShape(rectangle);

  const gadzhiev::point_t newCenter{ 12, -33 };
  const double dx = 6;
  const double dy = -34;
  const double area = cmpShape.getArea();

  cmpShape.move(dx, dy);

  BOOST_CHECK_CLOSE(cmpShape.getArea(), area, epsilon);

  cmpShape.move(newCenter);

  BOOST_CHECK_CLOSE(cmpShape.getArea(), area, epsilon);
}

BOOST_AUTO_TEST_CASE(AreaAfterScale_AreaChangedToSquaredCoef)
{
  gadzhiev::Shape::ShapePtr rectangle = std::make_shared<gadzhiev::Rectangle>(21, 4, gadzhiev::point_t{ -5, 18 });
  gadzhiev::Shape::ShapePtr circle = std::make_shared<gadzhiev::Circle>(12, gadzhiev::point_t{ 1, 6 });
  gadzhiev::Shape::ShapePtr secondCircle = std::make_shared<gadzhiev::Circle>(10, gadzhiev::point_t{ -1, 3 });

  gadzhiev::CompositeShape cmpShape(rectangle);
  cmpShape.add(circle);
  cmpShape.add(secondCircle);

  const double FirstShapeArea = rectangle->getArea();
  const double SecondShapeArea = circle->getArea();
  const double ThirdShapeArea = secondCircle->getArea();

  const double scaleCoef = 1.4;
  cmpShape.scale(scaleCoef);
  BOOST_CHECK_CLOSE(cmpShape.getArea(), scaleCoef * scaleCoef * (FirstShapeArea + SecondShapeArea + ThirdShapeArea), epsilon);
}

BOOST_AUTO_TEST_CASE(AreaAfterRotate_AreaNotChanged)
{
  gadzhiev::Shape::ShapePtr rectangle = std::make_shared<gadzhiev::Rectangle>(21, 4, gadzhiev::point_t{ -5, 18 });
  gadzhiev::CompositeShape cmpShape(rectangle);

  const double rotateCoef = 45;
  const double area = cmpShape.getArea();

  cmpShape.rotate(rotateCoef);

  BOOST_CHECK_CLOSE(cmpShape.getArea(), area, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CompositeShapeRotate)

BOOST_AUTO_TEST_CASE(CmpShapeRotate_ValidParametersOfFiguresAndValidFrameRect)
{
  gadzhiev::CompositeShape cmpShape(std::make_shared<gadzhiev::Rectangle>(4, 4, gadzhiev::point_t{ 2, 7 }));
  cmpShape.add(std::make_shared<gadzhiev::Rectangle>(2, 6, gadzhiev::point_t{ 3, 3 }));

  gadzhiev::rectangle_t rectangleStruct = cmpShape.getFrameRect();

  const double rotateCoef = 90;
  cmpShape.rotate(rotateCoef);

  BOOST_CHECK_CLOSE(cmpShape[0]->getCenter().x, -0.5, epsilon);
  BOOST_CHECK_CLOSE(cmpShape[0]->getCenter().y, 4.5, epsilon);
  BOOST_CHECK_CLOSE(cmpShape[1]->getCenter().x, 3.5, epsilon);
  BOOST_CHECK_CLOSE(cmpShape[1]->getCenter().y, 5.5, epsilon);

  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().width, 9, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().height, 4, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().width, 9, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().pos.x, rectangleStruct.pos.x, epsilon);
  BOOST_CHECK_CLOSE(cmpShape.getFrameRect().pos.y, rectangleStruct.pos.y, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()
