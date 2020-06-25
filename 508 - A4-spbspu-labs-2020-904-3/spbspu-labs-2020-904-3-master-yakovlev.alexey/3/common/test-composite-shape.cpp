#include <stdexcept>
#include <memory>

#include <boost/test/unit_test.hpp>

#include "composite-shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"

namespace
{
  const double eps = 1e-10;
}

BOOST_AUTO_TEST_SUITE(CompositeShapeConstructor)

BOOST_AUTO_TEST_CASE(ValidArgument_ValidInitialization)
{
  yakovlev::point_t pos = { 1.0, -2.0 };
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, pos) };
  BOOST_CHECK_EQUAL(shape.getCenter(), pos);
}

BOOST_AUTO_TEST_CASE(ValidInitializerList_ValidInitialization)
{
  yakovlev::CompositeShape shape = {
    std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 1.0, -2.0 }),
    std::make_shared<yakovlev::Rectangle>(2.0, 1.0, yakovlev::point_t{ -23.3, 94.3 }),
    std::make_shared<yakovlev::Circle>(3.2, yakovlev::point_t{ -1.0, 1.0 })
  };
  BOOST_CHECK_EQUAL(shape.getSize(), 3);
}

BOOST_AUTO_TEST_CASE(InvalidPointer_ThrowsInvalidArgument)
{
  BOOST_CHECK_THROW(yakovlev::CompositeShape(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(yakovlev::CompositeShape({
      std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 1.0, -2.0 }),
      nullptr,
      std::make_shared<yakovlev::Circle>(3.2, yakovlev::point_t{ -1.0, 1.0 })
  }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(EmptyInitializerList_ThrowsInvalidArgument)
{
  BOOST_CHECK_THROW(yakovlev::CompositeShape({ }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CompositeShapeContainer)

BOOST_AUTO_TEST_CASE(Add_ValidArgument_ContainerExtends)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 1.2, yakovlev::point_t{ 4.3, 1.2 }) };
  std::shared_ptr<yakovlev::Rectangle> rectptr = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ -23.3, 94.3 });
  shape.add(rectptr);
  BOOST_CHECK_EQUAL(shape.getSize(), 2);
  BOOST_CHECK_EQUAL(shape[1], rectptr);
}

BOOST_AUTO_TEST_CASE(Add_ValidArgument_AreaIncreases)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  yakovlev::CompositeShape shape = { rectptr1 };
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ -23.3, 94.3 });
  shape.add(rectptr2);
  BOOST_CHECK_EQUAL(shape.getArea(), rectptr1->getArea() + rectptr2->getArea());
}

BOOST_AUTO_TEST_CASE(Add_Itself_ThrowsInvalidArgument)
{
  std::shared_ptr<yakovlev::CompositeShape> shape = std::make_shared<yakovlev::CompositeShape>(
      std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 123.0, 321.0 }));
  BOOST_CHECK_THROW(shape->add(shape), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Add_Nullptr_ThrowsInvalidArgument)
{
  std::shared_ptr<yakovlev::CompositeShape> shape = std::make_shared<yakovlev::CompositeShape>(
      std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 123.0, 321.0 }));
  BOOST_CHECK_THROW(shape->add(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Add_Twice_ThrowsInvalidArgument)
{
  std::shared_ptr<yakovlev::Rectangle> rec = std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 123.0, 321.0 });
  std::shared_ptr<yakovlev::CompositeShape> shape = std::make_shared<yakovlev::CompositeShape>(rec);
  BOOST_CHECK_THROW(shape->add(rec), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Remove_ValidIndex_ContainerShrinks)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 1.2, yakovlev::point_t{ 4.3, 1.2 }) };
  shape.add(std::make_shared<yakovlev::Circle>(1.2, yakovlev::point_t{ 0.0, 0.0 }));
  std::shared_ptr<yakovlev::Rectangle> rectptr = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ -23.3, 94.3 });
  shape.add(rectptr);
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ -1.0, 1.0 });
  shape.add(circleptr);
  shape.remove(1);
  BOOST_CHECK_EQUAL(shape.getSize(), 3);
  BOOST_CHECK_EQUAL(shape[1], rectptr);
  BOOST_CHECK_EQUAL(shape[2], circleptr);
}

