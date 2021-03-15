#include<iostream>
using namespace std;

class MakeDrink
{
public:
	// ��ˮ
	virtual void Boil() = 0;

	// ����
	virtual void Make() = 0;

	// ���뱭��
	virtual void inCup() = 0;

	// ��������
	virtual  void putSomeThing() = 0;

	// �������� 
	void  howToMake()
	{
		Boil();
		Make();
		inCup();
		putSomeThing();
	}
};


// Make Tea
class Tea : public MakeDrink
{
	virtual void Boil()
	{
		cout << "������ˮ" << endl;
	}

	virtual void Make()
	{
		cout << "�����Ҷ" << endl;
	}

	virtual void  inCup()
	{
		cout << "����豭" << endl;
	}

	virtual  void putSomeThing()
	{
		cout << "�������" << endl;

	}
};

// Make  Coffee
class Coffee : public MakeDrink
{
public:

	virtual void Boil()
	{
		cout << "��ũ��ɽȪ" << endl;
	}

	virtual void Make()
	{
		cout << "����ȸ������" << endl;
	}

	virtual void  inCup()
	{
		cout << "���뿧�ȱ�" << endl;
	}

	virtual  void putSomeThing()
	{
		cout << "����ţ��" << endl;
	}
};

// ҵ�����
void BussineCode(MakeDrink* howtomake)
{
	howtomake->howToMake();
}

int main()
{
	BussineCode(new Tea);
	cout << endl;
	BussineCode(new Coffee);
}