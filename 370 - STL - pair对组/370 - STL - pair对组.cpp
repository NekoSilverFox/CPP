#include<iostream>
#include<string>
using namespace std;

// ʹ��pair���飬����Ҫ�����κ�ͷ�ļ�������


// ��һ�ִ���
void test01()
{
	// ����ֻ��������������
	pair<string, int> pair_1("Tom", 13);

	// ȡֵ
	cout << pair_1.first << "  " << pair_1.second << endl;
}


// �ڶ��ִ���
void test02()
{
	// ����ʹ��
	pair<string, int> pair_2 = make_pair("Jerry", 14);

	cout << pair_2.first << "  " << pair_2.second << "  " << endl;
}

int main()
{
	test01();
	test02();
}