#include<iostream>
using namespace std;
#include<vector>

int main()
{
	vector<int> v;

	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}
	cout << "vector - v ��������" << v.capacity() << endl;
	cout << "vector - v �Ĵ�С��" << v.size() << endl << endl;


	v.resize(3);
	cout << "<------v.resize(3)------->" << endl;
	cout << "vector - v ��������" << v.capacity() << endl;
	cout << "vector - v �Ĵ�С��" << v.size() << endl << endl;

	// ����swap

	vector<int>(v).swap(v); // ʹ���� �������� �������ݽ������֮��ָ������ָ��Է��ģ��������ִ�н�����ϵͳ�Զ������������󣡣�
	cout << "<------����swap - vector<int>(v).swap(v)------->" << endl;
	cout << "vector - v ��������" << v.capacity() << endl;
	cout << "vector - v �Ĵ�С��" << v.size() << endl;
}