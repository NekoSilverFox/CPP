// 550 - NVI - 实现与接口不分离
// 参考资料 ：https://www.cnblogs.com/gnuhpc/archive/2012/01/17/2324836.html

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void Foo()
	{
		cout << "Locking" << endl;

		cout << "Base's Foo" << endl;

		cout << "Unlocking" << endl;
	}
};

class Derived : public Base
{
public:
	// 如果实现与接口不分离，则从基类到子类都需要修改：
	virtual void Foo()
	{
		cout << "Locking" << endl;

		cout << "Derived's Foo" << endl;

		cout << "Unlocking" << endl;
	}
};
/*
注意，当且仅当子类需要调用基类的虚函数时才将虚函数设置为protected（否则没有权限），
并且NVI机制不适用于析构函数，对于析构函数，
如果设为公有则应该设置为虚拟（在允许多态删除的基类中），
否则设置为私有或者protected的非虚拟形式（不含多态删除的基类中）。
*/
int main()
{
	Derived t1;

	t1.Foo();
}