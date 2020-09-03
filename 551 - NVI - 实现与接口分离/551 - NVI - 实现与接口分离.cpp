// 550 - NVI - 实现与接口不分离
// 参考资料 ：https://www.cnblogs.com/gnuhpc/archive/2012/01/17/2324836.html

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Base
{
public:
	virtual void Foo()
	{
		cout << "Locking" << endl;

		DoFoo1();

		DoFoo2();

		cout << "Unlocking" << endl;
	}

private:
	virtual void DoFoo1()
	{
		cout << "Base's DoFoo1" << endl;
	}

	virtual void DoFoo2()
	{
		cout << "Base's DoFoo2" << endl;
	}
};

class Derived : public Base
{
public:
	// 如果实现与接口分离，只需要修改特定函数
	virtual void DoFoo1()
	{
		cout << "Derived's DoFoo1" << endl;
	}

};
/*
注意，当且仅当子类需要调用基类的虚函数时才将虚函数设置为protected（否则没有权限），
并且NVI机制不适用于析构函数，对于析构函数，
如果设为公有则应该设置为虚拟（在允许多态删除的基类中），
否则设置为私有或者protected的非虚拟形式（不含多态删除的基类中）。

带来的风险：

首先是FBC问题（Fragile Base Class ），下边是一个例子：
*/

class Set {

	std::set<int> s_;

public:
	void add(int i)
	{
		s_.insert(i);
		add_impl(i); // Note virtual call.
	}

	void addAll(int* begin, int* end)
	{
		s_.insert(begin, end);   //  --------- (1)
		addAll_impl(begin, end); // Note virtual call.
	}

private:
	virtual void add_impl(int i) = 0;
	virtual void addAll_impl(int* begin, int* end) = 0;
};

class CountingSet : public Set
{
private:
	int count_;
	virtual void add_impl(int i)-+
	{
		count_++;
	}

	virtual void addAll_impl(int* begin, int* end)
	{
		count_ += std::distance(begin, end);
	}
};

/*
如果此时我们在父类中修改了addAll函数，改为将从begin到end的数字都调用一遍add函数，
那么，子类的功能就紊乱了——子类计数就会多记录一倍
（因为在子类中，add_impl每次都会计数一个，并且addAll_impl也会整体计数一次）。
所以，为了防止出现FBC，一般一个公有非虚函数调用一个私有虚函数。
*/

int main()
{
	Derived t1;

	t1.Foo();
}