#include "LinkList.hpp"
#include "BinarySearchTree.hpp"
using namespace std;

void test01()
{
	LinkList<int> list;
	list.insert(4);
	list.insert(6);
	list.insert(0);
	list.insert(1);
	list.insert(6);
	list.insert(79);
	list.insert(3);

	list.foreach();

	list.sort();
	list.foreach();
}

void test02()
{
	BinarySearchTree tree;
	tree.addRowNum();
}

void test03(string& word)
{

	if (word.empty()) throw MyErrorInfo("null_string");
	if (word.at(0) > 64 && word.at(0) < 91)
	{
		word.at(0) += 32; // 操作ASCII码更改大小写
	}

	int index = 0;
	while (word.find(',', index) != string::npos)
	{
		index = word.find(',', index);
		word.erase(index, 1);
	}

	while (word.find('.', index) != string::npos)
	{
		index = word.find('.', index);
		word.erase(index, 1);
	}

	while (word.find("'s", index) != string::npos)
	{
		index = word.find("'s", index);
		word.erase(index, 2);
	}
}

int main()
{
	try
	{
		string str("Woefs's");
		cout << str << endl;
		// test02();
		test03(str);
		cout << str << endl;
	}
	catch ( MyErrorInfo& err)
	{
		cout << err.what() << endl;
	}
}