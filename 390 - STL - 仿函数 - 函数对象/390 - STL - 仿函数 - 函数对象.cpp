#include<iostream>
using namespace std;

// ���������������˺������÷��ŵ���
class MyPrint
{
public:
	int operator()(int num)
	{
		cout << "Number = " << num << endl;
		return ++count_;
	}

	int count_ = 0;
};

// ��������
// �������������ˣ�����������ʵ�������󣬿�������ͨ�����������ã������вΣ�Ҳ�����з���ֵ
void test01()
{
	MyPrint print;
	print(100);
	print(100);
	print(100);
	print(100);
	cout << "print ������������ " << print.count_ << " �Ρ�" << endl; // �������󳬳�����ͨ�����ĸ�����Ա��溯���ĵ���״̬
}

void doPrint(MyPrint print, int num)
{
	print(num);
}

int main()
{
	test01();

	// ����������Ϊ����
	doPrint(MyPrint(), 10); 	// ����1����������������
}