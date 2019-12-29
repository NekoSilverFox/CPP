#include<iostream>
#include<string>
using namespace std;

template<class TypeName, class TypeAge>
class Base
{
public:
	void func()
	{
		cout << this->m_age << endl << this->m_name << endl;
	}

public:
	TypeName m_name;
	TypeAge m_age;
};

//child�̳��� base�������base�е�T�����ͣ�����T�޷������ڴ�
class Child : public Base<string, int> // ����Ϊ��������ڴ棬��Ȼ�ᱨ��
{};


//child2 Ҳ��ģ����
template<class T, class L1, class L2>
class Child2 : public Base<L1, L2>
{
public:

	void func()
	{
		cout << typeid(T).name() << endl;
		cout << typeid(L1).name() << endl;
		cout << typeid(L2).name() << endl;
	}
	
	T m_name;
};

int main()
{

	Child2 <int, string, int>c1;
	c1.func();
}