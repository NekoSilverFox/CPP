#pragma once
#include <iostream>
#include "myexception.h"

class Wall
{
public:
	enum { Row = 26, Law = 26};
	
	// ��ʼ��ǽ��
	void initWall();

	// ����ǽ��
	void drawWall();

	// �����������ã�������ά�����е�����
	void setWall(int x, int y, char ch);

	// ������������ȡ��ǰλ���ϵķ���
	char getWall(int x, int y);

private:
	char wall_[Row][Law];

};