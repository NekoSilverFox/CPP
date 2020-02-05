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
		DouLinkNode::lenth++;
		newNode->date = val;
		newNode->pre = pCurrent;
		newNode->next = nullptr;

		pCurrent->next = newNode;

		pCurrent = newNode;
	}
	return header;
}

// 在 值为 oldval 后面插入一个新的数据 newval
void InSetByValue_LinkList(DouLinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATE" << endl;
		return;
	}
	int old_val, new_val;
	cout << "Old val = "; cin >> old_val;
	cout << "New val = "; cin >> new_val;

	DouLinkNode* pCurrent = header->next;

	while (true)
	{
		if (pCurrent == nullptr) break;
		if (pCurrent->date == old_val)
		{
			DouLinkNode* newNode = new DouLinkNode;
			newNode->date = new_val;
			newNode->pre = pCurrent->pre;
			newNode->next = pCurrent;
			pCurrent->pre->next = newNode;
			pCurrent->pre = newNode;
		}
		pCurrent = pCurrent->next;
	}
}

// 删除值为val的节点
void RemByValue_LinkList(DouLinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATE" << endl;
		return;
	}

	DouLinkNode* pCurrent = header->next;
	DouLinkNode* pDeleHelper;
	int del_val;
	while (true)
	{
		cout << "Delete val = "; cin >> del_val;
		if (del_val == 0)
		{
			cerr << "Can't delete 0 !" << endl;
			continue;
		}
		while (pCurrent != nullptr)
		{
			if (pCurrent->date == del_val)
			{
				cout << "Succful delete!" << endl;
				pDeleHelper = pCurrent->next;

				// 如果最后一个节点为删除的值，则会引发异常，所以，如果判断为了最后一个节点，直接删除后返回，并将指针指为nullptr
				if (pDeleHelper == nullptr)
				{
					// 勿忘将pCurrent的前一节点的下一节点置为空，然后再进行删除操作！
					pCurrent->pre->next = nullptr;
					// =========================================

					delete pCurrent;
					DouLinkNode::lenth--;
					pCurrent = nullptr;
					return;
				}
				// ===========================================================================
				pCurrent->pre->next = pCurrent->next;
				pCurrent->next->pre = pCurrent->pre;
				delete pCurrent;
				DouLinkNode::lenth--;
				pCurrent = pDeleHelper;
				continue;
			}
			pCurrent = pCurrent->next;
		}
		cout << "Delete has done!" << endl;
		return;
	}
}

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
void Clear_LinkList(DouLinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATE" << endl;
		return;
	}
	DouLinkNode* pCurrent = header->next;

	while (true)
	{
		if (pCurrent->next == nullptr)
		{
			delete pCurrent;
			pCurrent = nullptr;
			break;
		}
		pCurrent = pCurrent->next;
		delete pCurrent->pre;
		pCurrent->pre = nullptr;
	}
	header->next = nullptr;
	DouLinkNode::lenth = 0;
}

int main()
{
	DouLinkNode* header = Init_LinkList();
	ForEach_LinkList(header);

	RemByValue_LinkList(header);
	ForEach_LinkList(header);

	InSetByValue_LinkList(header);
	ForEach_LinkList(header);

	Clear_LinkList(header);
	ForEach_LinkList(header);


}