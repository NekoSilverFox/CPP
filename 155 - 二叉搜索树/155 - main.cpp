#include"LinkStack.h"
#include"Tree.h"

void FunCreatBinaryTree()
{
	BinarySearchTree<char> charTree;
	charTree.insertTree();
	cout << endl << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	charTree.printTree("ALL");
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << "Depth : " << charTree.getDepth() << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << "Leaf number : " << charTree.getLeafNum() << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << "Element number : " << charTree.getElementNum() << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << "Iterative search by element>>>>> " << endl; 
	if (charTree.iterativeSearch()) cout << "True" << endl;
	else cout << "False" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	charTree.deleteTree();
}


int main()
{
	FunCreatBinaryTree();
}