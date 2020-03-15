#include<iostream>
#include<deque>
using namespace std;
void foeach_deque(const deque<int>& d);

/*
deque构造函数
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数。
*/
void test01()
{
	// deque<T> deqT;//默认构造形式
	deque<int> d1;
	for (int i = 0; i < 5; i++) d1.push_back(i);
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) cout << *it << " "; cout << endl;

	// deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
	deque<int>d2(d1.begin() +1 , d1.end());
	for (deque<int>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;
	
	// deque(n, elem);//构造函数将n个elem拷贝给本身。
	// d2(6, 77); - ERROR
	deque<char> d3(10, 'A');
	for (deque<char>::iterator it = d3.begin(); it != d3.end(); it++) cout << *it << " "; cout << endl;
}

/*
3.3.3.2 deque赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
deque& operator=(const deque &deq); //重载等号操作符
swap(deq);// 将deq与本身的元素互换
*/
// ###################################会把原来的值覆盖掉！！！！
void test02()
{
	deque<char> d1(5, 'A');
	deque<char> d2(10, 'B');
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;

	// assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	d2.assign(d1.begin() + 1, d1.end()); // 会把d2中原本的10个B给覆盖掉
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;

	// assign(n, elem);//将n个elem拷贝赋值给本身。
	d2.assign(5, 'E');
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;

	// swap(deq);// 将deq与本身的元素互换
	d2.swap(d1);
	cout << "交换后的d1 ：";
	for (deque<char>::iterator it = d1.begin(); it != d1.end(); it++) cout << *it << " "; cout << endl;
	cout << "交换后的d2 ：";
	for (deque<char>::iterator it = d2.begin(); it != d2.end(); it++) cout << *it << " "; cout << endl;
}

/*
3.3.3.3 deque大小操作
deque.size();//返回容器中元素的个数
deque.empty();//判断容器是否为空
deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值 0 填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
*/
void test03()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	d1.push_front(100); // push_front - 头插！
	d1.push_front(200);
	for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) cout << *it << " "; cout << endl;

	cout << "Deque size : " << d1.size() << endl;
	if (d1.empty()) cout << "null" << endl;
	else cout << "not null" << endl;

	d1.resize(20);
	foeach_deque(d1);
	
	d1.resize(3, 1);
	foeach_deque(d1);

}

// 注意通过const进行遍历运算是要更换迭代器##########
// 1. 正序遍历：iterator
// 2. 逆序遍历：reverse_iterator
// 3.通过const传值遍历：const_iterator
void foeach_deque(const deque<int>& d)
{
	for (deque<int>::const_iterator c_it = d.begin(); c_it != d.end(); c_it++) cout << *c_it << " "; cout << '\'' << endl;
}


/*
deque双端插入和删除操作
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据

3.3.3.5 deque数据存取
at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据
3.3.3.6 deque插入操作
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
3.3.3.7 deque删除操作
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。

*/
int main()
{
	test01();
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
	test02();
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
	test03();
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
	cout << endl << "-----------------------------------------------------------------" << endl << endl;
}