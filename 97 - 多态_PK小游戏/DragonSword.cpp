#include"DragonSword.h"

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "屠龙宝刀";
	this->suckRate = 20;
	this->holdRate = 25;
	this->critRate = 23;
}

//获取基础伤害
float DragonSword::getBaseDamage()
{
	return this->m_BaseDamage;
 }

//获取吸血
float DragonSword::getSuckBlood()
{
	if (isTrigger(this->suckRate))
	{
		return this->m_BaseDamage * 0.5;
	}
	return 0;
 }

//获取是否定身
bool DragonSword::getHold()
{
	if (isTrigger(this->holdRate))
	{
		return true;
	}
	return false;
 }

//获取是否暴击
bool DragonSword::getCrit()
{
	if (isTrigger(this->critRate))
	{
		return true;
	}
	return false;
 }

// 判断是否触发技能
bool DragonSword::isTrigger(float rang)
{
	float num = rand() % 100 + 1;
	if (rang > num)
	{
		return true;
	}
	return false;
}