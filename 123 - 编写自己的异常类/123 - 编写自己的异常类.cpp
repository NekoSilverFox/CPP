#include<iostream>
#include<stdexcept> // ע�����ͷ�ļ�
#include<iostream>
using namespace std;

class MyOutofRange : public exception // !!!!!! �Լ���д���쳣Ҫ�̳��� exception �࣡������
{
public:
	MyOutofRange(string errorInfo) // 1. Ҫ��д�вι��캯��
	{
		this->m_error = errorInfo;
	}
	~MyOutofRange() {}

	virtual const char* what() // 2. Ҫ��д���ڴ�ӡ������Ϣ�� what() ����
	{
		//���� ������Ϣ
		return this->m_error.c_str(); // �� string תΪ char*        stringxxxx.c_str()
	}

private:
	string m_error;
};

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
		if (age < 0 || age > 120)
		{
			throw MyOutofRange("���ǲ��Ǻ�������������");
		}
	}

	string m_name;
	int m_age;
};

int main()
{
	try
	{
		Person p1("Nick", -10);
	}
	catch (MyOutofRange& err)
	{
		cout << err.what() << endl;
	}

}