#include<iostream>
using namespace std;

/*
��׼����������cin���ص����յĺ���
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
cin.getline()
cin.ignore()
cin.peek() ͵��
cin.putback()

*/

void cinget01()
{
	// ��� ����as  �������С� a   s ���С�
	// ��һ��a�� - a��
	// �ڶ���a2�� - s
	// ������a3�� - ����
	// ���ĸ�a4�� - �ȴ��´�����
	char a = cin.get();
	cout <<"a =  " <<  a << endl;

	char a2 = cin.get();
	cout << "a2 =  " << a2 << endl;

	char a3 = cin.get();
	cout << "a3 =  " << a3 << endl;

	char a4 = cin.get();
	cout << "a4 =  " << a4 << endl;
}

// cin.get(��������)  ���Զ��ַ���
void cinget02() // ���ۣ�cin.get(��������)  ��ȡ�ַ���ʱ������ѻ��з����ߣ����л��ڻ�����
{
	char arr[1024];
	cin.get(arr, 1024); // �����ַ���
	
	char a = cin.get();
	if (a == '\n')
	{
		cout << "���л��ڻ�����" << endl;
	}
	else
	{
		cout << "���в��ڻ�����" << endl;
	}

	cout << arr << endl;

}

void cingetline() // ���ۣ�cin.getline() �ѻ��з���ȡ�������ӵ���
{
	char arr[1024];
	cin.getline(arr, 1024);
	char a = cin.get();
	if (a == '\n')	{	cout << "���л��ڻ�����" << endl;}
	else	{cout << "���в��ڻ�����" << endl;}
	cout << arr << endl;
}


void cin_ignore01()
{
	cin.ignore(); // û�в����������һ���ַ�
	char c = cin.get();

	cout << "c = " << c << endl;
}

void cin_ignore02()
{
	char arr[1024];
	cin.ignore(2); // ���� n , ������� n ���ַ�
	cin.get(arr, 1024);
	cout << "arr = " << arr << endl;
}



// ͵��
void cin_peek()
{
	char c = cin.peek(); // ������� as��͵��һ��������ַ��ٷŻػ��������������л��� as
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;
}


// �Ż�
void cin_putback()
{
	char c = cin.get();
	cin.putback(c);
	char arr[1024];
	cin.getline(arr, 1024);
	cout << arr << endl;
}



int main()
{
	// cinget02();
	// cingetline();
	// cin_ignore01();
	// cin_ignore02();
	// cin_peek();
	cin_putback();
}