#include<iostream>
using namespace std;

struct Tree
{
	Tree(char ch, Tree* left, Tree* right) : ch_(ch), left_child(left), right_child(right) {}

	char ch_;
	Tree* left_child;
	Tree* right_child;
};

void Foreach_Tree_DLR(Tree* root)
{
	if (root == nullptr) return;

	cout << root->ch_;

	Foreach_Tree_DLR(root->left_child);
	Foreach_Tree_DLR(root->right_child);
}

void Foreach_Tree_LDR(Tree* root)
{
	if (root == nullptr) return;

	Foreach_Tree_LDR(root->left_child);
	cout << root->ch_;
	Foreach_Tree_LDR(root->right_child);
}

void Foreach_Tree_LRD(Tree* root)
{
	if (root == nullptr) return;

	Foreach_Tree_LRD(root->left_child);
	Foreach_Tree_LRD(root->right_child);
	cout << root->ch_;
}

void test()
{
	Tree* t1 = new Tree('A', nullptr, nullptr);
	Tree* t2 = new Tree('B', nullptr, nullptr);
	Tree* t3 = new Tree('F', nullptr, nullptr);
	Tree* t4 = new Tree('C', nullptr, nullptr);
	Tree* t5 = new Tree('D', nullptr, nullptr);
	Tree* t6 = new Tree('G', nullptr, nullptr);
	Tree* t7 = new Tree('E', nullptr, nullptr);
	Tree* t8 = new Tree('H', nullptr, nullptr);
	Tree* t9 = new Tree('I', nullptr, nullptr);
	
	t1->left_child = t2;
	t1->right_child = t3;
	t2->left_child = t4;
	t2->right_child = t5;
	t3->right_child = t6;
	t5->left_child = t7;
	t6->left_child = t8;
	t6->right_child = t9;
	
	cout << "DLR : ";
	Foreach_Tree_DLR(t1);
	cout << endl;

	cout << "LDR : ";
	Foreach_Tree_LDR(t1);
	cout << endl;

	cout << "LRD : ";
	Foreach_Tree_LRD(t1);
	cout << endl;
}

int main()
{
	test();
}