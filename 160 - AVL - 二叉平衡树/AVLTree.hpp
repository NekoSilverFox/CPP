#pragma once
#include <iostream>
#include "MyErrorInfo.hpp"
using namespace std;

template <typename T>
class AVLTree
{
private:
	
	struct AVLNode
	{
		AVLNode() : p_(nullptr), left_(nullptr), right_(nullptr) {}
		AVLNode(T key) : key_ (key), p_(nullptr), left_(nullptr), right_(nullptr) {}

		T key_;
		AVLNode* p_;
		AVLNode* left_;
		AVLNode* right_;
	};

	AVLNode* root_;

public:

	// 前序遍历 AVL树
	void preOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_preOrder_(this->root_);
	}

	// 中序遍历 AVL树
	void inOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_inOrder_(this->root_);
	}

	// 后续遍历 AVL树
	void postOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_postOrder_(this->root_);
	}

	// 递归 - 查找输入的key 的节点
	bool search(T key_search)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode* node_search = _search_(this->root_, key_search);

		if (nullptr == node_search)
		{
			cout << "\033[31m"
				<< "Can't search the node, which key is " << key_search
				<< " !"
				<< "\033[0m"
				<< endl;
			return true;
		}
		else
		{
			cout << "\033[032m"
				<< "Succeful search the node, which key is " << key_search
				<< " !"
				<<"\033[0m"
				<< endl;
			return false;
		}
	}

	// 迭代 - 查找输入的key 的节点
	bool iterativeSearch(T key_search)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode* node_search = _iterativeSearch_(this->root_, key_search);

		if (nullptr == node_search)
		{
			cout << "\033[31m"
				<< "Can't search the node, which key is " << key_search
				<< " !"
				<< "\033[0m"
				<< endl;
			return true;
		}
		else
		{
			cout << "\033[032m"
				<< "Succeful search the node, which key is " << key_search
				<< " !"
				<< "\033[0m"
				<< endl;
			return false;
		}
	}

	// 查找最小值
	T min()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode* min_node = _min_(this->root_);

		cout << "\033[032m"
			<< "The min node is " << min_node->key_
			<< "\033[0m"
			<< endl;

		return min_node->key_;
	}

	// 查找最大值
	T max()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode* max_node = _max_(this->root_);

		cout << "\033[032m"
			<< "The min node is " << max_node->key_
			<< "\033[0m"
			<< endl;

		return max_node->key_;
	}

	// 插入指定的节点到AVL树中
	void insert(T key_insert)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		AVLNode* node_insert = new AVLNode(key_insert);

		_insert_(node_insert);
	}

	// 删除指定的节点到 AVL树中
	void remove(T key_remove)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_remove_(this->root_, key_remove);
	}

	// ===============================================================================================
	// ==========================================private=================================================
	// ===============================================================================================

