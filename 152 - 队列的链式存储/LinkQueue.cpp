#include"LinkQueue.h"

// 初始化 
LinkQueue* Init_LinkQueue()
{
	LinkQueue* queue = new LinkQueue;
	queue->header->next = nullptr;
	queue->size = 0;
	return queue;
}

// 入队
void Push_LinkQueue(LinkQueue* queue, LinkNode* data)
{
	if (queue == nullptr || data == nullptr) return;

	LinkNode* pCurrent = queue->header;
	LinkNode* pTemp = pCurrent;
	while (pCurrent != nullptr)
	{
		pTemp = pCurrent;
		pCurrent = pCurrent->next;
	}

	pTemp = data;

	queue->size++;
}

// 返回队头元素
LinkNode* Frount_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return nullptr;

	//LinkNode* pCurrent = queue->header;
	//LinkNode* pTemp = pCurrent;
	//while (pCurrent != nullptr)
	//{
	//	// if (pCurrent->next == nullptr) break;
	//	pTemp = pCurrent;
	//	pCurrent = pCurrent->next;
	//}
	//return pTemp;
	return queue->header->next;
}

// 出队
void Pop_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return;
	LinkNode* dele_temp = queue->header->next;
	queue->header->next = queue->header->next->next;
	delete dele_temp;
	dele_temp = nullptr;
	queue->size--;
}

// 返回队尾元素
LinkNode* Back_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return nullptr;
	LinkNode* pCurrent = queue->header;
	while (pCurrent->next != nullptr)
	{
		pCurrent = pCurrent->next;
	}
	return pCurrent;
}

// 队列大小
int Size_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr ) return -1;
	return queue->size;
}

// 队列是否为空
bool IsEmpty_LinkQueue(LinkQueue* queue)
{
	if (queue == nullptr || queue->size == 0) return true;
	return false;
}

// 清空队列
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

// 销毁队列
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

