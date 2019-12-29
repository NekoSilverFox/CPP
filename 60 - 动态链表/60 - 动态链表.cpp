#include "LinkList.h"

void test02()
{
	// 初始化链表
	LinkNode* header = Init_LinkList();

	// 打印链表
	ForEach_LinkList(header);

	cout << "================================================" << endl;

	// 在值为 oldval 前插入一个新的数据 newval
	InSetByValue_LinkList(header, 500, 666);

	// 打印链表
	ForEach_LinkList(header);

	cout << "================================================" << endl;

	RemByValue_LinkList(header, 50);
	// 打印链表
	ForEach_LinkList(header);

	cout << "================================================" << endl;

	 // 清空 

	 Clear_LinkList(header);

	 
	// 销毁
	Destroy_LinkNode(header);

	// 打印链表
	// ForEach_LinkList(header);

	cout << "================================================" << endl;

}

// ===================================================================================

// 初始化链表
LinkNode* Init_LinkList()
{
	// 创建头节点
	LinkNode* header = new LinkNode;
	header->data = NULL;
	header->next = NULL;


	// 尾部(临时辅助)指针
	LinkNode* pRearCurrent = header;  

	int val = NULL;

	while (true)
	{
		cout << "输入插入的数据："; cin >> val;



		if (val == -1)
		{
			break;
		}


		// 先创建 新节点
		LinkNode* newNode = new LinkNode;
		newNode->data = val;
		newNode->next = NULL;

		// 新节点 插入到链表中
		pRearCurrent->next = newNode; // ========================================= -

		// 更新尾部(临时辅助)指针指向
		pRearCurrent = newNode; // newNode 相当于 temp
	}
	return header;
}

// 在值为 oldval 前插入一个新的数据 newval
void InSetByValue_LinkList(LinkNode* header, int old_val, int new_val)
{
	// 定义两个临时指针变量，一个指向前一个，一个指向后一个
	LinkNode* pPrev = header;
	LinkNode* pCurrent = header->next;

	while (pCurrent != NULL)
	{
		
		if (pCurrent->data == old_val)
		{
			break;
		}

		//pPrev = pPrev->next;
		//pCurrent = pCurrent->next; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		pPrev = pCurrent;
		pCurrent = pCurrent->next;

	}

	// 创建 new_val 的新节点
	LinkNode* newNode = new LinkNode;
	newNode->data = new_val;

	newNode->next = pCurrent;

	pPrev->next = newNode;
	
}

// 删除值为val的节点
void RemByValue_LinkList(LinkNode* header, int del_val)
{
	// 定义两个临时指针变量，一个指向前，一个指向后
	LinkNode* pRear = new LinkNode;
	LinkNode* pCurrent = new LinkNode;

	pRear = header;
	pCurrent = pRear->next;

	while (pCurrent != NULL)
	{
		if (header == NULL)
		{
			break;
		}
		if (pCurrent->data == del_val)
		{
			break;
		}
		else
		{
			pRear = pCurrent;
			pCurrent = pCurrent->next;
		}
	}
	if (pCurrent == NULL)
	{
		cout << "ERROR！  未找到值为 " << del_val << " 的节点！";
		return;
	}
	else
	{
		pRear->next = pCurrent->next;
		delete pCurrent;
	}
	return;
}

// 遍历
void ForEach_LinkList(LinkNode* header)
{
	if (NULL == header)
	{
		cout << "The header is NULL" << endl;
		return;
	}

	// 辅助指针变量
	LinkNode* pCurrent = header->next;

	while (pCurrent != NULL) // 既然 pCurrent 的数据都为空了，为什么还会向下执行呢？？？★★★
	{

		// 输出当前节点的数据域
		cout << pCurrent->data << endl;
		pCurrent = pCurrent->next;
	}
}

// 销毁
void Destroy_LinkNode(LinkNode* header)
{
	// 创建临时指针
	//LinkNode* pCurrent = new LinkNode;
	//pCurrent = header;
	LinkNode* pCurrent = header;

	LinkNode* pNext;

	while (pCurrent != NULL)
	{
		pNext = pCurrent->next;

		cout << "Delete " << pCurrent->data << endl;
		cout <<"释放前：" << pCurrent << endl;
		delete pCurrent;
		cout << "释放后：" << pCurrent << endl;
		cout << "---------------------------" << endl;

		pCurrent = pNext;
	}
}

// 清空
void Clear_LinkList(LinkNode* header)
{

	LinkNode* pCurrent = header->next;

	// 先要缓存当前节点的下一节点
	LinkNode* pNext;

	while (pCurrent !=  NULL)
	{
		pNext = pCurrent->next;

		delete pCurrent;

		pCurrent = pNext;

	}

	header->next = NULL; // 勿忘！！
}

int main()
{

	test02();
	return 0;
}
