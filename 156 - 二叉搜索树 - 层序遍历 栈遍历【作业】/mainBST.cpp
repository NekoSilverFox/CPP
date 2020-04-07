#include "Tree.hpp"
#include "LinkQueue.hpp"
#include "LinkStack.hpp"

void funcBinarySearchTree()
{
	BinarySearchTree<int> intTree;

	cout << "----------------------Creat Binary Search Tree----------------------" << endl;
	//intTree.CreatTree();
	cout << "Insert : ";
	intTree.CreatTreeITERATION();

	cout << endl << endl << "----------------------Print Binary Search Tree----------------------" << endl;
	enum MethodPrint { DLR_recursion = 1, LDR_recursion, LRD_recursion, ALL_recursion, depth_first, breadth_first};
	
	cout << "LDR (use recursion) : "; intTree.printTree(LDR_recursion); cout << endl;

	cout << "Depth-first (use Stack) :"; intTree.printTree(depth_first); cout << endl; // !! Code on row 517 in Tree.cpp

	cout << "Breadth-first (use Queue) : "; intTree.printTree(breadth_first); cout << endl; // !! Code on row 554 in Tree.cpp

	// intTree.printTree();

	/*
	cout << endl << endl << "-------------------------Similarity Two Tree-------------------------" << endl;
	BinarySearchTree<int> intTree2;
	cout << "Please creat the second tree >> " << endl; intTree2.CreatTree();

	cout << endl << endl
		<< "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "The  first  tree  :"; intTree.printLDR(); cout << endl;
	cout << "The second tree :"; intTree2.printLDR(); cout << endl;
	double similarity = intTree.howSameTree(intTree2);
	cout << endl << "Similarity = " << similarity * 100 << "%" << endl
		<< "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	*/

	/*cout << endl << "-----------------------------Insert Node-----------------------------" << endl;
	intTree.insetNode();

	cout << endl << "----------------------Print Binary Search Tree----------------------" << endl;
	intTree.printTree("LDR");

	cout << endl << "------------------------Print Tree with scope------------------------" << endl;
	intTree.iterableTree();

	cout << endl << "--------------------------------Depth--------------------------------" << endl;
	cout << "Depth : " << intTree.getDepth() << endl;

	cout << endl << "-----------------------------Leaf quantity-----------------------------" << endl;
	cout << "Leaf quantity : " << intTree.getLeafQuantity() << endl;

	cout << endl << "----------------------------Node quantity----------------------------" << endl;
	cout << "Node quantity : " << intTree.getElementQuantity() << endl;

	cout << endl << "-----------------------------Delete node-----------------------------" << endl;
	intTree.deleteNode();

	cout << endl << "-----------------------------After delete-----------------------------" << endl;
	intTree.printTree("LDR");

	cout << endl << "-----------------------------Search node-----------------------------" << endl;
	cout << "Iterative search by element>>>>> " << endl;
	if (intTree.iterativeSearch()) cout << "True" << endl;
	else cout << "False" << endl;

	cout << endl << "------------------------Search node by value------------------------" << endl;
	intTree.searchBSTbyValue();*/

	cout << endl << "------------------------------------------------------------------------" << endl;
	intTree.deleteTree();
}


int main()
{
	try
	{
		funcBinarySearchTree();
	}
	catch (MyErrorInfo& err)
	{
		cout << err.what() << endl;
	}
	
}