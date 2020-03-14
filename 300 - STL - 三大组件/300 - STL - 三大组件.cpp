#include<string>
#include<iostream>
using namespace std;

// ʹ��ϵͳ�㷨��ͷ�ļ�
#include<algorithm>
#include<vector>

// ������  - �������� - ��ָ�����
// ��ָͨ��Ҳ��һ�ֵ�����
void test01()
{
	int array1[] = { 1,2,3,4,5 };

	int* p = array1; //ָ��ָ�������׵�ַ  &array[0]

	for (int i = 0; i < 5; ++i)
	{
		// cout << array1[i] << " ";
		cout << *(p++) << " "; 
	}
	cout << endl;
}


void myPrint(int num)
{
	cout << num << " ";
}

void test02()
{
	// ��������
	vector<int> v; //����һ������  ��������д��int�������� ��������v

	// �������м�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);


	// iterator - ������
	// ���õ����� ���������е�Ԫ��
	vector<int>::iterator itBegin = v.begin(); // .begin - ָ����������е���ʼλ��
	vector<int>::iterator itEnd = v.end(); // .end - ָ����������У��������һ��Ԫ�ص���һ��λ�ã�����

	//1.  ʹ�õ���������
	while (itBegin != itEnd)
	{
		cout << *(itBegin++) << " ";
	}
	cout << endl;

	// 2. ʹ��for����
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	// 3. �����㷨
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}


// �����Զ�����������
class Person
{
public:
	Person(string name, int age) : name_(name) , age_(age){}
	string name_;
	int age_;
};

void test03()
{
	vector<Person> v;
	Person p1("����ѩ��", 13);
	Person p2("���ܲ�", 14);
	Person p3("�ʵ�", 17);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	// ����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "Name : " << (*it).name_ << " Age : " << it->age_ << endl;
	}
}


//����Զ����������͵�ָ��
void test04()
{
	vector<Person*> v;
	Person p1("����ѩ��", 13);
	Person p2("���ܲ�", 14);
	Person p3("�ʵ�", 17);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	for (vector<Person*>::iterator it = v.begin(); it < v.end(); ++it)
	{
		cout << "Name : " << (*it)->name_ << " Age : " << (*it)->age_ << endl;
	}

}


void test05()
{
	// ����Ƕ������
	vector<vector<int>> v;

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}

	// ��С�������뵽��������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}

}
int main()
{
	// test01();
	test02();
	test03();
	test04();
	test05();
}