BOOST_AUTO_TEST_CASE(Remove_ValidIndex_AreaDecreases)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  yakovlev::CompositeShape shape = { rectptr1 };
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ -23.3, 94.3 });
  shape.add(rectptr2);
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ -1.0, 1.0 });
  shape.add(circleptr);
  double oldarea = shape.getArea();
  shape.remove(0);
  BOOST_CHECK_EQUAL(shape.getArea(), oldarea - rectptr1->getArea());
}

BOOST_AUTO_TEST_CASE(Remove_InvalidIndex_ThrowsOutOfRange)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 1.2, yakovlev::point_t{ 4.3, 1.2 }) };
  std::shared_ptr<yakovlev::Rectangle> rectptr = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ -23.3, 94.3 });
  shape.add(rectptr);
  BOOST_CHECK_THROW(shape[5], std::out_of_range);
  BOOST_CHECK_THROW(shape[shape.getSize()], std::out_of_range);
  BOOST_CHECK_THROW(shape[-23], std::out_of_range);
  BOOST_CHECK_THROW(shape.remove(5), std::out_of_range);
  BOOST_CHECK_THROW(shape.remove(shape.getSize()), std::out_of_range);
  BOOST_CHECK_THROW(shape.remove(-23), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Remove_LastItem_ThrowsInvalidArgument)
{
  yakovlev::CompositeShape shape = {
      std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 123.0, 321.0 }) };
  BOOST_CHECK_THROW(shape.remove(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CompositeShapeFrame)

BOOST_AUTO_TEST_CASE(ValidShape_ValidFraming)
{
  double width = 3.42, height = 1.23;
  yakovlev::point_t pos = { 0.00312783, 323.2 };
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(width, height, pos) };
  yakovlev::rectangle_t frame = shape.getFrameRect();
  BOOST_CHECK_CLOSE(frame.width, width, eps);
  BOOST_CHECK_CLOSE(frame.height, height, eps);
  BOOST_CHECK_CLOSE(frame.pos.x, pos.x, eps);
  BOOST_CHECK_CLOSE(frame.pos.y, pos.y, eps);
}

BOOST_AUTO_TEST_CASE(Add_ValidShape_FrameUpdates)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  shape.add(std::make_shared<yakovlev::Circle>(4.0, yakovlev::point_t{ -2.0, -3.0 }));
  shape.add(std::make_shared<yakovlev::Triangle>(yakovlev::point_t{ 4.0, 5.0 }, yakovlev::point_t{ 6.0, 3.0 },
      yakovlev::point_t{ 2.0, -2.0 }));
  yakovlev::rectangle_t frame = shape.getFrameRect();
  BOOST_CHECK_CLOSE(frame.width, 12.0, eps);
  BOOST_CHECK_CLOSE(frame.height, 12.0, eps);
  yakovlev::point_t pos = { 0.0, -1.0 };
  BOOST_CHECK_CLOSE(frame.pos.x, pos.x, eps);
  BOOST_CHECK_CLOSE(frame.pos.y, pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CompositeShapeMove)

BOOST_AUTO_TEST_CASE(By_ValidArguments_CenterMoved)
{
  yakovlev::point_t center = { 83.3, -93.2 };
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, center) };
  double moveX = 312.4, moveY = 434.27;
  shape.move(moveX, moveY);
  yakovlev::point_t movedCenter = shape.getCenter();
  BOOST_CHECK_CLOSE(movedCenter.x, center.x + moveX, eps);
  BOOST_CHECK_CLOSE(movedCenter.y, center.y + moveY, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidPoint_CenterMoved)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  yakovlev::point_t newCenter = { 84.2, -1.4043 };
  shape.move(newCenter);
  yakovlev::point_t center = shape.getCenter();
  BOOST_CHECK_CLOSE(center.x, newCenter.x, eps);
  BOOST_CHECK_CLOSE(center.y, newCenter.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CompositeShapeMovePersistence)

