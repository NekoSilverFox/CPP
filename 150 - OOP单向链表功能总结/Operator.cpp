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



LinkNode* operator&(const LinkNode& header1, const LinkNode& header2)
{
	if (&header1 == nullptr || &header2 == nullptr || header1.next == nullptr || header2.next == nullptr) return 0;

	LinkNode* pCurrent_1 = header1.next;
	LinkNode* pCurrent_2 = header2.next;

	LinkNode* newHeader = new LinkNode;  // 创建新节点
	newHeader->data = NULL;
	newHeader->next = nullptr;

	LinkNode* pCurrent_newHeader = newHeader; // 新链表的 初始化 辅助指针
	LinkNode* pCurrent_repetition = newHeader; // 用于在检测 新链表插入新元素时 有没有 相同数据
	bool for_repetition = false; // 用于打破第二次循环

	// 通过类冒泡排序，将相同元素合并成一个新的链表
	while (pCurrent_1 != nullptr)
	{
		while (pCurrent_2 != nullptr)
		{
			if (pCurrent_1->data == pCurrent_2->data)
			{
				// （先判断元素是否重复）如果是重复的元素，则后移PCurrent_1，重新开始循环，避免将重复元素导入新链表（newHeader）	
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
		pCurrent_repetition = newHeader; // 重置 - 用于判断重复元素的辅助指针
		pCurrent_2 = header2.next; // 重置 - pCurrent_2
		for_repetition = false;  // 重置 - 打破循环（while2）
		pCurrent_1 = pCurrent_1->next;
	}
	return newHeader;
}

LinkNode* operator|(const LinkNode& header1, const LinkNode& header2)
{
	if (&header1 == nullptr || &header2 == nullptr || header1.next == nullptr || header2.next == nullptr) return 0;

	LinkNode* pCurrent_1 = header1.next;
	LinkNode* pCurrent_2 = header2.next;

	LinkNode* newHeader = new LinkNode;  // 创建新节点
	newHeader->data = NULL;
	newHeader->next = nullptr;
	LinkNode* pCurrent_newList = newHeader;
	LinkNode* pCurrent_repetition = newHeader;
	bool for_repetition = false; // 用于打破第二次循环

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