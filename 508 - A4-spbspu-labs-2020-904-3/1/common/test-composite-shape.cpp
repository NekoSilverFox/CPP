#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "composite-shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

const double EPSILON = 0.00000001;

BOOST_AUTO_TEST_SUITE(CompositeShapeTest)

  BOOST_AUTO_TEST_SUITE(CompositeShape_CompositeShapeConstructor)

    BOOST_AUTO_TEST_CASE(CompositeShape_NoParameters_NoException)
    {
      BOOST_CHECK_NO_THROW(samokhin::CompositeShape());
    }

    BOOST_AUTO_TEST_CASE(CompositeShape_ValidCompositeShapeAsParameter_NoException)
    {
      double width = 1.2;
      double height = 5.3;
      samokhin::point_t pos = {3.2, 7.4};

      samokhin::Rectangle rectangle(width, height, pos);
      samokhin::CompositeShape compositeShape{};
      compositeShape.add(std::make_shared<samokhin::Rectangle>(rectangle));

      BOOST_CHECK_NO_THROW(samokhin::CompositeShape{compositeShape});
    }

    BOOST_AUTO_TEST_CASE(CompositeShape_EmptyCompositeShapeAsParameter_NoException)
    {
      samokhin::CompositeShape compositeShape{};
      BOOST_CHECK_NO_THROW(samokhin::CompositeShape{compositeShape});
    }

    BOOST_AUTO_TEST_CASE(CompositeShape_RectangleAsParameter_NoException)
    {
      double width = 0.2;
      double height = 4.3;
      samokhin::point_t pos = {-3.1, 3.4};

      samokhin::Rectangle rectangle(width, height, pos);

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(std::make_shared<samokhin::Rectangle>(rectangle));
    }

    BOOST_AUTO_TEST_CASE(CompositeShape_CircleAsParameter_NoException)
    {
      double radius = 3.23;
      samokhin::point_t pos = {4.1, 3.4};

      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, pos));
      samokhin::CompositeShape compositeShape{};

      BOOST_CHECK_NO_THROW(compositeShape.add(circle));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_GetArea)

    BOOST_AUTO_TEST_CASE(GetArea_RightArea)
    {
      double width = 4.3;
      double height = 2.5;
      samokhin::point_t center = {5.1, 3.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 7.2;
      double x = 2.4;
      double y = -9.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double expectedArea = rectangle->getArea() + circle->getArea();

      BOOST_CHECK_CLOSE(compositeShape.getArea(), expectedArea, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(GetArea_ShapeAfterMove_ExcepitonThrown)
    {
      double width = 1.8;
      double height = 9.2;
      samokhin::point_t center = {2.1, 3.8};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);

      samokhin::CompositeShape compositeShape2 = std::move(compositeShape);

      BOOST_CHECK_THROW(compositeShape.getArea(), std::domain_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_GetFrameRect)

    BOOST_AUTO_TEST_CASE(GetFrameRect_EmptyCompositeShape_NegativeWidthAndHeight)
    {
      samokhin::CompositeShape compositeShape{};
      BOOST_CHECK_CLOSE(compositeShape.getFrameRect().width, -1, EPSILON);
      BOOST_CHECK_CLOSE(compositeShape.getFrameRect().height, -1, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(GetFrameRect_ValidCompositeShape_RightFrameRect)
    {
      double width = 5.0;
      double height = 3.0;
      samokhin::point_t center = {4.5, 3.5};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 2.0;
      double x = 7.0;
      double y = 6.0;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      samokhin::rectangle_t expectedFrame = {{5.5, 5.0}, 7.0, 6.0};
      samokhin::rectangle_t frame = compositeShape.getFrameRect();
      BOOST_CHECK_CLOSE(expectedFrame.pos.x, frame.pos.x, EPSILON);
      BOOST_CHECK_CLOSE(expectedFrame.pos.y, frame.pos.y, EPSILON);
      BOOST_CHECK_CLOSE(expectedFrame.width, frame.width, EPSILON);
      BOOST_CHECK_CLOSE(expectedFrame.height, frame.height, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(GetFrameRect_ShapeAfterMove_ExcepitonThrown)
    {
      double width = 6.8;
      double height = 9.3;
      samokhin::point_t center = {2.7, 3.22};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);

      samokhin::CompositeShape compositeShape2 = std::move(compositeShape);

      BOOST_CHECK_THROW(compositeShape.getFrameRect(), std::domain_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_Move_ByCords)

    BOOST_AUTO_TEST_CASE(Move_EmptyCompositeShapeAtMovingByCords_NoException)
    {
      double dx = 3.0;
      double dy = 2.6;
      samokhin::CompositeShape compositeShape{};
      BOOST_CHECK_NO_THROW(compositeShape.move(dx, dy));
    }

    BOOST_AUTO_TEST_CASE(Move_CompositeShapesFrameAtMovingByCords_ConstantFrame)
    {
      double width = 4.6;
      double height = 3.5;
      samokhin::point_t center = {8.1, 1.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.2;
      double x = 2.8;
      double y = 9.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double dx = 3.0;
      double dy = 2.6;
      samokhin::rectangle_t frame = compositeShape.getFrameRect();
      compositeShape.move(dx, dy);
      samokhin::rectangle_t newFrame = compositeShape.getFrameRect();
      samokhin::point_t newCentre = {frame.pos.x + dx, frame.pos.y + dy};

      BOOST_CHECK_CLOSE(frame.width, newFrame.width, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.height, EPSILON);

      BOOST_CHECK_CLOSE(newCentre.x, newFrame.pos.x, EPSILON);
      BOOST_CHECK_CLOSE(newCentre.y, newFrame.pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_CompositeShapesAreaAtMovingByCords_ConstantArea)
    {
      double width = 6.3;
      double height = 5.1;
      samokhin::point_t center = {1.9, 4.19};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.2;
      double x = 2.2;
      double y = 9.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double area = compositeShape.getArea();
      double dx = 2.6;
      double dy = 9.4;
      compositeShape.move(dx, dy);
      BOOST_CHECK_CLOSE(compositeShape.getArea(), area, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_ShapeAfterMove_ExcepitonThrown)
    {
      double width = 1.2;
      double height = 6.1;
      samokhin::point_t center = {4.1, 3.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);

      samokhin::CompositeShape compositeShape2 = std::move(compositeShape);

      double dx = 7.6;
      double dy = 5.4;
      BOOST_CHECK_THROW(compositeShape.move(dx, dy), std::domain_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_Move_AtPoint)

    BOOST_AUTO_TEST_CASE(Move_EmptyCompositeShapeAtMovingAtPoint_ExceptionThrown)
    {
      samokhin::point_t center = {6.1, 6.2};
      samokhin::CompositeShape compositeShape{};
      BOOST_CHECK_NO_THROW(compositeShape.move(center));
    }

    BOOST_AUTO_TEST_CASE(Move_CompositeShapesFrameAtMovingAtPoint_ConstantFrame)
    {
      double width = 1.6;
      double height = 3.1;
      samokhin::point_t center = {6.1, 6.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.3;
      double x = 2.2;
      double y = 3.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      samokhin::point_t newCentre = {3.0, 2.6};
      samokhin::rectangle_t frame = compositeShape.getFrameRect();
      compositeShape.move(newCentre);
      samokhin::rectangle_t newFrame = compositeShape.getFrameRect();

      BOOST_CHECK_CLOSE(frame.width, newFrame.width, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.height, EPSILON);

      BOOST_CHECK_CLOSE(newCentre.x, newFrame.pos.x, EPSILON);
      BOOST_CHECK_CLOSE(newCentre.y, newFrame.pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_CompositeShapesAreaAtMovingAtPoint_ConstantArea)
    {
      double width = 1.6;
      double height = 3.1;
      samokhin::point_t center = {6.1, 6.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.3;
      double x = 2.2;
      double y = 3.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      samokhin::point_t newCentre = {3.0, 2.6};

      double area = compositeShape.getArea();
      compositeShape.move(newCentre);

      BOOST_CHECK_CLOSE(compositeShape.getArea(), area, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Move_ShapeAfterMove_ExcepitonThrown)
    {
      double width = 22.2;
      double height = 4.1;
      samokhin::point_t center = {4.1, 3.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);

      samokhin::CompositeShape compositeShape2 = std::move(compositeShape);

      samokhin::point_t newCenter = {6.1, 6.2};
      BOOST_CHECK_THROW(compositeShape.move(newCenter), std::domain_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_Scale)

    BOOST_AUTO_TEST_CASE(Scale_NegativeNumberAsScaleCoefficient_ExceptionThrown)
    {
      double width = 8.6;
      double height = 3.8;
      samokhin::point_t center = {6.2, 5.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.1;
      double x = 23.6;
      double y = 3.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double k = -9;
      BOOST_CHECK_THROW(compositeShape.scale(k), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(Scale_PositiveNumberAsScaleCoefficient_NoException)
    {
      double width = 1.5;
      double height = 9.8;
      samokhin::point_t center = {6.2, 5.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.2;
      double x = 23.6;
      double y = 3.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double k = 6.1;
      BOOST_CHECK_NO_THROW(compositeShape.scale(k));
    }

    BOOST_AUTO_TEST_CASE(Scale_ZeroAsScaleCoefficient_NoException)
    {
      double width = 9.8;
      double height = 1.5;
      samokhin::point_t center = {1.2, 5.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 7.2;
      double x = 32.6;
      double y = 3.6;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double k = 0.0;
      BOOST_CHECK_NO_THROW(compositeShape.scale(k));
    }

    BOOST_AUTO_TEST_CASE(Scale_CompositeShapeArea_SquareAreaChange)
    {
      double width = 2.5;
      double height = 9.2;
      samokhin::point_t center = {1.2, 5.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double area = compositeShape.getArea();
      double k = 1.1;
      compositeShape.scale(k);

      BOOST_CHECK_CLOSE(compositeShape.getArea(), area * k * k, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Scale_ShapeAfterMove_ExcepitonThrown)
    {
      double width = 1.2;
      double height = 63.1;
      samokhin::point_t center = {7.1, 3.1};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);

      samokhin::CompositeShape compositeShape2 = std::move(compositeShape);

      double k = 0.1;
      BOOST_CHECK_THROW(compositeShape.scale(k), std::domain_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_Add)

    BOOST_AUTO_TEST_CASE(Add_ValidShapesAsParameter_NoException)
    {
      double width = 2.5;
      double height = 9.2;
      samokhin::point_t center = {1.2, 5.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};

      BOOST_CHECK_NO_THROW(compositeShape.add(circle));
      BOOST_CHECK_NO_THROW(compositeShape.add(rectangle));
    }

    BOOST_AUTO_TEST_CASE(Add_EmptyCompositeShapeAsParameter_NoException)
    {
      samokhin::CompositeShape emptyCompositeShape{};
      samokhin::CompositeShape compositeShape{};
      BOOST_CHECK_NO_THROW(compositeShape.add(std::make_shared<samokhin::CompositeShape>(emptyCompositeShape)));
    }

    BOOST_AUTO_TEST_CASE(Add_ValidShapesAsParameter_CorrectAddition)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};

      compositeShape.add(circle);

      BOOST_CHECK_EQUAL(compositeShape.getSize(), 1);
      BOOST_CHECK_EQUAL(compositeShape[0], circle);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_Remove)

    BOOST_AUTO_TEST_CASE(Remove_TooBigIndexAsParameter_ExceptionThrown)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(circle);

      BOOST_CHECK_THROW(compositeShape.remove(1), std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(Remove_RemoveFromEmptyShape_ExceptionThrown)
    {
      samokhin::CompositeShape compositeShape{};
      BOOST_CHECK_THROW(compositeShape.remove(1), std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(Remove_ValidIndexAsParameter_NoException)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(circle);

      BOOST_CHECK_NO_THROW(compositeShape.remove(0));
    }

    BOOST_AUTO_TEST_CASE(Remove_ValidIndexAsParameter_CorrectRemove)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(circle);
      compositeShape.remove(0);

      BOOST_CHECK_EQUAL(compositeShape.getSize(), 0);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_IndexOperator)

    BOOST_AUTO_TEST_CASE(IndexOperator_InvalidIndexAsParameter_ExceptionThrown)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(circle);
      size_t invalidIndex = 2;
      BOOST_CHECK_THROW(compositeShape[invalidIndex], std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(IndexOperator_RightIndexAsParameter_NoException)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(circle);

      size_t validIndex = 0;
      BOOST_CHECK_NO_THROW(compositeShape[validIndex]);
    }

    BOOST_AUTO_TEST_CASE(IndexOperator_RightIndexAsParameter_RightShape)
    {
      double radius = 9.3;
      double x = 5.2;
      double y = 1.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(circle);

      samokhin::rectangle_t frame = compositeShape[0]->getFrameRect();
      samokhin::point_t centre = frame.pos;

      BOOST_CHECK_CLOSE(compositeShape[0]->getArea(), circle->getArea(), EPSILON);
      BOOST_CHECK_CLOSE(frame.width, 2 * radius, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, 2 * radius, EPSILON);
      BOOST_CHECK_CLOSE(centre.x, x, EPSILON);
      BOOST_CHECK_CLOSE(centre.y, y, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(CompositeShape_Rotate)

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_ConstantArea)
    {
      double width = 2.1;
      double height = 9.3;
      samokhin::point_t center = {2.2, 1.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.3;
      double x = 1.2;
      double y = 3.2;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double area = compositeShape.getArea();
      double angle = 80.0;
      compositeShape.rotate(angle);
      BOOST_CHECK_CLOSE(area, compositeShape.getArea(), EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Rotate_AnyAngleAsParameter_RightFrameChange)
    {
      double width = 3.1;
      double height = 9.2;
      samokhin::point_t center = {1.2, 1.8};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      double radius = 1.3;
      double x = 6.2;
      double y = 3.3;
      std::shared_ptr<samokhin::Circle> circle(new samokhin::Circle(radius, {x, y}));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);
      compositeShape.add(circle);

      double angle = -90;
      samokhin::rectangle_t frame = compositeShape.getFrameRect();
      compositeShape.rotate(angle);
      samokhin::rectangle_t newFrame = compositeShape.getFrameRect();
      BOOST_CHECK_CLOSE(frame.width, newFrame.height, EPSILON);
      BOOST_CHECK_CLOSE(frame.height, newFrame.width, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(Rotate_ShapeAfterMove_ExcepitonThrown)
    {
      double width = 4.5;
      double height = 5.1;
      samokhin::point_t center = {-3.1, 3.2};
      std::shared_ptr<samokhin::Rectangle> rectangle(new samokhin::Rectangle(width, height, center));

      samokhin::CompositeShape compositeShape{};
      compositeShape.add(rectangle);

      samokhin::CompositeShape compositeShape2 = std::move(compositeShape);

      double angle = 9;
      BOOST_CHECK_THROW(compositeShape.rotate(angle), std::domain_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
