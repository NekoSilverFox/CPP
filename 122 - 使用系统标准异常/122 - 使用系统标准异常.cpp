#include<iostream>
#include<stdexcept> // 要包含头文件
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void printInfo()
	{
		if (this->m_age < 0 || this->m_age > 120)
		{
			throw out_of_range("年龄越界异常");  // 系统自带的异常里 封装了一个 what() 方法，注意使用方法
			throw range_error("溢出啦");
		}
		cout << "Name : " << this->m_name << endl << "Age : " << this->m_age << endl;
	}

public:
	string m_name;
	int m_age;
};

int main()
{
	Person p1("Nick", -13);
	try
	{
		p1.printInfo();
	}
	catch (out_of_range& err) // 和之前一样，要用一个引用，不明白的话 回看 119 - 自定义异常的捕获
	{
		cout << err.what() << endl; // 系统自带的异常里 封装了一个 what() 方法，可以直接调用
	}
	catch (range_error& err)
	{
		cout << err.what() << endl;
	}
}