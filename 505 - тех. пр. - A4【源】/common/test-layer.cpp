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

    BOOST_AUTO_TEST_CASE(InitializeLayer_TestCopyConstructor_NoError)
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
BOOST_AUTO_TEST_SUITE(AddShapeinLayer)
    BOOST_AUTO_TEST_CASE(AddShapeinLayer_AddCorrectShape_NoError)
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

    BOOST_AUTO_TEST_CASE(AddShapeinLayer_AddNullptr_ThrowError)
    {
      jianing::Layer layer;

      BOOST_CHECK_THROW(layer.addShape(nullptr), std::invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test overlap=====================
BOOST_AUTO_TEST_SUITE(TestOverlap)
    BOOST_AUTO_TEST_CASE(TestOverlap_Overlap_NoError)
    {
      jianing::Layer layer;

      // Shape No.1 - On layer No.1
      jianing::point_t center_cirle = {1.0, 1.0};
      double r_cirle = 2.0;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

      layer.addShape(circle);

      // Shape No.2
      jianing::rectangle_t center_width_height_rec = {2.0, 4.0, 2.0, 2.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      BOOST_CHECK_EQUAL(layer.isOverlap(rectangle), true);
    }

    BOOST_AUTO_TEST_CASE(TestOverlap_DoNotOverlap_NoError)
    {
      jianing::Layer layer;

      // Shape No.1 - On layer No.1
      jianing::point_t center_cirle = {1.0, 1.0};
      double r_cirle = 2.0;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

      layer.addShape(circle);

      // Shape No.2
      jianing::rectangle_t center_width_height_rec = {1.0, 1.0, 6.0, 1.0};
      jianing::Shape::ShapePtr first_rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      BOOST_CHECK_EQUAL(layer.isOverlap(first_rectangle), false);
    }

    BOOST_AUTO_TEST_CASE(TestOverlap_CompositeShapeOverlap_NoError)
    {
      // Make a composite shape
      jianing::CompositeShape com_shape;

      // push first shape
      jianing::point_t circle_center = {1.0, 1.0};
      double r_cirle = 2.0;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(circle_center, r_cirle);

      com_shape.pushShape(circle);

      // push second shape
      jianing::rectangle_t center_width_height_rec = {2.0, 4.0, 2.0, 2.0};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      com_shape.pushShape(rectangle);

      // add composite shape in layer (on first layer)
      jianing::Layer layer;

      // Shape No.1 - On layer No.1
      layer.addShape(std::make_shared<jianing::CompositeShape>(com_shape));

      BOOST_CHECK_EQUAL(1, layer.getSize());
      BOOST_CHECK_EQUAL(layer.empty(), false);

      // Shape No.2
      circle_center = {7.2, 1.1};
      r_cirle = 1.0;
      jianing::Shape::ShapePtr sec_circle = std::make_shared<jianing::Circle>(circle_center, r_cirle);

      BOOST_CHECK_EQUAL(layer.isOverlap(sec_circle), false);
    }

    BOOST_AUTO_TEST_CASE(TestOverlap_AddNullptr_ThrowError)
    {
      jianing::Layer layer;

      // Shape No.1 - On layer No.1
      jianing::point_t center_cirle = {1.2, 1.3};
      double r_cirle = 2.8;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center_cirle, r_cirle);

      layer.addShape(circle);

      jianing::rectangle_t center_width_height_rec = {2.2, 3.9, 2.1, 2.2};
      jianing::Shape::ShapePtr rectangle = std::make_shared<jianing::Rectangle>(center_width_height_rec);

      BOOST_CHECK_THROW(layer.isOverlap(nullptr), std::invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()

// =====================test get shape in layer=====================
BOOST_AUTO_TEST_SUITE(GetShapeinLayer)
    BOOST_AUTO_TEST_CASE(GetShapeinLayer_UseSquareBrackets_NoError)
    {
      jianing::point_t center = {1.2, 3.1};
      double r_cirle = 7.1;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Layer layer;

      layer.addShape(circle);

      BOOST_CHECK_CLOSE(1.2, layer[0]->getCenter().x, accuracy);
      BOOST_CHECK_CLOSE(3.1, layer[0]->getCenter().y, accuracy);
      BOOST_CHECK_CLOSE(M_PI * 7.1 * 7.1, layer[0]->getArea(), accuracy);
    }

    BOOST_AUTO_TEST_CASE(GetShapeinLayer_UseWrongIndex_ThrowError)
    {
      jianing::point_t center = {1.3, 2.7};
      double r_cirle = 4.5;
      jianing::Shape::ShapePtr circle = std::make_shared<jianing::Circle>(center, r_cirle);

      jianing::Layer layer;

      layer.addShape(circle);

      BOOST_CHECK_THROW(layer[6]->getArea(), std::out_of_range);
    }

BOOST_AUTO_TEST_SUITE_END()
