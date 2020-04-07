#pragma once
#include<exception>

//=========class QueueOverflow and QueueUnderflow ======================

class QueueOverflow:public std::exception
{
public:
	QueueOverflow():reason("Queue Overflow"){ }
	const char* what() const { return reason; }
private:
	const char* reason;
};



class QueueUnderflow :public std::exception
{
public:
	QueueUnderflow() :reason("Queue Underflow") { }
	const char* what() const { return reason; }
private:
	const char* reason;
};