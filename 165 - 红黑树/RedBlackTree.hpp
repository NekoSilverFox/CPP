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
		* bool init Ϊ��ʶ�����ж��Ƿ�Ϊ��һ������Ľڵ㣬����ǣ�ֱ�ӽ� root_������Ϊ key_insert
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
			// ��������ڣ���Ϊ����
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

			// ��������ڣ���Ϊ����
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

	// ��������ڣ���Ϊ����
	void adjustRedBlackTree_411(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_411");

		// �Ѹ��ڵ����������Ϊblack
		node->p_->colour_ = black;
		node->p_->p_->right_->colour_ = black;

		// ��үү��Ϊ red
		node->p_->p_->colour_ = red;

		judgmentAdjustmentCondition(node->p_->p_);

#if 0
		// �� pp ��Ϊ������Ľ�㣬��� pp  �ĸ��ڵ�Ϊ�죬��Ҫ��������ƽ�⴦��
		if (red == node->p_->p_->p_->colour_)
		{
			Node* tempNode = node->p_->p_;
			adjustRedBlackTree_411(tempNode);
		}
#endif

	}

	// ��������ڣ���Ϊ����
	void adjustRedBlackTree_412(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_412");

		// �Ѹ��ڵ����������Ϊblack
		node->p_->colour_ = black;
		node->p_->p_->right_->colour_ = black;

		// ��үү��Ϊ red
		node->p_->p_->colour_ = red;

		judgmentAdjustmentCondition(node->p_->p_);

#if 0
		// �� pp ��Ϊ������Ľ�㣬��� pp  �ĸ��ڵ�Ϊ�죬��Ҫ��������ƽ�⴦��
		if (red == node->p_->p_->p_->colour_)
		{
			Node* tempNode = node->p_->p_;
			adjustRedBlackTree_411(tempNode);
		}
#endif

	}
	
	// �����㲻���ڣ�����Ϊ�ڽ�㣬���Ҳ���Ľ���Ǹ��ڵ� �� �游������ڵ�
	
	// ����ڵ����丸�ڵ����ڵ�
	void adjustRedBlackTree_421(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_421");

		node->p_->colour_ = black;
		node->p_->p_->colour_ = red;

		// ��pp��������
		// ����һ�� pp
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

	// �����㲻���ڣ�����Ϊ�ڽ�㣬���Ҳ���Ľ���Ǹ��ڵ� �� �游������ڵ�
	// ����ڵ����丸�ڵ���ҽڵ�
	void adjustRedBlackTree_422(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_422");

		// ��p��������
		// ����һ�� p
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
		

		// �� p ����Ϊ����ڵ㣬�õ��龰 4.2.1

		// ���� 4.2.1 �Ĵ���
		adjustRedBlackTree_421(temp_p);

	}
	
	// �����㲻���ڻ�Ϊ�ڽ�㣬���Ҳ���Ľ��ĸ��ڵ����游�ڵ���ҽڵ�
	// ����ڵ��Ǹ��ڵ���ҽڵ�
	void adjustRedBlackTree_431(Node* node)
	{
		if (nullptr == node) throw MyErrorInfo("nullptr_node_in_431");

		// �� p ��Ϊ��ɫ
		node->p_->colour_ = black;

		// �� pp ��Ϊ��ɫ
		node->p_->p_->colour_ = red;

		// �� pp ��������
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
