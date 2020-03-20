#include "Tree.h"
#include "LinkQueue.h"
#include "LinkStack.h"

void funcBinarySearchTree()
{
	BinarySearchTree<char> charTree;

	cout << "----------------------Creat Binary Search Tree----------------------" << endl;
	charTree.CreatTree();

	cout << endl << "----------------------Print Binary Search Tree----------------------" << endl;
	charTree.printTree();

	/*cout << endl << "-----------------------------Insert Node-----------------------------" << endl;
	charTree.insetNode();

	cout << endl << "----------------------Print Binary Search Tree----------------------" << endl;
	charTree.printTree("LDR");

	cout << endl << "------------------------Print Tree with scope------------------------" << endl;
	charTree.iterableTree();*/

	cout << endl << "--------------------------------Depth--------------------------------" << endl;
	cout << "Depth : " << charTree.getDepth() << endl;

	cout << endl << "-----------------------------Leaf quantity-----------------------------" << endl;
	cout << "Leaf quantity : " << charTree.getLeafQuantity() << endl;

	cout << endl << "----------------------------Node quantity----------------------------" << endl;
	cout << "Node quantity : " << charTree.getElementQuantity() << endl;

	/*cout << endl << "-----------------------------Delete node-----------------------------" << endl;
	charTree.deleteNode();

	cout << endl << "-----------------------------After delete-----------------------------" << endl;
	charTree.printTree("LDR");

	cout << endl << "-----------------------------Search node-----------------------------" << endl;
	cout << "Iterative search by element>>>>> " << endl;
	if (charTree.iterativeSearch()) cout << "True" << endl;
	else cout << "False" << endl;

	cout << endl << "------------------------Search node by value------------------------" << endl;
	charTree.searchBSTbyValue();*/

	cout << endl << "------------------------------------------------------------------------" << endl;
	charTree.deleteTree();
}


int main()
{
	funcBinarySearchTree();
}