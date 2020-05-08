#include <iostream>
#include "AVLTree.hpp"
using namespace std;

void test01()
{
	AVLTree<int> t;

	t.insert(3);
	t.insert(2);
	t.insert(1);
	t.insert(4);
	t.insert(5);
	t.insert(6);
	t.insert(7);
	t.insert(16);
	t.insert(15);
	t.insert(14);
	t.insert(13);
	t.insert(12);
	t.insert(11);
	t.insert(10);
	t.insert(8);
	t.insert(9);

	cout << endl;
	t.inOrder();

	cout << endl;
	t.min();

	cout << endl;
	t.max();

	cout << endl;
	t.search(8);
	t.iterativeSearch(8);

	t.search(0);
	t.iterativeSearch(0);

	t.search(2);
	t.iterativeSearch(2);

	t.search(3);
	t.iterativeSearch(3);

	t.search(10);
	t.iterativeSearch(10);

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