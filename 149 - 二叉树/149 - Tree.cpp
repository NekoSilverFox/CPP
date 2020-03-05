#include"LinkStack.h"
#include"Tree.h"

void Tree()
{
	//BinaryTree<char>* t1 = new BinaryTree('A', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t2 = new BinaryTree('B', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t3 = new BinaryTree('F', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t4 = new BinaryTree('C', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t5 = new BinaryTree('D', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t6 = new BinaryTree('G', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t7 = new BinaryTree('E', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t8 = new BinaryTree('H', nullptr, nullptr, nullptr);
	//BinaryTree<char>* t9 = new BinaryTree('I', nullptr, nullptr, nullptr);

	/*BinaryTree<char> t1('A');
	BinaryTree<char> t2('B');
	BinaryTree<char> t3('F');
	BinaryTree<char> t4('C');
	BinaryTree<char> t5('D');
	BinaryTree<char> t6('G');
	BinaryTree<char> t7('E');
	BinaryTree<char> t8('H');
	BinaryTree<char> t9('I');

	t1.root_->left_ = t2.root_;
	t1.root_->right_ = t3.root_;
	t2.root_->left_ = t4.root_;
	t2.root_->right_ = t5.root_;
	t3.root_->right_ = t6.root_;
	t5.root_->left_ = t7.root_;
	t6.root_->left_ = t8.root_;
	t6.root_->right_ = t9.root_;

	t1.Foreach_Tree_DLR(t1.root_);*/

	BinaryTree<char> charTree;
	charTree.insertTree();
	charTree.printTree("ALL");
	charTree.getDepth();
	charTree.getLeafnum();
	charTree.deleteTree();
}
