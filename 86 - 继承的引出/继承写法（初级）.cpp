#include<iostream>
using namespace std;

// һ�����ô���������ơ����ࡱ�򡰸��ࡱ
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

// ����Ϊ�������ࡱ�����ࡱ
class News :public BasePage // BasePage - ���࣬News - �����࣬News�̳��� BasePage
{
public:
	void news()
	{
		cout << "The news " << endl;
	}
};

class Games :public BasePage // BasePage - ���࣬Games - �����࣬ Games�̳��� BasePage
{
public:
	void games()
	{
		cout << "Minecraft" << endl;
	}
};

void test02()
{
	cout << endl << "ʹ�ü̳д�ӡ�����" << endl;
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