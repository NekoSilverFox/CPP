#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include"LinkStack.h"
#include "LinkQueue.h"
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
		char user_choose;
		cout << "1 ~ recursion - 递归 - рекурсивно" << endl
			<< "2 ~ iteration - 迭代 - итеративно" << endl
			<< "\033[31m# ~ Exit insert\033[0m" << endl; 
		cout << ">>> ";  cin >> user_choose;
		switch (user_choose)
		{
		case '1':
			CreatTreeRECURSION();
			break;
		case '2':
			CreatTreeITERATION();
			break;
		case '#':
			return;
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
			<< "\033[31m# ~ Exit insert\033[0m" << endl;
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
			case '#':
				return;
			default:
				cerr << "!!! Unknown command !!!" << endl;
				break;
			}
		}
	}


	/******************************Foreach the Binary Search Tree******************************/
	void printTree() 
	{
		enum method	{DLR_recursion = 1, LDR_recursion, LRD_recursion, ALL_recursion, DLR_stack, lever_order_queue};
		int user_choose;

		cout << "1 ~ DLR (use recursion)" << endl
			<< "2 ~ LDR (use recursion)" << endl
			<< "3 ~ LRD (use recursion)" << endl
			<< "4 ~ ALL(1-3 use recursion)" << endl
			<< "5 ~ DLR (use Stack) " << "\033[32m<---lab 6(choose this one first)\033[0m" << endl
			<< "6 ~ Lever order (use Queue) " << "\033[32m<---lab 6\033[0m" <<endl;
		cout << "Please choose a foreach method >>> "; cin >> user_choose; cout << endl;

		switch (user_choose)
		{
		case DLR_recursion:
			Foreach_Tree_DLR(this->root_);
			break;

		case LDR_recursion:
			Foreach_Tree_LDR(this->root_);
			break;

		case LRD_recursion:
			Foreach_Tree_LRD(this->root_);
			break;

		case ALL_recursion:
			cout << "DLR : "; Foreach_Tree_DLR(this->root_); cout << endl;
			cout << "LDR : "; Foreach_Tree_LDR(this->root_); cout << endl;
			cout << "LRD : "; Foreach_Tree_LRD(this->root_); cout << endl;
			break;

		case DLR_stack:
			Foreach_Tree_ByStack(this->root_); //  <<<<<=========================LAB6==========================
			break;

		case lever_order_queue:
			printByLeverOrder();
			break;

		default:
			cerr << "----- Unknown command -----" << endl;
			cout << "1 ~ DLR (use recursion)" << endl
				<< "2 ~ LDR (use recursion)" << endl
				<< "3 ~ LRD (use recursion)" << endl
				<< "4 ~ ALL(1-3 use recursion)" << endl
				<< " 5 ~ DLR (use Stack)" << endl
				<< " 6 ~ Lever order (use Queue)" << endl;
			break;
		}
	}
	
	void printLDR()
	{
		Foreach_Tree_LDR(this->root_);
	}

	void printByLeverOrder()  //  <<<<<=========================LAB6==========================
	{
		Foreach_LeverOrder(this->root_);
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
	int getElementQuantity()
	{
		return CaculateElementQuantity(this->root_);
	}

	int getLeafQuantity()
	{
		return CaculateLeafQuantity(this->root_);
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
	
	double howSameTree(BinarySearchTree<T>& tree)
	{
		return SimilarityTwoTree(this->root_, tree.root_);
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

	void Foreach_Tree_ByStack(Node* root) //  <<<<<=========================LAB6==========================
	{
		if (nullptr == root)
		{
			cerr << "!!! Don't have any node !!!" << endl;
			return ;
		}
		// Make a Stack
		LinkStack<BinTreeStackNode*> stack;

		// 将根结点放到栈中 - first, make the root of the tree in the stack
		stack.push(CreatBinTreeStackNode(root, false));

		while (stack.size() > 0)
		{
			// 先弹出栈顶元素 - Pop the element, which is on the top of the stack
			BinTreeStackNode* node = (BinTreeStackNode*)stack.top();
			stack.pop();

			// 判断，如果为 nullptr 直接重新循环
			if (node->root == nullptr) continue;

			if (node->flag == true)
			{
				cout << node->root->key_ << " ";
			}
			else {
				// put the child of the node in the stack
				stack.push(CreatBinTreeStackNode(node->root->right_, false));
				stack.push(CreatBinTreeStackNode(node->root->left_, false));
				node->flag = true;
				stack.push(node);
			}
		}
		cout << endl;
	}

	void Foreach_LeverOrder(Node* root) //  <<<<<=========================LAB6==========================
	{
		if (nullptr == root) throw MyErrorInfo("null_tree");
		if (0 == val_static) return;

		LinkQueue<Node*>queue;
		Node* pCurrent = root;

		queue.push(pCurrent);
		while (queue.size() > 0)
		{
			pCurrent = queue.front();
			cout << "\033[32m" << pCurrent->key_  << "\033[0m" << " ";
			queue.pop();
			if (pCurrent->left_ != nullptr) queue.push(pCurrent->left_);
			if (pCurrent->right_ != nullptr) queue.push(pCurrent->right_);
		}
	}

	double SimilarityTwoTree(Node* root_1, Node* root_2)
	{
		if (nullptr == root_1 || nullptr == root_2) throw MyErrorInfo("null_tree");
		if (0 == val_static) return 0;

		double count_same_node = 0;
		LinkQueue<Node*>queue;
		Node* pCurrent = root_1;

		cout << "Same key : ";
		queue.push(pCurrent);
		while (queue.size() > 0)
		{
			pCurrent = queue.front();

			// Make a Stack
			LinkStack<BinTreeStackNode*> stack;

			// 将根结点放到栈中 - first, make the root of the tree in the stack
			stack.push(CreatBinTreeStackNode(root_2, false));

			while (stack.size() > 0)
			{
				// 先弹出栈顶元素 - Pop the element, which is on the top of the stack
				BinTreeStackNode* node = (BinTreeStackNode*)stack.top();
				stack.pop();

				// 判断，如果为 nullptr 直接重新循环
				if (node->root == nullptr) continue;

				if (node->flag == true)
				{
					if (pCurrent->key_ == node->root->key_)
					{
						count_same_node++;
						cout << "\033[32m" << pCurrent->key_ << "\033[0m" << " ";
					}
				}
				else {
					// put the child of the node in the stack
					stack.push(CreatBinTreeStackNode(node->root->right_, false));
					stack.push(CreatBinTreeStackNode(node->root->left_, false));
					node->flag = true;
					stack.push(node);
				}
			}

			queue.pop();
			if (pCurrent->left_ != nullptr) queue.push(pCurrent->left_);
			if (pCurrent->right_ != nullptr) queue.push(pCurrent->right_);
		}
		return count_same_node / CaculateElementQuantity(root_1);
	}

	/***************************************** Search *****************************************/
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
		LinkStack<BinTreeStackNode*> stack;
		Node* search_node = new Node;
		search_node = nullptr;

		// Make a pCurrent to know have or not element, which user cin
		Node* pBool = nullptr;

		// 将根结点放到栈中 - first, make the root of the tree in the stack
		stack.push(CreatBinTreeStackNode(root, false));

		while (stack.size() > 0)
		{
			// 先弹出栈顶元素 - Pop the element, which is on the top of the stack
			BinTreeStackNode* node = (BinTreeStackNode*)stack.top();
			stack.pop();

			// 判断，如果为 nullptr 直接重新循环
			if (node->root == nullptr) continue;

			if (node->flag == true)
			{
				if (search_key == node->root->key_)
				{
					cout << "\033[32m" << node->root->key_ << "\033[0m" << " ";
					pBool = node->root;
				}
				else
				{
					cout << node->root->key_ << " ";
				}
				search_node = node->root;
			}
			else {
				// put the child of the node in the stack
				stack.push(CreatBinTreeStackNode(node->root->right_, false));
				stack.push(CreatBinTreeStackNode(node->root->left_, false));
				node->flag = true;
				stack.push(node);
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
		LinkStack<BinTreeStackNode*> stack;

		// node need to search
		Node* search_node = new Node;
		search_node = nullptr;

		// 将根结点放到栈中 - first, make the root of the tree in the stack
		stack.push(CreatBinTreeStackNode(root, false));

		while (stack.size() > 0)
		{
			// 先弹出栈顶元素 - Pop the element, which is on the top of the stack
			BinTreeStackNode* node = (BinTreeStackNode*)stack.top();
			stack.pop();

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
				stack.push(CreatBinTreeStackNode(node->root->right_, false));
				stack.push(CreatBinTreeStackNode(node->root->left_, false));
				node->flag = true;
				stack.push(node);
			}
		}
		cout << endl;
		return nullptr;
	}


	/**************************Caculate XXXX of Binary Search Tree**************************/
	int CaculateElementQuantity(Node* root)
	{
		if (nullptr == root) return 0;
		static int element_num = 0;
		CaculateElementQuantity(root->left_); element_num++;
		CaculateElementQuantity(root->right_);
		return element_num;
	}

	int CaculateLeafQuantity(Node* root)
	{
		static int leaf_num = 0;
		if (nullptr == root) return 0;
		if (root->left_ == nullptr && root->right_ == nullptr) leaf_num++;
		CaculateLeafQuantity(root->left_); // number of the left leaf
		CaculateLeafQuantity(root->right_); // number of the right leaf
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