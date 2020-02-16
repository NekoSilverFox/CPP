#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
using namespace std;

struct LinkNode
{
	/// friend bool operator>(const LinkNode& node1, const LinkNode& node2);
	int data;
	LinkNode* next;
	LinkNode() {}
	LinkNode& operator++();
	LinkNode operator++(int);
	LinkNode& operator+=(const LinkNode& t1);
	LinkNode(const LinkNode& ln); // ��������
	LinkNode(LinkNode&& p); // �ƶ�����
	// bool operator>(const LinkNode& node1, const LinkNode& node2) const;
};

class LinkList
{
	friend ostream& operator<<(ostream& cout, LinkNode pCurrent);
	
public:
	LinkList();
	LinkList(LinkList&& linklist);
	~LinkList();

public:
	LinkNode* header;
};


// ��ʼ������
LinkNode* Init_LinkList();

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
#endif
