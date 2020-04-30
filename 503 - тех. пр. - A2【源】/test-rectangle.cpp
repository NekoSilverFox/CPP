#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"

const double accuracy = 0.00001;

// =====================test_initialization_rectangle=====================
BOOST_AUTO_TEST_SUITE(test_initialize_rectangle)

  BOOST_AUTO_TEST_CASE(initialize_rectangle)
  {
    jianing::Rectangle rectangle {{1.1, 2.2, 3.3, 4.4}};

    BOOST_REQUIRE_EQUAL(1.1, rectangle.getWidth());
    BOOST_REQUIRE_EQUAL(2.2, rectangle.getHeight());
    BOOST_REQUIRE_EQUAL(3.3, rectangle.getCenter().x);
    BOOST_REQUIRE_EQUAL(4.4, rectangle.getCenter().y);
    BOOST_REQUIRE_EQUAL(1.1 * 2.2, rectangle.getArea());
  }

  BOOST_AUTO_TEST_CASE(initialize_rectangle_on_invalid_coefficient)
  {
    BOOST_CHECK_THROW(jianing::Rectangle({-1.1, 2.1, 3.1, 4.1}), std::domain_error);
    BOOST_CHECK_THROW(jianing::Rectangle({1.2, -2.2, 3.2, 4.2}), std::domain_error);
    BOOST_CHECK_THROW(jianing::Rectangle({-1.3, -2.3, 3.3, 4.3}), std::domain_error);
    BOOST_CHECK_THROW(jianing::Rectangle({0.0, 2.4, 3.4, 4.4}), std::domain_error);
    BOOST_CHECK_THROW(jianing::Rectangle({1.5, 0.0, 3.5, 4.5}), std::domain_error);
    BOOST_CHECK_THROW(jianing::Rectangle({0.0, 0.0, 3.6, 4.6}), std::domain_error);
    BOOST_CHECK_THROW(jianing::Rectangle({-1.7, 0.0, 3.7, 4.7}), std::domain_error);
    BOOST_CHECK_THROW(jianing::Rectangle({0.0, -2.8, 3.8, 4.8}), std::domain_error);
  }

BOOST_AUTO_TEST_SUITE_END()

// =====================test_move_rectangle=====================
BOOST_AUTO_TEST_SUITE(test_move_rectangle)
  BOOST_AUTO_TEST_CASE(moving_rectangle_to_a_point_x_y)
  {
    jianing::Rectangle rectangle {{5.1, 10.1, 3.1, 4.1}};

    rectangle.move({10.9, 5.9});

    BOOST_CHECK_EQUAL(5.1, rectangle.getWidth());
    BOOST_CHECK_EQUAL(10.1, rectangle.getHeight());
    BOOST_CHECK_EQUAL(10.9, rectangle.getCenter().x);
    BOOST_CHECK_EQUAL(5.9, rectangle.getCenter().y);
    BOOST_CHECK_EQUAL(5.1 * 10.1, rectangle.getArea());
  }

  BOOST_AUTO_TEST_CASE(moving_rectangle_by_dx_dy)
  {
    jianing::Rectangle rectangle {{1.1, 2.2, 3.3, 4.4}};

    rectangle.move(-0.8, 0.9);

    BOOST_CHECK_EQUAL(1.1, rectangle.getWidth());
    BOOST_CHECK_EQUAL(2.2, rectangle.getHeight());
    BOOST_CHECK_EQUAL(3.3 - 0.8, rectangle.getCenter().x);
    BOOST_CHECK_EQUAL(4.4 + 0.9, rectangle.getCenter().y);
    BOOST_CHECK_EQUAL(1.1 * 2.2, rectangle.getArea());
  }
BOOST_AUTO_TEST_SUITE_END()

// =====================test_scale_rectangle=====================
BOOST_AUTO_TEST_SUITE(test_scale_rectangle)
  BOOST_AUTO_TEST_CASE(rectangle_scale_on_invalid_coefficient)
  {
    jianing::Rectangle rectangle = {{14.15, 9.26, 0.9, 4.8}};
    BOOST_CHECK_THROW(rectangle.scale(0.0), std::domain_error);
    BOOST_CHECK_THROW(rectangle.scale(-5.7), std::domain_error);
  }

  BOOST_AUTO_TEST_CASE(changing_rectangle_size_by_coefficient)
  {
    jianing::Rectangle rectangle {{5.5, 6.6, 7.7, 8.8}};

    rectangle.scale(2.1);

    BOOST_CHECK_EQUAL(7.7, rectangle.getCenter().x);
    BOOST_CHECK_EQUAL(8.8, rectangle.getCenter().y);
    BOOST_CHECK_CLOSE(5.5 * 2.1, rectangle.getWidth(), accuracy);
    BOOST_CHECK_CLOSE(6.6 * 2.1, rectangle.getHeight(), accuracy);
    BOOST_CHECK_CLOSE(2.1 * 5.5 * 2.1 * 6.6, rectangle.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()
