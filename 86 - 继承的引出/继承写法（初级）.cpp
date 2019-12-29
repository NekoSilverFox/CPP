#include<iostream>
using namespace std;

// 一个公用代码区，简称“基类”或“父类”
class BasePage
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
};

// 以下为“派生类”或“子类”
class News :public BasePage // BasePage - 基类，News - 派生类，News继承于 BasePage
{
public:
	void news()
	{
		cout << "The news " << endl;
	}
};

class Games :public BasePage // BasePage - 基类，Games - 派生类， Games继承于 BasePage
{
public:
	void games()
	{
		cout << "Minecraft" << endl;
	}
};

void test02()
{
	cout << endl << "使用继承打印输出：" << endl;
	News n2;
	n2.header();
	n2.lefter();
	n2.footer();
	n2.news();

	cout << endl;
	Games g2;
	g2.header();
	g2.lefter();
	g2.footer();
	g2.games();
}