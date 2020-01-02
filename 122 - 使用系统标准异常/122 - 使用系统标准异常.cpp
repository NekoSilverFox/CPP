#include<iostream>
#include<stdexcept> // Ҫ����ͷ�ļ�
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void printInfo()
	{
		if (this->m_age < 0 || this->m_age > 120)
		{
			throw out_of_range("����Խ���쳣");  // ϵͳ�Դ����쳣�� ��װ��һ�� what() ������ע��ʹ�÷���
			throw range_error("�����");
		}
		cout << "Name : " << this->m_name << endl << "Age : " << this->m_age << endl;
	}

public:
	string m_name;
	int m_age;
};

int main()
{
	Person p1("Nick", -13);
	try
	{
		p1.printInfo();
	}
	catch (out_of_range& err) // ��֮ǰһ����Ҫ��һ�����ã������׵Ļ� �ؿ� 119 - �Զ����쳣�Ĳ���
	{
		cout << err.what() << endl; // ϵͳ�Դ����쳣�� ��װ��һ�� what() ����������ֱ�ӵ���
	}
	catch (range_error& err)
	{
		cout << err.what() << endl;
	}
}