//#include"LinkList.h"
//
//void test02()
//{
//	LinkNode* t;
//	t = Init_LinkList();
//	ForEach_LinkList(t);
//}
//
//// ��ʼ������
//LinkNode* Init_LinkList()
//{
//	// Make the headerNode
//	LinkNode* header = (LinkNode*)malloc(sizeof(LinkNode));
//	header->data = NULL;
//	header->next = NULL;
//
//	// ������ʱRearָ��
//	//LinkNode* pRearCurrut = (LinkNode*)malloc(sizeof(LinkNode));
//	LinkNode* pRearCurrut;
//	pRearCurrut = header;
//	int val = NULL;
//
//	while (true)
//	{
//
//		cout << "���������ݣ�"; cin >> val;
//
//		if (val == -1)
//		{
//			break; // break ���� while ѭ��
//		}
//
//		
//		// Make the new Node
//		LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
//		newNode->data = val;
//		newNode->next = NULL;
//
//		// �� ��ʱָ��ָ����һ�����µĽڵ㣩���ڵ�Ƕ������Ҳ���ǽ��µĽڵ���뵽���һ���ڵ����һ��λ�ã�
//		pRearCurrut->next = newNode; // 1
//
//		// ���¸���ָ��
//		pRearCurrut = newNode; // 2
//
//		// ������������Ҫ�� 1�� 1 ��Ŀ���ǽ��ڵ��໥���ӣ����ֻд 2 ��д 1����ô���ڵ�֮���޷����ӣ�
//	}
//
//	return header;
//}
//
//// �� ֵΪ oldval �������һ���µ����� newval
//void InSetByValue_LinkList(LinkNode* herder, int old_val, int new_val);
//
//// ɾ��ֵΪval�Ľڵ�
//void RemByValue_LinkList(LinkNode* header, int del_val);
//
//// ����
//void ForEach_LinkList(LinkNode* header)
//{
//	if (header == NULL)
//	{
//		return;
//	}
//
//	// ����ָ�����
//	LinkNode* pCurrut = header->next;
//
//	while (pCurrut != NULL)
//	{
//		cout << pCurrut->data << endl;
//		pCurrut = pCurrut->next;
//	}
//}
//
//// ����
//void Destroy_LinkNode(LinkNode* header);
//
//// ���
//void Clear_LinkList(LinkNode* header);
//
//
//int main()
//{
//	test02();
//}