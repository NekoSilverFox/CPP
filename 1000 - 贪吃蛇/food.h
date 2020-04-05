#pragma once
#include "wall.h"
#include <iostream>
using namespace std;

class Food
{
public:
	Food(Wall& wall);
	void setFood();

private:
	Wall& wall_;
	int x_food, y_food;
};
