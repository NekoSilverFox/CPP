#include<iostream>
using namespace std;

class MyString
{
public:
	MyString()
	{}

	explicit MyString(int a) // explicit �ؼ���
	{
		m_A = a;
	}

	~MyString()
	{}

	int m_A;
};

int main()
{
	MyString str;

	// ֮���Ա�������Ϊ �� 10 �� ʹ���ˣ� explicit �ؼ��֣���ֹ��ʽ����ת����
	 str = 10; // ��ʽ����ת��  �൱�� t = t(10)   ���˿�-->��62 - ���캯��������ʱ����

	/*
	������ô�ֿ�д����
	MyString str2;
	str2(10);   <---- ����ᱨ��
	*/

	MyString str3(14);
}