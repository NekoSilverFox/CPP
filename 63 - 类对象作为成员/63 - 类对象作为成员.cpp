#include<iostream>
#include <string>
using namespace std;

class Game
{
public:
	Game()
	{
		cout << "Game Ĭ�Ϲ��캯������" << endl;
	}

	Game(string name)
	{
		cout << "Game �в� ���캯������" << endl;
		m_GameName = name;
	}

	~Game()
	{
		cout << "Game Ĭ��������������" << endl;
	}

	string m_GameName;
};

class Phone
{
public:
	Phone()
	{
		cout << "Phone Ĭ�Ϲ��캯������" << endl;
	}

	Phone(string name)
	{
		cout << "Phone �вκ�������" << endl;
		m_PhoneName = name;

	}

	~Phone()
	{
		cout << "Phone Ĭ��������������" << endl;
	}
	string m_PhoneName;
};

class Person
{
public:
	Person()
	{
		cout << "Person Ĭ�Ϲ��캯������" << endl;
	}

	//																												�� ��������� ð�ţ������� ��ʼ���б�������
	Person(string personName, string phoneName, string gameName) : m_PersonName(personName), m_Phone(phoneName), m_game(gameName)
	{
		// �б���ʼ���ˣ���ɶ������д������������ 
		// д������д������������
	}

	void printInfoPerson()
	{
		cout << m_PersonName << " ���� �� " << m_Phone.m_PhoneName << " ���ֻ������� " << m_game.m_GameName << " ��Ϸ" << endl;
	}

	~Person()
	{
		cout << "Person Ĭ��������������" << endl;
	}

	string m_PersonName;
	Game m_game;
	Phone m_Phone;
};

int main()
{
	Person pers;
	pers = { "����", "���޵Ĵ���","̰����" }; // ���� Person �ĳ�ʼ���б���� ��ֵ��������
	pers.printInfoPerson();
}