#pragma once
#include<iostream>
#include<string>
#include"Weapon.h"
using namespace std;

class Knife : public Weapon
{
public:

	Knife();
	//��ȡ�����˺�
	virtual float getBaseDamage();

	//��ȡ��Ѫ
	virtual float getSuckBlood();

	//��ȡ�Ƿ���
	virtual bool getHold();

	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();
};