#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////////////////////////////////////////���м̳�////////////////////////////////////////
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//���м̳�
class Son1 : public Base1
{
public:
	void func()
	{
		//cout << m_C << endl; //������˽�е����� ���ɼ̳�
		cout << m_A << endl;	//�����й��е����� �ɼ̳У�����public
		cout << m_B << endl;		//�����б��������� �ɼ̳У�������protected ������ʲ���
	}

};
void myFunc()
{
	Son1 s1;
	s1.m_A;
	//s1.m_B;
}

////////////////////////////////////////�����̳�////////////////////////////////////////

class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2 :protected Base2
{
public:
	void func()
	{
		//cout << m_C << endl; //������˽�е����� ���ɼ̳�
		cout << m_A << endl;	//�����й��е����� �ɼ̳У�����protected
		cout << m_B << endl;		//�����б��������� �ɼ̳У�����protected
	}

};
void myFunc2()
{
	Son2 s;
	//s.m_A; ���ܷ���
	//s.m_B; ���ܷ���
}


////////////////////////////////////////˽�м̳�////////////////////////////////////////
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;

};

class Son3 :private Base3
{
public:
	void func()
	{
		//cout << m_C << endl; //������˽�е����� ���ɼ̳�
		cout << m_A << endl;	//�����й��е����� �ɼ̳У�����private
		cout << m_B << endl;		//�����б��������� �ɼ̳У�����private
	}

};

class GrandSon3 :public Son3
{
public:
	void myFunc()
	{
		cout << m_A << endl; //�������� ���ʲ��� m_A����Ϊ��Son3��m_A�Ѿ���˽��������
	}

};



int main() {
	system("pause");
	return EXIT_SUCCESS;
}