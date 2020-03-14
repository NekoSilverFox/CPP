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
	cout << "vector - v 的容量：" << v.capacity() << endl;
	cout << "vector - v 的大小：" << v.size() << endl << endl;


	v.resize(3);
	cout << "<------v.resize(3)------->" << endl;
	cout << "vector - v 的容量：" << v.capacity() << endl;
	cout << "vector - v 的大小：" << v.size() << endl << endl;

	// 巧用swap

	vector<int>(v).swap(v); // 使用了 匿名对象 ，当数据交换完毕之后（指针重新指向对方的），该语句执行结束后系统自动回收匿名对象！！
	cout << "<------巧用swap - vector<int>(v).swap(v)------->" << endl;
	cout << "vector - v 的容量：" << v.capacity() << endl;
	cout << "vector - v 的大小：" << v.size() << endl;
}