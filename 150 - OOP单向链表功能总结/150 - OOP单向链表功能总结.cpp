#include"LinkList.h"
LinkNode::LinkNode(const LinkNode& ln) // 拷贝构造
{
	this->data = ln.data;
	this->next = ln.next;
}
LinkNode::LinkNode(LinkNode&& p) : data(p.data) // 移动构造
{
	p.data = NULL;
	next = p.next;
	p.next = nullptr;
}


LinkList::LinkList()
{
	header = new LinkNode;
	header->data = NULL;
	header->next = nullptr;
}

LinkList::~LinkList()
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
// ============================================================================

// ============================================================================

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
void Foreach_LinkNode(LinkNode* header)
{
	if (header == nullptr || header->next == nullptr)
	{
		cerr << "!!!NO DATA!!!" << endl;
		return;
	}
	LinkNode* pCurrent = header->next;

	while (pCurrent != nullptr)
	{
		cout << pCurrent;
		pCurrent = pCurrent->next;
	}
	cout << endl;
}

// 删除节点
void DeleteNode_LinkNode(LinkNode* header)
{
	if (header->next == nullptr || header == nullptr)
	{
		cerr << "!!!NO DATA!!!" << endl;
		return;
	}
	LinkNode* pRear = header;
	LinkNode* pCurrent = header->next;
	int val;
	cout << "Delete val = "; cin >> val;
	
	while (pCurrent != nullptr)
	{
		if (pCurrent->data == val) break;
		pRear = pCurrent;
		pCurrent = pCurrent->next;
	}

	pRear->next = pCurrent->next;
	delete pCurrent;
	pCurrent = nullptr;
}

// 清空建表
void Clearn_LinkNode(LinkNode* header)
{
	if (header == nullptr || header->next == nullptr)
	{
		return;
	}

	LinkNode* pCurrent = header->next;
	LinkNode* pNext = pCurrent->next;

	while (pNext != nullptr)
	{
		delete  pCurrent;
		pCurrent = nullptr;
		pCurrent = pNext;
		pNext = pNext->next;
	}
	header->next = nullptr; // 勿忘！！！
}

// 插入节点
void Inset_LinkNode(LinkNode* header)
{
	if (header == nullptr || header->next == nullptr)
	{
		return;
	}

	int new_val, old_val; 
	cout << "New val = "; cin >> new_val;
	cout << "Old val = "; cin >> old_val;

	LinkNode* pRear = header;
	LinkNode* pCurrent = header->next;

	while (pCurrent != nullptr)
	{
		if (pCurrent->data == old_val) break;
		pRear = pCurrent;
		pCurrent = pCurrent->next;
	}
	LinkNode* newNode = new LinkNode;
	newNode->data = new_val;
	newNode->next = pCurrent;
	pRear->next = newNode;
}


// merge 算法
LinkNode* Merge_LinkNode(LinkNode* header1, LinkNode* header2)
{
	if (header1 == nullptr || header2 == nullptr || header1->next == nullptr || header2->next == nullptr) return nullptr;

	//LinkNode* pCurrent = header1->next;
	//LinkNode* firstNode_list_1 = header1->next;
	//LinkNode* lastNode_list_1 = nullptr;

	//while (pCurrent != nullptr)
	//{
	//	lastNode_list_1 = pCurrent;
	//	pCurrent = pCurrent->next;
	//}

	//pCurrent = header2->next;
	//LinkNode* firstNode_list_2 = header2->next;
	//LinkNode* lastNode_list_2 = nullptr;

	//while (pCurrent != nullptr)
	//{
	//	lastNode_list_2 = pCurrent;
	//	pCurrent = pCurrent->next;
	//}

	//cout << length_list_1 << "  " << length_list_2 << endl;
	//cout << firstNode_list_1 << "   " << lastNode_list_1 << endl;
	//cout << firstNode_list_2 << "   " << lastNode_list_2 << endl;

	LinkNode* newHeader = new LinkNode;
	newHeader->data = NULL;
	newHeader->next = nullptr;
	LinkNode* pCurrent_newList = newHeader;

	LinkNode* pCurrent_1 = header1->next;
	LinkNode* pCurrent_2 = header2->next;

	while (true)
	{
		if (pCurrent_1 == nullptr || pCurrent_2 == nullptr) break;
		if (pCurrent_1->data <= pCurrent_2->data)
		{
			LinkNode* newNode = new LinkNode;
			newNode->data = pCurrent_1->data;
			newNode->next = nullptr;
			pCurrent_newList->next = newNode;
			pCurrent_newList = newNode;
			pCurrent_1 = pCurrent_1->next;
		}
		if (pCurrent_1 == nullptr || pCurrent_2 == nullptr) break;
		if (pCurrent_1->data > pCurrent_2->data)
		{
			LinkNode* newNode = new LinkNode;
			newNode->data = pCurrent_2->data;
			newNode->next = nullptr;
			pCurrent_newList->next = newNode;
			pCurrent_newList = newNode;
			pCurrent_2 = pCurrent_2->next;
		}
	}

	if (pCurrent_2 == nullptr)
	{
		while (pCurrent_1 != nullptr)
		{
			LinkNode* newNode = new LinkNode;
			newNode->data = pCurrent_1->data;
			newNode->next = nullptr;
			pCurrent_newList->next = newNode;
			pCurrent_newList = pCurrent_newList->next;
			pCurrent_1 = pCurrent_1->next;

			//LinkNode* newNodeCopy = new LinkNode;
			//newNodeCopy = pCurrent_1;
			//pCurrent_newList->next = newNodeCopy;
			//pCurrent_newList = pCurrent_newList->next;
			//pCurrent_1 = pCurrent_1->next;
		}
		return newHeader;
		// pCurrent_newList->next = pCurrent_2;
	}
	if (pCurrent_1 == nullptr)
	{
		while (pCurrent_2 != nullptr)
		{
			LinkNode* newNode = new LinkNode;
			newNode->data = pCurrent_2->data;
			newNode->next = nullptr;
			pCurrent_newList->next = newNode;
			pCurrent_newList = pCurrent_newList->next;
			pCurrent_2 = pCurrent_2->next;

			//LinkNode* newNodeCopy = pCurrent_2;
			//pCurrent_newList->next = newNodeCopy;
			//pCurrent_newList = pCurrent_newList->next;
			//pCurrent_2 = pCurrent_2->next;
		}
		// pCurrent_newList->next = pCurrent_2;
	}
	return newHeader;
}

