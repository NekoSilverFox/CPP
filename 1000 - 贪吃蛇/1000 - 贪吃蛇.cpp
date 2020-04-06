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
	pos.X = x;             // ������
	pos.Y = y;            // ������
	SetConsoleCursorPosition(hOut_game, pos);
}
HANDLE hOut_game = GetStdHandle(STD_OUTPUT_HANDLE); // ������ʾ���������

void game()
{
	srand((unsigned int)time(NULL));

	// �Ƿ�����
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
				// ���180 �� ��ת������ΰ�����Ϊ�ϴΰ���
				if (key == snake.LEFT && preKey == snake.RIGHT ||
					key == snake.RIGHT && preKey == snake.LEFT ||
					key == snake.UP && preKey == snake.DOWN ||
					key == snake.DOWN && preKey == snake.UP) 
				{
					key = preKey;
				}
				else // �������ͻ�����°�����ʶ
				{
					preKey = key;
				}

				if (snake.moveSnake(key) == true)
				{
					// system("cls");
					// wall.drawWall();

					// ������ӷ�
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
		game();
	}
	catch (MyException& error)
	{
		cout << error.what() << endl;
	}
	cin.get();
	return 0;
}