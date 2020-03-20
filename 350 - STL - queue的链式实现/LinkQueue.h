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
struct LinkQueue
{
	// ------------------------------ QueueNode ------------------------------
private:
	struct QueueNode
	{
		T data_;
		QueueNode* next_;
	};

public:
	LinkQueue()
	{
		this->header_ = new QueueNode;
		this->header_->data_ = NULL;
		this->header_->next_ = nullptr;
		this->rear_ = header_;
		this->size_ = 0;
		if (nullptr == this->header_) throw MyErrorInfo("bad_exception");
	}
	LinkQueue(const LinkQueue& queue)
	{
		if (nullptr == queue) throw MyErrorInfo("null_data");
		queue->header_ = this->header_;
		queue->rear_ = this->rear_;
		queue->size_ = this->size_;
	}

	// --------------------------- method functions---------------------------
public:
	void push(const T& data)
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		QueueNode* newNode = new QueueNode;
		newNode->data_ = data;
		newNode->next_ = nullptr;

		this->rear_->next_ = newNode;
		this->rear_ = newNode;
		this->size_++;
	}

	void pop()
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		if (0 == this->size_) throw MyErrorInfo("queue_not_data");

		if (1 == this->size_)
		{
			QueueNode* deleNode = this->header_->next_;
			this->header_->next_ = this->rear_;
			delete deleNode;
			deleNode = nullptr;
			this->size_--;
			return;
		}
		QueueNode* deleNode = this->header_->next_;
		this->header_->next_ = this->header_->next_->next_;
		delete deleNode;
		deleNode = nullptr;
		this->size_--;
	}

	T back() const
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		if (0 == this->size_) throw MyErrorInfo("queue_not_data");
		return this->rear_->data_;
	}

	T front() const
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		if (0 == this->size_) throw MyErrorInfo("queue_not_data");
		return this->header_->next_->data_;
	}

	bool empty() const
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		return this->size_;
	}

	int size() const
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		return this->size_;
	}

	void clear()
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		if (0 == this->size_) return;
		QueueNode* pCurrent = this->header_->next_;
		this->header_->next_ = nullptr;
		this->rear_ = this->header_;
		this->size_ = 0;

		while (pCurrent  != nullptr)
		{
			QueueNode* deleNode = pCurrent;
			pCurrent = pCurrent->next_;
			delete deleNode;
			deleNode = nullptr;
		}
	}

	void destroy()
	{
		if (nullptr == this->header_) throw MyErrorInfo("queue_is_nullptr");
		QueueNode* pCurrent = this->header;
		while (pCurrent != nullptr)
		{
			QueueNode* deleNode = pCurrent;
			pCurrent = pCurrent->next_;
			delete deleNode;
			deleNode = nullptr;
		}
		this->header_ = nullptr;
		this->rear_ = nullptr;
	}

private:
	QueueNode* header_;
	QueueNode* rear_;
	unsigned int size_;
};
