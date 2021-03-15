#include"Monster.h"


Monster::Monster()
{
	this->m_HP = 300;
	this->m_atk = 70;
	this->m_def = 40;
	this->m_Hold = false;
	this->m_name = "������";
}

void Monster::Attack(Hero* hero)
{
	if (this->m_Hold)
	{
		cout << this->m_name << " �������ˣ����غ��޷�������" << endl;
		return;
	}

	// ���㹥�����˺�
	float trueDemage = (this->m_atk - hero->m_def) > 0 ? this->m_atk - hero->m_def : 1;

	hero->m_hp -= trueDemage;

	cout << m_name << " ������ " << hero->m_name << " ����� " << trueDemage << " �˺� " << endl;
	// cout << hero->m_name << " ʣ��Ѫ��Ϊ��" << hero->m_hp << endl;
}