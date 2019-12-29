#include<iostream>
using namespace std;

// ���� int ���� a �� b ������
void mySwepInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ���� char ���� c �� d ������
void mySwepChar(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

// =====================================================
//���ͣ��߼��ַǳ�����
//���Ͳ�����  ���ͱ�� -- ģ�弼��
template<class T> // ���߱����� �����������T��Ҫ����T��һ��ͨ�õ�����
void mySwep(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// =====================================================
template<class D> // �ȼ��� template<class T>
void mySwep2() {}
void mySwep3(){}  // ����ģ�壬�����������Ĳ��ǣ�������
// =====================================================

int main()
{
	int a = 10;
	int b = 20;
	char c1 = 'c';
	mySwepInt(a, b);

	//1 �Զ������Ƶ�,�����в������Ͳſ����Ƶ�
	//mySwap(a, c1); �Ƶ�������T�����Բ�������
	mySwep(a, b);
	//2 ��ʾָ������
	mySwep<int>(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	char c = 'c';
	char d = 'd';
	mySwepChar(c, d);
	mySwep(a, b);
	cout << c << endl;
	cout << d << endl;


	//ģ�����Ҫָ����T�ſ���ʹ��
	mySwep2();
	mySwep2<string>();

	mySwep3();
}