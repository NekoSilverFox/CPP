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

	// �趨�Ѷ�
	// ��ȡˢ��ʱ��
	int getSleepTime();

	// ��ȡ�����
	int countList();

private:
	Point* header_;
	Wall& wall_;
	Food& food_;
	bool isRool; // ��������β�� or not
};
