#include"QueueArray.h"
#include"QueueList.h"
#include"BTS.h"
#include<iostream>

#define SIZE 10
static int arr[] = { 8,6,16,4,7,14,18,2,5,9,15,17,20 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )


//test for Queue
template<class T>
void testQ(Queue<T>* Q)
{
	cout << "Enter Queue:\n";
	for (int i = 0; i < SIZE; i++)
	{
		Q->enQueue(i);
		Q->printInfo();
	}
	cout << endl;
	cout << "Out Queue:\n";
	for (int i = 0; i < SIZE; i++)
	{
		Q->deQueue();
		Q->printInfo();
	}

}


//Use Queue to do Level Traval
template<class T>
void LevelTraval(BSTree<T>* tree)
{
	int i, len;
	len = TBL_SIZE(arr);
	//Add in
	for (i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
		tree->insert(arr[i]);
	}
	//print out
	tree->levelOrder();
	tree->preOrder();
	cout << endl;
	tree->destroy();

}

/*
* Compare two tree is Similar or not
* If all the elements in treeA can be found in treeB ,then they are "Similar"
* 1) Compare their size
* 2) Get 2 arrayies(Sorted) , compare every element in arraies
*/


template<class T>
bool isSimilarTree(BSTree<T>* Tr1, BSTree<T>* Tr2)
{
	bool isSimilar = true;
	int size1 = Tr1->getCount();
	int size2 = Tr2->getCount();
	if (size1!=size2){
		cout << "Different counts.\n";
		return isSimilar = false;
	}

	T* Array1 =Tr1->getArrayOfElem();
	T* Array2 = Tr2->getArrayOfElem();

	//print out
	cout << "treeA:\n";
	for (int i = 0; i < size1; i++)
	{
		cout << Array1[i]<<" ";
	}
	cout << endl;
	cout << "treeB:\n";
	for (int i = 0; i < size2; i++)
	{
		cout << Array2[i]<<" ";
	}
	cout << endl;

	//compare
	for (int i = 0; i < size1; i++)
	{
		if (Array1[i]!=Array2[i]){
			return isSimilar = false;
		}
	}
	return isSimilar;

}
int main() {

	//test for Queue
	QueueArray<int> QArray;
	cout << "******************Array Queue*****************" << endl;
	testQ(&QArray);
	QueueList <int> QList;
	cout << "******************List Queue*****************" << endl;
	testQ(&QList);

	

	//Use Queue to do Level Traval
	BSTree<int>* tree = new BSTree<int>();
	LevelTraval(tree);



	//Compare whether two trees are similar or not
	BSTree<int> *treeA= new BSTree<int>();
	BSTree<int>* treeB = new BSTree<int>();

	int  len = TBL_SIZE(arr);
	//Add in treeA
	for (int i = 0; i < len; i++)
	{
		treeA->insert(arr[i]);
	}

	//Add in treeB backward
	for (int i = len; i > 0; i--)
	{
		treeB->insert(arr[i-1]);
	}

	cout << "treeA and treeB are similar ?\n"; 
	cout << boolalpha << isSimilarTree(treeA, treeB);


	return 0;
}