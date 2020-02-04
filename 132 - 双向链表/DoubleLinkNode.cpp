#include"DoubleLinkList.h"

// ��ʼ��Double����
DouLinkNode* Init_LinkList()
{
	int val;
	DouLinkNode* header = new DouLinkNode;
	header->date = NULL;
	header->pre = nullptr;
	header->next = nullptr;

	// helper printer
	DouLinkNode* pCurrent = header;

	while (true)
	{
		cout << "Val = "; cin >> val;

		if (val == 0)
		{
			return header;
		}

		DouLinkNode* newNode = new DouLinkNode;
		newNode->date = val;
		newNode->pre = pCurrent;
		newNode->next = nullptr;

		pCurrent->next = newNode;

		pCurrent = newNode;


	}
	return header;
}

// �� ֵΪ oldval �������һ���µ����� newval
void InSetByValue_LinkList(DouLinkNode* herder, int old_val, int new_val);

// ɾ��ֵΪval�Ľڵ�
void RemByValue_LinkList(DouLinkNode* header, int del_val);

// ����
void ForEach_LinkList(DouLinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATE" << endl;
		return;
	}

	DouLinkNode* pCurrent = header->next;

	while (pCurrent != nullptr)
	{
		cout << pCurrent->date << "   ";
		pCurrent = pCurrent->next;
	}
}

// ����
void Destroy_LinkNode(DouLinkNode* header);

// ���
void Clear_LinkList(DouLinkNode* header);

int main()
{
	DouLinkNode* header = Init_LinkList();
	ForEach_LinkList(header);
}