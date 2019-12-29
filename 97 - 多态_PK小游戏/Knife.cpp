#include"Knife.h"

Knife::Knife()
{
	this->m_BaseDamage = 10;
	this->m_WeaponName = "小刀";
}

//获取基础伤害
float Knife::getBaseDamage()
{
	return this->m_BaseDamage;
}

//获取吸血
float Knife::getSuckBlood()
{
	return 0;
}

//获取是否定身
bool Knife::getHold()
{
	return false;
}

//获取是否暴击
bool Knife::getCrit()
{
	return 0;
}