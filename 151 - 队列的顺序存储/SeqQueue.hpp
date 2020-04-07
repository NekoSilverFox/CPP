#pragma once
#include <iostream>
#include "myexception.h"

template<typename T>
class SeqQueue
{
public:

	SeqQueue() : size_(0), capacity_(512)
	{
		this->data_ = new T[capacity_];
	}

	SeqQueue(unsigned int capacity) : size_(0), capacity_(capacity)
	{
		this->data_ = new T[capacity_];
	}

	SeqQueue(unsigned int capacity, T data) : size_(0), capacity_(capacity)
	{
		this->data_ = new T[capacity_];
		for (int i = 0; i < capacity_; i++) data_[i] = data;
	}
	~SeqQueue()
	{
		if (nullptr == data_) return;
		delete[] data_;
		data_ = nullptr;
		size_ = 0;
		capacity_ = 0;
	}

	void push(T data)
	{
		if (nullptr == data_) return;

		// first, if size == capacity, need more space
		if (size_ == capacity_)
		{
			epand_capacity(16);
		}

		data_[size_] = data;
		size_++;
	}

	T front()
	{
		if (nullptr == data_ || 0 == this->size_) throw MyException("no_data");
		return data_[0];
	}

	T back()
	{
		if (nullptr == data_ || 0 == this->size_) throw MyException("no_data");
		return data_[size_ - 1];
	}


	void pop()
	{
		if (nullptr == data_ || 0 == this->size_) return;

		for (int i = 0; i < size_ - 1; ++i)
		{
			data_[i] = data_[i + 1];
		}
		size_--;
	}

	// epand space
	void epand_capacity(unsigned int capacity_plus)
	{
		if (0 == capacity_plus) return;

		T* new_array = new T[capacity_plus + this->capacity_];

		// Transfer the original data to the new space
		for (int i = 0; i < this->capacity_; i++) new_array[i] = this->data_[i];

		// Delete the original spatial data
		delete[] this->data_;

		// change pointer to new space
		this->data_ = new_array;
		this->capacity_ += capacity_plus;
	}

	void epand_capacity(unsigned int capacity_plus, T data_for_new_size)
	{
		if (0 == capacity_plus) return;

		T* new_array = new T[capacity_plus + this->capacity_];
		int i = 0;
		for (; i < this->capacity_; i++) new_array[i] = this->data_[i];
		for (; i < capacity_plus + this->capacity_; i++) new_array[i] = data_for_new_size;

		// Delete the original spatial data
		delete[] this->data_;

		// change pointer to new space
		this->data_ = new_array;
		this->capacity_ += capacity_plus;
	}

	void resize(unsigned int capacity_new)
	{
		if (0 == capacity_new) return;

		T* new_array = new T[capacity_new];
		for (int i = 0; i < this->capacity_; i++) new_array[i] = this->data_[i];

		// Delete the original spatial data
		delete[] this->data_;

		// change pointer to new space
		this->data_ = new_array;
		this->capacity_ = capacity_new;
	}

	void resize(unsigned int capacity_new, T data_new_size)
	{
		if (0 == capacity_new) return;

		T* new_array = new T[capacity_new];
		int i = 0;
		for (; i < this->capacity_; i++) new_array[i] = this->data_[i];
		for (; i < capacity_new; i++) new_array[i] = data_new_size;

		// Delete the original spatial data
		delete[] this->data_;

		// change pointer to new space
		this->data_ = new_array;
		this->capacity_ = capacity_new;
	}


	int size()
	{
		if (nullptr == data_) return -1;
		return size_;
	}

	int capacity()
	{
		if (nullptr == data_) return -1;
		return capacity_;
	}

	bool empty()
	{
		if (nullptr == data_) return false;
		return size_;
	}


	void clear()
	{
		if (nullptr == data_ || 0 == this->size_) return;

		for (int i = 0; i < capacity_; i++)
		{
			data_[i] = nullptr;
		}
		size_ = 0;
	}


private:
	T* data_;
	unsigned int size_;
	unsigned int capacity_;
};