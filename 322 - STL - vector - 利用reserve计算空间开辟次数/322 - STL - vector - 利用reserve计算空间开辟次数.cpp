#include<iostream>
#include<vector>
using namespace std;

// 开辟100000数据用了多少次
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
	cout << "开辟100000数据用了 " << num << " 次 :" << endl;
}
