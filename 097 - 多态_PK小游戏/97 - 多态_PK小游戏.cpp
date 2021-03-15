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
	// 创建怪物
	Monster* monster = new Monster;

	// 创建英雄
	Hero* hero = new Hero;

	// 创建武器
	Weapon* knife = new Knife;
	Weapon* dragon = new DragonSword;

	// 选择武器
	cout << "请选择武器：" << endl;
	cout << "1.赤手空拳 \n2.小刀\n3.屠龙刀" << endl << endl;

	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
		cout << "你牛逼 " << endl;
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
		cout << endl << "----------------当前第 " << round << " 回合----------------" << endl;

		if (hero->m_hp <= 0)
		{
			cout << hero->m_name << " 已阵亡" << endl;
			cout << "---GAME OVER---" << endl;
			break;
		}
		hero->attack(monster);


		if (monster->m_HP <= 0)
		{
			cout << monster->m_name << " 死亡！" << endl;
			break;
		}
		monster->Attack(hero);

		if (hero->m_hp <= 0)
		{
			cout << hero->m_name << "阵亡，游戏结束！" << endl;
		}
		round++;
		cout << endl << "英雄HP: " << hero->m_hp << endl;
		cout <<  "怪物HP: " << monster->m_HP << endl;
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