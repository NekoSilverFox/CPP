#include"LinkList.h"
ostream& operator<<(ostream& cout, LinkNode* pCurrent)
{
	cout << pCurrent->data << "   ";
	return cout;
}
bool LinkNode::operator==(const LinkNode& node) const
{
	if (&node == nullptr) return true;
	return false;
}

bool operator>(const LinkNode& node1, const LinkNode& node2)
{
	return node1.data > node2.data;
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



LinkNode* operator&(const LinkNode& header1, const LinkNode& header2)
{
	if (&header1 == nullptr || &header2 == nullptr || header1.next == nullptr || header2.next == nullptr) return 0;

	LinkNode* pCurrent_1 = header1.next;
	LinkNode* pCurrent_2 = header2.next;

	LinkNode* newHeader = new LinkNode;  // �����½ڵ�
	newHeader->data = NULL;
	newHeader->next = nullptr;

	LinkNode* pCurrent_newHeader = newHeader; // ������� ��ʼ�� ����ָ��
	LinkNode* pCurrent_repetition = newHeader; // �����ڼ�� �����������Ԫ��ʱ ��û�� ��ͬ����
	bool for_repetition = false; // ���ڴ��Ƶڶ���ѭ��

	// ͨ����ð�����򣬽���ͬԪ�غϲ���һ���µ�����
	while (pCurrent_1 != nullptr)
	{
		while (pCurrent_2 != nullptr)
		{
			if (pCurrent_1->data == pCurrent_2->data)
			{
				// �����ж�Ԫ���Ƿ��ظ���������ظ���Ԫ�أ������PCurrent_1�����¿�ʼѭ�������⽫�ظ�Ԫ�ص���������newHeader��	
				while (pCurrent_repetition != nullptr)
				{
					if (pCurrent_repetition->data == pCurrent_1->data)
					{
						for_repetition = true;
						break;
					}
					pCurrent_repetition = pCurrent_repetition->next;
				}
				// ===============================================================

				if (for_repetition == true) break;

				LinkNode* newNodeForNewHeader = new LinkNode;
				newNodeForNewHeader->data = pCurrent_1->data;
				newNodeForNewHeader->next = nullptr;
				pCurrent_newHeader->next = newNodeForNewHeader;
				pCurrent_newHeader = pCurrent_newHeader->next;
				pCurrent_2 = pCurrent_2->next;
				break;
			}
			pCurrent_2 = pCurrent_2->next;
		}
		pCurrent_repetition = newHeader; // ���� - �����ж��ظ�Ԫ�صĸ���ָ��
		pCurrent_2 = header2.next; // ���� - pCurrent_2
		for_repetition = false;  // ���� - ����ѭ����while2��
		pCurrent_1 = pCurrent_1->next;
	}
	return newHeader;
}

LinkNode* operator|(const LinkNode& header1, const LinkNode& header2)
{
	if (&header1 == nullptr || &header2 == nullptr || header1.next == nullptr || header2.next == nullptr) return 0;

	LinkNode* pCurrent_1 = header1.next;
	LinkNode* pCurrent_2 = header2.next;

	LinkNode* newHeader = new LinkNode;  // �����½ڵ�
	newHeader->data = NULL;
	newHeader->next = nullptr;
	LinkNode* pCurrent_newList = newHeader;
	LinkNode* pCurrent_repetition = newHeader;
	bool for_repetition = false; // ���ڴ��Ƶڶ���ѭ��

	while (pCurrent_1 != nullptr)
	{
		while (pCurrent_repetition != nullptr)
		{
			if (pCurrent_1->data == pCurrent_repetition->data)
			{
				for_repetition = true;
				break;
			}
			pCurrent_repetition = pCurrent_repetition->next;
		}
		if (for_repetition == true)
		{
			pCurrent_repetition = newHeader;
			for_repetition = false;
			pCurrent_1 = pCurrent_1->next;
			continue;
		}

		LinkNode* newNode = new LinkNode;
		newNode->data = pCurrent_1->data;
		newNode->next = nullptr;
		pCurrent_newList->next = newNode;
		pCurrent_newList = pCurrent_newList->next;
		pCurrent_1 = pCurrent_1->next;

		pCurrent_repetition = newHeader;
		for_repetition = false;
	}

	while (pCurrent_2 != nullptr)
	{
		while (pCurrent_repetition != nullptr)
		{
			if (pCurrent_2->data == pCurrent_repetition->data)
			{
				for_repetition = true;
				break;
			}
			pCurrent_repetition = pCurrent_repetition->next;
		}
		if (for_repetition == true)
		{
			pCurrent_repetition = newHeader;
			for_repetition = false;
			pCurrent_2 = pCurrent_2->next;
			continue;
		}

		LinkNode* newNode = new LinkNode;
		newNode->data = pCurrent_2->data;
		newNode->next = nullptr;
		pCurrent_newList->next = newNode;
		pCurrent_newList = pCurrent_newList->next;
		pCurrent_2 = pCurrent_2->next;

		pCurrent_repetition = newHeader;
		for_repetition = false;
	}

	return newHeader;
}