#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//1 ��ͨ�����뺯��ģ������
template<class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c'; // a = 97 
	myPlus(a, c); //�����Ƶ������� , ����ģ�岻���Խ�����ʽ����ת��
	cout << myPlus2(a, c) << endl; // 10 + 99  ��ͨ���� ���Խ�����ʽ����ת��������
}

//2 ����ͨ�����ͺ���ģ��ĵ��ù���
template<class T>
void myPrint(T a, T b)
{
	cout << "ģ����õ�myPrint" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "ģ����õ�myPrint(a,b,c)" << endl;
}
////ͨ��ģ�����ɵĺ���  ��ģ�庯��
//void myPrint(int a, int b, int c)
//{
//
//}

void myPrint(int a, int  b)
{
	cout << "��ͨ�������� myPrint" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;

	//1 �������������  ����ʹ����ͨ��������,
	//		 �������ֻ������û��ʵ�֣����ִ��󣡣�����
	myPrint(a, b);

	//2�� �����ǿ�Ƶ���ģ�� ����ô����ʹ�ÿղ����б�
	myPrint<>(a, b);

	//3�� ����ģ����Է�������
	int c = 30;
	myPrint(a, b, c);

	//4�� �������ģ����Բ������õ�ƥ�䣬��ô���ȵ��ú���ģ��
	char c1 = 'c';
	char d = 'd';
	myPrint(c1, d);

}



int main() {

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}