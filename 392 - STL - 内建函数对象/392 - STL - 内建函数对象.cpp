#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>  //�ڽ���������ͷ�ļ�
using namespace std;

// 1. �����ຯ������
void test01()
{
	// ֻ�� negate ��һԪ���㣬��ȡ���º�����
	negate<int>n;
	cout << n(10) << endl
		<< n(-6) << endl;

	divides<double>div1;
	cout << div1(10, 3) << endl;
}


// 2. ��ϵ�����ຯ��
void test02()
{
	vector<int>v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(1);
	v.push_back(8);
	v.push_back(9);

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

// 3. �߼�����
void test03()
{
	vector<int>v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(1);
	v.push_back(8);
	v.push_back(9);

	// vector<int>::iterator it = find_if(v, begin(), v.end(), logical_not<int>());
}

int main()
{
	test01();
	test02();
}