// 69 - ��Ա�����ͳ�Ա�����ֿ��洢
// this ָ����һ������ָ�룬��������ÿ��   --�Ǿ�̬--  ��  ---��Ա����--- ��
#include<iostream>
using namespace std;

class NoThing
{
public:

};

class TestFunc
{
	void func() {
		cout << "������������������������������";
	};
};

class TestStatic
{

	int a;  //�Ǿ�̬��Ա���������ڶ�������

							// ��������͵͵����һ�� this ָ�룬TestStatic* this   ���� void fun( TestStatic* this ) {}
	void fun() {}; // �Ǿ�̬��Ա�����������ڶ�������

	// ��̬��Ա���� �ڲ�û�� this ָ�룬��̬��Ա�������ܲ����Ǿ�̬��Ա����
	static int b; // ��̬��Ա�����������ڶ�������
	static int fun2() {}; // ��̬��Ա�����������ڶ�������
};

// ���ۣ��Ǿ�̬��Ա���������ڶ�������
// ���к��������۾�̬���ǷǾ�̬�������ڶ������ϣ���ȻC++�����˷�װ�������ǻ��ǽ����������˷ֿ��洢

int main()
{
	cout << "����Ĵ�СΪ��" << sizeof(NoThing) << endl;
	cout << "ԭ�򣺿���Ĵ�СΪ 1 ��ÿ��ʵ�����Ķ��� ���ж�һ�޶��ĵ�ַ��char ά�������ַ������Ϊ 1" << endl << endl;

	cout << "ֻ�к����� ���С��" << sizeof(TestFunc) << endl << endl;

	cout << "TestStatic��" << sizeof(TestStatic) << endl;

}


