#include<iostream>
using namespace std;
class abstractCaculator
{
public:
	void setVal(double val1, double val2)
	{
		this->val1 = val1;
		this->val2 = val2;
	}
	double getVal1()
	{
		return val1;
	}
	double getVal2()
	{
		return val2;
	}

	// virtual double getAnswer() { return 0; } //虚函数
	
	//纯虚函数
	//如果父类中有了 纯虚函数  子类继承父类，就必须要实现 纯虚函数
	//如果父类中 有了 纯虚函数 ，这个父类 就无法实例化对象了
	//这个类有了纯虚函数，通常又称为 抽象类
	virtual double getAnswer() = 0;				// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
private:
	double val1;
	double val2;
};

// +
class PlusCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() + getVal2();
	}
};

class SubCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() - getVal2();
	}
};

class ChengCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() * getVal2();
	}
};

class ChuCaculator : public abstractCaculator
{
	virtual double getAnswer()
	{
		return getVal1() / getVal2();
	}
};

//如果父类中有了 纯虚函数  子类继承父类，就必须要实现 纯虚函数
class test : public abstractCaculator
{
	virtual double getAnswer()
	{
		return 0;
	}
};

int main()
{
	abstractCaculator* t1 = new PlusCaculator;

	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	t1 = new SubCaculator;
	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	t1 = new ChengCaculator;
	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	t1 = new ChuCaculator;
	t1->setVal(10, 20);
	cout << t1->getAnswer() << endl;
	delete t1;

	test t1; //如果父类中有了 纯虚函数  子类继承父类，就必须要实现 纯虚函数


	//如果父类有了纯虚函数，不能实例化对象了
	abstractCaculator sba1;
	abstractCaculator* abs2 = new abstractCaculator;
}