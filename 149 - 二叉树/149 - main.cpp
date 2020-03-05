#include"LinkStack.h"
#include"Tree.h"

void Test()
{
	BinaryTree<char>* t1 = new BinaryTree('A', nullptr, nullptr);
	BinaryTree<char>* t2 = new BinaryTree('B', nullptr, nullptr);
	BinaryTree<char>* t3 = new BinaryTree('F', nullptr, nullptr);
	BinaryTree<char>* t4 = new BinaryTree('C', nullptr, nullptr);
	BinaryTree<char>* t5 = new BinaryTree('D', nullptr, nullptr);
	BinaryTree<char>* t6 = new BinaryTree('G', nullptr, nullptr);
	BinaryTree<char>* t7 = new BinaryTree('E', nullptr, nullptr);
	BinaryTree<char>* t8 = new BinaryTree('H', nullptr, nullptr);
	BinaryTree<char>* t9 = new BinaryTree('I', nullptr, nullptr);

	t1->left_child = t2;
	t1->right_child = t3;
	t2->left_child = t4;
	t2->right_child = t5;
	t3->right_child = t6;
	t5->left_child = t7;
	t6->left_child = t8;
	t6->right_child = t9;
}


int main()
{

}