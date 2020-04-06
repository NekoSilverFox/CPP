#include "food.h"

void gotoxy_food(HANDLE hOut_food, int x, int y)
{
	COORD pos;
	pos.X = x;             // 横坐标
	pos.Y = y;            // 纵坐标
	SetConsoleCursorPosition(hOut_food, pos);
}
HANDLE hOut_food = GetStdHandle(STD_OUTPUT_HANDLE); // 定义显示器句柄变量

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
			gotoxy_food(hOut_food, y_food * 2, x_food);
			cout << "#";

			//// 分数表加分
			//gotoxy_food(hOut_food, y_food * 2, x_food);
			break;
		}
	}
}