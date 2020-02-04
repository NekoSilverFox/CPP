#include"DoubleLinkList.h"

// 初始化Double链表
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

// 在 值为 oldval 后面插入一个新的数据 newval
void InSetByValue_LinkList(DouLinkNode* herder, int old_val, int new_val);

// 删除值为val的节点
void RemByValue_LinkList(DouLinkNode* header, int del_val);

// 遍历
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

// 销毁
void Destroy_LinkNode(DouLinkNode* header);

// 清空
void Clear_LinkList(DouLinkNode* header);

int main()
{
	DouLinkNode* header = Init_LinkList();
	ForEach_LinkList(header);
}