#include <iostream>
#include <math.h>
using namespace std;

struct LinkNode
{
	int data;
	LinkNode* next;
};

// ��ʼ������
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

// ��������
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

// ����ķ������
void RevForeach_LinkList(LinkNode* header)
{
	if (header == nullptr) return;
	RevForeach_LinkList(header->next);
	cout << header->data << "    ";
}

// ����ת
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

