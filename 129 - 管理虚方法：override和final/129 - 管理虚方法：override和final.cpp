// 129 - �����鷽����override��final
// �����鷽�� !!!!!
// override - ��˵������ָ����Ҫ���ǵ��麯�������ڲ����б����
// final - ��ֹ�����า���ض����鷽��

#include <iostream>
using namespace std;

class Base1
{
public:
	int a;
public:
	virtual void speak()
	{
		cout << "Yiff Yiff" << endl;
	}
};

class Driv1 : public Base1
{
public:
	virtual void speak() override // !!!
	{
		cout << "Son 1  speak" << endl;
	}
};

// ==================================================

class Base2
{
public:
	int a;
public:
	virtual void speak2() final
	{
		cout << "The speak2() function in class - Base2" << endl;
	}
};

class Driv2 : public Base2
{
public:
	// �����޷���д�� ��Ϊ�ڻ�����ʹ���� final �ؼ��� 

	/*virtual void speak2() override
	{
		cout << " The speak2() function in classs - Son2 " << endl;
	}*/
};

int main()
{
	Driv1 d1;
	d1.speak();



	Driv2 d2;
	d2.speak2();

}