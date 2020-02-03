#include"linklist.h"
//LinkNode::LinkNode()
//{
//	 date = new Date; // !!!!!!!!!
//}


// 初始化链表
LinkNode* Init_LinkList()
{
	LinkNode* header = new LinkNode;
	header->date = NULL;
	header->next = nullptr;

	// printer - helper
	LinkNode* pRearCurrent = header;

	int val;

	while (true)
	{
		cout << "Please cin : "; cin >> val;
		if (val == 0)
		{
			if(pRearCurrent == nullptr)
				cerr << "You didn't cin date !" << endl;
			break;
		}

		LinkNode* newNode = new LinkNode;
		newNode->date = val;
		newNode->next = nullptr;

		pRearCurrent->next = newNode;
		pRearCurrent = newNode;
	}
	return header;
}

// 在 值为 oldval 后面插入一个新的数据 newval
void InSetByValue_LinkList(LinkNode* herder, int old_val, int new_val);

// 删除值为val的节点
void RemByValue_LinkList(LinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATE" << endl;
	}
	int del_val;
	cout << "Which date you want to remove :"; cin >> del_val;
	if (del_val == 0)
	{
		cerr << "Can't remove 0 !" << endl;
		return;
	}
	LinkNode* pFrount = header;
	LinkNode* pBehind = header->next;
	while (true)
	{
		if (pBehind != nullptr && pBehind->date == del_val)
		{
			cout << "Delete succful!" << endl;
			break;
		}
		if (pBehind == nullptr)
		{
			cerr << "Can't find the date" << endl;
			return;
		}
		pFrount = pBehind;
		pBehind = pBehind->next;
	}
	pFrount->next = pBehind->next;
	delete pBehind;
	pBehind = nullptr;
}

// 遍历
void ForEach_LinkList(LinkNode* header)
{
	LinkNode* pCurrent = header->next;

	if (header->next == nullptr)
	{
		cerr << "NO DATE" << endl;
	}

	while (pCurrent != nullptr)
	{
		cout << pCurrent->date << "   " << endl;
		pCurrent = pCurrent->next;
	}
}

// 销毁
void Destroy_LinkNode(LinkNode* header);

// 清空
void Clear_LinkList(LinkNode* header)
{
	if (header->next == nullptr)
	{
		cerr << "NO DATE " << endl;
		return;
	}

	LinkNode* pPear = header;
	LinkNode* pBehand = header->next;
	
}


int main()
{
	LinkNode* header = Init_LinkList();
	ForEach_LinkList(header);

	RemByValue_LinkList(header);
	ForEach_LinkList(header);

}