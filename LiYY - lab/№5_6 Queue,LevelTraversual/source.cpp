#include<iostream>
#include"BTS3.h"
using namespace std;


static int arr[] = { 8,6,16,4,7,14,18,2,5,9,15,17,20 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
	int i, len;
	BSTree<int>* tree = new BSTree<int>();

	cout << "== 依次添加: ";
	len = TBL_SIZE(arr);
	for (i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
		tree->insert(arr[i]);
	}

	cout << "\n== 前序遍历: ";
	tree->preOrder();

	cout << "\n== 中序遍历: ";
	tree->inOrder();

	cout << "\n== 后序遍历: ";
	tree->postOrder();
	cout << endl;

	cout << "\n== 第某个结点: \n";
	tree->number(5);
	cout << endl;


	cout << "== 最小值: " << tree->minimum() << endl;
	cout << "== 最大值: " << tree->maximum() << endl;
	cout << "== 树的详细信息: " << endl;
	cout << "Total nodes: " << tree->getCount() << endl;
	tree->print();

	cout << "\n== 删除根节点: " << arr[3];
	tree->remove(arr[3]);

	cout << "\n== 中序遍历: ";
	tree->inOrder();
	cout << endl;


	
	
	cout << "\n== 第某个结点: \n";
	tree->number(3);
	cout << endl;
	


	// 销毁二叉树
	tree->destroy();

	return 0;
}