#include <iostream>
#include <string>
using namespace std;

// 1. 使用智能指针首先应该包含头文件 <memory>
#include <memory>


class Report // 用于测试
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
	// 2. 智能指针模板位于命名空间std中
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

// 3. 三种指针都应该避免一点
// pvac过期时，程序会将delete用于非堆区内存，这是错误的！
void test02()
{

	string vacation("tha smart printer of test");
	shared_ptr<string> pvac(&vacation);

}

/*
** unique_ptr 为何优于 auto_ptr
*/
void test03()
{
	auto_ptr<string> str(new string("Test fo auto_ptr"));		//# 1
	auto_ptr<string> str2;														// # 2

	str2 = str;																			// # 3

	/*
	** 在语句 #3 中，str2 接管string对象的所有权后，str的所有权将会被剥夺。
	** 这是件好事，可以防止str1 与 str2 的析构函数试图删除同一个对象
	** 但如果程序随后试图使用 str1 ，会引发位置错误，因为 str1 不再指向有效的数据
	*/

	// 看一下 unique_ptr 的情况：
	unique_ptr<string> p1(new string("Test of unique_ptr"));  // # 4
	unique_ptr<string> p2;														// # 5

#if 0
	p2 = p1;																				// # 6
	/*
	** 编译器认为 #6 非法
	** 避免了 p1 不再指向有效数据的问题
	** 因此 unique_ptr 比 auto_ptr 更安全
	** （编译阶段错误比潜在程序崩溃更安全）
	*/
#endif
}


/*
** 但是，有的时候将智能指针赋值给另一个不会留下危险的悬挂指针
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
	** 总之，程序试图将一个unique_ptr赋给另一个时
	** 如果源unique_ptr是一个临时的右值， 编译器允许这么做
	** 但源 unique_ptr 将存在一段时间，编译器将终止这样做
	*/
}


void test06()
{
	unique_ptr<string> pu1(new string("Test06 "));
	unique_ptr<string> pu2;

	pu2 = pu1; // #1 不允许！

	pu2 = unique_ptr<string>(new string("test06")); //#2不报错，并且这是个匿名对象

	/*
	** 语句#1将留下悬挂的unique_ptr（pul），这可能导致危害。
	** 语句#2不会留下悬挂的unique_ptr，因为它调用unique_ptr的构造函数，该构造函数创建的临时对象在其所有权转让给pu2后就会被销毁。
	** 这种随情况而异的行为表明，unique_ptr优于允许两种赋值的auto_ptr。
	** 这也是禁止（只是一种建议，编译器并不禁止）在容器对象中使用auto_ptr，但允许使用unique_ptr的原因。
	** 如果容器算法试图对包含unique_ptr的容器执行类似于语句#1的操作，将导致编译错误；
	** 如果算法试图执行类似于语句#2的操作，则不会有任何问题。
	** 而对于auto_ptr，类似于语句#1的操作可能导致不确定的行为和神秘的崩溃。
	*/

	/*
	** 当然，您可能确实想执行类似于语句#1的操作。
	** 仅当以非智能的方式使用遗弃的智能指针（如解除引用时），这种赋值才不安全。
	** 要安全地重用这种指针，可给它赋新值。
	** C++有一个标准库函数std::move( )，让您能够将一个unique_ptr赋给另一个。
	** 下面是一个使用前述demo( )函数的例子，该函数返回一个unique_ptr对象：
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
	** 当然，您可能确实想执行类似于语句#1的操作。
	** 仅当以非智能的方式使用遗弃的智能指针（如解除引用时），这种赋值才不安全。
	** 要安全地重用这种指针，可给它赋新值。
	** C++有一个标准库函数std::move( )，让您能够将一个unique_ptr赋给另一个。
	** 下面是一个使用前述demo( )函数的例子，该函数返回一个unique_ptr对象：
	*/

	std::unique_ptr<double[]> pda(new double(5)); // will use delete[]
}

/*
** WANNING:
** 使用new分配内存时，才能使用auto_ptr和shared_ptr，使用new [ ]分配内存时，不能使用它们
** 不使用new分配内存时，不能使用auto_ptr或shared_ptr；
** 不使用new或new []分配内存时，不能使用unique_ptr
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