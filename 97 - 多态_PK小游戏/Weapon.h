#pragma once
#include<iostream>
#include<string>
using namespace std;

//������
class Weapon
{
public:
	//��ȡ�����˺�
	virtual float getBaseDamage() = 0;

	//��ȡ��Ѫ
	virtual float getSuckBlood() = 0;

	//��ȡ�Ƿ���
	virtual bool getHold() = 0;

	//��ȡ�Ƿ񱩻�
	virtual bool getCrit() = 0;


	string m_WeaponName; //��������
	int m_BaseDamage; //�����˺�
};
