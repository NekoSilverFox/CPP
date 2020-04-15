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

	LinkNode(const LinkNode& ln) // 拷贝构造
	{
		this->data = ln.data;
		this->next = ln.next;
	}

	LinkNode(LinkNode&& p)		// 移动构造
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
		//delete header; 已经删除了，删除第二遍会出错
		header = nullptr;
	}

public:
	LinkNode* header;
};


// 初始化链表
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

// 遍历链表
void Foreach_LinkNode(LinkNode* header);

// 删除节点
void DeleteNode_LinkNode(LinkNode* header);

// 清空建表
void Clearn_LinkNode(LinkNode* header);

// 插入节点
void Inset_LinkNode(LinkNode* header);

// merge算法
LinkNode* Merge_LinkNode(LinkNode* header1, LinkNode* header2);

// 冒泡排序
void Burrbe_LinkNode(LinkNode* header);

// 链表反转
void TurnOff_LinkNode(LinkNode* header);

// 首节点放到尾部
void Shift_LinkNode(LinkNode* header);

// 删除最小值
void RemoveMinimal_LinkNode(LinkNode* header);

// 删除重复值
void RemoveSame_LinkNode(LinkNode* header);

// 删除已知值前面的所有值
void RemoveFrount_LinkNode(LinkNode* header);

// 合并链表
void Togeter_LinkNode(LinkNode* header1, LinkNode* header2);

// 两个有序链表合并为一个有序链表
void TogerterSince_LinkNode(LinkNode* header1, LinkNode* header2);

// 第二个链表有几个第一个链表中的元素
void SameElement_LinkNode(LinkNode* header1, LinkNode* header2);

