#pragma once
#include "MyErrorInfo.hpp"
#include <string>
#include <iostream>

template<typename T> class LinkNode;
template<typename T> class LinkList;
template<typename T> ostream& operator<<(ostream& cout,  LinkNode<T>& pCurrent);
template<typename T> bool operator>(const LinkNode<T>& node1, const LinkNode<T>& node2);

template<typename T>
ostream& operator<<(ostream& cout, LinkNode<T>& pCurrent)
{
	cout << pCurrent.data_;
	return cout;
}

template<typename T>
bool operator>(const LinkNode<T>& node1, const LinkNode<T>& node2)
{
	return node1.data_ > node2.data_;
}

template<typename T>
class LinkNode
{
	friend ostream& operator<<<T>(ostream& cout, LinkNode<T>& pCurrent); // !! Pay att-en <T>
	friend bool operator><T>(const LinkNode<T>& node1, const LinkNode<T>& node2);
	friend class LinkList<T>;
	friend class BinarySearchTree;
private:
	T data_;
	LinkNode* next_;
};

template<typename T>
class LinkList
{
	friend class BinarySearchTree;
public:
	LinkList()
	{
		header_ = new LinkNode<T>;
		header_->next_ = nullptr;
	}

	void insert(T data)
	{
		if (nullptr == header_) throw MyErrorInfo("null_header_in_function_insert()");

		// if is the first node
		if (nullptr == header_->next_)
		{
			LinkNode<T>* newNode = new LinkNode<T>;
			newNode->data_ = data;
			newNode->next_ = nullptr;
			header_->next_ = newNode;
			return;
		}

		LinkNode<T>* pCurrent = header_->next_;
		while (nullptr != pCurrent->next_)
		{
			pCurrent = pCurrent->next_;
		}

		LinkNode<T>* newNode = new LinkNode<T>;
		newNode->data_ = data;
		newNode->next_ = nullptr;
		pCurrent->next_ = newNode;
	}

	void foreach() const
	{
		if (nullptr == header_) throw MyErrorInfo("null_header_in_function_foreach()");

		LinkNode<T>* pCurrent = header_->next_;
		while (nullptr != pCurrent)
		{
			cout << *pCurrent;
			pCurrent = pCurrent->next_;
		}
		cout << endl;
	}

	void sort()
	{
		if (nullptr == header_ || nullptr == header_->next_) throw MyErrorInfo("null_header_in_function_sort()");

		// get the amount of node
		unsigned int count_node = 0;
		LinkNode<T>* pCurrent = header_->next_;
		while (nullptr != pCurrent)
		{
			count_node++;
			pCurrent = pCurrent->next_;
		}
		
		//-------------------------------------------------
		pCurrent = header_->next_;
		LinkNode<T>* pNext = pCurrent->next_;

		T temp;
		for (int i = 0; i < count_node; ++i)
		{
			for (int j = 0; j < count_node - i; ++j)
			{
				if (*pCurrent > * pNext)
				{
					temp = pCurrent->data_;
					pCurrent->data_ = pNext->data_;
					pNext->data_ = temp;
				}

				pCurrent = pNext;
				pNext = pNext->next_;

				if (nullptr == pNext)
				{
					pCurrent = header_->next_;
					pNext = pCurrent->next_;
				}

			}
		}
	}

	~LinkList()
	{
		if ( nullptr == header_ || nullptr == header_->next_)
		{
			delete header_;
			header_ = nullptr;
			return;
		}
		LinkNode<T>* pCurrent = header_;
		LinkNode<T>* pNext = header_->next_;

		while (nullptr != pNext && nullptr != pCurrent)
		{
			delete  pCurrent;
			pCurrent = nullptr;
			pCurrent = pNext;
			pNext = pNext->next_;
		}

		header_ = nullptr;
	}

private:
	LinkNode<T>* header_;
};