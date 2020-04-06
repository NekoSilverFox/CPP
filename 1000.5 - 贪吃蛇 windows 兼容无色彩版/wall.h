#pragma once
#include <iostream>
#include "myexception.h"

class Wall
{
public:
	enum { Row = 26, Law = 26};
	
	// 初始化墙壁
	void initWall();

	// 画出墙壁
	void drawWall();

	// 根据索引设置，画出二维数组中的内容
	void setWall(int x, int y, char ch);

	// 根据索引，获取当前位置上的符号
	char getWall(int x, int y);

	// 设置分数
	int setScore(int score_plus);

	// 获取分数
	int getScore();
private:
	char wall_[Row][Law];
	int score_ = 0;
};