// 129 - 管理虚方法：override和final
// 用于虚方法 !!!!!
// override - 虚说明符，指出想要覆盖的虚函数，放在参数列表后面
// final - 禁止派生类覆盖特定的虚方法

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
	// 函数无法重写， 因为在基类中使用了 final 关键字 

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