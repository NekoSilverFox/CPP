#include<string>
#include<iostream>
using namespace std;

class Person1
{
public:
	void print_1()
	{
		cout << "Person 1 �ĵ���" << endl;
	}
};

class Person2
{
public:
	void print_2()
	{
		cout << "Person 2 �ĵ���" << endl;
	}
};

// ��ģ��
template<class T>
class myClass
{
public:
	T obj;

	//void showWay()
	//{
	//	obj.print_1();
	//	obj.print_2();
	//}
	
	void func1()
	{
		obj.print_1(); 
	}
	void func2() // ��� û�е��ã��ǲ�����ǰ����ģ���ȻҲ���ᱨ��
	{
		obj.print_2();
	}

};

int main()
{
	myClass<Person1> mc;
	mc.func1();
	// mc.func2();
}

// ���� ����ģ���г�Ա���� һ��ʼ���ᴴ��������������    -----> ����ʱ��ȥ���� <------ ��������