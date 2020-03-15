#pragma once
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include"base-types.hpp"
// ÐÎ×´ - §æ§à§â§Þ§Ñ
class Shape
{
public:
	virtual double getArea() const = 0;

	virtual rectangle_t getFrameRect() const = 0;

	virtual void move(double x_move, double y_move) = 0;

	virtual void move(const point_t& point_new) = 0;

	virtual void printInfo() const = 0;
};

#endif // !SHAPE_HPP

