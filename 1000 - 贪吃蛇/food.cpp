#include "food.h"

Food::Food(Wall& wall) : wall_(wall) {}

void Food::setFood()
{
	while (true)
	{
		this->x_food = rand() % (Wall::Row - 2) + 1;
		this->y_food = rand() % (Wall::Law - 2) + 1;

		if (wall_.getWall(x_food, y_food) == ' ')
		{
			this->wall_.setWall(x_food, y_food, '#');
			break;
		}
	}
}