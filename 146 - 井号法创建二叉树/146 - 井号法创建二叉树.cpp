#include<iostream>
using namespace std;

struct BinaryNode
{
	char ch_;
	BinaryNode* left_child;
	BinaryNode* right_child;
};

BinaryNode* CreatBinaryTree()
{
	BinaryNode* node = new BinaryNode;

	char ch;
	cout << ">> "; cin >> ch;

	if (ch == '#')
	{
		node = nullptr;
	}
	else
	{
		node->ch_ = ch;
		node->left_child = CreatBinaryTree();
		node->right_child = CreatBinaryTree();
	}

	return node;
}

void Recursion(BinaryNode* root)
{
	if (root == nullptr) return;

	cout << root->ch_ << " ";
	Recursion(root->left_child);
	Recursion(root->right_child);
}

int main()
{
	BinaryNode* root = CreatBinaryTree();
	Recursion(root);
}