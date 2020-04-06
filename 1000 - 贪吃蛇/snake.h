#pragma once
#include "wall.h"
#include "myexception.h"
#include "food.h"
#include <Windows.h>
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

	// 设定难度
	// 获取刷屏时间
	int getSleepTime();

	// 获取蛇身段
	int countList();

private:
	Point* header_;
	Wall& wall_;
	Food& food_;
	bool isRool; // 碰到的是尾巴 or not
};
