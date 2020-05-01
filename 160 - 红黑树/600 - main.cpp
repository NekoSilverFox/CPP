#include "RedBlackTree.hpp"
#include <iostream>
using namespace std;


void test01()
{
	RedBlackTree t;
	t.insert(5);
	t.insert(2);
	t.insert(4);
	t.insert(3);
	t.insert(9);
	t.insert(1);

	t.foreach();
}

int main()
{
	test01();
}