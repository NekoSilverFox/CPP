#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// һԪν��
class MoreThan2
{
public:
	bool operator()(int val)
	{
		return val > 2;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(6);
	v.push_back(2);
	v.push_back(1);

	//��ӡ�����д���2 ���� ��ע��Ҫ����ϵͳ��ͷ�ļ���
	
	// 1.
	//MoreThan2 than2;
	// vector<int>::iterator it = find_if(v.begin(), v.end(), than2); // <--- ע�⣬�����Ǵ����ŵģ���������������������������������
	
	// 2.
	vector<int>::iterator it = find_if(v.begin(), v.end(), MoreThan2()); // <--- ע�⣬�����Ǵ����ŵģ���������������������������������
	if (it != v.end())
		cout << "�ҵ���Ϊ " << *it << " ������" << endl;
	else cout << "δ�ҵ���" << endl;
}


class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

// ��Ԫν��
void test02()
{
	vector<int>v;
	v.push_back(3);
	v.push_back(10);
	v.push_back(4);
	v.push_back(3);
	v.push_back(8);
	v.push_back(7);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;


	sort(v.begin(), v.end(), MyCompare());
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//	cout << *it << " ";
	//cout << endl;

	// �������� lambda ���ʽ [](){};
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}
int main()
{
	test01();
	test02();
}
