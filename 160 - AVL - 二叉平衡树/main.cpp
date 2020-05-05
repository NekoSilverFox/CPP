#include <iostream>
#include "AVLTree.hpp"
using namespace std;

void test01()
{
	AVLTree<int> t;
	
	t.insert(5);
	t.insert(1);
	t.insert(4);
	t.insert(7);
	t.insert(8);
	t.insert(7);
	t.insert(0);
	t.insert(3);
	t.insert(2);
	t.insert(0);
}

int main()
{
	try
	{
		test01();
	}
	catch (MyErrorInfo& err)
	{
		cerr << "\033[031m" << err.what() << "\033\0m" << endl;
	}
}