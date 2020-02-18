#include"LinkList.h"
LinkNode::LinkNode(const LinkNode& ln) // ��������
{
	this->data = ln.data;
	this->next = ln.next;
}
LinkNode::LinkNode(LinkNode&& p) : data(p.data) // �ƶ�����
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
	//delete header; �Ѿ�ɾ���ˣ�ɾ���ڶ�������
	header = nullptr;
}
// ============================================================================

// ============================================================================

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

// ɾ���ڵ�
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

// ��ս���
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
	header->next = nullptr; // ����������
}

// ����ڵ�
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


// merge �㷨
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

// ð������
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

// ����ת
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

// �׽ڵ�ŵ�β��
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


// ɾ����Сֵ
void RemoveMinimal_LinkNode(LinkNode* header);

// ɾ���ظ�ֵ
void RemoveSame_LinkNode(LinkNode* header);

// ɾ����ֵ֪ǰ�������ֵ
void RemoveFrount_LinkNode(LinkNode* header);

// �ϲ�����
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

// ������������ϲ�Ϊһ����������
void TogerterSince_LinkNode(LinkNode* header1, LinkNode* header2);

// �ڶ��������м�����һ�������е�Ԫ��
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

