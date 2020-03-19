#pragma once
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include"shape.hpp"

class Rectangle : public Shape/*, public rectangle_t*/
{
public:

	Rectangle(rectangle_t rec);

	Rectangle(double width_rec, double height_rec, double x_rec, double y_rec);

	Rectangle(double width_rec, double height_rec, const point_t& point_rec);

	double getArea() const;

	rectangle_t getFrameRect() const;

	void move(double x_move, double y_move);

	void move(const point_t& point_new);

	void printInfo() const;

private:
	rectangle_t rectangle_;
};
#endif // !RECTANGLE_HPP
