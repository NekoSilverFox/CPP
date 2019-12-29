#include<iostream>
#include <string>
using namespace std;

class Game
{
public:
	Game()
	{
		cout << "Game 默认构造函数调用" << endl;
	}

	Game(string name)
	{
		cout << "Game 有参 构造函数调用" << endl;
		m_GameName = name;
	}

	~Game()
	{
		cout << "Game 默认析构函数调用" << endl;
	}

	string m_GameName;
};

class Phone
{
public:
	Phone()
	{
		cout << "Phone 默认构造函数调用" << endl;
	}

	Phone(string name)
	{
		cout << "Phone 有参函数调用" << endl;
		m_PhoneName = name;

	}

	~Phone()
	{
		cout << "Phone 默认析构函数调用" << endl;
	}
	string m_PhoneName;
};

class Person
{
public:
	Person()
	{
		cout << "Person 默认构造函数调用" << endl;
	}

	//																												↓ 别忘了这个 冒号！！！！ 初始化列表！！！！
	Person(string personName, string phoneName, string gameName) : m_PersonName(personName), m_Phone(phoneName), m_game(gameName)
	{
		// 列表都初始化了，这啥都不用写！！！！！！ 
		// 写个锤子写！！！！！！
	}

	void printInfoPerson()
	{
		cout << m_PersonName << " 拿着 《 " << m_Phone.m_PhoneName << " 》手机，玩着 " << m_game.m_GameName << " 游戏" << endl;
	}

	~Person()
	{
		cout << "Person 默认析构函数调用" << endl;
	}

	string m_PersonName;
	Game m_game;
	Phone m_Phone;
};

int main()
{
	Person pers;
	pers = { "狗蛋", "老罗的锤子","贪吃蛇" }; // 利用 Person 的初始化列表进行 赋值！！！！
	pers.printInfoPerson();
}