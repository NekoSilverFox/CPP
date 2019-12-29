#pragma once
#include<iostream>
#include<string>
#include"Weapon.h"
#include"Hero.h"
using namespace std;

class Hero;

class Monster
{
public:
	Monster();

	string m_name;
	float m_HP;
	float m_atk;
	float m_def;
	bool m_Hold;

	void Attack(Hero* hero);
};