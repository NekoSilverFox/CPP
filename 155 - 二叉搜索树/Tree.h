#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

/****************************************************************
							recursion - 递归 - рекурсивно
							iteration - 迭代 - итеративно
****************************************************************/

template<typename T>
class BinarySearchTree
{
	/**************************************Struct - Node**************************************/
private:
	struct Node
	{
		Node() {}
		Node(T key) : key_(key),val_(val_static), left_(nullptr), right_(nullptr), p_(nullptr) {}
		Node(T key, Node* left, Node* right, Node* p) : key_(key),val_(val_static), left_(left), right_(right), p_(p) {}

		T key_;
		unsigned int val_ ;
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
	static unsigned int val_static;

	// ===========================================Public==========================================
public:
	BinarySearchTree()
	{
		root_ = new Node;
		root_->key_ = NULL;
		root_->val_ = 0;
		root_->left_ = nullptr;
		root_->right_ = nullptr;
		root_->p_ = nullptr;
	}
	BinarySearchTree(T key)
	{
		root_ = new Node<T>(key);
	}
	BinarySearchTree(T key, Node* left, Node* right, Node* p)
	{
		root_ = new Node<T>(key, left, right, p);
	}

	/******************************Creat the Binary Search Tree******************************/
	void CreatTree()
	{
		int user_choose;
		cout << "1. recursion - 递归 - рекурсивно" << endl
			<< "2. iteration - 迭代 - итеративно" << endl;
		cout << ">>> ";  cin >> user_choose;
		switch (user_choose)
		{
		case 1:
			CreatTreeRECURSION();
			break;
		case 2:
			CreatTreeITERATION();
			break;
		default:
			cerr << "!!! Unknown command !!!" << endl;
			break;
		}
	}

	void CreatTreeRECURSION()
	{
		val_static = 0;
		T key_cin;
		cout << "Value = " << val_static << " | Key = "; cin >> key_cin;
		if (key_cin == '#') return;
		this->root_->key_ = key_cin;
		while (true)
		{
			++val_static;
			cout << "Value = " << val_static << " | Key = "; cin >> key_cin;
			if ('#' == key_cin)
			{
				--val_static;
				break;
			}
			CreatBinarySearchTreeRECURSION(this->root_, key_cin);
		}		
	}

	void CreatTreeITERATION()
	{
		val_static = 0;
		root_ = CreatBinarySearchTreeITERATION();
	}
	

	/*******************************Insert the Binary Search Tree*******************************/
	void insetNode()
	{
		char user_choose;
		cout << "1 - recursion - 递归 - рекурсивно" << endl
			<< "2 - iteration - 迭代 - итеративно" << endl
			<< "# - Exit" << endl;
		cout << ">>> "; cin >> user_choose;

		T key_cin;

		while (true)
		{
			++val_static;
			cout << "Value = " << val_static << " | Key = "; cin >> key_cin;
			if ('#' == key_cin)
			{
				--val_static;
				return;
			}

			switch (user_choose)
			{
			case '1':
				InsertNodeRECURSION(this->root_, key_cin);
				break;
			case '2':
				InsertNodeITERATION(this->root_, key_cin);
				break;
			default:
				cerr << "!!! Unknown command !!!" << endl;
				break;
			}
		}
	}

	/******************************Foreach the Binary Search Tree******************************/
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
	
	void iterableTree()
	{
		T first_key, sec_key, temp;
		cout << "---------- Scope of search  ----------" << endl;
		cout << "Key No.1 >>> "; cin >> first_key;
		cout << "Key No.2 >>> "; cin >> sec_key;
		cout << "----------------------------------------" << endl;
		
		if (first_key > sec_key)
		{
			temp = first_key;
			first_key = sec_key;
			sec_key = temp;
		}
		IterableBinarySearchTree(this->root_, first_key, sec_key);
		cout << endl;
	}

	/************************************Function Get XXXXX************************************/
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
	
	void searchBSTbyValue()
	{
		Node* searchNode = SearchByValue(this->root_);
		if (nullptr == searchNode)
		{
			cout << "Don't have node !" << endl;
		}
		else
		{
			cout << "Valul : " << searchNode->val_ << " | Key : " << searchNode->key_ << endl;
		}
	}

