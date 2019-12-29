#pragma once
#include<iostream>
#include<string>
#include"Weapon.h"
using namespace std;

class DragonSword : public Weapon
{
public:
	DragonSword();

	//��ȡ�����˺�
	virtual float getBaseDamage();

	//��ȡ��Ѫ
	virtual float getSuckBlood();

	//��ȡ�Ƿ���
	virtual bool getHold();

	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();

	//  ��Ѫ��  ������ ������ 
	int suckRate;
	int holdRate;
	int critRate;

	//������� �ж��Ƿ񴥷�
	bool isTrigger(float rate);
};