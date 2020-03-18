#include<iostream>
#include<set>
using namespace std;

// 372 - STL - set - 自定义insert排序规则

//指定set排序规则 从大到小
//仿函数
template<class T>
class myCompare
{
public:
	//重载 ()
	bool operator()(T data1, T data2) const // 注意加const！！
	{
		return data1 > data2;
	}
};

//set容器排序
void setSort()
{
	set<int, myCompare<int>> s;
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.insert(9);
	s.insert(8);
	s.insert(0);

	//                        ↓               ↓          注意，此时遍历中迭代器也要更新！！！
	for (set<int, myCompare<int>>::iterator it = s.begin(); it != s.end(); it++) cout << *it << " "; cout << endl;
}

int main()
{
	setSort();
}
