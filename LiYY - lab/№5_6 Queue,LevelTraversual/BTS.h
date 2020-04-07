#pragma once
#include <iomanip>
#include <iostream>
#include"QueueArray.h"
#include<stack>
using namespace std;

template <class T>
class BSTNode {
public:
	T key;            
	BSTNode* left;   
	BSTNode* right;  
	BSTNode* parent;

	BSTNode(T value, BSTNode* p, BSTNode* l, BSTNode* r) :
		key(value), parent(), left(l), right(r) {}
};

template <class T>
class BSTree {
private:
	BSTNode<T>* mRoot;   
public:
	BSTree();
	~BSTree();

	void preOrder();
	void levelOrder();
	void insert(T key);

	//Get array of elem in the tree and sort the array
	T* getArrayOfElem() const;

	void destroy();

	//count
	const int getCount() const { return getCountSubTree(this->mRoot ); }

private:
	void preOrder(BSTNode<T>* tree) const;
	//PreOrder Using Stack
	void preOrderUsingStack(BSTNode<T>* tree) const;
	//Level Traval and mark
	void levelOrder(BSTNode<T>* tree) const;
	void insert(BSTNode<T>*& tree, BSTNode<T>* z);
	void destroy(BSTNode<T>*& tree);

	//number
	const int getCountSubTree(BSTNode<T>* node) const 
	{ if (node == nullptr)    return 0;   
		return (1 + getCountSubTree(node->left) + getCountSubTree(node->right)); 
	}
};

/*
 * 构造函数
 */

template <class T>
BSTree<T>::BSTree() :mRoot(NULL)
{
}

/*
 * 析构函数
 */
template <class T>
BSTree<T>::~BSTree()
{
	destroy();
}


template <class T>
void BSTree<T>::insert(BSTNode<T>*& tree, BSTNode<T>* z)
{
	BSTNode<T>* y = NULL;
	BSTNode<T>* x = tree;
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		tree = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

template <class T>
void BSTree<T>::insert(T key)
{
	BSTNode<T>* z = NULL;

	if ((z = new BSTNode<T>(key, NULL, NULL, NULL)) == NULL)
	{
		cout << "Insert not succeed.\n";
		return;
	}

	insert(mRoot, z);
}



/*
 * 前序遍历"二叉树"
 */
template <class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

/*
 * 用栈前序遍历"二叉树"
 */
template <class T>
void BSTree<T>::preOrderUsingStack(BSTNode<T>* tree) const
{
	stack<BSTNode<T>*> s;
	BSTNode<T>* p = tree;
	while (p || !s.empty())
	{
		if (p) {	//if node is not nullptr
			cout << p->key << " ";
			s.push(p);
			p = p->left;
		}
		else {	//if stack is not empty
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

template <class T>
void BSTree<T>::preOrder()
{
	cout << "\n**************** Recursive preTravel *********************\n";
	preOrder(mRoot);
	cout << "\n**************** Using stack to preTravel ****************\n";
	preOrderUsingStack(mRoot);
}



template <class T>
void BSTree<T>::levelOrder()
{
	levelOrder(mRoot);
}

template<class T>
void BSTree<T>::levelOrder(BSTNode<T>* tree) const
{
	cout << "\n************ Using QueueArray to Level Traversal:****************\n";
	QueueArray<BSTNode<T>*> q;
	if (!tree)
		return;
	q.enQueue(tree);
	int count = this->getCount();
	T* arr = new T[count];
	int i = 0;
	while (!q.isEmpty())
	{
		tree = q.front();
		q.deQueue();
		if (i < count)
		{
			arr[i] = tree->key;
			cout << "Number " << i << ":  " << arr[i] << "\n";
			i++;
		}
		if (tree->left)
			q.enQueue(tree->left);
		if (tree->right)
			q.enQueue(tree->right);
	}
	cout << "Total : " << i << endl;
}


/*
 * 销毁二叉树
 */
template <class T>
void BSTree<T>::destroy(BSTNode<T>*& tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}

template <class T>
void BSTree<T>::destroy()
{
	destroy(mRoot);
}


/*Get the Array Of Elements
* 1)Get the array
* 2)Sort the array
*
*/

template <class T>
T* BSTree<T>::getArrayOfElem() const
{
	T* arr = new T[this->getCount()];
	int counter = 0;
	stack<BSTNode<T>*> s;
	BSTNode<T>* p = mRoot;
	while (p || !s.empty())
	{
		if (p) {	//if node is not nullptr
			arr[counter++] = p->key;	//push elem into array
			s.push(p);
			p = p->left;
		}
		else {	//if stack is not empty
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	//bubble sort
	int i, j;
	T temp;
	for (i = 0; i < counter - 1; i++)
	{
		for (j = 0; j < counter - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr;
}
