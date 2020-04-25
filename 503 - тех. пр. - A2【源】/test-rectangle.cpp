#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"

const double accuracy = 0.00001;

BOOST_AUTO_TEST_SUITE(rectangle)

  BOOST_AUTO_TEST_CASE(moving_rectangle_to_a_point_x_y)
  {
    jianing::Rectangle rectangle {{5.0, 10.0, 3.0, 4.0}};

    double expectedWidth = rectangle.getWidth();
    double expectedHeight = rectangle.getHeight();
    double expectedArea = rectangle.getArea();

    rectangle.move({10, 5});

    BOOST_CHECK_EQUAL(rectangle.getWidth(), expectedWidth);
    BOOST_CHECK_EQUAL(rectangle.getHeight(), expectedHeight);
    BOOST_CHECK_EQUAL(rectangle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(moving_rectangle_by_dx_dy)
  {
    jianing::Rectangle rectangle {{-5.0, -10.0, 5.0, 10.0}};

    double expectedWidth = rectangle.getWidth();
    double expectedHeight = rectangle.getHeight();
    double expectedArea = rectangle.getArea();

    rectangle.move(5.0, 10.0);

    BOOST_CHECK_EQUAL(rectangle.getWidth(), expectedWidth);
    BOOST_CHECK_EQUAL(rectangle.getHeight(), expectedHeight);
    BOOST_CHECK_EQUAL(rectangle.getArea(), expectedArea);
  }

  BOOST_AUTO_TEST_CASE(changing_rectangle_size_by_coefficient)
  {
    jianing::Rectangle rectangle {{5.0, 5.0, 10.0, 5.0}};

    double coefficient = 2.0;
    double expectedArea = coefficient * coefficient * rectangle.getArea();

    rectangle.scale(coefficient);

    BOOST_CHECK_CLOSE(expectedArea, rectangle.getArea(), accuracy);
  }

BOOST_AUTO_TEST_SUITE_END()
