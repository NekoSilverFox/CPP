#pragma once
#include"Exception.h"
#include<iostream>


//============================================
//  Template Class Queue is abstructive queue
//============================================

template <class T>
class Queue
{
public:
	Queue()=default;
	virtual ~Queue() {};
	virtual void enQueue(const T& e) = 0;
	virtual T& deQueue() = 0;
	virtual bool isEmpty() const = 0; 
	virtual void printInfo() const = 0;
};
