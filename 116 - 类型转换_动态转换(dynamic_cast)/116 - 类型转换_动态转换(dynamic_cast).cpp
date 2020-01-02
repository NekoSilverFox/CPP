#include<iostream>
using namespace std;

// 116 - ����ת��_��̬ת��(dynamic_cast) dynamic_cast�ǳ��ϸ�ʧȥ���� ���߲���ȫ��������ת��


// ��ͨ����ת��
//�������Ͳ�����ת��
void test01()
{
	int int_type = 10;
	double double_type = 3.14926;
	short short_type = 1.11;
	char chat_type = 'a';

	// double ת shout ����ʧ���ȣ�
	//short_type = dynamic_cast<short>(double_type);

	//// shout ת double 
	//double_type = dynamic_cast<double>(short_type);

	//// int ת double 
	//double_type = dynamic_cast<double>(int_type);
}


// �̳й�ϵָ��
class Base {};
class Son : public Base {};
class Other{};

void dynamicTest()
{

	Base* base = nullptr;
	Son* son = nullptr;
	Other* other = nullptr;

	// ��������ת�� - ����ȫ ���Ƿ�����̬
	son = dynamic_cast <Son*>(base);

	// ��������ת�� - ��ȫ
	base = dynamic_cast<Base*>(son);

	// ��������ת�� - ��֧��
	son = dynamic_cast<Son*>(other);
	base = dynamic_cast<Base*>(other);
	other = dynamic_cast<Other*>(son);
}




// �̳й�ϵָ�� (�����˶�̬)
class Base2 { virtual void virtual_func() = 0; };
class Son2 : public Base2 { void virtual_fun() {} };
class Other2 {};

void dynamicTest2()
{

	Base2* base2 = nullptr;
	Son2* son2 = nullptr;
	Other2* other2 = nullptr;

	// ��������ת�� - ����ȫ - ���Ƿ����˶�̬
	son2 = dynamic_cast <Son2*>(base2);

	// ��������ת�� - ��ȫ
	base2 = dynamic_cast<Base2*>(son2);

	// ��������ת�� - ��֧��
	son2 = dynamic_cast<Son2*>(other2);
	base2= dynamic_cast<Base2*>(other2);
	other2 = dynamic_cast<Other2*>(son2); // �����˶�̬