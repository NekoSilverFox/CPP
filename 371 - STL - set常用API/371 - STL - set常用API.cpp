#include<iostream>
#include<set> // set 和 multiset 只需要引入同一个头文件！
using namespace std;

// set的本质是一棵 二叉搜索树！！

/*
3.7.2.1 set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数
3.7.2.2 set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器
3.7.2.3 set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.7.2.4 set插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。

3.7.2.5 set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

*/
void test01()
{
	set<char> set1;

	if (set1.empty()) cout << "set1 is null" << endl;
	else cout << "set1 is not null" << endl;

	// set dont have PUSH!  need use "inset"
	set1.insert('E'); //    pair<iterator, bool> insert(value_type&& _Val) 
	set1.insert('e');// inset() 插入并返回一个迭代器和bool，看上面这行定义！！
	set1.insert('A');
	set1.insert('C');
	set1.insert('T');

	cout << "Size - set_1 : " << set1.size() << endl;
	if (set1.empty()) cout << "set1 is null" << endl;
	else cout << "set1 is not null" << endl;

	cout << endl;

	for (set<char>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << "--------------------------------------------------------------" << endl << endl;


	/*
	clear();//清除所有元素
	erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	erase(elem);//删除容器中值为elem的元素。
	*/
	set1.erase(set1.begin());
	for (set<char>::iterator it = set1.begin(); it != set1.end(); it++) cout << *it << " "; cout << endl;

	set1.erase('T');
	for (set<char>::reverse_iterator it = set1.rbegin(); it != set1.rend(); it++) cout << *it << " "; cout << endl;

	set1.insert('D');
	set1.insert('S');
	set1.insert('G');
	for (set<char>::iterator it = set1.begin(); it != set1.end(); it++) cout << *it << " "; cout << endl;
	cout << endl << "--------------------------------------------------------------" << endl << endl;
	/*
	find(key);//查找键key是否存在,若存在，返回该键的元素的#@@@#迭代器#@@@#；若不存在，返回set.end();
	count(key);//查找键key的元素个数 0 OR 1
	*/
	set<char>::iterator find_it = set1.find('S');
	if (find_it == set1.end()) cout << "Didn't find key S ! " << endl;
	else cout << "Find key : " << *find_it << endl; // 注意 ！ find_it是迭代器，注意取星！！

	cout << "D 的个数为：" << set1.count('D') << endl;
	cout << "U 的个数为：" << set1.count('U') << endl;
	cout << endl << "--------------------------------------------------------------" << endl << endl;

}


// 查看插入重复的元素是否成功！！
void insert_same_key()
{
	set<char> set1;
	//    pair<iterator, bool> insert(value_type&& _Val) 
	// inset() 插入并返回一个对组，其中包含：【迭代器和bool】，看上面这行定义！！
	// 	注意， 对组是一个尖括号！！pair< xxx  >
	pair<set<char>::iterator, bool> pair_set =  set1.insert('E'); 
	if (pair_set.second) cout << "Seccful insert !" << endl;
	else cout << "Faile insert !" << endl;

	pair<set<char>::iterator, bool> pair_set2 = set1.insert('E');
	if (pair_set2.second) cout << "Seccful insert !" << endl;
	else cout << "Faile insert !" << endl;

	cout << endl << "--------------------------------------------------------------" << endl << endl;

}


/*
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/
void test03()
{
	set<int> s;
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	s.insert(0);
	s.insert(12);
	s.insert(7);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) cout << *it << " "; cout << endl;

	/*
	lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。也就是lower_bound和upper_bound两个迭代器
	*/
	set<int>::iterator lower_it = s.lower_bound(5); cout << *lower_it << endl;
	set<int>::iterator upper_it = s.upper_bound(5); cout << *upper_it << endl;

	set<int>::iterator lower_it2 = s.lower_bound(6); cout << *lower_it2 << endl;
	set<int>::iterator upper_it2 = s.upper_bound(6); cout << *upper_it2 << endl;

	pair<set<int>::iterator, set<int>::iterator> equal_it = s.equal_range(7);
	cout << *equal_it.first << "  " << *equal_it.second << endl;

}
int main()
{
	//test01();
	//insert_same_key();
	test03();
}