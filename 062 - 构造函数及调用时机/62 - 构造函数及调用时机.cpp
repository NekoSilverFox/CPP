#include <iostream>
using namespace std;

//����
//���ղ������з���  �޲ι��캯����Ĭ�Ϲ��캯����   �вι��캯��
//�������ͽ��з���  ��ͨ���캯��  �������캯��
class Person
{

	//�������������д��public�²ſ��Ե��õ�
public:
	Person() // Ĭ�ϣ��޲� ���캯������
	{
		cout << "Ĭ�� ���캯������" << endl;
	}

	Person(int a)
	{
		cout << "�в� ���캯������" << endl;
	}

	Person(const Person& p) // �������캯������
	{
		m_Age = p.m_Age;
		cout << "���� ���캯������" << endl;

	}

	~Person()
	{ 
		cout << "Ĭ�� ������������" << endl; 
	}

	int m_Age;
};

int main()
{
	//���캯�����÷�ʽ
	//���ŷ�����
	Person p1(100);
	p1.m_Age = 16;
	Person p2(p1); // ����
	Person p3; //Ĭ�Ϲ��캯�� ��Ҫ�� ()   
	Person p3(); //��������Ϊ�����Ǻ��������� ��������


	//��ʾ������
	Person p4 = Person(100);
	Person p5 = Person(p4);

	//Person(100) ���������� ,���������ص㣬��������������˶����������ģ���ô�� ->����<- �����������ͷ��������

	//�����ÿ������캯�� ��ʼ����������
	Person p6 = Person(p5); //���д����ֵ����������Ϊ��д�� Person p5; ��������������д����ֵ����ô����


	Person p7 = 100; //�൱�ڵ����� Person p7 = Person(100) ����ʽ����ת��
	Person p8 = p7; // �൱��  Person p8 = Person(p7);

}