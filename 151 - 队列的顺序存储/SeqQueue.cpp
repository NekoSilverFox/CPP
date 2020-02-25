#include"SeqQueue.h"

// ��ʼ��
SeqQueue* Init_SeqQueue()
{
	SeqQueue* queue = new SeqQueue;
	for (int i = 0; i < MAX_SIZE; ++i) { queue->data[i] = nullptr; }
	queue->size = 0;
	return queue;
}

// ���
void Push_SeqQueue(SeqQueue* queue, void* data)
{
	if (queue == nullptr || data == nullptr || queue->size == MAX_SIZE) return;

	queue->data[queue->size] = data;
	queue->size++;
}

// ���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return nullptr;
	return queue->data[0];
}

// ����
void Pop_SeqQueue(SeqQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return;

	for (int i = 0; i < queue->size - 1; ++i)
	{
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;
}

// ���ض�βԪ��
void* Back_SeqQueue(SeqQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return nullptr;
	return queue->data[queue->size - 1];
}

// ���ش�С
int Size_SeqQueue(SeqQueue* queue)
{
	if (queue == nullptr ) return -1;
	return queue->size;
}

// ��ն���
void Clear_SeqQueue(SeqQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return;
	for (int i = 0; i < queue->size - 1; i++)
	{
		queue->data[i] = nullptr;
	}
	queue->size = 0;
}

// ����
void Desgroy_SeqQueue(SeqQueue* queue)
{
	if (queue == nullptr ) return;
	delete queue;
	queue = nullptr;
}