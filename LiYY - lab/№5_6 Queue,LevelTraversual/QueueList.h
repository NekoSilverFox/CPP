#pragma once
#include<iostream>
#include"Queue.h"
using namespace std;

//===========Exception===========
class QueueEmpty :public std::exception
{
public:
	QueueEmpty() :reason("Queue Empty") { }
	const char* what() const { return reason; }
private:
	const char* reason;
};


template<class T>
class QueueList:public Queue<T>
{
public:
	struct NodeQ {
		T val;
		NodeQ* next;
		NodeQ(const T& v) :val(v), next(NULL) { }
	};

	QueueList();
	~QueueList();
	void enQueue(const T& e);
	T& deQueue();
	bool isEmpty() const;
	void printInfo() const;


private:
	NodeQ* head;	//head element
	NodeQ* back;	//tail element
	int count;
};

template<class T>
QueueList<T>::QueueList()
	:head(NULL), back(nullptr), count(0)
{
}

template<class T>
QueueList<T>::~QueueList()
{
	delete head;
}


template<class T>
void QueueList<T>::enQueue(const T& e)
{
	if (isEmpty()) {
		head = back = new NodeQ(e);
	}
	else {
		back->next = new NodeQ(e);
		back = back->next;
	}
	count++;
}


template<class T>
T& QueueList<T>::deQueue() {
	T ret = head->val;
	if (isEmpty()) {
		cout << "Empty queue\n";
		throw QueueEmpty();
	}
	else {
		NodeQ* temp = head;
		head = head->next;
		delete temp;
	}
}



template<class T>
bool QueueList<T>::isEmpty() const{
	return count == 0;
}

template<class T>
void QueueList<T>::printInfo() const {
	NodeQ* p = head;
	cout << "In Queue:";
	if (!p)
	{
		cout << "Empty.\n";
	}
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
