#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

void gotoxy_game(HANDLE hOut_game, int x, int y)
{
	COORD pos;
	pos.X = x;             // 横坐标
	pos.Y = y;            // 纵坐标
	SetConsoleCursorPosition(hOut_game, pos);
}
HANDLE hOut_game = GetStdHandle(STD_OUTPUT_HANDLE); // 定义显示器句柄变量

void game()
{
	srand((unsigned int)time(NULL));

	// 是否死亡
	bool isDead = false;

	char preKey = NULL;

	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();

	

	while (!isDead)
	{
		// 接受用户输入
		char key = _getch();

		// 判断 如果是第一次按左键不能激活游戏
		// 技巧：判断上一次移动方向
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{

				// 判断本次的按键是否与上次冲突
				// 如果180 ° 旋转，将这次按键变为上次按键
				if (key == snake.LEFT && preKey == snake.RIGHT ||
					key == snake.RIGHT && preKey == snake.LEFT ||
					key == snake.UP && preKey == snake.DOWN ||
					key == snake.DOWN && preKey == snake.UP) 
				{
					key = preKey;
				}
				else // 如果不冲突，将新按键标识
				{
					preKey = key;
				}

				if (snake.moveSnake(key) == true)
				{
					// system("cls");
					// wall.drawWall();

					// 分数表加分
					gotoxy_game(hOut_game, 60, 14);
					cout << "\033[32mScore : " << wall.getScore() << "\033[0m";

					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}

			}
			else
			{
				// 强制将错误按键变成上次的按键
				key = preKey;
			}

		} while (!_kbhit()); // 当键盘没有输入的时候 返回 0

	}

}

int main()
{
	try
	{
		game();
	}
	catch (MyException& error)
	{
		cout << error.what() << endl;
	}
	cin.get();
	return 0;
}