#include <boost/test/unit_test.hpp>
#include "layer.hpp"
#include <memory>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <cmath>

const double accuracy = 0.00001;

// =====================test initialization layer=====================
BOOST_AUTO_TEST_SUITE(InitializeLayer)

    BOOST_AUTO_TEST_CASE(InitializeLayer_DefaultConstructors)
    {
      jianing::Layer layer;

      BOOST_REQUIRE_EQUAL(0, layer.getSize());
      BOOST_REQUIRE_EQUAL(true, layer.empty());
    }

    BOOST_AUTO_TEST_CASE(InitializeShape_TestCopyConstructor_NoError)
    {
      jianing::point_t center = {1.1, 2.2};
      double r_cirle = 3.3;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::CompositeShape old_layer;

      old_layer.pushShape(circle);

      jianing::CompositeShape new_layer = old_layer;

      BOOST_REQUIRE_EQUAL(1, new_layer.getSize());
      BOOST_REQUIRE_EQUAL(false, new_layer.empty());

      BOOST_REQUIRE_CLOSE(1.1, new_layer[0]->getCenter().x, accuracy);
      BOOST_REQUIRE_CLOSE(2.2, new_layer[0]->getCenter().y, accuracy);
      BOOST_REQUIRE_CLOSE(M_PI * 3.3 * 3.3, new_layer[0]->getArea(), accuracy);

      BOOST_REQUIRE_EQUAL(1, old_layer.getSize());
      BOOST_REQUIRE_EQUAL(false, old_layer.empty());

      BOOST_REQUIRE_CLOSE(1.1, old_layer.getCenter().x, accuracy);
      BOOST_REQUIRE_CLOSE(2.2, old_layer.getCenter().y, accuracy);
      BOOST_REQUIRE_CLOSE(M_PI * 3.3 * 3.3, old_layer.getArea(), accuracy);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test add shape in layer=====================
BOOST_AUTO_TEST_SUITE(AddShape)
    BOOST_AUTO_TEST_CASE(TestAddShape_AddCorrectShape_NoError)
    {
      jianing::point_t center = {1.1, 2.2};
      double r_cirle = 3.3;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Layer layer;

      layer.addShape(circle);

      BOOST_CHECK_EQUAL(1, layer.getSize());
      BOOST_CHECK_EQUAL(false, layer.empty());
      BOOST_CHECK_CLOSE(1.1, layer[0]->getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, layer[0]->getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, layer[0]->getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(TestpushShape_AddNullptr_ThrowError)
    {
      jianing::Layer layer;

      BOOST_CHECK_THROW(layer.addShape(nullptr), std::invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test get shape in layer=====================
BOOST_AUTO_TEST_SUITE(GetShape)
    BOOST_AUTO_TEST_CASE(GetShape_GetFirstShape_NoError)
    {
      jianing::point_t center = {1.1, 2.2};
      double r_cirle = 3.3;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Layer layer;

      layer.addShape(circle);

      jianing::Shape::ShapePtr get_circle = layer.getShape(0);

      BOOST_CHECK_CLOSE(1.1, get_circle->getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(2.2, get_circle->getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 3.3 * 3.3, get_circle->getArea(), accuracy);
    }

BOOST_AUTO_TEST_SUITE_END()
