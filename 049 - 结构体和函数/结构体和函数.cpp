#include <iostream>
#include<string>
using namespace std;

// ����һ���ṹ��
struct Students
{
	string name;
	int age;
};

// ������ı� �������� �� �ṹ��s
void test01(Students s)
{
	s.name = "TTTTTT";
	s.age = 16;

	cout << endl << s.name << endl;
	cout << s.age << endl << endl;
}

// ��Ϊ���� ����һ�� ��ַ �����Ի�ı��������� �� s
void test02(Students* t)
{
	t->name = "JJJJJJJ";  // ע�� �õ��� �� -> ��
	t->age = 16;
}

// �ṹ����Ϊ ����ֵ
// ������Ϊ�ṹ��
Students test03(Students* p)
{
	
	p->name = "GGGGGGG";
	p->age = 14;
	return *p;
}

int main()
{
	Students s;
	// s.name = (char*)malloc(sizeof(char) * 200);
	s.name = "Mr.Z";
	s.age = 18;

	cout << endl << s.name << endl;
	cout << s.age << endl << endl;

	test01(s);
	cout << endl << s.name << endl;
	cout << s.age << endl << endl;

	test02(&s);
	cout << endl << s.name << endl;
	cout << s.age << endl << endl;

	s = test03(&s);
	cout << endl << s.name << endl;
	cout << s.age << endl << endl;
}