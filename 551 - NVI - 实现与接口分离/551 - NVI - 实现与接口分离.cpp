// 550 - NVI - ʵ����ӿڲ�����
// �ο����� ��https://www.cnblogs.com/gnuhpc/archive/2012/01/17/2324836.html

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
	// ���ʵ����ӿڷ��룬ֻ��Ҫ�޸��ض�����
	virtual void DoFoo1()
	{
		cout << "Derived's DoFoo1" << endl;
	}

};
/*
ע�⣬���ҽ���������Ҫ���û�����麯��ʱ�Ž��麯������Ϊprotected������û��Ȩ�ޣ���
����NVI���Ʋ�������������������������������
�����Ϊ������Ӧ������Ϊ���⣨�������̬ɾ���Ļ����У���
��������Ϊ˽�л���protected�ķ�������ʽ��������̬ɾ���Ļ����У���

�����ķ��գ�

������FBC���⣨Fragile Base Class �����±���һ�����ӣ�
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
�����ʱ�����ڸ������޸���addAll��������Ϊ����begin��end�����ֶ�����һ��add������
��ô������Ĺ��ܾ������ˡ�����������ͻ���¼һ��
����Ϊ�������У�add_implÿ�ζ������һ��������addAll_implҲ���������һ�Σ���
���ԣ�Ϊ�˷�ֹ����FBC��һ��һ�����з��麯������һ��˽���麯����
*/

int main()
{
	Derived t1;

	t1.Foo();
}