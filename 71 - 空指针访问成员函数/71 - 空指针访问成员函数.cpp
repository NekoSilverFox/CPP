#include <iostream>
using namespace std;
class Person
{
public:
	
	void show()
	{
		cout << "The age is what?" << endl; // 没有用到 this 指针
	}

	void showAge()
	{

		if (this == NULL)
		{
			return;
		}

		cout << m_age;// 用到了 this 指针 相当于 this->m_age; 但是这个时候 this == NULL，所以会宕掉
	}
	int m_age;
};

int main()
{
	// 定义一个空指针
	Person* p = NULL;

	p->show();

	p->showAge();
}

总结：
1. 如果成员函数没有用到 this ，那么空指针可以直接访问
2. 如果成员函数用的 this 指针，就要注意，可以加 if 判断，如果 this 为 NULL 就  return