#include<iostream>
using namespace std;

struct BinaryNode
{
	char ch_;
	BinaryNode* lchild;
	BinaryNode* rchild;
};

void Recursion(BinaryNode* root)
{
	if (root == nullptr) return;

	cout << root->ch_ << " ";

	Recursion(root->lchild);
	Recursion(root->rchild);
}

BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	if (root == nullptr) return nullptr;

	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	BinaryNode* rchild = CopyBinaryTree(root->rchild);

	BinaryNode* newNode = new BinaryNode;

	newNode->ch_ = root->ch_;
	newNode->lchild = lchild;
	newNode->rchild = rchild;

	return newNode;
}

void FreeSpaceBinaryTree(BinaryNode* root)
{
	if (root == nullptr) return;


	FreeSpaceBinaryTree(root->lchild);
	FreeSpaceBinaryTree(root->rchild);
	delete root;
}

void CresteBinaryTree() {

	//创建结点
	BinaryNode node1 = { 'A', nullptr, nullptr };
	BinaryNode node2 = { 'B', nullptr, nullptr };
	BinaryNode node3 = { 'C', nullptr, nullptr };
	BinaryNode node4 = { 'D', nullptr, nullptr };
	BinaryNode node5 = { 'E', nullptr, nullptr };
	BinaryNode node6 = { 'F', nullptr, nullptr };
	BinaryNode node7 = { 'G', nullptr, nullptr };
	BinaryNode node8 = { 'H', nullptr, nullptr };


	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	BinaryNode* root = CopyBinaryTree(&node1);
	Recursion(root);
	FreeSpaceBinaryTree(root);
}

int main() {

	CresteBinaryTree();

}