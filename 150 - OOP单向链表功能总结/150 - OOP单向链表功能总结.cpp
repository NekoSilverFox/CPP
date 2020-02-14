#include"LinkList.h"
LinkNode::LinkNode(const LinkNode& p) : data(p.data) {} // ��������
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

	while (pNext != nullptr)
	{
		delete  pCurrent;
		pCurrent = nullptr;
		pCurrent = pNext;
		pNext = pNext->next;
	}
	delete pCurrent;
	pCurrent = nullptr;
	//delete header; �Ѿ�ɾ���ˣ�ɾ���ڶ�������
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

// ����ǰ��++
LinkNode& LinkNode::operator++() // ǰ��++��������
{
	this->data++;
	return *this;
}

// ���ú���++
LinkNode LinkNode::operator++(int) // ����++����ֵ
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
void Inset_LinkNode(LinkNode* header);

// merge�㷨
void Merge_LinkNode(LinkNode* header);

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

	Burrbe_LinkNode(list1.header);
	Foreach_LinkNode(list1.header);
}

