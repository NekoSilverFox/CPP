#include<iostream>
//#include<stdlib.h>
using namespace std;

class Person
{
public:
	Person()
	{
		// m_A = 0;  // ͨ���������ʲ�����ù��캯�������Բ����ù��캯����ʼ����
	}

	Person(int a)
	{

	}

	~Person()
	{}
								// ���� static ���Ǿ�̬��Ա�������Ṳ������
	static int m_A;  // ��̬��Ա����������������������<-���г�ʼ����	
							// ��̬��Ա���� Ҳ����Ȩ�޵�

private:
	static int m_B; //˽��Ȩ�� �����ⲻ�ܷ��ʣ������Գ�ʼ��!!
};

//�����ʼ��ʵ��
// ��Ϊ�Ƿ���ȫ���������Բ��ܷ����κκ�����ʵ�ֳ�ʼ����
int Person::m_A = 0; // !!
int Person::m_B = 0; // !!


int main()
{

	// 1. ͨ�������������
	Person p1;
	p1.m_A = 10;

	Person p2;
	p2.m_A = 20;

	cout << "p1.m_A = " << p1.m_A << endl; // ��������
	cout << "p2.m_A = " << p2.m_A << endl;


	// 2. ͨ��������������
	cout << "ͨ���������� Person::m_A ��" << Person::m_A << endl;
	// cout << "ͨ���������� Person::m_B ��" << Person::m_B << endl; //˽��Ȩ���������޷�����

}