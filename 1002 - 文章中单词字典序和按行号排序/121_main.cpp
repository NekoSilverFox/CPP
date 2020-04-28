#include "LinkList.hpp"
#include "BinarySearchTree.hpp"
using namespace std;

void testFunc()
{
	string file_name;
	cout << "¡ô Please enter the required file name : "; cin >> file_name; // 1.txt

	BinarySearchTree tree;
	tree.openFile(file_name);

	/*
	**  first add rol number, and output in file (output.txt)
	*/
	tree.printTextWithRowNum();

	/*
	** Insert all word into the binary search tree
	*/
	tree.makeTree();

	/*
	** print the words on screen
	** true - print same word;
	** false - do not print same word
	*/
	tree.printDictionaryOrder(false);

	/*
	** Seach word
	** if have this word print this word with its info (row, col, count, length...)
	*/
	tree.searchWord("fire");

	/*
	**  Delete word
	*/
	tree.deleteWord("student");

	/*
	**  out put the word by Dictionary order in to the file "output.txt"
	*/
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
		cerr << err.what() << endl;
	}
	catch (...)
	{
		cerr << "Unknow error!!!" << endl;
	}
}