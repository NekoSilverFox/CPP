#pragma once
#include "MyErrorInfo.h"
#include <iostream>

#define red true
#define black false

class RedBlackTree
{
private:
	struct Node
	{
		Node() : key_(0), colour_(red), p_(nullptr), left_(nullptr), right_(nullptr) {}
		Node(int key) : key_(key), colour_(true), p_(nullptr), left_(nullptr), right_(nullptr) {}
		int key_;
		bool colour_; // red - true; black - false;
		Node* p_;
		Node* left_;
		Node* right_;
	};

	Node* root_;

public:
	RedBlackTree()
	{
		root_ = new Node;
		root_->key_ = -1;
		root_->colour_ = black;
		root_->p_ = nullptr;
		root_->left_ = nullptr;
		root_->right_ = nullptr;
	}

	void insert(int key_insert)
	{
		/*
		* bool init 为标识符，判断是否为第一个插入的节点，如果是，直接将 root_结点更新为 key_insert
		*/
		static bool init = false;
		if (false == init)
		{
			init = true;
			root_->key_ = key_insert;
			root_->colour_ = black;
		}
		else
		{
			Node* node_insert = new Node;
			node_insert->key_ = key_insert;
			insertNode(root_, node_insert);
		}
	}

	void foreach()
	{
		foreachRBTree(root_);
	}

private:

	void insertNode(Node* root, Node* node_insert)
	{
		if (nullptr == root) throw MyErrorInfo("nullptr_in_insertNode");

		if (node_insert->key_ > root->key_)
		{
			if (nullptr != root->right_) { insertNode(root->right_, node_insert); }
			else
			{
				root->right_ = node_insert;
				node_insert->p_ = root->right_;
			}
		}
		else if (node_insert->key_ < root->key_)
		{
			if (nullptr != root->left_) { insertNode(root->left_, node_insert); }
			else
			{
				root->left_ = node_insert;
				node_insert->p_ = root->left_;
			}
		}
		else
		{
			return;
		}
	}

	void foreachRBTree(Node* root)
	{
		if (nullptr == root) return;

		foreachRBTree(root->left_);
		std::cout << root->key_ << " ";
		foreachRBTree(root->right_);
	}

	int judgmentAdjustmentCondition(Node* node)
	{
		if (nullptr == node) return;

		if (black == node->p_->colour_)
		{
			return 2;
		}
		else if (red == node->p_->colour_)
		{
			if (
					node->p_ == node->p_->p_->left_ && 
					nullptr != node->p_->p_->right_ && 
					red == node->p_->p_->right_->colour_
				)
			{
				return 411;
			}

			else if 
				(
					node->p_ == node->p_->p_->right_ && 
					nullptr != node->p_->p_->left_ && 
					red == node->p_->p_->left_->colour_
				)
			{
				return 412;
			}

			else if
				(
					(node->p_ == node->p_->p_->left_) &&
					(
						nullptr == node->p_->p_->right_ ||
						black == node->p_->p_->right_
					)
				)
			{
				if (node == node->p_->left_)
				{
					return 421;
				}
				if (node == node->p_->right_)
				{
					return 422;
				}
			}

			else if
				(
					(node->p_ == node->p_->p_->right_) &&
					(
						nullptr == node->p_->p_->left_ ||
						black == node->p_->p_->left_
					)
				)
			{
				if (node == node->p_->left_)
				{
					return 431;
				}
				else if (node == node->p_->right_)
				{
					return 432;
				}
			}
		}
	}

	void adjustRedBlackTree_411(Node* node);

	void adjustRedBlackTree_412(Node* node);

	void adjustRedBlackTree_421(Node* node);

	void adjustRedBlackTree_422(Node* node);

	void adjustRedBlackTree_431(Node* node);

	void adjustRedBlackTree_432(Node* node);

};
