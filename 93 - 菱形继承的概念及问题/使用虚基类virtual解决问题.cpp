#include<iostream>
using namespace std;

class Animal
{
public:
	Animal() :m_age(0) {}
public:
	int m_age;
};

class Sheep : virtual public Animal
{
	// ��ʵ��
};

class Tuo : virtual public Animal
{

};

class SheepTuo : public Sheep, public Tuo
{

};

int main()
{
	SheepTuo st;
	st.Sheep::m_age = 10;
	st.Tuo::m_age = 20;

	// cout << st.m_age << endl; ���������
	cout << st.Sheep::m_age << endl;
	cout << st.Tuo::m_age << endl;
	cout << st.m_age << endl; // ��������ԣ���������һ������
	

}

// ��ͼ�ڸ�Ŀ¼�ļ����У���
// ���152 ҳ
// ע�⿴ƫ��������