BOOST_AUTO_TEST_CASE(By_ValidArguments_AreaPersists)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  double area = shape.getArea();
  shape.move(482.2, -645.5432);
  BOOST_CHECK_CLOSE(shape.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidPoint_AreaPersists)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  double area = shape.getArea();
  shape.move({ 432.3, 4523.21 });
  BOOST_CHECK_CLOSE(shape.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(By_ValidArguments_FramePersists)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  yakovlev::rectangle_t frame = shape.getFrameRect();
  shape.move(3.2, 45.532);
  yakovlev::rectangle_t movedFrame = shape.getFrameRect();
  BOOST_CHECK_CLOSE(movedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(movedFrame.height, frame.height, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidPoint_FramePersists)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  yakovlev::rectangle_t frame = shape.getFrameRect();
  shape.move({ -43.2, 5.532 });
  yakovlev::rectangle_t movedFrame = shape.getFrameRect();
  BOOST_CHECK_CLOSE(movedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(movedFrame.height, frame.height, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(CompositeShapeRotate)

BOOST_AUTO_TEST_CASE(AnyAngle_AreaPersists)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  shape.add(std::make_shared<yakovlev::Circle>(4.0, yakovlev::point_t{ -2.0, -3.0 }));
  shape.add(std::make_shared<yakovlev::Triangle>(yakovlev::point_t{ 4.0, 5.0 }, yakovlev::point_t{ 6.0, 3.0 },
      yakovlev::point_t{ 2.0, -2.0 }));
  double area = shape.getArea();
  shape.rotate(12);
  BOOST_CHECK_CLOSE(shape.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(AnyAngle_FrameUpdates)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  shape.add(std::make_shared<yakovlev::Circle>(4.0, yakovlev::point_t{ -2.0, -3.0 }));
  shape.add(std::make_shared<yakovlev::Triangle>(yakovlev::point_t{ 4.0, 5.0 }, yakovlev::point_t{ 6.0, 3.0 },
      yakovlev::point_t{ 2.0, -2.0 }));
  yakovlev::rectangle_t frame = shape.getFrameRect();
  shape.rotate(90);
  yakovlev::rectangle_t updatedFrame = shape.getFrameRect();
  BOOST_CHECK_CLOSE(updatedFrame.height, frame.width, eps);
  BOOST_CHECK_CLOSE(updatedFrame.width, frame.height, eps);
}

BOOST_AUTO_TEST_SUITE_END()


//=====================================================================================

BOOST_AUTO_TEST_SUITE(CompositeShapeScale)

BOOST_AUTO_TEST_CASE(ValidCoefficient_AreaScales)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  double area = shape.getArea();
  double coef = 1.534;
  shape.scale(coef);
  BOOST_CHECK_CLOSE(shape.getArea(), area * coef * coef, eps);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient_ThrowsInvalidArgument)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  BOOST_CHECK_THROW(shape.scale(-3.4), std::invalid_argument);
  BOOST_CHECK_THROW(shape.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ValidCoefficient_FrameUpdates)
{
  yakovlev::CompositeShape shape = { std::make_shared<yakovlev::Rectangle>(3.0, 2.0, yakovlev::point_t{ 0.0, 2.0 }) };
  yakovlev::rectangle_t frame = shape.getFrameRect();
  double coef = 432.32;
  shape.scale(coef);
  yakovlev::rectangle_t scaledFrame = shape.getFrameRect();
  BOOST_CHECK_CLOSE(scaledFrame.width, frame.width * coef, eps);
  BOOST_CHECK_CLOSE(scaledFrame.height, frame.height * coef, eps);
  BOOST_CHECK_CLOSE(scaledFrame.pos.x, frame.pos.x, eps);
  BOOST_CHECK_CLOSE(scaledFrame.pos.y, frame.pos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()
