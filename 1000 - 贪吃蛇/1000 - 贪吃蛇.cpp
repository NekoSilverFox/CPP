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

	// �Ƿ�����
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
		// �����û�����
		char key = _getch();

		// �ж� ����ǵ�һ�ΰ�������ܼ�����Ϸ
		// ���ɣ��ж���һ���ƶ�����
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				// �жϱ��εİ����Ƿ����ϴγ�ͻ
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
				// ǿ�ƽ����󰴼�����ϴεİ���
				key = preKey;
			}

		} while (!_kbhit()); // ������û�������ʱ�� ���� 0

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