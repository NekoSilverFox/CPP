#include <boost/test/unit_test.hpp>
#include "circle.hpp"

const double accuracy = 0.00001;

BOOST_AUTO_TEST_SUITE(circle)

  BOOST_AUTO_TEST_CASE(moving_circle_to_a_point_x_y)
  {
    jianing::Circle circle {{10.0, 0.0}, 5.0};

    double expectedRadius = circle.getRadius();
    double expectedArea = circle.getArea();

    circle.move({-10, -10});

    BOOST_CHECK_EQUAL(circle.getRadius(), expectedRadius);
    BOOST_CHECK_EQUAL(circle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(moving_circle_by_dx_dy)
  {
    jianing::Circle circle {{-5.0, 5.0}, 2.5};

    double expectedRadius = circle.getRadius();
    double expectedArea = circle.getArea();

    circle.move(5.0, -5.0);

    BOOST_CHECK_EQUAL(circle.getRadius(), expectedRadius);
    BOOST_CHECK_EQUAL(circle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(changing_circle_size_by_coefficient)
  {
    jianing::Circle circle {{3.0, -3.0}, 1.5};

    double coefficient = 2.0;
    double expectedArea = coefficient * coefficient * circle.getArea();

    circle.scale(coefficient);

    BOOST_CHECK_CLOSE(expectedArea, circle.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()
