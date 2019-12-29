#include<iostream>
#include<string>
using namespace std;

// ע�⣬��������ģ�壡
template<class TypeName, class TypeAge>
class Person
{
public:

	Person(TypeName name, TypeAge age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	
	void printInfo()
	{
		cout << "Name : " << this->m_name << endl;
		cout << "Age : " << this->m_age << endl;
		cout << endl;
	}

	TypeName m_name;
	TypeAge m_age;
};

// 1. ��ʾָ������
void showInfo(Person<string, int> &p)
{
	p.printInfo();
}


// 2. ����ģ�廯
template<class T1, class T2>
void showInfo2(Person<T1, T2> &p)
{
	//��β鿴����
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
	p.printInfo();
}



// 3. ����ģ�廯
template<class T>
void showInfo3(T& p)
{
	cout << typeid(T).name() << endl;
	p.printInfo();
}

int main()
{
	// ���Կ��������۲���ʲô���ݷ�ʽ����ʼ���ķ�ʽ����һ���ģ�������
	// ע�⣬��������ģ�壡
	Person<string, int> p1("Nick", 14);

	// 1. ��ʾָ������
	showInfo(p1);

	// 2. ����ģ�廯
	showInfo2(p1);

	// 3. ����ģ�廯
	showInfo3(p1);
}

