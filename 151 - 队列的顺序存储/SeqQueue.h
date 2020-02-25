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

// ��ʼ��
SeqQueue* Init_SeqQueue();

// ���
void Push_SeqQueue(SeqQueue* queue, void* data);

// ���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue* queue);

// ����
void Pop_SeqQueue(SeqQueue* queue);

// ���ض�βԪ��
void* Back_SeqQueue(SeqQueue* queue);

// ���ش�С
int Size_SeqQueue(SeqQueue* queue);

// ��ն���
void Clear_SeqQueue(SeqQueue* queue);

// ����
void Desgroy_SeqQueue(SeqQueue* queue);

#endif