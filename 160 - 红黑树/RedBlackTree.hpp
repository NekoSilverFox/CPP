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
		Node(int key) : key_(key), colour_(red), p_(nullptr), left_(nullptr), right_(nullptr) {}
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
		root_->colour_ = red;
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
				node_insert->p_ = root;
				judgmentAdjustmentCondition(node_insert);
			}
		}
		else if (node_insert->key_ < root->key_)
		{
			if (nullptr != root->left_) { insertNode(root->left_, node_insert); }
			else
			{
				root->left_ = node_insert;
				node_insert->p_ = root;
				judgmentAdjustmentCondition(node_insert);
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
		if (nullptr == node) throw MyErrorInfo("nullptr_node_judgmentAdjustmentCondition");
		if (nullptr == node->p_) return 0;

		if (black == node->p_->colour_)
		{
			cout << "\033[31m (2) \033[0m";
			return 2;
		}
		else if (red == node->p_->colour_)
		{
			// 叔叔结点存在，且为红结点
			if (
					node->p_ == node->p_->p_->left_ && 
					nullptr != node->p_->p_->right_ && 
					red == node->p_->p_->right_->colour_
				)
			{
				adjustRedBlackTree_411(node);
				cout << "\033[31m (411) \033[0m";
				return 411;
			}

			// 叔叔结点存在，且为红结点
			else if 
				(
					node->p_ == node->p_->p_->right_ && 
					nullptr != node->p_->p_->left_ && 
					red == node->p_->p_->left_->colour_
				)
			{
				adjustRedBlackTree_412(node);
				cout << "\033[31m (412) \033[0m";
				return 412;
			}

			else if
				(
					(node->p_ == node->p_->p_->left_) &&
					(
						nullptr == node->p_->p_->right_ ||
						black == node->p_->p_->right_->colour_
					)
				)
			{
				if (node == node->p_->left_)
				{
					adjustRedBlackTree_421(node);
					cout << "\033[31m (421) \033[0m";
					return 421;
				}
				if (node == node->p_->right_)
				{
					adjustRedBlackTree_422(node);
					cout << "\033[31m (422) \033[0m";
					return 422;
				}
			}

			else if
				(
					(node->p_ == node->p_->p_->right_) &&
					(
						nullptr == node->p_->p_->left_ ||
						black == node->p_->p_->left_->colour_
					)
				)
			{
				if (node == node->p_->left_)
				{
					adjustRedBlackTree_431(node);
					cout << "\033[31m (431) \033[0m";
					return 431;
				}
				else if (node == node->p_->right_)
				{
					adjustRedBlackTree_432(node);
					cout << "\033[31m (432) \033[0m";
					return 432;
				}
			}
		}
		else
		{
			return 0;
		}
	}

	// 叔叔结点存在，且为红结点
	void adjustRedBlackTree_411(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_411");

		// 把父节点和叔叔结点设为black
		node->p_->colour_ = black;
		node->p_->p_->right_->colour_ = black;

		// 把爷爷设为 red
		node->p_->p_->colour_ = red;

		judgmentAdjustmentCondition(node->p_->p_);

#if 0
		// 将 pp 设为待插入的结点，如果 pp  的父节点为红，需要继续做自平衡处理
		if (red == node->p_->p_->p_->colour_)
		{
			Node* tempNode = node->p_->p_;
			adjustRedBlackTree_411(tempNode);
		}
#endif

	}

	// 叔叔结点存在，且为红结点
	void adjustRedBlackTree_412(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_412");

		// 把父节点和叔叔结点设为black
		node->p_->colour_ = black;
		node->p_->p_->right_->colour_ = black;

		// 把爷爷设为 red
		node->p_->p_->colour_ = red;

		judgmentAdjustmentCondition(node->p_->p_);

#if 0
		// 将 pp 设为待插入的结点，如果 pp  的父节点为红，需要继续做自平衡处理
		if (red == node->p_->p_->p_->colour_)
		{
			Node* tempNode = node->p_->p_;
			adjustRedBlackTree_411(tempNode);
		}
#endif

	}
	
	// 叔叔结点不存在，或者为黑结点，并且插入的结点是父节点 是 祖父结点的左节点
	
	// 插入节点是其父节点的左节点
	void adjustRedBlackTree_421(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_421");

		node->p_->colour_ = black;
		node->p_->p_->colour_ = red;

		// 对pp进行右旋
		// 缓存一下 pp
		Node* temp_pp = node->p_->p_;
		
		if (nullptr != temp_pp->p_)
		{
			if (temp_pp->p_->left_ == temp_pp)
			{
				temp_pp->p_->left_ = node->p_;
			}
			else if (temp_pp->p_->right_ == temp_pp)
			{
				temp_pp->p_->right_ = node->p_;
			}

			node->p_->right_ = temp_pp;
			temp_pp->left_ = nullptr;
			temp_pp->p_ = node->p_;
		}
		else
		{
			root_ = node->p_;
			root_->p_ = nullptr;
			root_->left_ = node;
			node->p_ = root_;
			root_->right_ = temp_pp;
			temp_pp->left_ = nullptr;
			temp_pp->p_ = root_;


			//node->p_->p_ = node->p_;
			//node->p_->p_ = nullptr;
			//node->p_->right_ = temp_pp;
			//temp_pp->p_ = node->p_;
			//temp_pp->left_ = nullptr;
		}
	}

	// 叔叔结点不存在，或者为黑结点，并且插入的结点是父节点 是 祖父结点的左节点
	// 插入节点是其父节点的右节点
	void adjustRedBlackTree_422(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_422");

		// 对p进行左旋
		// 缓存一下 p
		Node* temp_p = node->p_;

		//if (temp_p->p_->left_ == temp_p->p_)
		//{
		//	temp_p->p_->left_ = node;
		//}
		//else if (temp_p->p_->right_ == temp_p->p_)
		//{
		//	temp_p->p_->right_ == node;
		//}
		
		node->p_->p_->left_ = node;
		node->p_ = temp_p->p_;
		node->right_ = temp_p;
		temp_p->p_ = node;
		temp_p->right_ = nullptr;
		

		// 把 p 设置为插入节点，得到情景 4.2.1

		// 进行 4.2.1 的处理
		adjustRedBlackTree_421(temp_p);

	}
	
	// 叔叔结点不存在或为黑结点，并且插入的结点的父节点是祖父节点的右节点
	// 插入节点是父节点的右节点
	void adjustRedBlackTree_431(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_431");

		// 将 p 设为黑色
		node->p_->colour_ = black;

		// 将 pp 设为红色
		node->p_->p_->colour_ = red;

		// 将 pp 进行左旋
		Node* temp_pp = node->p_->p_;

		if (nullptr != temp_pp->p_)
		{
			if (temp_pp->p_->left_ == temp_pp)
			{
				temp_pp->p_->left_ = node->p_;
			}
			else if (temp_pp->p_->right_ == temp_pp)
			{
				temp_pp->p_->right_ = node->p_;
			}
			node->p_ = temp_pp->p_;
			node->left_ = temp_pp;
			temp_pp->p_ = node->p_;
			temp_pp->right_ = nullptr;
		}
		else
		{

			root_ = node->p_;
			root_->p_ = nullptr;
			root_->left_ = temp_pp;
			temp_pp->p_ = root_;
			temp_pp->right_ = nullptr;

			//node->p_ = temp_pp->p_;
			//node->p_->left_ = temp_pp;
			//temp_pp->p_ = node->p_;
			//temp_pp->right_ = nullptr;
		}
	}

	void adjustRedBlackTree_432(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_432");

		Node* temp_p = node->p_;

		node->p_->p_->right_ = node;
		node->right_ = temp_p;
		node->p_ = temp_p->p_;
		temp_p->p_ = node;
		temp_p->left_ = nullptr;



		//temp_p->p_->right_ = node;
		//node->p_ = temp_p->p_;
		//node->right_ = temp_p;
		//temp_p->left_ = nullptr;

		adjustRedBlackTree_431(temp_p);
	}

};
