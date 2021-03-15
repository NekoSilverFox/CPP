#include"Monster.h"


Monster::Monster()
{
	this->m_HP = 300;
	this->m_atk = 70;
	this->m_def = 40;
	this->m_Hold = false;
	this->m_name = "特朗普";
}

void Monster::Attack(Hero* hero)
{
	if (this->m_Hold)
	{
		cout << this->m_name << " 被定身了，本回合无法攻击！" << endl;
		return;
	}

	// 计算攻击的伤害
	float trueDemage = (this->m_atk - hero->m_def) > 0 ? this->m_atk - hero->m_def : 1;

	hero->m_hp -= trueDemage;

	cout << m_name << " 攻击了 " << hero->m_name << " 造成了 " << trueDemage << " 伤害 " << endl;
	// cout << hero->m_name << " 剩余血量为：" << hero->m_hp << endl;
}