#pragma once
#include<iostream>
#include<string>
#include"Weapon.h"
using namespace std;

class Knife : public Weapon
{
public:

	Knife();
	//获取基础伤害
	virtual float getBaseDamage();

	//获取吸血
	virtual float getSuckBlood();

	//获取是否定身
	virtual bool getHold();

	//获取是否暴击
	virtual bool getCrit();
};