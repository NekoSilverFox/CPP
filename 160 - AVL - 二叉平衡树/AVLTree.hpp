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
		AVLNode() : p_(nullptr), height_(1), left_(nullptr), right_(nullptr) {}
		AVLNode(T key) : key_ (key), height_(1), p_(nullptr), left_(nullptr), right_(nullptr) {}

		T key_;
		unsigned int height_;
		AVLNode* p_;
		AVLNode* left_;
		AVLNode* right_;
	};

	AVLNode* root_;

public:

	AVLTree()
	{
		this->root_ = new AVLNode;
	}

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

		cout << key_insert << " ";

		AVLNode* node_insert = new AVLNode(key_insert);

		this->root_ = _insert_(this->root_, node_insert); // 注意这里 this->root 要重新复制，避免插入的前几个节点时造成节点丢失！！
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
	=============================LL==============================
				  |																													|
				 k2 <---- root																								k1
			   /  \																												  /	  \
			  k1   Z							                                     ==>							        X    k2
			 /  \                                                                                                                   /  \
		   X	  Y																												Y	 Z
	*/
	AVLNode* _LLRotation_(AVLNode* k2)
	{
		if (nullptr == k2) throw MyErrorInfo("root is nullptr in _LLRotation_");

		AVLNode* k1 = k2->left_;

		k2->left_ = k1->right_;

		if (nullptr != k1->right_)
		{
			k1->right_->p_ = k2;
		}

		k1->right_ = k2;

		if (nullptr != k2->left_)
		{
			k2->left_->p_ = k2;
		}

		k1->p_ = k2->p_;
		k2->p_ = k1;

		return k1; // 返回新的根结点
	}

	/*
	=============================LR==============================
				  |																	|
				 k3 <---- root							    				k3 <---root
			   /  \																   / \
			  k1  D                        ==>                          k2    D                         ==>  _LLRotation_(root)
			 / \																/ \
			A	k2															   k1  C
				/\																/\
			   B  C														  A   B
	*/
	AVLNode* _LRRotation_(AVLNode* k3)
	{
		if (nullptr == k3) throw MyErrorInfo("root is nullptr in _LRRotation_");

		k3->left_ = _RRRotation_(k3->left_);

		return _LLRotation_(k3);

	}


	/*
	=============================RR=============================
				   |																	|
				  k1 <---- root											  K2
			     /   \															  /  \
			   X     k2							==>						K1   Z
				   	 /\															/\
					Y	Z													  X  Y
	*/
	AVLNode* _RRRotation_(AVLNode* k1)
	{
		if (nullptr == k1) throw MyErrorInfo("root is nullptr in _RRRotation_");

		AVLNode* k2 = k1->right_;

		k1->right_ = k2->left_;

		if (nullptr != k2->left_)
		{
			k2->left_->p_ = k1;
		}

		k2->left_ = k1;

		if (nullptr != k1->right_)
		{
			k1->right_->p_ = k1;
		}

		k2->p_ = k1->p_;
		k1->p_ = k2;

		return k2; // 返回新的根结点
	}

	/*
	=============================RL==============================
				  |														|
				 k1 <---- root								   k1
			   /   \												  / \
		     A     k3							==>         A    k2                ==>   _RRRotation_(AVLNode* root)
					 /\													   /\
				   k2  D                                              B   k3
				   /\															/\
				 B   C													  C   D
	*/
	AVLNode* _RLRotation_(AVLNode* k1)
	{
		if (nullptr == k1) throw MyErrorInfo("root is nullptr in _RLRotation_");

		k1->right_ = _LLRotation_(k1->right_);

		return _RRRotation_(k1);
	}

	// 插入指定的节点到AVL树中
	AVLNode* _insert_(AVLNode* root, AVLNode* node_insert)
	{
		if (nullptr == node_insert) throw MyErrorInfo("node is nullptr in function _insert_!");

		// the first node
		static bool s_init = false;
		if (false == s_init)
		{
			s_init = true;
			// node_insert->height_ = 1;
			this->root_ = node_insert;
			return this->root_;
		}

		if (nullptr == root) return node_insert;

		// 将 node 插入到 左子树 的情况
		if (node_insert->key_ < root->key_)
		{
			root->left_ = _insert_(root->left_, node_insert);

			// 插入节点之后，若AVL树失去平衡，则进行相应的调节
			if (2 == _heightDifference_(root->left_, root->right_))
			{
				/*
				==============LL===============
							  |
							 6 <---- root
						   /  \
						  5   null  <<---- root->left_
						 /
					   3	<----node_insert (root->left_->left_)
				*/
				if (root->left_->left_ == node_insert) root = _LLRotation_(root);

				/*
				==============LR===============
							  |
							 9 <---- root
						   /  \
						  5   null  <<---- root->left_
						   \
							6	 <----node_insert (root->left_->left_)
				*/
				else if (root->left_->right_ == node_insert) root = _LRRotation_(root);
			}

		}
		// ==============================================================================
		// 将 node 插入到 右子树 的情况
		else if (node_insert->key_ > root->key_)
		{
			root->right_ = _insert_(root->right_, node_insert);

			// 插入节点之后，若AVL树失去平衡，则进行相应的调节
			if (2 == _heightDifference_(root->left_, root->right_))
			{
				/*
				==============RL===============
							  |
							 6 <---- root
						   /   \
					   null     8   <---- root->right_
								 /
							   7	<----node_insert (root->right_->left_)
				*/
				if (root->right_->left_ == node_insert) root = _RLRotation_(root);

				/*
				==============RR==============
							   |
							  9 <---- root
						   /    \
						null   10     <---- root->right_
								   \
									11	 <----node_insert (root->right_->right_)
				*/
				else if (root->right_->right_ == node_insert) root = _RRRotation_(root);
			}
		}
		else
		{
			cout << "The key " << node_insert->key_ << " already have!" << endl;
		}

		return root;

#if 0

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
#endif
	}

	// 删除指定的节点到 AVL树中
	void _remove_(AVLNode* root, T key_remove)
	{
		if (nullptr == root) return;

		// 待删除节点是根结点的左节点
		if (key_remove < root->key_)
		{
			root->left_ = _remove_(root->left_, key_remove);

			// 删除节点后若AVL树失去平衡，则进行相应的调节
			if (2 == _heightDifference_(root->left_, root->right_))
			{
				// 因为删除节点是root的左树，所以删除完毕后root右侧要高。所以要调整root->right_
				AVLNode* right_node = root->right_;

				if (_height_(right_node->left_) > _height_(right_node->right_)) root = _RLRotation_(root);
				else root = _RRRotation_(root);
			}
		}

		// 待删除节点是根结点的右节点
		else if (key_remove > root->key_)
		{
			root->right_ = _remove_(root->right_, key_remove);

			if (2 == _heightDifference_(root->left_, root->right_))
			{
				// 因为删除节点在root右侧，所以删除之后root左侧 要高 。要重新调整 root->left_;
				AVLNode* left_node = root->left_;

				if (_height_(left_node->left_) > _height_(left_node->right_)) root = _LLRotation_(root);
				else root = _LRRotation_(root);
			}
		}

		// root 为应删除的节点
		else
		{
			// 如果root的左右孩子都不为空
			if ((nullptr != root->left_) && (nullptr != root->right_))
			{
				if (_height_(root->left_) > _height_(root->right))
				{
					/* 如果删除节点的左树比右树高
					** 1. 找到root左树中最大的节点
					** 2. 将最大节点的值赋给 root （root的值被覆盖）
					** 3.  删除最大节点
					*/
					AVLNode* max_node = _max_(root->left_);

					root->key_ = max_node->key_;

					root->left_ = _remove_(root->left, max_node->key_);
#if 0
					// 不能直接这么删除，因为删除完树可能失去平衡
					delete max_node;
					max_node = nullptr;
#endif
				}
				else
				{
					/* 如果删除节点的右树比左树高
					** 1. 找到root右树中最小的节点
					** 2. 将最小节点的值赋给 root （root的值被覆盖）
					** 3.  删除最小节点
					*/
					AVLNode* min_node = _min_(root->right_);

					root->key_ = min_node->key_;

					root->right_ = _remove_(root->right_, min_node->key_);
				}

			}
			else
			{
				AVLNode* dele_node = root;

				if (nullptr != root->left_)	root->left_->p_ = root->p_;
				else root->right_->p_ = root->p_;

				delete dele_node;
				dele_node = nullptr;
			}
		}
		return root;
	}

};