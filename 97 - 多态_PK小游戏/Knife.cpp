#include"Knife.h"

Knife::Knife()
{
	this->m_BaseDamage = 10;
	this->m_WeaponName = "С��";
}

//��ȡ�����˺�
float Knife::getBaseDamage()
{
	return this->m_BaseDamage;
}

//��ȡ��Ѫ
float Knife::getSuckBlood()
{
	return 0;
}

//��ȡ�Ƿ���
bool Knife::getHold()
{
	return false;
}

//��ȡ�Ƿ񱩻�
bool Knife::getCrit()
{
	return 0;
}