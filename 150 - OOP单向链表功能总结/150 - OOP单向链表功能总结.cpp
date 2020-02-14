#include"LinkList.h"
LinkNode::LinkNode(const LinkNode& p) : data(p.data) {} // 拷贝构造
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

	while (pNext != nullptr)
	{
		delete  pCurrent;
		pCurrent = nullptr;
		pCurrent = pNext;
		pNext = pNext->next;
	}
	delete pCurrent;
	pCurrent = nullptr;
	//delete header; 已经删除了，删除第二遍会出错
	header = nullptr;
}
// ============================================================================
ostream& operator<<(ostream& cout, LinkNode* pCurrent)
{
	cout << pCurrent->data << "     ";
	return cout;
}

bool operator>(const LinkNode& node1, const LinkNode& node2)
{
	return node1.data > node2.data;
	//if (node1.data > node2.data) return true;
	//else return false;
}

// 重置前置++
LinkNode& LinkNode::operator++() // 前置++返回引用
{
	this->data++;
	return *this;
}

// 重置后置++
LinkNode LinkNode::operator++(int) // 后置++返回值
{
	LinkNode temp = *this;
	this->data++;
	return temp;
}

LinkNode& LinkNode::operator+=(const LinkNode& node) {
	this->data += node.data;
	return *this;
}
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
	if (header->next == nullptr || header == nullptr)
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
void Inset_LinkNode(LinkNode* header);

// merge算法
void Merge_LinkNode(LinkNode* header);

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

	Burrbe_LinkNode(list1.header);
	Foreach_LinkNode(list1.header);
}

