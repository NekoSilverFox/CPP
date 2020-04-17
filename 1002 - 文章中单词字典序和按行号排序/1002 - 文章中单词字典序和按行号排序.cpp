#include "LinkList.hpp"
#include "BinarySearchTree.hpp"
using namespace std;

void testFunc()
{
	string file_name;
	cout << "¡ô Please enter the required file name : "; cin >> file_name;

	BinarySearchTree tree;
	tree.openFile(file_name);
	tree.printTextWithRowNum();
	tree.makeTree();
	tree.printDictionaryOrder(false);
	tree.searchWord("fire");
	tree.deleteWord("fire");
	tree.outputDictionaryOrderInFile(false);
}

int main()
{
	try
	{
		testFunc();
	}
	catch ( MyErrorInfo& err)
	{
		cout << err.what() << endl;
	}
}