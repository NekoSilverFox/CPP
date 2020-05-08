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

		_inOrder_(this->root_);
	}

	// �������� AVL��
	void postOrder()
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		_postOrder_(this->root_);
	}

	// �ݹ� - ���������key �Ľڵ�
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

	// ���� - ���������key �Ľڵ�
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

	// ������Сֵ
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

	// �������ֵ
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

	// ����ָ���Ľڵ㵽AVL����
	void insert(T key_insert)
	{
		if (nullptr == this->root_) throw MyErrorInfo("The root of the AVL Tree is nullptr!");

		cout << key_insert << " ";

		AVLNode* node_insert = new AVLNode(key_insert);

		_insert_(this->root_, node_insert);
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
		if (nullptr == root) return 0;

		int left_height = _height_(root->left_);
		int right_height = _height_(root->right_);

		int height = left_height > right_height ? ++left_height : ++right_height;
		return height;
	}

	// ��ȡ�������ĸ߶Ȳ�
	unsigned int _heightDifference_(AVLNode* root_left, AVLNode* root_right)
	{
		int left_height = _height_(root_left);
		int right_height = _height_(root_right);

		return left_height - right_height;
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
	AVLNode* _search_(AVLNode* root, const T& key_search)
	{
		if (nullptr == root || key_search == root->key_) return root;

		if (key_search < root->key_)
		{
			// ע�⣺���� ���� �� return������������������������������������������������������ʡ��Դ
			// _search_(root->left_, key_search);
			return _search_(root->left_, key_search);
		}
		else if (key_search > root->key_)
		{
			return _search_(root->right_, key_search);
		}
	}

	// ���� - ���������key �Ľڵ�
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

	// ������Сֵ
	AVLNode* _min_(AVLNode* root)
	{
		AVLNode* t_node = root;

		while (nullptr != t_node->left_)
		{
			t_node = t_node->left_;
		}

		return t_node;
	}

	// �������ֵ
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
				 6 <---- root																								5						
			   /  \																												  /	  \
			  5   null							                                     ==>							    3      6
			 /                                                   
		   3	                                                  
	*/
	AVLNode* _LLRotation_(AVLNode* root)
	{
		if (nullptr == root) throw MyErrorInfo("root is nullptr in _LLRotation_");

		AVLNode* t_root_right = root->left_;

		root->left_ = t_root_right->right_;
		t_root_right->right_->p_ = root;

		AVLNode* t_root_p = root->p_;
		root->p_ = t_root_right;
		t_root_right->p_ = t_root_p;

		t_root_right->right_ = root;



#if 0
		AVLNode* t_root = root;

		root->left_->right_ = root;
		root->left_->right_->left_ = nullptr;
		root->left_->right_->p_ = root->left_;
		root->left_->p_ = root->p_;

		t_root = root->left_;

		return t_root;
#endif

		//root->left_->right_ = root;
		//root->left_->p_ = root->p_;
		//root->left_ = root->left_;
		//root->left_ = nullptr;

		//t_root = root->p_;
	}

	/*
	=============================LR==============================
				  |																	|
				 9 <---- root							    				9 <---root
			   /  \																   / \
			  5   null                         ==>                        6                             ==>  _LLRotation_(root)
			   \																/
				6															   5
	*/
	AVLNode* _LRRotation_(AVLNode* root)
	{
		if (nullptr == root) throw MyErrorInfo("root is nullptr in _LRRotation_");

		AVLNode* t_root_left = root->left_;

		root->left_ = root->left_->right_;
		root->left_->left_ = t_root_left;
		root->left_->p_ = t_root_left->p_;
		t_root_left->p_ = root;
		t_root_left->right_ = nullptr;

		return _LLRotation_(root);

	}


	/*
	=============================RR=============================
				   |																	|
				  9 <---- root											  10
			   /    \															  /  \
			null   10							==>						9    11
					   \
						11		
	*/
	AVLNode* _RRRotation_(AVLNode* root) 
	{
		if (nullptr == root) throw MyErrorInfo("root is nullptr in _RRRotation_");

		AVLNode* t_root = root;

		root->right_->left_ = root;
		root->right_->left_->p_ = root->right_;
		root->right_->left_->left_ = nullptr;
		root->left_->p_ = root->p_;

		t_root = root->right_;

		return t_root;
	}

	/*
	=============================RL==============================
				  |														|
				 6 <---- root								   6
			   /   \												  / \
		   null     8							==>                  7                ==>   _RRRotation_(AVLNode* root) 
					 /													   \
				   7														8
	*/
	AVLNode* _RLRotation_(AVLNode* root)
	{
		if (nullptr == root) throw MyErrorInfo("root is nullptr in _RLRotation_");

		AVLNode* t_root_right = root->right_;

		root->right_ = root->right_->left_;
		root->right_->right_ = t_root_right;
		root->right_->p_ = root;
		t_root_right->p_ = t_root_right->left_;
		t_root_right->left_ = nullptr;

		return _RRRotation_(root);
	}

	// ����ָ���Ľڵ㵽AVL����
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

		// �� node ���뵽 ������ �����
		if (node_insert->key_ < root->key_)
		{
			root->left_ = _insert_(root->left_, node_insert);

			// ����ڵ�֮����AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
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
		// �� node ���뵽 ������ �����
		else if (node_insert->key_ > root->key_)
		{
			root->right_ = _insert_(root->right_, node_insert);

			// ����ڵ�֮����AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
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

		// ���ҵ�Ӧ�ò����ĸ��ڵ�֮��
		AVLNode* pCurrent = root_;
		AVLNode* p_parents_of_node_insert = pCurrent; // Ӧ���뵽�˽ڵ�֮��
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
		// ֻ��һ�����ڵ��ʱ��
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

		// �ж���ڵ㣬����
		// �� node ���뵽 ������ �����
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

		// �� node ���뵽 ������ �����
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

	// ɾ��ָ���Ľڵ㵽 AVL����
	void _remove_(AVLNode* root, T key_remove);
};