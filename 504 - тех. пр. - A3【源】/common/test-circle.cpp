#include <boost/test/unit_test.hpp>
#include "circle.hpp"
#include <cmath>

const double accuracy = 0.00001;

// =====================test initialization circle=====================
BOOST_AUTO_TEST_SUITE(InitializeCircle)

  BOOST_AUTO_TEST_CASE(InitializeCircle_OnCorrectValue_NoError)
  {
    jianing::Circle circle {{1.1, 1.2}, 3.5};

    BOOST_REQUIRE_EQUAL(1.1, circle.getCenter().x);
    BOOST_REQUIRE_EQUAL(1.2, circle.getCenter().y);
    BOOST_REQUIRE_EQUAL(3.5, circle.getRadius());
    BOOST_CHECK_CLOSE(M_PI * 3.5 * 3.5, circle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(InitializeCircle_OnWrongValue_ThrowError)
  {
    BOOST_CHECK_THROW(jianing::Circle({3.10, 4.15}, 0.0), std::domain_error);
    BOOST_CHECK_THROW(jianing::Circle({3.10, 4.15}, -9.9), std::domain_error);
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test initialization circle(FrameRect)=====================
BOOST_AUTO_TEST_SUITE(TestFrameRectWhenInitializeCircle)
  BOOST_AUTO_TEST_CASE(TestFrameRectWhenInitializeCircle_OnCorrectValue_NoError)
  {
    jianing::Circle circle {{1.1, 1.2}, 3.5};

    BOOST_CHECK_CLOSE(3.5 * 2.0, circle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(3.5 * 2.0, circle.getFrameRect().height, accuracy);
    BOOST_REQUIRE_EQUAL(1.1, circle.getFrameRect().pos.x);
    BOOST_REQUIRE_EQUAL(1.2, circle.getFrameRect().pos.y);
  }
BOOST_AUTO_TEST_SUITE_END()

// =====================test move circle=====================
BOOST_AUTO_TEST_SUITE(MoveCirle)

  BOOST_AUTO_TEST_CASE(MoveCirle_ToPointXY_CorrectCenterAfterMove)
  {
    jianing::Circle circle {{10.0, 0.0}, 5.0};

    circle.move({-10.0, -20.0});

    BOOST_CHECK_EQUAL(-10.0, circle.getCenter().x);
    BOOST_CHECK_EQUAL(-20.0, circle.getCenter().y);
    BOOST_CHECK_EQUAL(5.0, circle.getRadius());
    BOOST_CHECK_CLOSE(M_PI * 5.0 * 5.0, circle.getArea(), accuracy);
  }

  BOOST_AUTO_TEST_CASE(MoveCirle_Bydxdy_CorrectCenterAfterMove)
  {
    jianing::Circle circle {{-5.1, 5.2}, 2.5};

    circle.move(5.0, -5.0);

    BOOST_CHECK_CLOSE(-5.1 + 5.0, circle.getCenter().x, accuracy);
    BOOST_CHECK_CLOSE(5.2 - 5.0, circle.getCenter().y, accuracy);
    BOOST_CHECK_CLOSE(M_PI * 2.5 * 2.5, circle.getArea(), accuracy);
    BOOST_CHECK_EQUAL(2.5, circle.getRadius());
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test move circle(FrameRect)=====================
BOOST_AUTO_TEST_SUITE(TestFrameRectAfterMoveCirle)

  BOOST_AUTO_TEST_CASE(TestFrameRectAfterMoveCirle_ToPointXY_CorrectFrameAfterMove)
  {
    jianing::Circle circle {{10.0, 0.0}, 5.0};

    circle.move({-10.0, -20.0});

    BOOST_CHECK_CLOSE(5.0 * 2.0, circle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(5.0 * 2.0, circle.getFrameRect().height, accuracy);
    BOOST_CHECK_EQUAL(-10.0, circle.getFrameRect().pos.x);
    BOOST_CHECK_EQUAL(-20.0, circle.getFrameRect().pos.y);
  }

  BOOST_AUTO_TEST_CASE(TestFrameRectAfterMoveCirle_Bydxdy_CorrectFrameAfterMove)
  {
    jianing::Circle circle {{-5.1, 5.2}, 2.5};

    circle.move(5.0, -5.0);

    BOOST_CHECK_CLOSE(2.5 * 2.0, circle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(2.5 * 2.0, circle.getFrameRect().height, accuracy);
    BOOST_CHECK_CLOSE(-5.1 + 5.0, circle.getFrameRect().pos.x, accuracy);
    BOOST_CHECK_CLOSE(5.2 - 5.0, circle.getFrameRect().pos.y, accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test scale circle=====================
BOOST_AUTO_TEST_SUITE(ScaleCircle)

  BOOST_AUTO_TEST_CASE(ScaleCircle_OnWrongCoefficientNegativeOrZero_ThrowError)
  {
    jianing::Circle circle {{3.10, 4.15}, 9.26};

    BOOST_CHECK_THROW(circle.scale(0.0), std::domain_error);
    BOOST_CHECK_THROW(circle.scale(-1.8), std::domain_error);
  }

  BOOST_AUTO_TEST_CASE(ScaleCircle_OnCorrectCoefficient_CorrectRadiusAfterScale)
  {
    jianing::Circle circle {{3.3, -3.3}, 1.5};

    circle.scale(2.2);

    BOOST_CHECK_EQUAL(3.3, circle.getCenter().x);
    BOOST_CHECK_EQUAL(-3.3, circle.getCenter().y);
    BOOST_CHECK_CLOSE(1.5 * 2.2, circle.getRadius(), accuracy);
    BOOST_CHECK_CLOSE(M_PI * 1.5 * 2.2 * 1.5 *2.2, circle.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test scale circle(FrameRect)=====================
BOOST_AUTO_TEST_SUITE(TestFrameRectAfterScaleCircle)

  BOOST_AUTO_TEST_CASE(TestFrameRectAfterScaleCircle_OnCorrectCoefficient_CorrectFrameAfterScale)
  {
    jianing::Circle circle {{3.3, -3.3}, 1.5};

    circle.scale(2.2);

    BOOST_CHECK_CLOSE(1.5 * 2.0 * 2.2, circle.getFrameRect().width, accuracy);
    BOOST_CHECK_CLOSE(1.5 * 2.0 * 2.2, circle.getFrameRect().height, accuracy);
    BOOST_CHECK_EQUAL(3.3, circle.getFrameRect().pos.x);
    BOOST_CHECK_EQUAL(-3.3, circle.getFrameRect().pos.y);
  }

BOOST_AUTO_TEST_SUITE_END()
