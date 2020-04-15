#pragma once
#include<iostream>
using namespace std;


struct LinkNode
{
	friend LinkNode* operator|(const LinkNode& header1, const LinkNode& header2);
	friend LinkNode* operator&(const LinkNode& header1, const LinkNode& header2);
	friend ostream& operator<<(ostream& cout, LinkNode* pCurrent);
	bool operator==(const LinkNode& node) const;

	int data;
	LinkNode* next;
	LinkNode() {}
	LinkNode& operator++();
	LinkNode operator++(int);
	LinkNode& operator+=(const LinkNode& t1);

	LinkNode(const LinkNode& ln) // ��������
	{
		this->data = ln.data;
		this->next = ln.next;
	}

	LinkNode(LinkNode&& p)		// �ƶ�����
	{
		p.data = NULL;
		next = p.next;
		p.next = nullptr;
	}
};

class LinkList
{
	friend ostream& operator<<(ostream& cout, LinkNode* pCurrent);
	friend LinkNode* operator&(const LinkNode& header1, const LinkNode& header2);
public:
	LinkList()
	{
		header = new LinkNode;
		header->data = NULL;
		header->next = nullptr;
	}

	~LinkList()
	{
		if (header == nullptr || header->next == nullptr)
		{
			delete header;
			header = nullptr;
			return;
		}
		LinkNode* pCurrent = header;
		LinkNode* pNext = header->next;

		while (pNext != nullptr && pCurrent != nullptr)
		{
			delete  pCurrent;
			pCurrent = nullptr;
			pCurrent = pNext;
			pNext = pNext->next;
		}
		//delete pCurrent;
		//pCurrent = nullptr;
		//delete header; �Ѿ�ɾ���ˣ�ɾ���ڶ�������
		header = nullptr;
	}

public:
	LinkNode* header;
};


// ��ʼ������
LinkNode* Init_LinkList()
{
	LinkNode* header = new LinkNode;
	header->data = NULL;
	header->next = nullptr;
	LinkNode* pCurrent = header;
	int val;

	while (true)
	{
		cout << "Val = "; cin >> val;
		if (val == 0) break;

		LinkNode* newNode = new LinkNode;
		newNode->data = val;
		newNode->next = nullptr;

		pCurrent->next = newNode;
		pCurrent = newNode;
	}
	return header;
}

// ��������
void Foreach_LinkNode(LinkNode* header);

// ɾ���ڵ�
void DeleteNode_LinkNode(LinkNode* header);

// ��ս���
void Clearn_LinkNode(LinkNode* header);

// ����ڵ�
void Inset_LinkNode(LinkNode* header);

// merge�㷨
LinkNode* Merge_LinkNode(LinkNode* header1, LinkNode* header2);

// ð������
void Burrbe_LinkNode(LinkNode* header);

// ����ת
void TurnOff_LinkNode(LinkNode* header);

// �׽ڵ�ŵ�β��
void Shift_LinkNode(LinkNode* header);

// ɾ����Сֵ
void RemoveMinimal_LinkNode(LinkNode* header);

// ɾ���ظ�ֵ
void RemoveSame_LinkNode(LinkNode* header);

// ɾ����ֵ֪ǰ�������ֵ
void RemoveFrount_LinkNode(LinkNode* header);

// �ϲ�����
void Togeter_LinkNode(LinkNode* header1, LinkNode* header2);

// ������������ϲ�Ϊһ����������
void TogerterSince_LinkNode(LinkNode* header1, LinkNode* header2);

// �ڶ��������м�����һ�������е�Ԫ��
void SameElement_LinkNode(LinkNode* header1, LinkNode* header2);

