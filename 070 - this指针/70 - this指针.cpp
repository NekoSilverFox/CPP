// this ָ����һ������ָ�룬��������ÿ��   --�Ǿ�̬--  ��  ---��Ա����--- ��

#include <iostream>
using namespace std;

class Person
{
public:
	Person() {};

	Person(int age)
	{

		// 1. this ���������ͻ
		// age = age; �������
		// this->age ��ǰ�����age, age���Ҳࣩ��������age
		this->age = age;
	}


	//�Ա�����
	void duibiAge(Person& person)
	{
		if (this->age == person.age)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << "���䲻���" << endl;
		}
	}

	// 2. ���ض����������
	// �������
	Person& plusAge(Person& person)
	{
		this->age += person.age;
		return *this;
	}

	int age;

};

void test01()
{
	Person p1;
	p1.age = 10;
	cout << "p1.age ==" << p1.age << endl;

	//Person p2;
	//p2.duibiAge(p1);
	Person p2(20);
	p1.duibiAge(p2);

	p1.plusAge(p2);

	//��ʽ���
	p1.plusAge(p2).plusAge(p2).plusAge(p2);
	cout << "�����Ϊ��" << p1.age;
}

int main() {
	test01();
}