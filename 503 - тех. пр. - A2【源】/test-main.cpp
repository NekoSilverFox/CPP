
#define BOOST_TEST_MODULE A2

#include <boost/test/included/unit_test.hpp> 
#include "rectangle.hpp"
#include "circle.hpp"

double accuracy = 0.00001;

BOOST_AUTO_TEST_SUITE(rectangle)

  BOOST_AUTO_TEST_CASE(immutability_after_moving_to_point)
  {
    dzutseva::Rectangle rectangle {{6, 10}, 13, 5};

    double expectedWidth = rectangle.getWidth();
    double expectedHeight = rectangle.getHeight();
    double expectedArea = rectangle.getArea();

    rectangle.move({-4, 2});

    BOOST_CHECK_EQUAL(rectangle.getWidth(), expectedWidth);
    BOOST_CHECK_EQUAL(rectangle.getHeight(), expectedHeight);
    BOOST_CHECK_EQUAL(rectangle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(immutability_after_moving_by_coordinate)
  {
    dzutseva::Rectangle rectangle {{1, 0}, 25, 17};

    double expectedWidth = rectangle.getWidth();
    double expectedHeight = rectangle.getHeight();
    double expectedArea = rectangle.getArea();

    rectangle.move(3.4, 1);

    BOOST_CHECK_EQUAL(rectangle.getWidth(), expectedWidth);
    BOOST_CHECK_EQUAL(rectangle.getHeight(), expectedHeight);
    BOOST_CHECK_EQUAL(rectangle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(quadratic_area_change_after_scaling)
  {
    dzutseva::Rectangle rectangle {{1, 0}, 25.4, 17.14};

    double coefficient = 2.3;
    double expectedArea = coefficient * coefficient * rectangle.getArea();

    rectangle.scale(coefficient);

    BOOST_CHECK_CLOSE(expectedArea, rectangle.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(circle)

  BOOST_AUTO_TEST_CASE(immutability_after_moving_to_point)
  {
    dzutseva::Circle circle {{-6, -12}, 8};

    double expectedRadius = circle.getRadius();
    double expectedArea = circle.getArea();

    circle.move({1, 1});

    BOOST_CHECK_EQUAL(circle.getRadius(), expectedRadius);
    BOOST_CHECK_EQUAL(circle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(immutability_after_moving_by_coordinate)
  {
    dzutseva::Circle circle {{1, 9}, 17};

    double expectedRadius = circle.getRadius();
    double expectedArea = circle.getArea();

    circle.move(2.5, 1.1);

    BOOST_CHECK_EQUAL(circle.getRadius(), expectedRadius);
    BOOST_CHECK_EQUAL(circle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(quadratic_area_change_scaling)
  {
    dzutseva::Circle circle {{1, 9}, 12.5};

    double coefficient = 1.1;
    double expectedArea = coefficient * coefficient * circle.getArea();

    circle.scale(coefficient);

    BOOST_CHECK_CLOSE(expectedArea, circle.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()