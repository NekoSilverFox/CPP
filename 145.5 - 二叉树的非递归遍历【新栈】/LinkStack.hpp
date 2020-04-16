#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

// ------------------------------ ERROR INFO ------------------------------
class MyErrorInfo : public exception
{
public:
	MyErrorInfo(string errorInfo)
	{
		this->m_error = errorInfo;
	}
	~MyErrorInfo() {}

	virtual const char* what()
	{
		return this->m_error.c_str();
	}

private:
	string m_error;
};

template<typename T>
struct LinkStack
{
	// ------------------------------ QueueNode ------------------------------
private:
	struct StackNode
	{
		T data_;
		StackNode* next_;
	};

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

	// ѹջ
	void push(const T& data)
	{
		if (nullptr == this->header_) throw MyErrorInfo("data_nullptr");
		StackNode* newNode = new StackNode;
		newNode->next_ = this->header_->next_;
		newNode->data_ = data;
		this->header_->next_ = newNode;
		this->size_++;
	}

	// ����ջ��Ԫ��
	T top() const
	{
		if (nullptr == this->header_ || 0 == this->size_) throw MyErrorInfo("null_stack");
		return this->header_->next_->data_;
	}

	// ����Ԫ�ظ���
	int size() const
	{
		if (nullptr == this->header_ || 0 == this->size_) return 0;
		return this->size_;
	}

	// �ж��Ƿ�Ϊ��
	bool empty() const
	{
		return this->size_;
	}

	// ��ջ
	void pop()
	{
		if (nullptr == this->header_ || 0 == this->size_) return;
		StackNode* deleNode = this->header_->next_;
		this->header_->next_ = this->header_->next_->next_;
		delete deleNode;
		deleNode = nullptr;
		this->size_--;
	}

	// ���ջ
	void clear()
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

	// ����ջ
	void desgroy()
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

private:
	StackNode* header_;
	unsigned int size_;
};