private:
	// 树的高度
	unsigned int _height_(AVLNode* root)
	{
		if (nullptr == root) return 0;

		int left_height = _height_(root->left_);
		int right_height = _height_(root->right_);

		int height = left_height > right_height ? ++left_height : ++right_height;
		return height;
	}

	// 获取两棵树的高度差
	unsigned int _heightDifference_(AVLNode* root_left, AVLNode* root_right)
	{
		int left_height = _height_(root_left);
		int right_height = _height_(root_right);

		return left_height - right_height;
	}

	// 前序遍历 AVL树
	void _preOrder_(AVLNode* root)
	{
		if (nullptr == root) return;

		cout << root->key_ << " ";
		_preOrder_(root->left_);
		_preOrder_(root->right_);
	}

	// 中序遍历 AVL树
	void _inOrder_(AVLNode* root)
	{
		if (nullptr == root) return;

		_inOrder_(root->left_);
		cout << root->key_ << " ";
		_inOrder_(root->right_);
	}

	// 后续遍历 AVL树
	void _postOrder_(AVLNode* root)
	{
		if (nullptr == root) return;

		_postOrder_(root->left_);
		_postOrder_(root->right_);
		cout << root->key_ << " ";
	}

	// 递归 - 查找输入的key 的节点 【改】
	AVLNode* _search_(AVLNode* root, const T& key_search)
	{
		if (nullptr == root || key_search == root->key_) return root;

		if (key_search < root->key_)
		{
			// 注意：这里 可以 加 return！！！！！！！！！！！！！！！！！！！！！！！！！！节省资源
			// _search_(root->left_, key_search);
			return _search_(root->left_, key_search);
		}
		else if (key_search > root->key_)
		{
			return _search_(root->right_, key_search);
		}
	}

	// 迭代 - 查找输入的key 的节点
	AVLNode* _iterativeSearch_(AVLNode* root, const T& key_search)
	{
		AVLNode* pCurrent = root;

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

	// 查找最小值
	AVLNode* _min_(AVLNode* root)
	{
		AVLNode* t_node = root;

		while (nullptr != t_node->left_)
		{
			t_node = t_node->left_;
		}

		return t_node;
	}

	// 查找最大值
	AVLNode* _max_(AVLNode* root)
	{
		AVLNode* t_node = root;

		while (nullptr != t_node->right_)
		{
			t_node = t_node->right_;
		}

		return  t_node;
	}



					/*
				==============LL===============
							  |
							 6 <---- p_parents_of_node_insert->p_
						   /  \
						  5   null  <<---- p_parents_of_node_insert
						 /
					   3	<----node_insert
				*/
	AVLNode* _LLRotation_(AVLNode* node);


					/*
				==============RR==============
							   |
							  9 <---- p_parents_of_node_insert->p_
						   /    \
						null   10     <---- p_parents_of_node_insert
								   \
									11	 <----node_insert
				*/
	AVLNode* _RRRotation_(AVLNode* node);


					/*
					==============LR===============
								  |
								 9 <---- p_parents_of_node_insert->p_
							   /  \
							  5   null  <<---- p_parents_of_node_insert
							   \
								6	 <----node_insert
					*/
	AVLNode* _LRRotation_(AVLNode* node);


					/*
				==============RL===============
							  |
							 6 <---- p_parents_of_node_insert->p_
						   /   \
					   null     8   <---- p_parents_of_node_insert
								 /
							   7	<----node_insert
				*/
	AVLNode* _RLRotation_(AVLNode* node);

	// 插入指定的节点到AVL树中
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

		// 先找到应该插入哪个节点之下
		AVLNode* pCurrent = root_;
		AVLNode* p_parents_of_node_insert = pCurrent; // 应插入到此节点之下
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
		// 只有一个主节点的时候
		if (nullptr == p_parents_of_node_insert->p_)
		{
			if (node_insert->key_ < p_parents_of_node_insert->key_)
			{
				p_parents_of_node_insert->left_ = node_insert;
				node_insert->p_ = p_parents_of_node_insert;
			}
			else
			{
				p_parents_of_node_insert->right_ = node_insert;
				node_insert->p_ = p_parents_of_node_insert;
			}
			return;
		}

		// 有多个节点，并且
		// 将 node 插入到 左子树 的情况
		if (node_insert->key_ < p_parents_of_node_insert->key_)
		{
			p_parents_of_node_insert->left_ = node_insert;
			node_insert->p_ = p_parents_of_node_insert;

			if (2 == _heightDifference_(p_parents_of_node_insert->p_->left_, p_parents_of_node_insert->p_->right_))
			{
				/*
				==============LL===============
				              |
							 6 <---- p_parents_of_node_insert->p_
						   /  \
						  5   null  <<---- p_parents_of_node_insert
						 /
					   3	<----node_insert			
				*/
				if (p_parents_of_node_insert == p_parents_of_node_insert->p_->left)
				{
					_LLRotation_(p_parents_of_node_insert->p);
				}

				/*
                ==============RL===============
                			  |
                			 6 <---- p_parents_of_node_insert->p_
                		   /   \
                	   null     8   <---- p_parents_of_node_insert
                	        	 /
                	           7	<----node_insert
                */
				else if (p_parents_of_node_insert == p_parents_of_node_insert->p_->right_)
				{
					_RLRotation_(p_parents_of_node_insert->p_);
				}
			}

		}

		// 将 node 插入到 右子树 的情况
		else if (node_insert->key_ > p_parents_of_node_insert->key_)
		{
			p_parents_of_node_insert->right_ = node_insert;
			node_insert->p_ = p_parents_of_node_insert;

			if (2 == _heightDifference_(p_parents_of_node_insert->p_->left, p_parents_of_node_insert->p_->right_))
			{
				/*
				==============LR===============
							  |
							 9 <---- p_parents_of_node_insert->p_
						   /  \
						  5   null  <<---- p_parents_of_node_insert
						   \
					        6	 <----node_insert
				*/
				if (p_parents_of_node_insert == p_parents_of_node_insert->p_->left_)
				{
					_LRRotation_(p_parents_of_node_insert->p_);
				}

				/*
				==============RR==============
							   |
							  9 <---- p_parents_of_node_insert->p_
						   /    \
						null   10     <---- p_parents_of_node_insert
						    	   \
						    		11	 <----node_insert
				*/
				else if (p_parents_of_node_insert = p_parents_of_node_insert->p_->right_)
				{
					_RRRotation_(p_parents_of_node_insert->p_);
				}
			}
		}

	}

	// 删除指定的节点到 AVL树中
	void _remove_(AVLNode* root, T key_remove);
};