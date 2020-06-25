#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "matrix.hpp"
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

const double epsilon = 0.0000001;

BOOST_AUTO_TEST_SUITE(MatrixConstructor)

BOOST_AUTO_TEST_CASE(DefaultConstructor_ValidEmptyMatrixConstructed)
{
  gadzhiev::Matrix matrix;
  BOOST_CHECK_EQUAL(matrix.getCountOfLayers(), 0);
  BOOST_CHECK_EQUAL(matrix.getCountOfShapesInMatrix(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(addShape)

BOOST_AUTO_TEST_CASE(InvalidShapeAdd_ThrownInvalidArgument)
{
  gadzhiev::Matrix matrix;
  gadzhiev::Shape::ShapePtr rectangle { nullptr };
  BOOST_CHECK_THROW(matrix.add(rectangle), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ValidShapesAdd_ShapesValidAddedToMatrixToEssentialLayers)
{
  gadzhiev::Matrix matrix;

  matrix.add(std::make_shared<gadzhiev::Rectangle>(2, 5, gadzhiev::point_t{ -11, 3.5 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(2, 5, gadzhiev::point_t{ -8, 8.5 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(4, 2, gadzhiev::point_t{ -7, 3 }));
  matrix.add(std::make_shared<gadzhiev::Circle>(1, gadzhiev::point_t{ -4, 7 }));
  matrix.add(std::make_shared<gadzhiev::Circle>(2.5, gadzhiev::point_t{ -12, 6 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(1, 7, gadzhiev::point_t{ -7, 0 }));

  
  gadzhiev::CompositeShape cmpShapeForMatrix(std::make_shared<gadzhiev::Rectangle>(9, 6, gadzhiev::point_t{ 20, 25 }));
  cmpShapeForMatrix.add(std::make_shared<gadzhiev::Circle>(3.5, gadzhiev::point_t{ 31, 20 }));
  std::shared_ptr<gadzhiev::Shape> cmpShapeForAdd = std::make_shared<gadzhiev::CompositeShape>(cmpShapeForMatrix);
  matrix.add(cmpShapeForAdd);
  
  matrix.add(std::make_shared<gadzhiev::Circle>(2, gadzhiev::point_t{ -12.5, 9 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(1, 6, gadzhiev::point_t{ -13.5, 3 }));
  matrix.add(std::make_shared<gadzhiev::Circle>(2, gadzhiev::point_t{ -12.5, 12 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(0.5, 0.5, gadzhiev::point_t{ -14.5, 9 }));


  BOOST_CHECK_EQUAL(matrix.getCountOfLayers(), 4);
  BOOST_CHECK_EQUAL(matrix.getCountOfShapesInMatrix(), 11);
  BOOST_CHECK_EQUAL(matrix.getCountOfShapeInLayer(0), 5);
  BOOST_CHECK_EQUAL(matrix.getCountOfShapeInLayer(1), 2);
  BOOST_CHECK_EQUAL(matrix.getCountOfShapeInLayer(2), 2);
  BOOST_CHECK_EQUAL(matrix.getCountOfShapeInLayer(3), 2);
  BOOST_CHECK_EQUAL(matrix.getLayersNumber(1), 0);
  BOOST_CHECK_EQUAL(matrix.getLayersNumber(10), 3);
  BOOST_CHECK_THROW(matrix.getLayersNumber(132), std::invalid_argument);
  BOOST_CHECK_THROW(matrix.getLayersNumber(11), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(getShape)

BOOST_AUTO_TEST_CASE(getValidShapeFromMatrix_ReturnValidShape)
{
  gadzhiev::Matrix matrix;

  gadzhiev::Shape::ShapePtr rectOne = std::make_shared<gadzhiev::Rectangle>(2, 5, gadzhiev::point_t{ -11, 3.5 });

  matrix.add(rectOne);
  matrix.add(std::make_shared<gadzhiev::Rectangle>(2, 5, gadzhiev::point_t{ -8, 8.5 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(4, 2, gadzhiev::point_t{ -7, 3 }));
  matrix.add(std::make_shared<gadzhiev::Circle>(1, gadzhiev::point_t{ -4, 7 }));
  matrix.add(std::make_shared<gadzhiev::Circle>(2.5, gadzhiev::point_t{ -12, 6 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(1, 7, gadzhiev::point_t{ -7, 0 }));


  gadzhiev::CompositeShape cmpShapeForMatrix(std::make_shared<gadzhiev::Rectangle>(9, 6, gadzhiev::point_t{ 20, 25 }));
  cmpShapeForMatrix.add(std::make_shared<gadzhiev::Circle>(3.5, gadzhiev::point_t{ 31, 20 }));
  std::shared_ptr<gadzhiev::Shape> cmpShapeForAdd = std::make_shared<gadzhiev::CompositeShape>(cmpShapeForMatrix);
  matrix.add(cmpShapeForAdd);


  gadzhiev::Shape::ShapePtr circOne = std::make_shared<gadzhiev::Circle>(2, gadzhiev::point_t{ -12.5, 9 });
  matrix.add(circOne);
  matrix.add(std::make_shared<gadzhiev::Rectangle>(1, 6, gadzhiev::point_t{ -13.5, 3 }));
  matrix.add(std::make_shared<gadzhiev::Circle>(2, gadzhiev::point_t{ -12.5, 12 }));

  gadzhiev::Shape::ShapePtr rectTwo = std::make_shared<gadzhiev::Rectangle>(0.5, 0.5, gadzhiev::point_t{ -14.5, 9 });
  matrix.add(rectTwo);

  BOOST_CHECK_EQUAL(matrix[0][0], rectOne);
  BOOST_CHECK_EQUAL(matrix[3][1], rectTwo);
}

BOOST_AUTO_TEST_CASE(InValidGetShapeWithInvalidLayerOrInvalidFigureNumber_ThrownOutOfRange)
{
  gadzhiev::Matrix matrix;

  matrix.add(std::make_shared<gadzhiev::Rectangle>(2, 5, gadzhiev::point_t{ -11, 3.5 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(2, 5, gadzhiev::point_t{ -8, 8.5 }));
  matrix.add(std::make_shared<gadzhiev::Rectangle>(4, 2, gadzhiev::point_t{ -7, 3 }));

  BOOST_CHECK_THROW(matrix[1][0], std::out_of_range);
  BOOST_CHECK_THROW(matrix[2][0], std::out_of_range);
  BOOST_CHECK_THROW(matrix[0][20], std::out_of_range);
  BOOST_CHECK_THROW(matrix[15][2], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(InValidGetShapeFromEmptyMatrix_ThrownLengthError)
{
  gadzhiev::Matrix matrix;

  BOOST_CHECK_THROW(matrix[0][0], std::length_error);
  BOOST_CHECK_THROW(matrix[2][0], std::length_error);
  BOOST_CHECK_THROW(matrix[0][20], std::length_error);
}


BOOST_AUTO_TEST_SUITE_END()
