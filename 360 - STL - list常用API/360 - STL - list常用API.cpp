#include<iostream>
#include<list>
using namespace std;

// list容器不仅是一个双向链表，而且还是一个循环的双向链表。
// 证明：
void listisDoubleList()
{
	//list<int> myList;
	//for (int i = 0; i < 10; i++) {
	//	myList.push_back(i);
	//}

	//list<int>::_Nodeptr node = myList._Myhead->_Next;

	//for (int i = 0; i < myList._Mysize * 2; i++) {
	//	cout << "Node:" << node->_Myval << endl;
	//	node = node->_Next;
	//	if (node == myList._Myhead) {
	//		node = node->_Next;
	//	}
	//}

}

//3.6.4.1 list构造函数
//list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
//list(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
//list(n, elem);//构造函数将n个elem拷贝给本身。
//list(const list& lst);//拷贝构造函数。
void test01()
{
	list<char> list1(6, 'a');
	list<char>list2(list1.begin(), list1.end());
	list2.push_back('E');

	for (list<char>::iterator it = list2.begin(); it != list2.end(); it++) cout << *it << " ";
	cout << endl;

	for (list<char>::reverse_iterator it = list2.rbegin(); it != list2.rend(); it++) cout << *it << " ";
	cout << endl << endl;
}

//
//3.6.4.2 list数据元素插入和删除操作
//push_back(elem);//在容器尾部加入一个元素
//pop_back();//删除容器中最后一个元素
//push_front(elem);//在容器开头插入一个元素
//pop_front();//从容器开头移除第一个元素
//insert(pos, elem);//在pos位置插elem元素的拷贝，返回新数据的位置。// !!!!!!!!!!!!!!!!!!!!!!@@@@@@@@@@@@@@@@@@
//insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值。
//insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值。
//clear();//移除容器的所有数据
//erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置。
//erase(pos);//删除pos位置的数据，返回下一个数据的位置。
//remove(elem);//删除容器中所有与elem值匹配的元素。
void test02()
{
	list<char> l;
	l.push_back('a');
	l.push_back('b');
	l.push_back('c');
	l.push_front('A');
	l.push_front('B');
	l.push_front('C');

	l.pop_back();
	l.pop_front();

	list<char> l2(5, 'd');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.insert(l2.begin(), 'A');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.insert(l2.end(), 5, 'b');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.insert(l2.end(), l.begin(), l.end());
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.erase(l2.begin());
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.remove('a');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

	l2.clear();
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << endl;

}

//3.6.4.3 list大小操作
//size();//返回容器中元素的个数
//empty();//判断容器是否为空
//resize(num);//重新指定容器的长度为num，
//若容器变长，则以默认值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
//resize(num, elem);//重新指定容器的长度为num，
//若容器变长，则以elem值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
//
//3.6.4.4 list赋值操作
//assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。会覆盖原有的数据
//assign(n, elem);//将n个elem拷贝赋值给本身。
//list& operator=(const list& lst);//重载等号操作符
//swap(lst);//将lst与本身的元素互换。
//3.6.4.5 list数据的存取
//front();//返回第一个元素。
//back();//返回最后一个元素。
//3.6.4.6 list反转排序
//reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
//sort(); //list排序
void test03()
{
	list<char> l1;
	l1.push_back('a');
	l1.push_back('b');
	l1.push_back('c');
	l1.push_back('d');
	l1.push_back('e');

	cout << "List size : " << l1.size() << endl;

	if (l1.empty()) cout << "list in null" << endl;
	else cout << "list is not null" << endl;

	l1.resize(10);
	for (list<char>::iterator it = l1.begin(); it != l1.end(); it++) cout << *it << " "; cout << '\'' << endl;
	
	l1.resize(15, '#');
	for (list<char>::iterator it = l1.begin(); it != l1.end(); it++) cout << *it << " "; cout << '\'' << endl;
	cout << endl << endl;
	// --------------------
	//assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。会覆盖原有的数据
	//assign(n, elem);//将n个elem拷贝赋值给本身。
	//list& operator=(const list& lst);//重载等号操作符
	//swap(lst);//将lst与本身的元素互换。
	//3.6.4.5 list数据的存取
	//front();//返回第一个元素。
	//back();//返回最后一个元素。
	//3.6.4.6 list反转排序
	//reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
	//sort(); //list排序
	list<char>l2(5, 'a');
	l2.assign(l1.begin(), l1.end());
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	l2.assign(3, 'B');
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	l2.swap(l1);
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	cout << "The first element : " << l2.front() << endl;
	cout << "The list element : " << l2.back() << endl;

	l2.reverse();
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;

	l2.sort();
	for (list<char>::iterator it = l2.begin(); it != l2.end(); it++) cout << *it << " "; cout << '\'' << endl;


}

int main()
{
	test01();
	test02();
	test03();
}