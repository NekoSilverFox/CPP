#include <boost/test/unit_test.hpp>
#include <memory>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <cmath>

const double accuracy = 0.00001;

// =====================test initialization shape=====================
BOOST_AUTO_TEST_SUITE(InitializeShape)

    BOOST_AUTO_TEST_CASE(InitializeShape_DefaultConstructors)
    {
      jianing::CompositeShape com_shape;

      BOOST_REQUIRE_EQUAL(0, com_shape.getSize());
      BOOST_REQUIRE_EQUAL(3, com_shape.getCapacity());
      BOOST_REQUIRE_EQUAL(true, com_shape.empty());
      BOOST_REQUIRE_EQUAL(0.0, com_shape.getCenter().x);
      BOOST_REQUIRE_EQUAL(0.0, com_shape.getCenter().y);
      BOOST_REQUIRE_EQUAL(0.0, com_shape.getArea());

      BOOST_CHECK_THROW(com_shape.removeShape(0), std::out_of_range);
      BOOST_CHECK_THROW(com_shape.printShape(), std::domain_error);
      BOOST_CHECK_THROW(com_shape.scale(0), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE(InitializeShape_DefaultParameterConstructorOnCorrectShape_NoError)
    {
      jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

      jianing::CompositeShape com_shape(circle);

      BOOST_REQUIRE_EQUAL(1, com_shape.getSize());
      BOOST_REQUIRE_EQUAL(3, com_shape.getCapacity());
      BOOST_REQUIRE_EQUAL(false, com_shape.empty());
      BOOST_CHECK_CLOSE(1.1, com_shape.getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, com_shape.getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, com_shape.getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(InitializeShape_DefaultParameterConstructorOnnullptr_ThrowError)
    {
      BOOST_CHECK_THROW(jianing::CompositeShape old_com_shape(nullptr), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(InitializeShape_TestCopyConstructor_NoError)
    {
      jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

      jianing::CompositeShape old_com_shape(circle);

      jianing::CompositeShape new_com_shape = old_com_shape;

      BOOST_REQUIRE_EQUAL(1, new_com_shape.getSize());
      BOOST_REQUIRE_EQUAL(3, new_com_shape.getCapacity());
      BOOST_REQUIRE_EQUAL(false, new_com_shape.empty());
      BOOST_CHECK_CLOSE(1.1, new_com_shape.getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, new_com_shape.getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, new_com_shape.getArea(), accuracy);

      BOOST_REQUIRE_EQUAL(1, old_com_shape.getSize());
      BOOST_REQUIRE_EQUAL(3, old_com_shape.getCapacity());
      BOOST_REQUIRE_EQUAL(false, old_com_shape.empty());
      BOOST_CHECK_CLOSE(1.1, old_com_shape.getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, old_com_shape.getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, old_com_shape.getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(InitializeShape_TestMoveConstructor_NoError)
    {
      jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

      jianing::CompositeShape old_com_shape(circle);

      jianing::CompositeShape new_com_shape = std::move(old_com_shape);

      BOOST_REQUIRE_EQUAL(1, new_com_shape.getSize());
      BOOST_REQUIRE_EQUAL(3, new_com_shape.getCapacity());
      BOOST_REQUIRE_EQUAL(false, new_com_shape.empty());
      BOOST_CHECK_CLOSE(1.1, new_com_shape.getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, new_com_shape.getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, new_com_shape.getArea(), accuracy);

      BOOST_REQUIRE_EQUAL(0, old_com_shape.getSize());
      BOOST_REQUIRE_EQUAL(0, old_com_shape.getCapacity());
      BOOST_REQUIRE_EQUAL(true, old_com_shape.empty());
      BOOST_REQUIRE_EQUAL(0.0, old_com_shape.getCenter().x);
      BOOST_REQUIRE_EQUAL(0.0, old_com_shape.getCenter().y);
      BOOST_REQUIRE_EQUAL(0.0, old_com_shape.getArea());
    }

    BOOST_AUTO_TEST_CASE(InitializeShape_OnWrongValue_ThrowError)
    {
      BOOST_CHECK_THROW(jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, -3.3)), std::domain_error);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test initialization shape(FrameRect)=====================
BOOST_AUTO_TEST_SUITE(TestFrameRectWhenInitializeShape)

  BOOST_AUTO_TEST_CASE(TestFrameRectWhenInitializeShape_DefaultConstructors_NoError)
  {
    jianing::CompositeShape com_shape;

    BOOST_REQUIRE_EQUAL(0.0, com_shape.getFrameRect().pos.x);
    BOOST_REQUIRE_EQUAL(0.0, com_shape.getFrameRect().pos.y);
    BOOST_REQUIRE_EQUAL(0.0, com_shape.getFrameRect().width);
    BOOST_REQUIRE_EQUAL(0.0, com_shape.getFrameRect().height);
  }

  BOOST_AUTO_TEST_CASE(TestFrameRectWhenInitializeShape_DefaultParameterConstructor_NoError)
  {
    jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

    jianing::CompositeShape com_shape(circle);

    BOOST_CHECK_CLOSE(1.1, com_shape.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE(2.2, com_shape.getFrameRect().pos.y, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, com_shape.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, com_shape.getFrameRect().height, accuracy);
  }

  BOOST_AUTO_TEST_CASE(TestFrameRectWhenInitializeShape_TestCopyConstructor_NoError)
  {
    jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

    jianing::CompositeShape old_com_shape(circle);

    jianing::CompositeShape new_com_shape = old_com_shape;

    BOOST_CHECK_CLOSE(1.1, new_com_shape.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE(2.2, new_com_shape.getFrameRect().pos.y, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, new_com_shape.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, new_com_shape.getFrameRect().height, accuracy);

    BOOST_CHECK_CLOSE(1.1, old_com_shape.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE(2.2, old_com_shape.getFrameRect().pos.y, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, old_com_shape.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, old_com_shape.getFrameRect().height, accuracy);
  }

  BOOST_AUTO_TEST_CASE(TestFrameRectWhenInitializeShape_TestMoveConstructor_NoError)
  {
    jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

    jianing::CompositeShape old_com_shape(circle);

    jianing::CompositeShape new_com_shape = std::move(old_com_shape);

    BOOST_CHECK_CLOSE(1.1, new_com_shape.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE(2.2, new_com_shape.getFrameRect().pos.y, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, new_com_shape.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(3.3 * 2.0, new_com_shape.getFrameRect().height, accuracy);

    BOOST_REQUIRE_EQUAL(0.0, old_com_shape.getFrameRect().pos.x);
    BOOST_REQUIRE_EQUAL(0.0, old_com_shape.getFrameRect().pos.y);
    BOOST_REQUIRE_EQUAL(0.0, old_com_shape.getFrameRect().width);
    BOOST_REQUIRE_EQUAL(0.0, old_com_shape.getFrameRect().height);
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test function pushShape=====================
BOOST_AUTO_TEST_SUITE(TestpushShape)

    BOOST_AUTO_TEST_CASE(TestpushShape_PushCorrectShape_NoError)
    {
      jianing::CompositeShape com_shape;
      jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

      com_shape.pushShape(circle);

      BOOST_CHECK_EQUAL(1, com_shape.getSize());
      BOOST_CHECK_EQUAL(3, com_shape.getCapacity());
      BOOST_CHECK_EQUAL(false, com_shape.empty());
      BOOST_CHECK_CLOSE(1.1, com_shape.getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, com_shape.getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, com_shape.getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(TestpushShape_PushNullptr_ThrowError)
    {
      jianing::CompositeShape com_shape;

      BOOST_CHECK_THROW(com_shape.pushShape(nullptr), std::invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test function pushShape(FrameRect)=====================
BOOST_AUTO_TEST_SUITE(TestFrameRectAfterpushShape)

    BOOST_AUTO_TEST_CASE(TestFrameRectAfterpushShape_PushCorrectShape_NoError)
    {
      jianing::CompositeShape com_shape;
      jianing::ShapePtr circle(new jianing::Circle({1.1, 2.2}, 3.3));

      com_shape.pushShape(circle);

      BOOST_CHECK_CLOSE(1.1, com_shape.getFrameRect().pos.x, accuracy);
      BOOST_CHECK_CLOSE(2.2, com_shape.getFrameRect().pos.y, accuracy);
      BOOST_CHECK_CLOSE(3.3 * 2.0, com_shape.getFrameRect().width, accuracy);
      BOOST_CHECK_CLOSE(3.3 * 2.0, com_shape.getFrameRect().height, accuracy);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test function removeShape=====================
BOOST_AUTO_TEST_SUITE(TestRemoveShape)

    BOOST_AUTO_TEST_CASE(TestRemoveShape_CorrectValueAfterPushShape_NoError)
    {
      jianing::CompositeShape com_shape;

      // push first shape
      jianing::ShapePtr circle(new jianing::Circle({1.2, 2.2}, 3.2));

      com_shape.pushShape(circle);

      // push second shape
      jianing::ShapePtr rectangle(new jianing::Rectangle({5.1, 9.3, 13.6, 21.3}));

      com_shape.pushShape(rectangle);

      //remove first shape
      com_shape.removeShape(0);

      BOOST_CHECK_EQUAL(1, com_shape.getSize());
      BOOST_CHECK_CLOSE(13.6, com_shape.getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(21.3, com_shape.getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(5.1 * 9.3, com_shape.getArea(), accuracy);

      //remove second shape
      com_shape.removeShape(0);

      BOOST_CHECK_EQUAL(0, com_shape.getSize());
      BOOST_CHECK_EQUAL(0.0, com_shape.getCenter().x);
      BOOST_CHECK_EQUAL(0.0, com_shape.getCenter().y);
      BOOST_CHECK_EQUAL(0.0, com_shape.getArea());
    }

    BOOST_AUTO_TEST_CASE(TestRemoveShape_RemoveShapeWhenArrayEmpty_ThrowError)
    {
      jianing::CompositeShape com_shape;

      BOOST_CHECK_THROW(com_shape.removeShape(0), std::out_of_range);

      // push one shape
      jianing::ShapePtr circle(new jianing::Circle({4.5, 7.7}, 8.9));

      com_shape.pushShape(circle);

      BOOST_CHECK_THROW(com_shape.removeShape(8), std::out_of_range);
    }
BOOST_AUTO_TEST_SUITE_END()

// =====================Test Frame Rect After Remove Shape=====================
BOOST_AUTO_TEST_SUITE(TestFrameRectAfterPushAndRemoveShape)

  BOOST_AUTO_TEST_CASE(TestFrameRectAfterRemoveShape_CorrectValueAfterPushShape_Noerror)
  {
    jianing::CompositeShape com_shape;

    // push first shape
    jianing::ShapePtr circle(new jianing::Circle({1.0, 2.0}, 1.0));

    com_shape.pushShape(circle);

    BOOST_CHECK_CLOSE(1.0, com_shape.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE(2.0, com_shape.getFrameRect().pos.y, accuracy);
    BOOST_CHECK_CLOSE(1.0 + 1.0, com_shape.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(1.0 + 1.0, com_shape.getFrameRect().height, accuracy);

    // push second shape
    jianing::ShapePtr rectangle(new jianing::Rectangle({1.0, 2.0, 0.5, 1.0}));

    com_shape.pushShape(rectangle);

    BOOST_CHECK_CLOSE((1.0 + 1.0) / 2, com_shape.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE((1.0 + 2.0) / 2, com_shape.getFrameRect().pos.y, accuracy);
    BOOST_CHECK_CLOSE(1.0 + 1.0, com_shape.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(1.0 + 2.0, com_shape.getFrameRect().height, accuracy);

    //remove first shape
    com_shape.removeShape(0);

    BOOST_CHECK_CLOSE(0.5, com_shape.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE(1.0, com_shape.getFrameRect().pos.y, accuracy);
    BOOST_CHECK_CLOSE(1.0, com_shape.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(2.0, com_shape.getFrameRect().height, accuracy);

    //remove second shape
    com_shape.removeShape(0);

    BOOST_CHECK_EQUAL(0.0, com_shape.getFrameRect().pos.x);
    BOOST_CHECK_EQUAL(0.0, com_shape.getFrameRect().pos.y);
    BOOST_CHECK_EQUAL(0.0, com_shape.getFrameRect().width);
    BOOST_CHECK_EQUAL(0.0, com_shape.getFrameRect().height);
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================Test size and capacity=====================
BOOST_AUTO_TEST_SUITE(TestSizeAndCapacity)

  BOOST_AUTO_TEST_CASE(TestSizeAndCapacity_OnCorrectValue_NoError)
  {
    jianing::CompositeShape com_shape;

    BOOST_CHECK_EQUAL(0, com_shape.getSize());
    BOOST_CHECK_EQUAL(3, com_shape.getCapacity());

    // push one shape
    jianing::ShapePtr first_rectangle(new jianing::Rectangle({3.3, 2.2, 3.5, 1.4}));

    com_shape.pushShape(first_rectangle);

    BOOST_CHECK_EQUAL(1, com_shape.getSize());
    BOOST_CHECK_EQUAL(3, com_shape.getCapacity());

    // push other three shape
    jianing::ShapePtr first_circle(new jianing::Circle({4.5, 6.7}, 3.4));
    jianing::ShapePtr sec_circle(new jianing::Circle({3.1, 4.5}, 9.2));
    jianing::ShapePtr sec_rectangle(new jianing::Rectangle({6.1, 4.3, 4.4, 9.8}));

    com_shape.pushShape(first_circle);
    com_shape.pushShape(sec_circle);
    com_shape.pushShape(sec_rectangle);

    BOOST_CHECK_EQUAL(4, com_shape.getSize());
    BOOST_CHECK_EQUAL(2 * 3, com_shape.getCapacity());

    // test resever
    com_shape.reserve(22);

    BOOST_CHECK_EQUAL(4, com_shape.getSize());
    BOOST_CHECK_EQUAL(22, com_shape.getCapacity());

    // reduce capacity
    com_shape.reserve(1);

    BOOST_CHECK_EQUAL(1, com_shape.getSize());
    BOOST_CHECK_EQUAL(1, com_shape.getCapacity());
    BOOST_CHECK_EQUAL(3.5, com_shape.getCenter().x);
    BOOST_CHECK_EQUAL(1.4, com_shape.getCenter().y);
    BOOST_CHECK_CLOSE(3.3 * 2.2, com_shape.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()
