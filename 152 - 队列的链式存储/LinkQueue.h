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

// ��ʼ�� 
LinkQueue* Init_LinkQueue();

// ���
void Push_LinkQueue(LinkQueue* queue, LinkNode* data);

// ���ض�ͷԪ��
LinkNode* Frount_LinkQueue(LinkQueue* queue);

// ����
void Pop_LinkQueue(LinkQueue* queue);

// ���ض�βԪ��
LinkNode* Back_LinkQueue(LinkQueue* queue);

// ���д�С
int Size_LinkQueue(LinkQueue* queue);

// �����Ƿ�Ϊ��
bool IsEmpty_LinkQueue(LinkQueue* queue);

// ��ն���
void Clear_LinkQueue(LinkQueue* queue);

// ���ٶ���
void Desgroy_LinkQueue(LinkQueue* queue);

#endif