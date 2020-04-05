#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

void test01()
{
	srand((unsigned int)time(NULL));

	// 是否死亡
	bool isDead = false;

	char preKey = NULL;

	Wall wall;
	wall.initWall();
	
	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();

	wall.drawWall();

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
				if (key == snake.LEFT && preKey == snake.RIGHT ||
					key == snake.RIGHT && preKey == snake.LEFT ||
					key == snake.UP && preKey == snake.DOWN ||
					key == snake.DOWN && preKey == snake.UP) 
				{
					key = preKey;
				}

				if (snake.moveSnake(key) == true)
				{
					system("cls");
					wall.drawWall();
					Sleep(300);
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
		test01();
	}
	catch (MyException& error)
	{
		cout << error.what() << endl;
	}
}