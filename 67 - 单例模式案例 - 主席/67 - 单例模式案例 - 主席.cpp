#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//������ϯ��
//���� ����ģʽ  Ϊ�˴������еĶ��󣬲��ұ�ֻ֤��һ������ʵ��
class ChairMan
{
public:
	//�ṩ get���� ���� ��ϯ
	static ChairMan* getInstance()
	{
		return singleMan;
	}

private:
	static ChairMan* singleMan;
	//1���캯�� ����˽�л�
	ChairMan()
	{
		cout << "����������ϯ - ϰ��ƽ" << endl;
	}
	//�������� ˽�л�
	ChairMan (const ChairMan& c)
	{}
};
ChairMan* ChairMan::singleMan = new ChairMan;

int main()
{
	ChairMan* cm1 = ChairMan::getInstance();
	ChairMan* cm2 = ChairMan::getInstance();
	if (cm1 == cm2)
	{
		cout << "cm1 == cm2" << endl;
	}
	else
	{
		cout << "cm2 != cm2" << endl;
	}
}