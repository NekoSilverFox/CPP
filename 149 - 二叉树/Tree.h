#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
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

private:
	Node* root_;
	// -----------------------------------------------------------------

public:
	BinaryTree()
	{
		root_ = new Node;
		root_->key_ = nullptr;
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

	void printTree(string method) const 
	{
		if ("DLR" == method) { Foreach_Tree_DLR(this->root_); }
		else if ("LDR" == method) { Foreach_Tree_LDR(this->root_); }
		else if ("LRD" == method) { Foreach_Tree_LRD(this->root_); }
		else if ("ALL" == method)
		{
			cout << "DLR : " << Foreach_Tree_DLR(this->root_) << endl;
			cout << "LDR : " << Foreach_Tree_DLR(this->root_) << endl;
			cout << "LRD : " << Foreach_Tree_DLR(this->root_) << endl;
		}
		else
		{
			cerr << "----- Unknown command -----" << endl;
			cout << "， DLR" << endl
					<< "， LDR" << endl
					<< "， LRD" << endl
					<< "， ALL" << endl;
		}
	}

	int getLeafnum() const
	{
		return CaculateLeafNum(this->root_);
	}

	int getDepth() const
	{
		return CaculateTreeDepth(this->root_);
	}

	Node* copyTree() const 
	{
		return CopyBinaryTree(this->root_);
	}

	void deleteTree() const
	{
		FreeSpaceBinaryTree(root_);
	}

	// ---------------------------- --- ----------------------------
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
		if (root == nullptr) return;

		cout << root->key_ << " ";
		Foreach_Tree_DLR(root->left_);
		Foreach_Tree_DLR(root->right_);
	}

	void Foreach_Tree_LDR(Node* root)
	{
		if (root == nullptr) return;

		Foreach_Tree_LDR(root->left_);
		cout << root->key_;
		Foreach_Tree_LDR(root->right_);
	}

	void Foreach_Tree_LRD(Node* root)
	{
		if (root == nullptr) return;

		Foreach_Tree_LRD(root->left_);
		Foreach_Tree_LRD(root->right_);
		cout << root->key_;
	}

	int CaculateLeafNum(Node* root)
	{
		static int leaf_num = 0;
		if (root == nullptr) return;
		if (root->left_ == nullptr && root->right_ == nullptr) leaf_num++;
		CaculateLeafNum(root->left_); // number of the left leaf
		CaculateLeafNum(root->right_); // number of the right leaf
	}

	int CaculateTreeDepth(Node* root)
	{
		if (root == nullptr) return 0;
		int depth = 0;
		int left_depth = CaculateTreeDepth(root->left_);
		int right_depth = CaculateTreeDepth(root->right_);
		depth = left_depth > right_depth ? ++left_depth : ++right_depth;
		return depth;
	}

	Node* CopyBinaryTree(Node* root)
	{
		if (root == nullptr) return nullptr;
		Node* left_child = CopyBinaryTree(root->left_);
		Node* right_child = CopyBinaryTree(root->right_);

		Node* newNode = new Node;
		newNode->key_ = root->key_;
		newNode->left_ = left_child;
		newNode->right = right_child;
	} 

	void FreeSpaceBinaryTree(Node* root)
	{
		if (root == nullptr) return;
		FreeSpaceBinaryTree(root->left_);
		FreeSpaceBinaryTree(root->right_);
		delete root;
	}

};
#endif