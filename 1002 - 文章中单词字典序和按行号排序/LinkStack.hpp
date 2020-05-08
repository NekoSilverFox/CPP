#pragma once
#include "MyErrorInfo.hpp"
#include <string>
using namespace std;

template<typename T>
struct LinkStack
{
	// ------------------------------ StackNode ------------------------------
private:
	struct StackNode
	{
		T data_;
		StackNode* next_;
	};

	StackNode* header_;
	unsigned int size_;

public:
	LinkStack()
	{
		this->header_ = new StackNode;
		this->header_->data_ = NULL;
		this->header_->next_ = nullptr;
		this->size_ = 0;
		if (nullptr == this->header_) throw MyErrorInfo("bad_exception");

	}

	LinkStack(const LinkStack& stack)
	{
		if (nullptr == stack) throw MyErrorInfo("null_data");
		stack->header_ = this->header_;
		stack->size_ = this->size_;
	}

	void push(const T& data)
	{
		_push_(data);
	}
	
	T top() const
	{
		return _top_();
	}

	int size() const
	{
		return _size_();
	}
	
	bool empty() const
	{
		return _empty_();
	}
	
	void pop()
	{
		_pop_();
	}

	void clear() const
	{
		_clear_();
	}
	
	void desgroy() const
	{
		_desgroy_();
	}

private:

	void _push_(const T& data)
	{
		if (nullptr == this->header_) throw MyErrorInfo("data_nullptr");
		StackNode* newNode = new StackNode;
		newNode->next_ = this->header_->next_;
		newNode->data_ = data;
		this->header_->next_ = newNode;
		this->size_++;
	}

	T _top_() const
	{
		if (nullptr == this->header_ || 0 == this->size_) throw MyErrorInfo("null_stack");
		return this->header_->next_->data_;
	}

	int _size_() const
	{
		if (nullptr == this->header_ || 0 == this->size_) return 0;
		return this->size_;
	}

	bool _empty_() const
	{
		return this->size_;
	}

	void _pop_()
	{
		if (nullptr == this->header_ || 0 == this->size_) return;
		StackNode* deleNode = this->header_->next_;
		this->header_->next_ = this->header_->next_->next_;
		delete deleNode;
		deleNode = nullptr;
		this->size_--;
	}

	void _clear_()
	{
		if (nullptr == this->header_ || 0 == this->size_) return;
		StackNode* pCurrent = this->header_->next_->next_;
		StackNode* pRear = this->header_->next_;

		while (pCurrent != nullptr)
		{
			delete pRear;
			pRear = nullptr;
			pRear = pCurrent;
			pCurrent = pCurrent->next_;
		}
		delete pRear;
		pRear = nullptr;
	}

	void _desgroy_()
	{
		if (nullptr == this->header_) return;
		StackNode* pCurrent = this->header_->next_;
		StackNode* pRear = this->header_;

		while (pCurrent != nullptr)
		{
			delete pRear;
			pRear = nullptr;
			pRear = pCurrent;
			pCurrent = pCurrent->next_;
		}
		delete pRear;
		pRear = nullptr;
	}

};