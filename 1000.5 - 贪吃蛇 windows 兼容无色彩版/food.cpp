#include "food.h"

void gotoxy_food(HANDLE hOut_food, int x, int y)
{
	COORD pos;
	pos.X = x;             // ������
	pos.Y = y;            // ������
	SetConsoleCursorPosition(hOut_food, pos);
}
HANDLE hOut_food = GetStdHandle(STD_OUTPUT_HANDLE); // ������ʾ���������

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

			//// ������ӷ�
			//gotoxy_food(hOut_food, y_food * 2, x_food);
			break;
		}
	}
}