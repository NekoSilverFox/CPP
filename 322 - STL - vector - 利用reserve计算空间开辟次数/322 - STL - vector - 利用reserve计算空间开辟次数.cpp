#include<iostream>
#include<vector>
using namespace std;

// ����100000�������˶��ٴ�
int main()
{
	vector<int> v;
	void* p = nullptr;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "����100000�������� " << num << " �� :" << endl;
}
