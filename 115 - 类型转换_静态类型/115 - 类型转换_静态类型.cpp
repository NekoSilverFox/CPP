#include<iostream>
using namespace std;

// ���� = static_cast<Ҫת���ɵ�����>(Ҫת���Ķ���)


//��̬ת��
//��������
void test01()
{
	char a = 'a';
	double d = static_cast<double>(a);
	cout << d << endl << endl;

	a = static_cast<char>(d + 1);
	cout << a << endl << endl;

}


//����֮��ת��
class Base {};
class Son : public Base{};
class Other{};
void test02()
{
	Base* base = nullptr;
	Son* son = nullptr;
	Other* other = nullptr;

	// ��������ת��	��baseתΪ Child*����		����ȫ
	Son* son_2 = static_cast<Son*>(base);
	son = static_cast<Son*>(base);

	// ��������ת��	��sonתΪ Base* ����		��ȫ
	Base* base_2 = static_cast<Base*>(son);
	base = static_cast<Base*>(son);

	// ��������ת��	�����ԣ��� ��Ч������
	Other* other_2 = static_cast<Other*>(son);
	other = static_cast<Other*>(base);

}

int main()
{
	test01();
}