#include"DragonSword.h"

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "��������";
	this->suckRate = 20;
	this->holdRate = 25;
	this->critRate = 23;
}

//��ȡ�����˺�
float DragonSword::getBaseDamage()
{
	return this->m_BaseDamage;
 }

//��ȡ��Ѫ
float DragonSword::getSuckBlood()
{
	if (isTrigger(this->suckRate))
	{
		return this->m_BaseDamage * 0.5;
	}
	return 0;
 }

//��ȡ�Ƿ���
bool DragonSword::getHold()
{
	if (isTrigger(this->holdRate))
	{
		return true;
	}
	return false;
 }

//��ȡ�Ƿ񱩻�
bool DragonSword::getCrit()
{
	if (isTrigger(this->critRate))
	{
		return true;
	}
	return false;
 }

// �ж��Ƿ񴥷�����
bool DragonSword::isTrigger(float rang)
{
	float num = rand() % 100 + 1;
	if (rang > num)
	{
		return true;
	}
	return false;
}