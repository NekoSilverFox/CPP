#include<iostream>
using namespace std;

struct BinaryNode
{
	char ch_;
	BinaryNode* left_child;
	BinaryNode* right_child;
};

int CaculateTreeDepth(BinaryNode* root)
{
	if (root == nullptr) return;

	int depth = 0;

	int left_depth = CaculateTreeDepth(root->left_child);
	int right_depth = CaculateTreeDepth(root->right_child);

	depth = left_depth > right_depth ? left_depth : right_depth;

	return depth;
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
	node1.left_child = &node2;
	node1.right_child = &node6;
	node2.right_child = &node3;
	node3.left_child = &node4;
	node3.right_child = &node5;
	node6.right_child = &node7;
	node7.left_child = &node8;

	int depth = CaculateTreeDepth(&node1);
	cout << "树的高度为：" << depth << endl;
}


int main() {
	CresteBinaryTree();
}