	/**************************************Other function**************************************/
	Node* copyTree() const 
	{
		return CopyBinaryTree(this->root_);
	}

	bool iterativeSearch()
	{
		T search_key;
		cout << "Which key need to search : "; cin >> search_key;
		return (IterativeSearchNode(this->root_, search_key) != nullptr);
	}

	void deleteNode()
	{
		int user_choose;
		cout << "1 - Delete MIN node" << endl
			<< "2 - Delete MAX node" << endl
		<< "3 - Delete other Node" << endl;
		cout << "Choose >>> "; cin >> user_choose;
		switch (user_choose)
		{
		case 1:
			DeleteMinBinarySearchTree(this->root_);
			break;
		case 2:
			DeleteMaxBinarySearchTree(this->root_);
			break;
		default:
			DeleteNodeBinarySearchTree(this->root_);
			break;
		}

	}

	void deleteTree()
	{
		FreeSpaceBinaryTree(this->root_);
	}
	

	// ===============================================Private===============================================
private:
	/******************************Creat the Binary Search Tree******************************/
	Node* CreatBinarySearchTreeRECURSION(Node* root, T key)
	{

		if (nullptr == root) return root;

		// If is the first Node
		if (0 == val_static)
		{
			root->key_ = key;
			root->val_ = val_static;
			root->left_ = nullptr;
			root->right_ = nullptr;
			return root;
		}

		//if (nullptr == root->left_ && (root->key_) > key)
		//{
		//	Node* newNode = new Node;
		//	newNode->left_ = nullptr;
		//	newNode->right_ = nullptr;
		//	newNode->key_ = key;
		//	newNode->val_ = ++val_static;
		//	root->left_ = newNode;
		//	//  ++val_static;
		//	// return root;
		//}
		//else if (nullptr == root->right_ && (root->key_) < key)
		//{
		//	//Node* newNode = new Node(key);
		//	Node* newNode = new Node;
		//	newNode->left_ = nullptr;
		//	newNode->right_ = nullptr;
		//	newNode->key_ = key;
		//	newNode->val_ = ++val_static;
		//	root->right_ = newNode;
		//	// ++val_static;
		//	//return root;
		//}
		//else
		//{
		//	throw 0;
		//}

		// if other Node
		if (root->key_ > key)
		{
			if (root->left_ != nullptr)	{ root = CreatBinarySearchTreeRECURSION(root->left_, key);}
			else
			{
				Node* newNode = new Node(key);
				root->left_ = newNode;
			}
		}
		else if (root->key_ < key)
		{
			if (root->right_ != nullptr) { root = CreatBinarySearchTreeRECURSION(root->right_, key); }
			else
			{
				Node* newNode = new Node(key);
				root->right_ = newNode;
			}
		}
		else if (root->key_ == key)
		{
			root->val_ = val_static;
			return root;
		}
	}

	Node* CreatBinarySearchTreeITERATION()
	{
		T key_cin;
		cout << "Value = " << val_static << " | Key = "; cin >> key_cin;
		if (key_cin == '#') return nullptr;

		root_->key_ = key_cin;
		root_->val_ = val_static;

		Node* pCurrent = root_;

		while (true)
		{
			++val_static;
			cout << "Value = " << val_static << " | Key = "; cin >> key_cin;
			if (key_cin == '#')
			{
				--val_static;
				break;
			}

			while (true)
			{
				while (pCurrent->key_ > key_cin && pCurrent->left_ != nullptr)
				{
					pCurrent = pCurrent->left_;
				}
				while (pCurrent->key_ < key_cin && pCurrent->right_ != nullptr)
				{
					pCurrent = pCurrent->right_;
				}

				if (pCurrent->key_ > key_cin && pCurrent->left_ == nullptr) break;
				else if (pCurrent->key_ < key_cin && pCurrent->right_ == nullptr) break;
				else if (pCurrent->key_ == key_cin) break;
			}

			if (pCurrent->key_ > key_cin)
			{
				Node* newNode = new Node(key_cin);
				pCurrent->left_ = newNode;
			}
			else if (pCurrent->key_ < key_cin)
			{
				Node* newNode = new Node(key_cin);
				pCurrent->right_ = newNode;
			}
			else
			{
				pCurrent->val_ = val_static;
			}
			pCurrent = root_; // !!!!!!!!!!!!!!
		}
		return root_;
	}


