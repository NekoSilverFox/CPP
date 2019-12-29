#include<iostream>
using namespace std;

class News_
{
public:
	void header()
	{
		cout << "The header" << endl;
	}
	void footer()
	{
		cout << "The footer" << endl;
	}
	void lefter()
	{
		cout << "The lefter" << endl;
	}
	void news()
	{
		cout << "The news" << endl;
	}
};

class Games_
{
public:
	void header()
	{
		cout << "The header" << endl;
	}
	void footer()
	{
		cout << "The footer" << endl;
	}
	void lefter()
	{
		cout << "The lefter" << endl;
	}
	void games()
	{
		cout << "The games" << endl;
	}
};



void test01()
{
	News_ n1;
	Games_ g1;

	n1.header();
	n1.lefter();
	n1.footer();
	n1.news();
	cout << endl;

	g1.header();
	g1.lefter();
	g1.footer();
	g1.games();
 }

// 以上这么写会造成大量代码的重复，所以引出继承的概念！
void test02();
int main()
{
	test01();
	test02();
}