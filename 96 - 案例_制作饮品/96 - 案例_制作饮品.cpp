#include<iostream>
using namespace std;

class MakeDrink
{
public:
	// 烧水
	virtual void Boil() = 0;

	// 冲泡
	virtual void Make() = 0;

	// 倒入杯中
	virtual void inCup() = 0;

	// 加入佐料
	virtual  void putSomeThing() = 0;

	// 制作流程 
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
		cout << "煮开自来水" << endl;
	}

	virtual void Make()
	{
		cout << "放入茶叶" << endl;
	}

	virtual void  inCup()
	{
		cout << "倒入茶杯" << endl;
	}

	virtual  void putSomeThing()
	{
		cout << "放入蜂蜜" << endl;

	}
};

// Make  Coffee
class Coffee : public MakeDrink
{
public:

	virtual void Boil()
	{
		cout << "煮开农夫山泉" << endl;
	}

	virtual void Make()
	{
		cout << "放入雀巢卡飞" << endl;
	}

	virtual void  inCup()
	{
		cout << "倒入咖啡杯" << endl;
	}

	virtual  void putSomeThing()
	{
		cout << "放入牛奶" << endl;
	}
};

// 业务代码
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