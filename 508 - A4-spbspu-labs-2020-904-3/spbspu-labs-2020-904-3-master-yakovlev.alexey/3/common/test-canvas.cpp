#include <stdexcept>
#include <memory>

#include <boost/test/unit_test.hpp>

#include "composite-shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"
#include "canvas.hpp"

BOOST_AUTO_TEST_SUITE(Canvas)

BOOST_AUTO_TEST_CASE(NonIntersectingShapes_OnSingleLayer)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ -23.3, 94.3 });
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ -12.0, 1.0 });
  yakovlev::Canvas canvas = {};
  canvas.add(rectptr1);
  canvas.add(rectptr2);
  canvas.add(circleptr);
  BOOST_CHECK_EQUAL(canvas.getLayersCount(), 1);
  BOOST_CHECK_EQUAL(canvas.getLayerSize(0), 3);
}

BOOST_AUTO_TEST_CASE(IntersectingShapes_OnConsequentLayers)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ 4, 0.8 });
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ 2.0, 1.0 });
  yakovlev::Canvas canvas = {};
  canvas.add(rectptr1);
  canvas.add(rectptr2);
  canvas.add(circleptr);
  BOOST_CHECK_EQUAL(canvas.getLayersCount(), 3);
  BOOST_CHECK_EQUAL(canvas.getLayerSize(0), 1);
  BOOST_CHECK_EQUAL(canvas[0][0], rectptr1);
  BOOST_CHECK_EQUAL(canvas.getLayerSize(1), 1);
  BOOST_CHECK_EQUAL(canvas[1][0], rectptr2);
  BOOST_CHECK_EQUAL(canvas.getLayerSize(2), 1);
  BOOST_CHECK_EQUAL(canvas[2][0], circleptr);
}

BOOST_AUTO_TEST_CASE(NonIntersectingShapeAfterIntersectingShape_OnLowerLayer)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ 4, 0.8 });
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ 20.0, 1.0 });
  yakovlev::Canvas canvas = {};
  canvas.add(rectptr1);
  canvas.add(rectptr2);
  canvas.add(circleptr);
  BOOST_CHECK_EQUAL(canvas.getLayersCount(), 2);
  BOOST_CHECK_EQUAL(canvas.getLayerSize(0), 2);
  BOOST_CHECK_EQUAL(canvas[0][0], rectptr1);
  BOOST_CHECK_EQUAL(canvas[0][1], circleptr);
  BOOST_CHECK_EQUAL(canvas.getLayerSize(1), 1);
  BOOST_CHECK_EQUAL(canvas[1][0], rectptr2);
}

BOOST_AUTO_TEST_CASE(InvalidIndex_ThrowsOutOfRange)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ 4, 0.8 });
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ 20.0, 1.0 });
  yakovlev::Canvas canvas = {};
  BOOST_CHECK_EQUAL(canvas.getLayersCount(), 0);
  canvas.add(rectptr1);
  canvas.add(rectptr2);
  canvas.add(circleptr);
  BOOST_CHECK_THROW(canvas.getLayerSize(123), std::out_of_range);
  BOOST_CHECK_THROW(canvas.getLayerSize(-12), std::out_of_range);
  BOOST_CHECK_THROW(canvas.getLayerSize(canvas.getLayersCount()), std::out_of_range);
  BOOST_CHECK_THROW(canvas[123][0], std::out_of_range);
  BOOST_CHECK_THROW(canvas[-12][0], std::out_of_range);
  BOOST_CHECK_THROW(canvas[canvas.getLayersCount()][0], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(AddNullptr_ThrowsInvalidArgument)
{
  yakovlev::Canvas canvas = {};
  BOOST_CHECK_THROW(canvas.add(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(AddTwice_ThrowsInvalidArgument)
{
  yakovlev::Canvas canvas = {};
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ 20.0, 1.0 });
  canvas.add(circleptr);
  BOOST_CHECK_THROW(canvas.add(circleptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
