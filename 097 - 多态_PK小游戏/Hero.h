#pragma once
#include<iostream>
#include<string>
#include"Weapon.h"
#include"Monster.h"
using namespace std;

class Monster;

class Hero
{
public:
	Hero();

	string m_name; // 人名
	float m_atk;			// 攻击力
	float m_def;		// 防御力
	float m_hp;		// 血量

	Weapon* m_weapon; // 武器

	void equipWeapon(Weapon* weapon);

	void attack(Monster* monster);

};