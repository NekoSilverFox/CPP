#include <stdexcept>

#include <boost/test/unit_test.hpp>

#include "base-types.hpp"
#include "triangle.hpp"

namespace
{
  const double eps = 1e-10;
}

BOOST_AUTO_TEST_SUITE(TriangleConstructor)

BOOST_AUTO_TEST_CASE(ValidArguments_ValidInitialization)
{
  yakovlev::Triangle tri = { { 32.0, -23.0 }, { -5.0, -15.0 }, { 124.3, 54.3 } };
  yakovlev::point_t pos = { (124.3 + 32.0 - 5.0) / 3.0, (54.3 - 15.0 - 23.0) / 3.0 };
  BOOST_CHECK_EQUAL(tri.getCenter(), pos);
}

BOOST_AUTO_TEST_CASE(DegenerateTriangleArguments_ThrowsInvalidArgument)
{
  BOOST_CHECK_THROW(yakovlev::Triangle({ 3.2 , 0.0 }, { -622.32, 0.0 }, { 432.2, 0.0 }), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(TriangleFrame)

BOOST_AUTO_TEST_CASE(ValidTriangle_ValidFraming)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::rectangle_t frame = tri.getFrameRect();
  BOOST_CHECK_EQUAL(frame.width, 3.0);
  BOOST_CHECK_EQUAL(frame.height, 11.0);
  yakovlev::point_t center = { 4.5, -0.5 };
  BOOST_CHECK_EQUAL(frame.pos, center);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(TriangleMove)

BOOST_AUTO_TEST_CASE(By_ValidArguments_CenterMoved)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::point_t center = { 13.0 / 3.0, 1.0 / 3.0 };
  double moveX = 312.4, moveY = -134.27;
  tri.move(moveX, moveY);
  yakovlev::point_t movedCenter = tri.getCenter();
  BOOST_CHECK_EQUAL(movedCenter.x, center.x + moveX);
  BOOST_CHECK_EQUAL(movedCenter.y, center.y + moveY);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_CenterMoved)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::point_t newCenter = { 8654.2, -321.4043 };
  tri.move(newCenter);
  BOOST_CHECK_EQUAL(tri.getCenter(), newCenter);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(TriangleMovePersistence)

BOOST_AUTO_TEST_CASE(By_ValidArguments_AreaPersists)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  double area = tri.getArea();
  tri.move(-234.4, 0.2134);
  BOOST_CHECK_CLOSE(tri.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_AreaPersists)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  double area = tri.getArea();
  tri.move({ 231.23, -231.23 });
  BOOST_CHECK_CLOSE(tri.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(By_ValidArguments_FramePersists)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::rectangle_t frame = tri.getFrameRect();
  double moveX = 4234.4, moveY = 123.34;
  tri.move(moveX, moveY);
  yakovlev::rectangle_t movedFrame = tri.getFrameRect();
  BOOST_CHECK_EQUAL(movedFrame.width, frame.width);
  BOOST_CHECK_EQUAL(movedFrame.height, frame.height);
  BOOST_CHECK_EQUAL(movedFrame.pos.x, frame.pos.x + moveX);
  BOOST_CHECK_EQUAL(movedFrame.pos.y, frame.pos.y + moveY);
}

BOOST_AUTO_TEST_CASE(To_ValidArguments_FramePersists)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::rectangle_t frame = tri.getFrameRect();
  yakovlev::point_t triCenter = tri.getCenter();
  yakovlev::point_t centerDist = { frame.pos.x - triCenter.x, frame.pos.y - triCenter.y };
  tri.move({ 44.4, 4.4 });
  yakovlev::rectangle_t movedFrame = tri.getFrameRect();
  BOOST_CHECK_CLOSE(movedFrame.width, frame.width, eps);
  BOOST_CHECK_CLOSE(movedFrame.height, frame.height, eps);
  yakovlev::point_t movedTriCenter = tri.getCenter();
  yakovlev::point_t movedFramePos = { movedTriCenter.x + centerDist.x, movedTriCenter.y + centerDist.y };
  BOOST_CHECK_CLOSE(movedFrame.pos.x, movedFramePos.x, eps);
  BOOST_CHECK_CLOSE(movedFrame.pos.y, movedFramePos.y, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(TriangleRotate)

BOOST_AUTO_TEST_CASE(AnyAngle_AreaPersists)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  double area = tri.getArea();
  tri.rotate(12);
  BOOST_CHECK_CLOSE(tri.getArea(), area, eps);
}

BOOST_AUTO_TEST_CASE(AnyAngle_CenterPersists)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::point_t center = tri.getCenter();
  tri.rotate(-12);
  BOOST_CHECK_CLOSE(tri.getCenter().x, center.x, eps);
  BOOST_CHECK_CLOSE(tri.getCenter().y, center.y, eps);
}

BOOST_AUTO_TEST_CASE(AnyAngle_FrameUpdates)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::rectangle_t frame = tri.getFrameRect();
  tri.rotate(90);
  yakovlev::rectangle_t updatedFrame = tri.getFrameRect();
  BOOST_CHECK_CLOSE(updatedFrame.height, frame.width, eps);
  BOOST_CHECK_CLOSE(updatedFrame.width, frame.height, eps);
}

BOOST_AUTO_TEST_SUITE_END()

//=====================================================================================

BOOST_AUTO_TEST_SUITE(TriangleScale)

BOOST_AUTO_TEST_CASE(ValidCoefficient_AreaScales)
{
  yakovlev::Triangle tri = { { 45.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  double area = tri.getArea();
  double coef = 34.2;
  tri.scale(coef);
  BOOST_CHECK_CLOSE(tri.getArea(), area * coef * coef, eps);
}

BOOST_AUTO_TEST_CASE(InvalidCoefficient_ThrowsInvalidArgument)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  BOOST_CHECK_THROW(tri.scale(-3.4), std::invalid_argument);
  BOOST_CHECK_THROW(tri.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ValidCoefficient_FrameUpdates)
{
  yakovlev::Triangle tri = { { 6.0, 2.0 }, { 4.0, -6.0 }, { 3.0, 5.0 } };
  yakovlev::rectangle_t frame = tri.getFrameRect();
  BOOST_CHECK_CLOSE(frame.width, 3.0, eps);
  BOOST_CHECK_CLOSE(frame.height, 11.0, eps);
  double coef = 2.5;
  tri.scale(coef);
  yakovlev::rectangle_t scaledFrame = tri.getFrameRect();
  BOOST_CHECK_CLOSE(scaledFrame.width, frame.width * coef, eps);
  BOOST_CHECK_CLOSE(scaledFrame.height, frame.height * coef, eps);
}

BOOST_AUTO_TEST_SUITE_END()
