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

	string m_name; // ����
	float m_atk;			// ������
	float m_def;		// ������
	float m_hp;		// Ѫ��

	Weapon* m_weapon; // ����

	void equipWeapon(Weapon* weapon);

	void attack(Monster* monster);

};