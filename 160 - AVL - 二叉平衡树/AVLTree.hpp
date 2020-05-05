#pragma once
#include <iostream>
#include "MyErrorInfo.hpp"
using namespace std;

template <typename T>
class AVLTree
{
private:
	template <typename T>
	struct AVLNode
	{
		AVLNode() : height_(0), p_(nullptr), left_(nullptr), right_(nullptr) {}
		AVLNode(T key) : height_(0), key_ (key), p_(nullptr), left_(nullptr), right_(nullptr) {}

		unsigned int height_;
		T key_;
		AVLNode<T>* p_;
		AVLNode<T>* left_;
		AVLNode<T>* right_;
	};

	AVLNode<T>* root_;

public:
	// ���ĸ߶�
	unsigned int height()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		return _height_(this->root_);
	}

	// ǰ����� AVL��
	void preOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_preOrder_(this->root_);
	}

	// ������� AVL��
	void inOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		inOrder(this->root_);
	}

	// �������� AVL��
	void postOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_postOrder_(this->root_);
	}

	// �ݹ� - ���������key �Ľڵ�
	T* search(T key_search)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode<T>* node_search = search(this->root_, key_search);

		if (nullptr == node_search)
		{
			cout << "\033[31m"
				<< "Can't search the node, which key is " << key_search
				<< " !"
				<< "\033[0m"
				<< endl;
		}
		else
		{
			cout << "\033[032m"
				<< "Succeful search the node, which key is" << key_search
				<< " !"
				<<"\033[0m"
				<< endl;
		}
	}

	// ���� - ���������key �Ľڵ�
	T* iterativeSearch(T key_search)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode<T>* node_search = _iterativeSearch_(this->root_, key_search);

		if (nullptr == node_search)
		{
			cout << "\033[32m"
				<< "Can't search the node, which key is " << key_search
				<< " !"
				<< "\033[0m"
				<< endl;
		}
		else
		{
			cout << "\033[032m"
				<< "Succeful search the node, which key is" << key_search
				<< " !"
				<< "\033[0m"
				<< endl;
		}
	}

	// ������Сֵ
	T* min()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode<T>* min_node = _min_(this->root_);

		cout << "\033[032m"
			<< "The min node is " << min_node->key_
			<< "\033[0m"
			<< endl;
	}

	// �������ֵ
	T* max()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode<T>* max_node = _min_(this->root_);

		cout << "\033[032m"
			<< "The min node is " << max_node->key_
			<< "\033[0m"
			<< endl;
	}

	// ����ָ���Ľڵ㵽AVL����
	void insert(T key_insert)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode<T>* node_insert = new AVLNode<T>(key_insert);

		_insert_(node_insert);
	}

	// ɾ��ָ���Ľڵ㵽 AVL����
	void remove(T key_remove)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_remove_(this->root_, key_remove);
	}

	// ===============================================================================================
	// ==========================================private=================================================
	// ===============================================================================================

private:
	// ���ĸ߶�
	unsigned int _height_(AVLNode* root)
	{
		return root->height_;
	}

	// ��ȡ�������ĸ߶Ȳ�
	int _heightDifference_(AVLNode* node_1, AVLNode* node_2)
	{
		if (nullptr == node_1 || nullptr == node_2) throw MyErrorInfo("node is nullptr !");

		return node_1->height_ - node_2->height_;
	}

	// ǰ����� AVL��
	void _preOrder_(AVLNode* root)
	{
		if (nullptr == root) return;

		cout << root->key_ << " ";
		_preOrder_(root->left_);
		_preOrder_(root->right_);
	}

	// ������� AVL��
	void _inOrder_(AVLNode* root)
	{
		if (nullptr == root) return;

		_inOrder_(root->left_);
		cout << root->key_ << " ";
		_inOrder_(root->right_);
	}

	// �������� AVL��
	void _postOrder_(AVLNode* root)
	{
		if (nullptr == root) return;

		_postOrder_(root->left_);
		_postOrder_(root->right_);
		cout << root->key_ << " ";
	}

	// �ݹ� - ���������key �Ľڵ� ���ġ�
	AVLNode<T>* _search_(AVLNode* root, const T& key_search)
	{
		if (nullptr == root || key_search == root->key_) return root;

		if (key_search < root->key_)
		{
			_search_(root->right_);
		}
		else if (key_search > root->key_)
		{
			_search_(root->left_);
		}
	}

	// ���� - ���������key �Ľڵ�
	AVLNode<T>* _iterativeSearch_(AVLNode* root, const T& key_search)
	{
		AVLNode<T>* pCurrent = root;

		while (nullptr != pCurrent)
		{
			if (key_search == pCurrent->key_)
			{
				return pCurrent;
			}

			while (nullptr != pCurrent && key_search < pCurrent->key_)
			{
				pCurrent = pCurrent->left_;
			}

			while (nullptr != pCurrent && key_search > pCurrent->key_)
			{
				pCurrent = pCurrent->right_;
			}
		}

		return nullptr;
	}

	// ������Сֵ
	AVLNode<T>* _min_(AVLNode* root)
	{
		AVLNode<T>* t_node = root;

		while (nullptr != t_node->left_)
		{
			t_node == t_node->left_;
		}

		return t_node;
	}

	// �������ֵ
	AVLNode<T>* _max_(AVLNode* root)
	{
		AVLNode<T>* t_node = root;

		while (nullptr != root->right_)
		{
			t_node = t_node->right_;
		}

		return  t_node;
	}

	// LL
	AVLNode<T>* LLRotation(AVLNode<T>* node);

	// RR
	AVLNode<T>* RRRotation(AVLNode<T>* node);

	// LR
	AVLNode<T>* LRRotation(AVLNode<T>* node);

	// RL
	AVLNode<T>* RLRotation(AVLNode<T>* node);

	// ����ָ���Ľڵ㵽AVL����
	void _insert_(AVLNode* node_insert)
	{
		if (nullptr == node_insert) throw MyErrorInfo("node is nullptr in function _insert_!");

		// the first node
		static bool s_init = false;
		if (false == s_init)
		{
			s_init = true;
			this->root_ = node_insert;
			return;
		}

		// ���ҵ�Ӧ�ò����ĸ��ڵ�֮��
		AVLNode<T>* pCurrent = root_;
		AVLNode<T>* p_parents_of_node_insert = pCurrent; // Ӧ���뵽�˽ڵ�֮��
		while (nullptr != pCurrent)
		{
			if (node_insert->key_ < pCurrent->key_)
			{
				p_parents_of_node_insert = pCurrent;
				pCurrent = pCurrent->left_;
			}
			else if (node_insert->key_ > pCurrent->key_)
			{
				p_parents_of_node_insert = pCurrent;
				pCurrent = pCurrent->right_;
			}
			else
			{
				cout << "The key " << node_insert->key_ << " already have!" << endl;
				return;
			}
		}

		// =====================
		if (node_insert->key_ < p_parents_of_node_insert->key_)
		{
			p_parents_of_node_insert->left_ = node_insert;
			node_insert->p_ = p_parents_of_node_insert;
		}
		else if (node_insert->key_ > p_parents_of_node_insert)
		{
			p_parents_of_node_insert->right_ = node_insert;
			node_insert->p_ = p_parents_of_node_insert;
		}

	}

	// ɾ��ָ���Ľڵ㵽 AVL����
	void _remove_(AVLNode* root, T key_remove);
};