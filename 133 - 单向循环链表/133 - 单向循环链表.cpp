#include <iostream>
#include <math.h>
using namespace std;

struct CycleLinkNode
{
	int data;
	CycleLinkNode* next;
};

CycleLinkNode* Init_CycleLinkList()
{
	CycleLinkNode* header = new CycleLinkNode;
	header->data = 0;
	header->next = header;

	int val;
	CycleLinkNode* pCurrent = header;

	while (true)
	{
		cout << "������ֵ��"; cin >> val;
		if (val == 0) break;

		CycleLinkNode* newNode = new CycleLinkNode;
		newNode->data = val;
		newNode->next = header;
		pCurrent->next = newNode;
		pCurrent = pCurrent->next;
	}
	return pCurrent;
}

void Foreach_CycleLinkNode(CycleLinkNode* rear)
{
	if (rear->next->next == rear)
	{
		cerr << "NO DATA" << endl;
		return;
	}

	CycleLinkNode* pCurrent = rear->next->next;

	while (pCurrent != rear->next)
	{
		cout << pCurrent->data << "    " << endl;
		pCurrent = pCurrent->next;
	}
}

CycleLinkNode* Merge_CycleLinkNode(CycleLinkNode* rear_list1, CycleLinkNode* rear_list2)
{
	if (rear_list1->next->next == rear_list1 || rear_list2->next->next == rear_list2)
	{
		cerr << "ERROR�����ڿ�����" << endl;
		return 0;
	}

	CycleLinkNode* pHelper = rear_list1->next;
	rear_list1->next = rear_list2->next->next;
	delete rear_list2->next;
	rear_list2->next = pHelper;

	cout << "�ϲ��ɹ�" << endl;
	CycleLinkNode* rear_list_new = rear_list2;
	return rear_list_new;
}

int main() {

	CycleLinkNode* rear = Init_CycleLinkList();
	Foreach_CycleLinkNode(rear);


	CycleLinkNode* rear2 = Init_CycleLinkList();
	Foreach_CycleLinkNode(rear2);

	CycleLinkNode* rear3 = Merge_CycleLinkNode(rear, rear2);
	Foreach_CycleLinkNode(rear3);

}