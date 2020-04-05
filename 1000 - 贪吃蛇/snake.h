#pragma once
#include "wall.h"
#include "myexception.h"
#include "food.h"
#include <iostream>

class Snake
{
public:
	Snake(Wall& wall, Food& food);

	enum Key { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

	struct Point
	{
		int x_point, y_point;
		Point* next_;
	};

	void initSnake();
	void addPoint(int x, int y);
	void destotySnake();
	void deleteRear();
	bool moveSnake(char key);
private:
	Point* header_;
	Wall& wall_;
	Food& food_;
};
