#include "wall.h"

void Wall::initWall()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Law; j++)
		{
			// ��ǽ��
			if (0 == i || 0 == j || Row - 1 == i || Law - 1 == j) wall_[i][j] = '*';
			else wall_[i][j] = ' ';
		}
	}
}

void Wall::drawWall()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Law; j++)
		{
			//if ('#' == wall_[i][j])
			//{
			//	cout << "\033[33m" << wall_[i][j] << " \033[0m";
			//	continue;
			//}
			cout << wall_[i][j] << ' ';
		}
		// ��ʾ��Ϣ
		if (9 == i) cout << "        " << "w - up";
		if (10 == i) cout << "        " << "s - down";
		if (11 == i) cout << "        " << "a - left";
		if (12 == i) cout << "        " << "d - right";
		if (14 == i) cout << "        " << "Score : " << getScore();
		if (15 == i) cout << "        " << "���к���";
		if (16 == i) cout << "        " << "Bate 1.1";

		cout << endl;
	}
}

void Wall::setWall(int x, int y, char ch)
{
	if (x > Row || y > Law || x < 0 || y < 0) throw MyException("out_of_range");
	wall_[x][y] = ch;
}

char Wall::getWall(int x, int y)
{
	if (x > Row || y > Law || x < 0 || y < 0) throw MyException("out_of_range");
	return wall_[x][y];
}

// ���÷���
int Wall::setScore(int score_plus)
{
	score_ += score_plus;
	return score_;
}

// ��ȡ����
int Wall::getScore()
{
	return score_;
}