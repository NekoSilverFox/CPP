#include<string>
#include<iostream>
using namespace std;


//��ģ��
template<class TypeName, class TypeAge = int>  //��ģ�������Ĭ������(���ڿɸ���), ����ģ�岻���ԣ���
class Person
{
public:
	
	Person(TypeName name, TypeAge age)
	{
		this->m_age = age;
		this->m_name = name;
	}

	TypeName m_name;
	TypeAge m_age;

	void func()
	{
		cout << "������" << this->m_name << endl;
		cout << "���䣺" << this->m_age << endl;
	}
};


int main()
{
	// ���� ��ģ�� - ������ - �Զ������Ƶ��� 
	//				����ģ�� - ���� - �Զ������Ƶ��� 
	// Person p1("Nick", 14);


	//��ʾָ������
	Person<string, double> p1("Nick", 14);

	p1.func();

}