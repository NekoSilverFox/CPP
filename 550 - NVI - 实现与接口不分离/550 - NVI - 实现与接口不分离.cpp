// 550 - NVI - ʵ����ӿڲ�����
// �ο����� ��https://www.cnblogs.com/gnuhpc/archive/2012/01/17/2324836.html

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void Foo()
	{
		cout << "Locking" << endl;

		cout << "Base's Foo" << endl;

		cout << "Unlocking" << endl;
	}
};

class Derived : public Base
{
public:
	// ���ʵ����ӿڲ����룬��ӻ��ൽ���඼��Ҫ�޸ģ�
	virtual void Foo()
	{
		cout << "Locking" << endl;

		cout << "Derived's Foo" << endl;

		cout << "Unlocking" << endl;
	}
};
/*
ע�⣬���ҽ���������Ҫ���û�����麯��ʱ�Ž��麯������Ϊprotected������û��Ȩ�ޣ���
����NVI���Ʋ�������������������������������
�����Ϊ������Ӧ������Ϊ���⣨�������̬ɾ���Ļ����У���
��������Ϊ˽�л���protected�ķ�������ʽ��������̬ɾ���Ļ����У���
*/
int main()
{
	Derived t1;

	t1.Foo();
}