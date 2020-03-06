#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

template<typename T>
class BinaryTree
{
	// ---------------------------- Node ----------------------------
private:
	struct Node
	{
		Node() {}
		Node(T key) : key_(key), left_(nullptr), right_(nullptr), p_(nullptr) {}
		Node(T key, Node* left, Node* right, Node* p) : key_(key), left_(left), right_(right), p_(p) {}

		T key_;
		Node* left_;
		Node* right_;
		Node* p_;
	};

	struct BinTreeStackNode
	{
		LinkNode node;
		Node* root;
		bool flag;
	};

private:
	Node* root_;
	// -----------------------------------------------------------------

public:
	BinaryTree()
	{
		root_ = new Node;
		root_->key_ = NULL;
		root_->left_ = nullptr;
		root_->right_ = nullptr;
		root_->p_ = nullptr;
	}
	BinaryTree(T key)
	{
		root_ = new Node<T>(key);
	}
	BinaryTree(T key, Node* left, Node* right, Node* p)
	{
		root_ = new Node<T>(key, left, right, p);
	}

	void insertTree()
	{
		root_ = CreatBinaryTreeByMethodPound();
	}

	void printTree(string method) 
	{
		if ("DLR" == method) { Foreach_Tree_DLR(this->root_); }
		else if ("LDR" == method) { Foreach_Tree_LDR(this->root_); }
		else if ("LRD" == method) { Foreach_Tree_LRD(this->root_); }
		else if ("ALL" == method)
		{
			cout << "DLR : "; Foreach_Tree_DLR(this->root_); cout << endl;
			cout << "LDR : "; Foreach_Tree_LDR(this->root_); cout << endl;
			cout << "LRD : "; Foreach_Tree_LRD(this->root_); cout << endl;
		}
		else
		{
			cerr << "----- Unknown command -----" << endl;
			cout << "· DLR" << endl
					<< "· LDR" << endl
					<< "· LRD" << endl
					<< "· ALL" << endl;
		}
	}

	int getElementNum()
	{
		return CaculateElementNum(this->root_);
	}

	int getLeafNum()
	{
		return CaculateLeafNum(this->root_);
	}

	int getDepth()
	{
		return CaculateTreeDepth(this->root_);
	}

	Node* copyTree() const 
	{
		return CopyBinaryTree(this->root_);
	}

	bool iterativeSearch()
	{
		return (IterativeSearchNode(this->root_) != nullptr);
	}

	void deleteTree()
	{
		FreeSpaceBinaryTree(this->root_);
	}

	// -----------------------------------------------------------
private:
	Node* CreatBinaryTreeByMethodPound()
	{
		Node* node = new Node;

		T key;
		cout << ">> "; cin >> key;

		if (key == '#')
		{
			node = nullptr;
		}
		else
		{
			node->key_ = key;
			node->left_ = CreatBinaryTreeByMethodPound();
			node->right_ = CreatBinaryTreeByMethodPound();
		}
		return node;
	}

	void Foreach_Tree_DLR(Node* root)
	{
		if (nullptr == root) return;

		cout << root->key_ << " ";
		Foreach_Tree_DLR(root->left_);
		Foreach_Tree_DLR(root->right_);
	}

	void Foreach_Tree_LDR(Node* root)
	{
		if (nullptr == root) return;

		Foreach_Tree_LDR(root->left_);
		cout << root->key_ << " ";
		Foreach_Tree_LDR(root->right_);
	}

	void Foreach_Tree_LRD(Node* root)
	{
		if (nullptr == root) return;

		Foreach_Tree_LRD(root->left_);
		Foreach_Tree_LRD(root->right_);
		cout << root->key_ << " ";
	}

	// 创建栈中的结点 - Creat element in stack
	BinTreeStackNode* CreatBinTreeStackNode(Node* node, bool flag)
	{
		BinTreeStackNode* newNode = new BinTreeStackNode;
		newNode->root = node;
		newNode->flag = false;
		return newNode;
	}

	int CaculateElementNum(Node* root)
	{
		if (nullptr == root) return 0;
		static int element_num = 0;
		CaculateElementNum(root->left_); element_num++;
		CaculateElementNum(root->right_);
		return element_num;
	}

	int CaculateLeafNum(Node* root)
	{
		static int leaf_num = 0;
		if (nullptr == root) return 0;
		if (root->left_ == nullptr && root->right_ == nullptr) leaf_num++;
		CaculateLeafNum(root->left_); // number of the left leaf
		CaculateLeafNum(root->right_); // number of the right leaf
		return leaf_num;
	}

	int CaculateTreeDepth(Node* root)
	{
		if (nullptr == root) return 0;
		int depth = 0;
		int left_depth = CaculateTreeDepth(root->left_);
		int right_depth = CaculateTreeDepth(root->right_);
		depth = left_depth > right_depth ? ++left_depth : ++right_depth;
		return depth;
	}

	Node* IterativeSearchNode(Node* root)
	{
		// 创建栈
		LinkStack* stack = InIt_LinkStack();
		Node* search_node = new Node;
		search_node = nullptr;
		//int counter = 0;
		//int place_key[50];
		//int i = 0;
		T search_key;

		cout << "Which key need to search : "; cin >> search_key;

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
				if (search_key == node->root->key_)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					cout << node->root->key_ << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				else
				{
					cout << node->root->key_ << " ";
				}
				//++counter;
				//if (node->root->key_ == search_key)
				//{
				//	if (0 == i)
				//	{
				//		place_key[i] = counter - 1;
				//		++i;
				//	}
				//	if (i > 0)
				//	{
				//		place_key[i] = counter - place_key[i - 1];
				//		++i;
				//	}	
				//	search_node = node->root;
				//}
				search_node = node->root;
			}
			else {
				Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(node->root->right_, false));
				Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(node->root->left_, false));
				node->flag = true;
				Push_LinkStack(stack, (LinkNode*)node);
			}
		}
		cout << endl;
		//for (int j = 0; j < i; ++j)
		//{
		//	for (int space_ = 0; space_ < place_key[j]; ++space_) cout << " ";
		//	cout << "A";
		//}
		return search_node;
	}

	T OutputDataElement(Node* root) // xxx
	{
		if (nullptr == root) return 0;
		unsigned int no_element;
		cout << "Element number :  "; cin >> no_element;
		if (no_element > CaculateElementNum(root))
		{
			cerr << "Don't have data!" << endl
				<< "The element number should less than " << CaculateElementNum() << " !" << endl;
			return 0;
		}

	}

	Node* CopyBinaryTree(Node* root)
	{
		if (nullptr == root) return nullptr;
		Node* left_child = CopyBinaryTree(root->left_);
		Node* right_child = CopyBinaryTree(root->right_);

		Node* newNode = new Node;
		newNode->key_ = root->key_;
		newNode->left_ = left_child;
		newNode->right = right_child;
	} 

	void FreeSpaceBinaryTree(Node* root)
	{
		if (nullptr == root) return;
		FreeSpaceBinaryTree(root->left_);
		FreeSpaceBinaryTree(root->right_);
		delete root;
	}

};
#endif