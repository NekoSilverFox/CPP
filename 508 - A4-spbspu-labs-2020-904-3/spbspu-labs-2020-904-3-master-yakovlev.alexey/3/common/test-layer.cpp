#include <stdexcept>
#include <memory>

#include <boost/test/unit_test.hpp>

#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "layer.hpp"

BOOST_AUTO_TEST_SUITE(Layer)

BOOST_AUTO_TEST_CASE(DefaultConstructor_InstantiatesEmptyLayer)
{
  yakovlev::Layer layer = {};
  BOOST_CHECK_EQUAL(layer.isEmpty(), true);
}

BOOST_AUTO_TEST_CASE(WorksAsContainer)
{
  yakovlev::Layer layer = {};
  BOOST_CHECK_THROW(layer.add(nullptr), std::invalid_argument);
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2, 
      yakovlev::point_t{ 2.0, 1.0 });
  layer.add(circleptr);
  BOOST_CHECK_EQUAL(layer.getSize(), 1);
  BOOST_CHECK_EQUAL(layer[0], circleptr);
  BOOST_CHECK_THROW(layer.add(circleptr), std::invalid_argument);

  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  layer.add(rectptr1);
  BOOST_CHECK_EQUAL(layer.getSize(), 2);
  BOOST_CHECK_EQUAL(layer[1], rectptr1);

  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ 4, 0.8 });
  layer.add(rectptr2);
  BOOST_CHECK_EQUAL(layer.getSize(), 3);
  BOOST_CHECK_EQUAL(layer[2], rectptr2);

  layer.remove(1);
  BOOST_CHECK_EQUAL(layer.getSize(), 2);
  BOOST_CHECK_EQUAL(layer[0], circleptr);
  BOOST_CHECK_EQUAL(layer[1], rectptr2);
  BOOST_CHECK_EQUAL(layer.contains(rectptr2), true);

  layer.remove(0);
  layer.remove(0);
  BOOST_CHECK_EQUAL(layer.isEmpty(), true);
  BOOST_CHECK_EQUAL(layer.contains(rectptr2), false);
}

BOOST_AUTO_TEST_CASE(InvalidIndex_ThrowsOutOfRange)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ 4, 0.8 });
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ 20.0, 1.0 });

  yakovlev::Layer layer = {};
  layer.add(rectptr1);
  layer.add(rectptr2);
  layer.add(circleptr);

  BOOST_CHECK_THROW(layer[123], std::out_of_range);
  BOOST_CHECK_THROW(layer[-12], std::out_of_range);
  BOOST_CHECK_THROW(layer[layer.getSize()], std::out_of_range);
  BOOST_CHECK_THROW(layer.remove(123), std::out_of_range);
  BOOST_CHECK_THROW(layer.remove(-12), std::out_of_range);
  BOOST_CHECK_THROW(layer.remove(layer.getSize()), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Intersects_IntersectingShape_ReturnsTrue)
{
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ 20.0, 1.0 });
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ 4, 0.8 });

  yakovlev::Layer layer = {};
  layer.add(circleptr);
  layer.add(rectptr1);
  BOOST_CHECK_EQUAL(layer.intersects(*rectptr2), true);
  BOOST_CHECK_EQUAL(layer.intersects(*circleptr), true);
}

BOOST_AUTO_TEST_CASE(Intersects_NonIntersectingShape_ReturnsFalse)
{
  std::shared_ptr<yakovlev::Rectangle> rectptr1 = std::make_shared<yakovlev::Rectangle>(3.0, 1.2,
      yakovlev::point_t{ 4.3, 1.2 });
  std::shared_ptr<yakovlev::Rectangle> rectptr2 = std::make_shared<yakovlev::Rectangle>(2.0, 1.0,
      yakovlev::point_t{ 4, 0.8 });
  std::shared_ptr<yakovlev::Circle> circleptr = std::make_shared<yakovlev::Circle>(3.2,
      yakovlev::point_t{ 20.0, 1.0 });

  yakovlev::Layer layer = {};

  BOOST_CHECK_EQUAL(layer.intersects(*rectptr2), false);

  layer.add(rectptr1);
  layer.add(rectptr2);

  BOOST_CHECK_EQUAL(layer.intersects(*circleptr), false);
}

BOOST_AUTO_TEST_SUITE_END()  
