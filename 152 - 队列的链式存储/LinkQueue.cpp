#include"LinkQueue.h"

// ��ʼ�� 
LinkQueue* Init_LinkQueue()
{
	LinkQueue* queue = new LinkQueue;
	queue->header->next = nullptr;
	queue->size = 0;
	return queue;
}

// ���
void Push_LinkQueue(LinkQueue* queue, LinkNode* data)
{
	if (queue == nullptr || data == nullptr) return;

	LinkNode* pCurrent = queue->header;

	while (pCurrent != nullptr)
	{
		pCurrent = pCurrent->next;
	}

	pCurrent->next = data;

	queue->size++;
}

// ���ض�ͷԪ��
LinkNode* Frount_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return nullptr;

	LinkNode* pCurrent = queue->header;

	while (true)
	{
		if (pCurrent->next == nullptr) break;
		pCurrent = pCurrent->next;
	}
	return pCurrent;
}

// ����
void Pop_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return;
	LinkNode* dele_temp = queue->header->next;
	queue->header->next = queue->header->next->next;
	delete dele_temp;
	dele_temp = nullptr;
	queue->size--;
}

// ���ض�βԪ��
LinkNode* Back_LinkQueue(LinkQueue* queue)
{
	
}

// ���д�С
int Size_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr ) return -1;
	return queue->size;
}

// �����Ƿ�Ϊ��
bool IsEmpty_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return true;
	return false;
}

// ��ն���
void Clear_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return;

	LinkNode* pCurrent = queue->header;
	LinkNode* pNext = queue->header->next;

	while (pNext != nullptr)
	{
		pCurrent = pNext;
		pNext = pNext->next;
		delete pCurrent;
		pCurrent = nullptr;
	}
}

// ���ٶ���
void Desgroy_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return;

	LinkNode* pCurrent = queue->header;
	LinkNode* pNext = queue->header->next;

	while (pNext != nullptr)
	{
		pCurrent = pNext;
		pNext = pNext->next;
		delete pCurrent;
		pCurrent = nullptr;
	}

	delete queue;
	queue = nullptr;
}