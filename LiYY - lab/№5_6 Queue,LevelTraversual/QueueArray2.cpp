#include"QueueArray2.h"

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
const T& QueueArray<T>::deQueue()
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
	if (isEmpty()) {
		cout << "Empty Queue.\n";
		return;
	}
	else {
		cout << "In Queue: ";
		for (int i = 0; i < count; i++)
		{
			cout << array_[i] << " ";
		}
		cout << "\n";
	}
}