	/******************************Insert the Binary Search Tree******************************/
	void InsertNodeRECURSION(Node* root, T key_new)
	{
		if (0 == val_static) return;
		if (nullptr == root) return;

		if (root->key_ > key_new)
		{
			if (root->left_ != nullptr) { InsertNodeRECURSION(root->left_, key_new); }
			else
			{
				Node* newNode = new Node(key_new);
				root->left_ = newNode;
				return;
			}
		}
		else if (root->key_ < key_new)
		{
			if (root->right_ != nullptr) { InsertNodeRECURSION(root->right_, key_new); }
			else
			{
				Node* newNode = new Node(key_new);
				root->right_ = newNode;
				return;
			}
		}
		else
		{
			root->val_ = val_static;
			cout << "Have element " << key_new << " ! Change the value to " << val_static << " !" << endl;
		}
	}

	void InsertNodeITERATION(Node* root, T key_new)
	{
		if (nullptr == root || key_new == '#') return;
		
		Node* pCurrent = root;
		
		while (true)
		{
			while (pCurrent->key_ > key_new && pCurrent->left_ != nullptr)
			{
				pCurrent = pCurrent->left_;
			}
			while (pCurrent->key_ < key_new && pCurrent->right_ != nullptr)
			{
				pCurrent = pCurrent->right_;
			}

			if (pCurrent->key_ > key_new && pCurrent->left_ == nullptr) break;
			else if (pCurrent->key_ < key_new && pCurrent->right_ == nullptr) break;
			else if (pCurrent->key_ == key_new) break;
		}

		if (pCurrent->key_ > key_new)
		{
			Node* newNode = new Node(key_new);
			pCurrent->left_ = newNode;
		}
		else if (pCurrent->key_ < key_new)
		{
			Node* newNode = new Node(key_new);
			pCurrent->right_ = newNode;
		}
		else
		{
			cout << "Have element " << key_new << " ! Change the value to " << val_static << " !" << endl;
			pCurrent->val_ = val_static;
		}
	}


