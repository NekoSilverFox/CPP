#include<iostream>
#include<ctime>
#include"Hero.h"
#include"Knife.h"
#include"Monster.h"
#include"DragonSword.h"
#include"Weapon.h"
using namespace std;

void playGame()
{
	// ��������
	Monster* monster = new Monster;

	// ����Ӣ��
	Hero* hero = new Hero;

	// ��������
	Weapon* knife = new Knife;
	Weapon* dragon = new DragonSword;

	// ѡ������
	cout << "��ѡ��������" << endl;
	cout << "1.���ֿ�ȭ \n2.С��\n3.������" << endl << endl;

	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
		cout << "��ţ�� " << endl;
		break;
	case 2:
		hero->equipWeapon(knife);
		break;
	case 3:
		hero->equipWeapon(dragon);
	}

	getchar();

	int round = 0;

	while (true)
	{
		getchar();
		system("cls");
		cout << endl << "----------------��ǰ�� " << round << " �غ�----------------" << endl;

		if (hero->m_hp <= 0)
		{
			cout << hero->m_name << " ������" << endl;
			cout << "---GAME OVER---" << endl;
			break;
		}
		hero->attack(monster);


		if (monster->m_HP <= 0)
		{
			cout << monster->m_name << " ������" << endl;
			break;
		}
		monster->Attack(hero);

		if (hero->m_hp <= 0)
		{
			cout << hero->m_name << "��������Ϸ������" << endl;
		}
		round++;
		cout << endl << "Ӣ��HP: " << hero->m_hp << endl;
		cout <<  "����HP: " << monster->m_HP << endl;
	}
	delete monster;
	delete hero;
	delete knife;
	delete dragon;
}

int main()
{
	srand((unsigned int)time(NULL));

	playGame();
}