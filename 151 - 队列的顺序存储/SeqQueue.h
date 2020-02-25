#pragma once
#include<iostream>
using namespace std;

#ifndef SEQQUEUE
#define SEQQUEUE

const int MAX_SIZE = 1024;

struct SeqQueue
{
	void* data[MAX_SIZE];
	unsigned int size;
};

// 初始化
SeqQueue* Init_SeqQueue();

// 入队
void Push_SeqQueue(SeqQueue* queue, void* data);

// 返回对头元素
void* Front_SeqQueue(SeqQueue* queue);

// 出队
void Pop_SeqQueue(SeqQueue* queue);

// 返回队尾元素
void* Back_SeqQueue(SeqQueue* queue);

// 返回大小
int Size_SeqQueue(SeqQueue* queue);

// 清空队列
void Clear_SeqQueue(SeqQueue* queue);

// 销毁
void Desgroy_SeqQueue(SeqQueue* queue);

#endif