// 冒泡排序
void Burrbe_LinkNode(LinkNode* header)
{
	if (header->next == nullptr || header == nullptr)
	{
		cerr << "!!!NO DATA!!!" << endl;
		return;
	}
	int NodeSum = 0;
	LinkNode* pCurrent = header->next;
	while (pCurrent != nullptr)
	{
		NodeSum++;
		pCurrent = pCurrent->next;
	}
//	cout << NodeSum;
	//-------------------------------------------------
	pCurrent = header->next;
	LinkNode* pNext = pCurrent->next;
	int temp;

	for (int i = 0; i < NodeSum; ++i)
	{
		for (int j = 0; j < NodeSum - i; ++j)
		{
			if (pNext > pCurrent)
			{
				temp = pCurrent->data;
				pCurrent->data = pNext->data;
				pNext->data = temp;
			}
 			pCurrent = pNext;
			pNext = pNext->next;

			if (pNext == nullptr)
			{
				pCurrent = header->next;
				pNext = pCurrent->next;
			}
		}
	}
}

// 链表反转
void TurnOff_LinkNode(LinkNode* header)
{
	if (header->next == nullptr || header == nullptr)
	{
		cerr << "!!!NO DATA!!!" << endl;
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

// 首节点放到尾部
void Shift_LinkNode(LinkNode* header)
{
	if (header->next == nullptr || header == nullptr)
	{
		cerr << "!!!NO DATA!!!" << endl;
		return;
	}
	if (header->next->next == nullptr)
	{
		return;
	}
	LinkNode* firstNode = header->next;
	LinkNode* lastNode = header->next;

	while (lastNode->next != nullptr)
	{
		lastNode = lastNode->next;
	}
	header->next = header->next->next;
	lastNode->next = firstNode;
	firstNode->next = nullptr;
}


// 删除最小值
void RemoveMinimal_LinkNode(LinkNode* header);

// 删除重复值
void RemoveSame_LinkNode(LinkNode* header);

// 删除已知值前面的所有值
void RemoveFrount_LinkNode(LinkNode* header);

// 合并链表
void Togeter_LinkNode(LinkNode* header1, LinkNode* header2)
{
	if (header1 == nullptr || header2 == nullptr) return;
	
	LinkNode* pEndNode_List1 = header1;
	while (pEndNode_List1->next != nullptr)
	{
		pEndNode_List1 = pEndNode_List1->next;
	}

	pEndNode_List1->next = header2->next;
	header2 = header1;
}

// 两个有序链表合并为一个有序链表
void TogerterSince_LinkNode(LinkNode* header1, LinkNode* header2);

// 第二个链表有几个第一个链表中的元素
void SameElement_LinkNode(LinkNode* header1, LinkNode* header2);


int main()
{
	LinkList list1;
	list1.header = Init_LinkList();
	Foreach_LinkNode(list1.header);

	LinkList list2;
	list2.header = Init_LinkList();
	Foreach_LinkNode(list2.header);

	//Burrbe_LinkNode(list1.header);
	//Foreach_LinkNode(list1.header);

	//Inset_LinkNode(list1.header);
	//Foreach_LinkNode(list1.header);

	//LinkList list3;
	//list3.header = Merge_LinkNode(list1.header, list2.header);
	//Foreach_LinkNode(list3.header);

	cout << "Operator & : ";
	LinkList list4;
	list4.header = *(list1.header) & *(list2.header);
	Foreach_LinkNode(list4.header);

	cout << "Operator | : ";
	LinkList list5;
	list5.header = *(list1.header) | *(list2.header);
	Foreach_LinkNode(list5.header);

}

