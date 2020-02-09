#include <iostream>
#include <math.h>
using namespace std;

struct LinkNode
{
	int data;
	LinkNode* next;
};

// 初始化链表
LinkNode* Init_LinkList()
{
	int val;
	LinkNode* header = new LinkNode;
	header->data = NULL;
	header->next = nullptr;

	LinkNode* pCurrent = header;

	while (true)
	{
		cout << "Val = "; cin >> val;
		if (val == 0) break;
		LinkNode* newNode = new LinkNode;
		newNode->data = val;
		newNode->next = nullptr;

		pCurrent->next = newNode;
		pCurrent = pCurrent->next;

	}
	return header;
}

// 遍历链表
void Foreach_LinkList(LinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATA" << endl;
		return;
	}

	LinkNode* pCurrent = header->next;

	while (pCurrent != nullptr)
	{
		cout << pCurrent->data << "    ";
		pCurrent = pCurrent->next;
	}
}

// 链表的反向遍历
void RevForeach_LinkList(LinkNode* header)
{
	if (header == nullptr) return;
	RevForeach_LinkList(header->next);
	cout << header->data << "    ";
}

// 链表反转
void Reverse_LinkList(LinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATA" << endl;
		return;
	}

	LinkNode* pPrev = nullptr;
	LinkNode* pCurrent = header->next;
	LinkNode* pNext = nullptr;

	while (pCurrent != nullptr)
	{
		pNext = pCurrent->next;
		pCurrent->next = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;

	}
	header->next = pPrev;

}




int main()
{
	LinkNode* header = Init_LinkList();
	Foreach_LinkList(header);

	RevForeach_LinkList(header->next);
	cout << endl;
	Reverse_LinkList(header);
	Foreach_LinkList(header);

}

