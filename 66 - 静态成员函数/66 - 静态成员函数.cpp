#include<iostream>
using namespace std;

class Person
{
public:
	int m_A;
	static int m_A_Public_Static;

	//��ͨ��Ա���� ���Է�����ͨ��Ա������Ҳ���Է��ʾ�̬��Ա����
	void funPublic()
	{
		m_A = 10; 
		m_A_Public_Static = 10;
		cout << "��ͨ ��Ա��������" << endl;
	}

	//��̬��Ա����
	//�����Է���  ��ͨ��Ա����
	//���Է��� ��̬��Ա����
	static void funStaticPublic()
	{
		m_A = 10; // <- ERROR
		m_A_Public_Static = 10;
		cout << "��̬ ��Ա��������" << endl;
	}

private:
	int m_B;
	static int m_B_Private_Static;

	//��̬��Ա���� Ҳ����Ȩ�޵�
	static void fun2_Private_Static()
	{
		cout << "˽�� - ��̬ ��Ա���� ����" << endl;
	}
	
};

int main()
{

	Person p1;
	p1.funStaticPublic();
	Person::funStaticPublic();

	//��̬��Ա���� Ҳ����Ȩ�޵�
	Person::fun2_Private_Static(); // <- ���ɷ���
}