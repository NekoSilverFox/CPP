#pragma once
#include"Queue.h"
using namespace std;
//Exception
class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() :reason("Wrong Queue Size") { }
	const char* what() const { return reason; }
private:
	const char* reason;
};

//============================================
//  Template Class QueueArray - 
//	Elements set in array
//============================================

template<class T>
class QueueArray : public Queue<T>
{
public:
	QueueArray(int size = 100);
	QueueArray(const QueueArray<T>& src);
	~QueueArray();
	void enQueue(const T& e);
	T& deQueue();
	const T& front() const;
	bool isEmpty() const;
	bool isFull() const;
	void printInfo() const;
private:
	T* array_;
	int count;		//How many elements in queue
	int size_;		//Size of queue
};

template<class T>
bool QueueArray<T>::isEmpty() const
{
	return count == 0;
}

template<class T>
bool QueueArray<T>::isFull() const
{
	return count == size_;
}


template<class T>
QueueArray<T>::QueueArray(int size)
	:count(0)
{
	try
	{
		array_ = new T[size_ = size];
	}
	catch (const std::exception&)
	{
		throw WrongQueueSize();
	}
}

template<class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src)
	:count(src.count)
{
	try {
		array_ = new T[size_ = src.size_];
	}
	catch (const std::exception&) {
		throw WrongQueueSize();
	}
}


template<class T>
QueueArray<T>::~QueueArray()
{
	if (array_) {
		delete[] array_;
		array_ = nullptr;
	}
}

template<class T>
void QueueArray<T>::enQueue(const T& e)
{
	if (isFull())		//If queue is full
		throw QueueOverflow();
	else {
		array_[count++] = e;
	}
}

template<class T>
const T& QueueArray<T>::front() const
{
	return array_[0];
}


template<class T>
T& QueueArray<T>::deQueue()
{
	if (isEmpty()) {
		throw QueueUnderflow();
	}
	int i = 0;
	T ret = array_[0];
	count--;
	while (i++ < count) {
		array_[i - 1] = array_[i];
	}
	return ret;
}


template<class T>
void QueueArray<T>::printInfo() const
{
	cout << "In Queue: ";
	if (isEmpty()) {
		cout << "Empty.\n";
		return;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			cout << array_[i] << " ";
		}
		cout << "\n";
	}
}
