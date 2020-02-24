#include<iostream>
using namespace std;

struct BinaryNode {
	char ch;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;
};


void CaculateLeafNum(BinaryNode* root, int* leafNum) {

	if (root == nullptr) {
		return;
	}

	if (root->lchild == nullptr && root->rchild == nullptr) {
		(*leafNum)++;
	}

	//左子树叶子结点的数目
	CaculateLeafNum(root->lchild, leafNum);
	//右子树叶子结点的数目
	CaculateLeafNum(root->rchild, leafNum);

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

	int leafNum = 0;
	CaculateLeafNum(&node1, &leafNum);
	cout << "叶子结点的数目: " << leafNum;

}

int main() {

	CresteBinaryTree();
}