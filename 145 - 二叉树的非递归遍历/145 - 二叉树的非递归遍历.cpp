#include"LinkStack.h"

// 二叉树结点
struct BinaryTree
{
	BinaryTree(char ch, BinaryTree* left, BinaryTree* right);
	char ch_;
	BinaryTree* left_child;
	BinaryTree* right_child;
};
BinaryTree::BinaryTree(char ch, BinaryTree* left, BinaryTree* right) : ch_(ch), left_child(left), right_child(right) {}


// 二叉树的非递归遍历
struct BinTreeStackNode
{
	LinkNode node;
	BinaryTree* root;
	bool flag;
};

// 创建栈中的结点
BinTreeStackNode* CreatBinTreeStackNode(BinaryTree* node, bool flag)
{
	BinTreeStackNode* newNode = new BinTreeStackNode;
	newNode->root = node;
	newNode->flag = false;
	return newNode;
}

void NoneRecursion(BinaryTree* root)
{
	// 创建栈
	LinkStack* stack = InIt_LinkStack();

	// 将根结点放到栈中
	Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(root, false));

	while (Size_LinkStack(stack) > 0)
	{
		// 先弹出栈顶元素
		BinTreeStackNode* node = (BinTreeStackNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);

		// 判断，如果为 nullptr 直接重新循环
		if (node->root == nullptr) continue;

		if (node->flag == true)
		{
			cout << node->root->ch_ << " ";
		} else {
			Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(node->root->right_child, false));
			Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(node->root->left_child, false));
			node->flag = true;
			Push_LinkStack(stack, (LinkNode*)node);
		}
	}
}

BinaryTree* CreatTree()
{
	BinaryTree* t1 = new BinaryTree('A', nullptr, nullptr);
	BinaryTree* t2 = new BinaryTree('B', nullptr, nullptr);
	BinaryTree* t3 = new BinaryTree('F', nullptr, nullptr);
	BinaryTree* t4 = new BinaryTree('C', nullptr, nullptr);
	BinaryTree* t5 = new BinaryTree('D', nullptr, nullptr);
	BinaryTree* t6 = new BinaryTree('G', nullptr, nullptr);
	BinaryTree* t7 = new BinaryTree('E', nullptr, nullptr);
	BinaryTree* t8 = new BinaryTree('H', nullptr, nullptr);
	BinaryTree* t9 = new BinaryTree('I', nullptr, nullptr);

	t1->left_child = t2;
	t1->right_child = t3;
	t2->left_child = t4;
	t2->right_child = t5;
	t3->right_child = t6;
	t5->left_child = t7;
	t6->left_child = t8;
	t6->right_child = t9;

	return t1;

}

int main()
{
	// 二叉树非递归打印
	NoneRecursion(CreatTree());
}