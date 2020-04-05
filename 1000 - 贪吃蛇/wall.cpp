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
		for (int j = 0; j < Law; j++) std::cout << wall_[i][j] << ' ';

		// ��ʾ��Ϣ
		if (10 == i) cout << "        " << "w - up";
		if (11 == i) cout << "        " << "s - down";
		if (12 == i) cout << "        " << "a - left";
		if (13 == i) cout << "        " << "d - right";
		if (14 == i) cout << "        " << "Score : " << getScore();
		if (15 == i) cout << "        " << "���к���";
		if (16 == i) cout << "        " << "Bate 0.1";

		std::cout << std::endl;
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