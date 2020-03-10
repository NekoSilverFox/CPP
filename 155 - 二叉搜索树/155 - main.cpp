#include"LinkStack.h"
#include"Tree.h"

void FunCreatBinaryTree()
{
	BinarySearchTree<char> charTree;

	cout << "---------------------Creat Binary Search Tree---------------------" << endl;
	charTree.CreatTree();
	cout << endl << "----------------------------Insert Node----------------------------" << endl;
	//charTree.insetNode();

	//cout << endl << "---------------------Print Binary Search Tree---------------------" << endl;
	charTree.printTree("ALL");

	cout << endl << "------------------------Print Tree with scope------------------------" << endl;
	/*charTree.iterableTree();

	cout << endl << "--------------------------------Depth--------------------------------" << endl;
	cout << "Depth : " << charTree.getDepth() << endl;

	cout << endl << "-----------------------------Leaf number-----------------------------" << endl;
	cout << "Leaf number : " << charTree.getLeafNum() << endl;

	cout << endl << "----------------------------Node number----------------------------" << endl;
	cout << "Node number : " << charTree.getElementNum() << endl;

	cout << endl << "-----------------------------Delete node-----------------------------" << endl;*/
	charTree.deleteNode();

	cout << endl << "-----------------------------After delete-----------------------------" << endl;
	charTree.printTree("LDR");

	cout << endl << "-----------------------------Search node-----------------------------" << endl;
	cout << "Iterative search by element>>>>> " << endl; 
	if (charTree.iterativeSearch()) cout << "True" << endl;
	else cout << "False" << endl;

	cout << endl << "------------------------------------------------------------------------" << endl;
	charTree.deleteTree();
}


int main()
{
	FunCreatBinaryTree();
}