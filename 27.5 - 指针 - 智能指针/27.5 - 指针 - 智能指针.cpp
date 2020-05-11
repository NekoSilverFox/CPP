#include <iostream>
#include <string>
using namespace std;

// 1. ʹ������ָ������Ӧ�ð���ͷ�ļ� <memory>
#include <memory>


class Report // ���ڲ���
{
public:
	Report(const std::string str)
	{
		this->str_ = str;
		std::cout << "Report has created !\n";
	}

	void print()
	{
		std::cout << this->str_ << std::endl;
	}

	~Report()
	{
		std::cout << "Report had delete !\n";
	}

private:
	std::string str_;
};

void test01()
{
	// 2. ����ָ��ģ��λ�������ռ�std��
	{
		std::auto_ptr<Report> report(new Report("use auto_ptr"));
		report->print();
	}
		std::cout << std::endl;

	{
		std::shared_ptr<Report> report(new Report("use shared_ptr"));
		report->print();
	}
		std::cout << std::endl;

	{
		std::unique_ptr<Report> report(new Report("use unique_ptr"));
		report->print();
	}
		std::cout << std::endl;

}

// 3. ����ָ�붼Ӧ�ñ���һ��
// pvac����ʱ������Ὣdelete���ڷǶ����ڴ棬���Ǵ���ģ�
void test02()
{

	string vacation("tha smart printer of test");
	shared_ptr<string> pvac(&vacation);

}

/*
** unique_ptr Ϊ������ auto_ptr
*/
void test03()
{
	auto_ptr<string> str(new string("Test fo auto_ptr"));		//# 1
	auto_ptr<string> str2;														// # 2

	str2 = str;																			// # 3

	/*
	** ����� #3 �У�str2 �ӹ�string���������Ȩ��str������Ȩ���ᱻ���ᡣ
	** ���Ǽ����£����Է�ֹstr1 �� str2 ������������ͼɾ��ͬһ������
	** ��������������ͼʹ�� str1 ��������λ�ô�����Ϊ str1 ����ָ����Ч������
	*/

	// ��һ�� unique_ptr �������
	unique_ptr<string> p1(new string("Test of unique_ptr"));  // # 4
	unique_ptr<string> p2;														// # 5

#if 0
	p2 = p1;																				// # 6
	/*
	** ��������Ϊ #6 �Ƿ�
	** ������ p1 ����ָ����Ч���ݵ�����
	** ��� unique_ptr �� auto_ptr ����ȫ
	** ������׶δ����Ǳ�ڳ����������ȫ��
	*/
#endif
}


/*
** ���ǣ��е�ʱ������ָ�븳ֵ����һ����������Σ�յ�����ָ��
*/
unique_ptr<string> demo(const char* s)
{
	unique_ptr<string> str(new string(s));

	return str;
}
void test05()
{
	unique_ptr<string> str;
	str = demo("test test04 turn to test05");

	/*
	** ��֮��������ͼ��һ��unique_ptr������һ��ʱ
	** ���Դunique_ptr��һ����ʱ����ֵ�� ������������ô��
	** ��Դ unique_ptr ������һ��ʱ�䣬����������ֹ������
	*/
}


void test06()
{
	unique_ptr<string> pu1(new string("Test06 "));
	unique_ptr<string> pu2;

	pu2 = pu1; // #1 ������

	pu2 = unique_ptr<string>(new string("test06")); //#2�������������Ǹ���������

	/*
	** ���#1���������ҵ�unique_ptr��pul��������ܵ���Σ����
	** ���#2�����������ҵ�unique_ptr����Ϊ������unique_ptr�Ĺ��캯�����ù��캯����������ʱ������������Ȩת�ø�pu2��ͻᱻ���١�
	** ����������������Ϊ������unique_ptr�����������ָ�ֵ��auto_ptr��
	** ��Ҳ�ǽ�ֹ��ֻ��һ�ֽ��飬������������ֹ��������������ʹ��auto_ptr��������ʹ��unique_ptr��ԭ��
	** ��������㷨��ͼ�԰���unique_ptr������ִ�����������#1�Ĳ����������±������
	** ����㷨��ͼִ�����������#2�Ĳ������򲻻����κ����⡣
	** ������auto_ptr�����������#1�Ĳ������ܵ��²�ȷ������Ϊ�����صı�����
	*/

	/*
	** ��Ȼ��������ȷʵ��ִ�����������#1�Ĳ�����
	** �����Է����ܵķ�ʽʹ������������ָ�루��������ʱ�������ָ�ֵ�Ų���ȫ��
	** Ҫ��ȫ����������ָ�룬�ɸ�������ֵ��
	** C++��һ����׼�⺯��std::move( )�������ܹ���һ��unique_ptr������һ����
	** ������һ��ʹ��ǰ��demo( )���������ӣ��ú�������һ��unique_ptr����
	*/
	unique_ptr<string> ps1, ps2;

	ps1 = demo("test function move()");

	ps2 = move(ps1);

	ps1 = demo(" contuion test move()");

	cout << "*ps1" << *ps1 << endl
		<< "*ps2" << *ps2 << endl;

}

void test07()
{

	/*
	** ��Ȼ��������ȷʵ��ִ�����������#1�Ĳ�����
	** �����Է����ܵķ�ʽʹ������������ָ�루��������ʱ�������ָ�ֵ�Ų���ȫ��
	** Ҫ��ȫ����������ָ�룬�ɸ�������ֵ��
	** C++��һ����׼�⺯��std::move( )�������ܹ���һ��unique_ptr������һ����
	** ������һ��ʹ��ǰ��demo( )���������ӣ��ú�������һ��unique_ptr����
	*/

	std::unique_ptr<double[]> pda(new double(5)); // will use delete[]
}

/*
** WANNING:
** ʹ��new�����ڴ�ʱ������ʹ��auto_ptr��shared_ptr��ʹ��new [ ]�����ڴ�ʱ������ʹ������
** ��ʹ��new�����ڴ�ʱ������ʹ��auto_ptr��shared_ptr��
** ��ʹ��new��new []�����ڴ�ʱ������ʹ��unique_ptr
*/

int main()
{
	try
	{
		test02();

		test03();
	}
	catch (...)
	{

	}
}