	/*****************************Foreach the Binary Search Tree*****************************/
	void Foreach_Tree_DLR(Node* root)
	{
		if (nullptr == root) return;

		cout << endl << root->val_ << " " << root->key_ << endl;
		// cout << root->key_ << " ";
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

	void IterableBinarySearchTree(Node* root, T key_1, T key_2)
	{
		if (nullptr == root) return; 
		IterableBinarySearchTree(root->left_, key_1, key_2);
		if (root->key_ >= key_1 && root->key_ <= key_2) { cout << root->key_ << " "; }
		IterableBinarySearchTree(root->right_, key_1, key_2);
	}

	Node* IterativeSearchNode(Node* root, T search_key)
	{
		if (nullptr == root)
		{
			cerr << "!!! Don't have any node !!!" << endl;
			return nullptr;
		}
		// Make a Stack
		LinkStack* stack = InIt_LinkStack();
		Node* search_node = new Node;
		search_node = nullptr;
		//int counter = 0;

		// Make a pCurrent to know have or not element, which user cin
		Node* pBool = nullptr;

		// 将根结点放到栈中 - first, make the root of the tree in the stack
		Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(root, false));

		while (Size_LinkStack(stack) > 0)
		{
			// 先弹出栈顶元素 - Pop the element, which is on the top of the stack
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
					pBool = node->root;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				else
				{
					cout << node->root->key_ << " ";
				}
				search_node = node->root;
			}
			else {
				// put the child of the node in the stack
				Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(node->root->right_, false));
				Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(node->root->left_, false));
				node->flag = true;
				Push_LinkStack(stack, (LinkNode*)node);
			}
		}
		cout << endl;
		return pBool;
	}

	Node* SearchByValue(Node* root)
	{
		if (nullptr == root) return nullptr;
		int num_search;
		cout << "Node number >>> "; cin >> num_search;

		if (nullptr == root)
		{
			cerr << "!!! Don't have any node !!!" << endl;
			return nullptr;
		}

		// Make a Stack
		LinkStack* stack = InIt_LinkStack();

		// node need to search
		Node* search_node = new Node;
		search_node = nullptr;

		// 将根结点放到栈中 - first, make the root of the tree in the stack
		Push_LinkStack(stack, (LinkNode*)CreatBinTreeStackNode(root, false));

		while (Size_LinkStack(stack) > 0)
		{
			// 先弹出栈顶元素 - Pop the element, which is on the top of the stack
			BinTreeStackNode* node = (BinTreeStackNode*)Top_LinkStack(stack);
			Pop_LinkStack(stack);

			// 判断，如果为 nullptr 直接重新循环
			if (node->root == nullptr) continue;

			if (node->flag == true)
			{
				if (num_search == node->root->val_)
				{
					return node->root;
				}
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
		return nullptr;
	}

	/**************************Caculate XXXX of Binary Search Tree**************************/
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
	
	// 创建栈中的结点 - Creat element in stack
	BinTreeStackNode* CreatBinTreeStackNode(Node* node, bool flag)
	{
		BinTreeStackNode* newNode = new BinTreeStackNode;
		newNode->root = node;
		newNode->flag = false;
		return newNode;
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

	/**************************************** Delete ****************************************/
	void DeleteMinBinarySearchTree(Node* root)
	{
		if (nullptr == root) return;

		/****************
					E
				   /
				 A
		****************/
		else if (root->right_ == nullptr && root->left_ != nullptr)
		{
			Node* delete_node = root;
			root = root->left_;
			delete delete_node;
			delete_node = nullptr;
		}
		

		/****************
						S
					  /
					E <-root
				  /
				 C <-delete
			   /
			  A
		*****************/
		else if (root->left_ != nullptr && root->left_->right_ == nullptr && root->left_->left_ != nullptr)
		{
			Node* delete_node = root;
			root->left_ = root->left_->left_;
			delete delete_node;
			delete_node = nullptr;
		}


		/****************
						S
					  /
					E <- root
				  /
				A <- delete
			  	  \
					C
		*****************/
		else if (root->left_ != nullptr && root->left_->left_ == nullptr && root->left_->right_ != nullptr)
		{
			Node* delete_node = root->left_;
			root->left_ = root->left_->right_;
			delete delete_node;
			delete_node = nullptr;
			return;
		}
		else DeleteMinBinarySearchTree(root->left_);
	}

	void DeleteMaxBinarySearchTree(Node* root)
	{
		if (nullptr == root) return;

		/**********************
			A
			  \
			    B
		**********************/
		else if (root->left_ == nullptr && root->right_ != nullptr)
		{
			Node* delete_node = root;
			root = root->right_;
			delete delete_node;
			delete_node = nullptr;
		}


		/**********************
			\
			  B <- root
			/   \
		   A	  E <--DELETE
				 /
			   C	 
		**********************/
		else if (root->right_ != nullptr && root->right_->left_ == nullptr && root->right_->right_ == nullptr)
		{
			Node* delete_node = root->right_;
			root->right_ = nullptr;
			delete delete_node;
			delete_node = nullptr;
		}


		/**********************
					E <- root
					 \
					   X <- DELETE
					  / 
					S
		**********************/
		else if (root->right_ != nullptr && root->right_->right_ == nullptr && root->right_->left_ != nullptr)
		{
			Node* delete_node = root->right_;
			root->right_ = root->right_->left_;
			delete delete_node;
			delete_node = nullptr;
		}
		else DeleteMaxBinarySearchTree(root->right_);
	}

	void DeleteNodeBinarySearchTree(Node* root)
	{
		if (nullptr == root) return;
		T dele_key;

		cout << "Which key need to delete :" << endl << ">>> "; cin >> dele_key;

		// First of all, need to find the node, which need to delete
		Node* pCurrent = root;
		Node* pParent = pCurrent;
		while (true)
		{
			if (pCurrent->key_ > dele_key)
			{
				pParent = pCurrent;
				pCurrent = pCurrent->left_;
			}
			else if (pCurrent->key_ < dele_key)
			{
				pParent = pCurrent;
				pCurrent = pCurrent->right_;
			}
			else if (pCurrent->key_ == dele_key)
			{
				break;
			}

			if (pCurrent == nullptr)
			{
				cout << "Don't have node, which key is " << dele_key << " !" << endl;
				return;
			}
		}

		cout << "pParent : " << pParent->key_ << endl;
		cout << "pCurrent : " << pCurrent->key_ << endl;

		// if delete node is the leaf
		if (pCurrent->left_ == nullptr && pCurrent->right_ == nullptr)
		{
			if (pParent->left_ == pCurrent)
			{
				pParent->left_ = nullptr;
			}
			else pParent->right_ = nullptr;

			delete pCurrent;
			pCurrent = nullptr;
			return;
		}

		/*********************
							 S  <-- pParent
						   /  \
		DELETE-> E      X
					  /   \
					A    null
				   /  \
				  *    *
		*********************/
		if (pCurrent->left_ != nullptr && pCurrent->right_ == nullptr && pCurrent == pParent->left_)
		{
			Node* deleNode = pCurrent;
			pParent->left_ = deleNode->right_;
			delete deleNode;
			deleNode = nullptr;
			return;
		}


		/*********************
							S  <-- pParent
						   /  \
		DELETE-> E      X
					  /   \
                  null    R  
				           /  \
				          *    *
		*********************/
		else if (pCurrent->left_ == nullptr && pCurrent->right_ != nullptr && pCurrent == pParent->left_)
		{
			Node* deleNode = pCurrent;
			pParent->left_ = pCurrent->right_;
			delete deleNode;
			deleNode = nullptr;
			return;
		}
		

		/*********************
							S  <-- pParent
						   /  \
		                 E      X <-DELETE
					           /  \
                              Q   null
		*********************/
		else if (pCurrent->left_ != nullptr && pCurrent->right_ == nullptr && pCurrent == pParent->right_)
		{
			Node* deleNode = pCurrent;
			pParent->right_ = deleNode->left_;
			delete deleNode;
			deleNode = nullptr;
		}


		/*********************
							S  <-- pParent
						   /  \
						 E      X <-DELETE
							   /  \
							null  Z
		*********************/
		else if (pCurrent->left_ == nullptr && pCurrent->right_ != nullptr && pCurrent == pParent->right_)
		{
			Node* deleNode = pCurrent;
			pParent->right_ = deleNode->right_;
			delete deleNode;
			deleNode = nullptr;
		}


		// 最复杂的情况 - The WORST situation  -  QAQ
		else if (pCurrent->left_ != nullptr && pCurrent->right_ != nullptr)
		{
			Node* deleNode = pCurrent;
			pCurrent = pCurrent->right_;

			/*********************
								S  <-- pParent
							   /  \
        	DELETE-> E      X
					   	  /   \
					   	A     R  <- pCurrent
			           /  \
					  *    *
			*********************/
			if (pCurrent->left_ == nullptr && pCurrent->right_ == nullptr)
			{
				deleNode->key_ = pCurrent->key_;
				deleNode->val_ = pCurrent->val_;
				deleNode->right_ = nullptr;

				delete pCurrent;
				pCurrent = nullptr;
				return;
			}


			/*********************
								S  <-- pParent
							   /  \
			DELETE-> E      X
						  /     \
						A        R <- pCurrent
					   /  \     /   \
					  *    *  H      *
					         /   \
     pParent --->  *      *  ( pParent after "while")
						 /
					   G <---- pCurrent  (之后的pCurrent - pCurrent after "while")
					 /   \
				  null   *
			*********************/
			if (pCurrent->left_ != nullptr)
			{
				while (pCurrent->left_ != nullptr)
				{
					pParent = pCurrent;
					pCurrent = pCurrent->left_;
				}
				
				deleNode->key_ = pCurrent->key_;
				deleNode->val_ = pCurrent->val_;
				pParent->left_ = pCurrent->right_;
				delete pCurrent;
				pCurrent = nullptr;
			 }
			return;
		}
	}

	void FreeSpaceBinaryTree(Node* root)
	{
		if (nullptr == root) return;
		FreeSpaceBinaryTree(root->left_);
		FreeSpaceBinaryTree(root->right_);
		delete root;
		val_static = 0;
	}

};
template <typename T>
unsigned int BinarySearchTree<T>::val_static = 0;
#endif