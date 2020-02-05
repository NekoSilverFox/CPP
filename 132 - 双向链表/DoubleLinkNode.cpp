#include"DoubleLinkList.h"

// ��ʼ��Double����
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

// �� ֵΪ oldval �������һ���µ����� newval
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

// ɾ��ֵΪval�Ľڵ�
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

				// ������һ���ڵ�Ϊɾ����ֵ����������쳣�����ԣ�����ж�Ϊ�����һ���ڵ㣬ֱ��ɾ���󷵻أ�����ָ��ָΪnullptr
				if (pDeleHelper == nullptr)
				{
					// ������pCurrent��ǰһ�ڵ����һ�ڵ���Ϊ�գ�Ȼ���ٽ���ɾ��������
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

// ����
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

// ����
void Destroy_LinkNode(DouLinkNode* header);

// ���
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