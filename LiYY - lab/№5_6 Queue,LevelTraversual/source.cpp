#include<iostream>
#include"BTS3.h"
using namespace std;


static int arr[] = { 8,6,16,4,7,14,18,2,5,9,15,17,20 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
	int i, len;
	BSTree<int>* tree = new BSTree<int>();

	cout << "== �������: ";
	len = TBL_SIZE(arr);
	for (i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
		tree->insert(arr[i]);
	}

	cout << "\n== ǰ�����: ";
	tree->preOrder();

	cout << "\n== �������: ";
	tree->inOrder();

	cout << "\n== �������: ";
	tree->postOrder();
	cout << endl;

	cout << "\n== ��ĳ�����: \n";
	tree->number(5);
	cout << endl;


	cout << "== ��Сֵ: " << tree->minimum() << endl;
	cout << "== ���ֵ: " << tree->maximum() << endl;
	cout << "== ������ϸ��Ϣ: " << endl;
	cout << "Total nodes: " << tree->getCount() << endl;
	tree->print();

	cout << "\n== ɾ�����ڵ�: " << arr[3];
	tree->remove(arr[3]);

	cout << "\n== �������: ";
	tree->inOrder();
	cout << endl;


	
	
	cout << "\n== ��ĳ�����: \n";
	tree->number(3);
	cout << endl;
	


	// ���ٶ�����
	tree->destroy();

	return 0;
}