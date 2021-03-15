//#include"LinkList.h"
//
//void test02()
//{
//	LinkNode* t;
//	t = Init_LinkList();
//	ForEach_LinkList(t);
//}
//
//// 初始化链表
//LinkNode* Init_LinkList()
//{
//	// Make the headerNode
//	LinkNode* header = (LinkNode*)malloc(sizeof(LinkNode));
//	header->data = NULL;
//	header->next = NULL;
//
//	// 创建临时Rear指针
//	//LinkNode* pRearCurrut = (LinkNode*)malloc(sizeof(LinkNode));
//	LinkNode* pRearCurrut;
//	pRearCurrut = header;
//	int val = NULL;
//
//	while (true)
//	{
//
//		cout << "请输入数据："; cin >> val;
//
//		if (val == -1)
//		{
//			break; // break 的是 while 循环
//		}
//
//		
//		// Make the new Node
//		LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
//		newNode->data = val;
//		newNode->next = NULL;
//
//		// 让 临时指针指向下一个（新的节点），节点嵌入链表，也就是将新的节点插入到最后一个节点的下一个位置！
//		pRearCurrut->next = newNode; // 1
//
//		// 更新辅助指针
//		pRearCurrut = newNode; // 2
//
//		// ！！！！必须要有 1， 1 的目的是将节点相互连接，如果只写 2 不写 1，那么，节点之间无法连接！
//	}
//
//	return header;
//}
//
//// 在 值为 oldval 后面插入一个新的数据 newval
//void InSetByValue_LinkList(LinkNode* herder, int old_val, int new_val);
//
//// 删除值为val的节点
//void RemByValue_LinkList(LinkNode* header, int del_val);
//
//// 遍历
//void ForEach_LinkList(LinkNode* header)
//{
//	if (header == NULL)
//	{
//		return;
//	}
//
//	// 辅助指针变量
//	LinkNode* pCurrut = header->next;
//
//	while (pCurrut != NULL)
//	{
//		cout << pCurrut->data << endl;
//		pCurrut = pCurrut->next;
//	}
//}
//
//// 销毁
//void Destroy_LinkNode(LinkNode* header);
//
//// 清空
//void Clear_LinkList(LinkNode* header);
//
//
//int main()
//{
//	test02();
//}