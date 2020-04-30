#include <boost/test/unit_test.hpp>
#include "circle.hpp"
#include <cmath>

const double accuracy = 0.00001;

// =====================test_initialization_circle=====================
BOOST_AUTO_TEST_SUITE(test_initialize_circle)

  BOOST_AUTO_TEST_CASE(initialize_circle)
  {
    jianing::Circle circle {{1.1, 1.2}, 3.5};

    BOOST_REQUIRE_EQUAL(1.1, circle.getCenter().x);
    BOOST_REQUIRE_EQUAL(1.2, circle.getCenter().y);
    BOOST_REQUIRE_EQUAL(3.5, circle.getRadius());
    BOOST_REQUIRE_EQUAL(M_PI * 3.5 * 3.5, circle.getArea());
  }

  BOOST_AUTO_TEST_CASE(initialize_circle_on_invalid_coefficient)
  {
    BOOST_CHECK_THROW(jianing::Circle({3.10, 4.15}, 0.0), std::domain_error);
    BOOST_CHECK_THROW(jianing::Circle({3.10, 4.15}, -9.9), std::domain_error);
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test_move_circle=====================
BOOST_AUTO_TEST_SUITE(test_move_circle)

  BOOST_AUTO_TEST_CASE(moving_circle_to_a_point_x_y)
  {
    jianing::Circle circle {{10.0, 0.0}, 5.0};

    circle.move({-10.0, -20.0});

    BOOST_CHECK_EQUAL(-10.0, circle.getCenter().x);
    BOOST_CHECK_EQUAL(-20.0, circle.getCenter().y);
    BOOST_CHECK_EQUAL(5.0, circle.getRadius());
    BOOST_CHECK_EQUAL(M_PI * 5.0 * 5.0, circle.getArea());
  }

  BOOST_AUTO_TEST_CASE(moving_circle_by_dx_dy)
  {
    jianing::Circle circle {{-5.1, 5.2}, 2.5};

    circle.move(5.0, -5.0);

    BOOST_CHECK_EQUAL(-5.1 + 5.0, circle.getCenter().x);
    BOOST_CHECK_EQUAL(5.2 - 5.0, circle.getCenter().y);
    BOOST_CHECK_EQUAL(2.5, circle.getRadius());
    BOOST_CHECK_EQUAL(M_PI * 2.5 * 2.5, circle.getArea());
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test_scale_circle=====================
BOOST_AUTO_TEST_SUITE(test_scale_circle)

  BOOST_AUTO_TEST_CASE(circle_scale_on_invalid_coefficient)
  {
    jianing::Circle circle {{3.10, 4.15}, 9.26};
    BOOST_CHECK_THROW(circle.scale(0.0), std::domain_error);
    BOOST_CHECK_THROW(circle.scale(-1.8), std::domain_error);
  }

  BOOST_AUTO_TEST_CASE(changing_circle_size_by_coefficient)
  {
    jianing::Circle circle {{3.3, -3.3}, 1.5};

    circle.scale(2.2);

    BOOST_CHECK_EQUAL(3.3, circle.getCenter().x);
    BOOST_CHECK_EQUAL(-3.3, circle.getCenter().y);
    BOOST_CHECK_CLOSE(1.5 * 2.2, circle.getRadius(), accuracy);
    BOOST_CHECK_CLOSE(M_PI * 1.5 * 2.2 * 1.5 *2.2, circle.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()
