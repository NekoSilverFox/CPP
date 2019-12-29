#include"Hero.h"


// 初始化
Hero::Hero()
{
	this->m_hp = 500.0;
	this->m_atk = 50;
	this->m_def = 50;
	this->m_name = "刘法师";
	this->m_weapon = nullptr;
}

// 装备武器
void Hero::equipWeapon(Weapon* weapon)
{
	this->m_weapon = weapon;
	cout << "英雄 " << this->m_name << " 装备了 " << this->m_weapon->m_WeaponName << endl;
}

// 攻击
void Hero::attack(Monster* monster)
{
	float demage = 0;
	float addHP = 0;
	bool isHold = false;
	bool isCrit = false;

	if (this->m_weapon == nullptr)
	{
		demage = this->m_atk; // 武器为空没有加成
	}
	else
	{
		// 基础伤害
		demage = this->m_atk + this->m_weapon->getBaseDamage();

		//  计算吸血
		addHP = this->m_weapon->getSuckBlood();

		// 定身
		isHold = this->m_weapon->getHold();

		// 计算暴击
		isCrit = this->m_weapon->getCrit();
	}

	if (isCrit) // 暴击伤害加成
	{
		demage = demage * 2;
		cout << "英雄触发了暴击，怪物受到了双倍的伤害！伤害值：" << demage << endl;
	}
	if (isHold)
	{
		cout << "触发定身，怪物停止攻击一回合" << endl;
	}
	if (addHP > 0)
	{
		cout << "触发了吸血效果，增加的血量为：" << addHP << endl;
	}

	// 设置怪物定身
	monster->m_Hold = isHold;

	// 设置真实伤害
	float trueDemage = (demage - monster->m_def) > 0 ? demage - monster->m_def : 1;
	monster->m_HP -= trueDemage;

	this->m_hp += addHP;

	cout << "英雄 " << this->m_name << " 攻击了 " << monster->m_name << " 造成了 " << trueDemage << " 伤害" << endl;
	
}