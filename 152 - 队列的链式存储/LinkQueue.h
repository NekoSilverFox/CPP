#pragma once
#include<iostream>
using namespace  std;
#ifndef LINKQUEUE	
#define LINKQUEUE

struct LinkNode
{
	LinkNode* next;
};

struct LinkQueue
{
	LinkNode* header;
	int size;
};

// 初始化 
LinkQueue* Init_LinkQueue();

// 入队
void Push_LinkQueue(LinkQueue* queue, LinkNode* data);

// 返回队头元素
LinkNode* Frount_LinkQueue(LinkQueue* queue);

// 出队
void Pop_LinkQueue(LinkQueue* queue);

// 返回队尾元素
LinkNode* Back_LinkQueue(LinkQueue* queue);

// 队列大小
int Size_LinkQueue(LinkQueue* queue);

// 队列是否为空
bool IsEmpty_LinkQueue(LinkQueue* queue);

// 清空队列
void Clear_LinkQueue(LinkQueue* queue);

// 销毁队列
void Desgroy_LinkQueue(LinkQueue* queue);

#endif