#include"Hero.h"


// ��ʼ��
Hero::Hero()
{
	this->m_hp = 500.0;
	this->m_atk = 50;
	this->m_def = 50;
	this->m_name = "����ʦ";
	this->m_weapon = nullptr;
}

// װ������
void Hero::equipWeapon(Weapon* weapon)
{
	this->m_weapon = weapon;
	cout << "Ӣ�� " << this->m_name << " װ���� " << this->m_weapon->m_WeaponName << endl;
}

// ����
void Hero::attack(Monster* monster)
{
	float demage = 0;
	float addHP = 0;
	bool isHold = false;
	bool isCrit = false;

	if (this->m_weapon == nullptr)
	{
		demage = this->m_atk; // ����Ϊ��û�мӳ�
	}
	else
	{
		// �����˺�
		demage = this->m_atk + this->m_weapon->getBaseDamage();

		//  ������Ѫ
		addHP = this->m_weapon->getSuckBlood();

		// ����
		isHold = this->m_weapon->getHold();

		// ���㱩��
		isCrit = this->m_weapon->getCrit();
	}

	if (isCrit) // �����˺��ӳ�
	{
		demage = demage * 2;
		cout << "Ӣ�۴����˱����������ܵ���˫�����˺����˺�ֵ��" << demage << endl;
	}
	if (isHold)
	{
		cout << "������������ֹͣ����һ�غ�" << endl;
	}
	if (addHP > 0)
	{
		cout << "��������ѪЧ�������ӵ�Ѫ��Ϊ��" << addHP << endl;
	}

	// ���ù��ﶨ��
	monster->m_Hold = isHold;

	// ������ʵ�˺�
	float trueDemage = (demage - monster->m_def) > 0 ? demage - monster->m_def : 1;
	monster->m_HP -= trueDemage;

	this->m_hp += addHP;

	cout << "Ӣ�� " << this->m_name << " ������ " << monster->m_name << " ����� " << trueDemage << " �˺�" << endl;
	
}