#include<iostream>
#include<map>
using namespace std;

/*
3.8.2.1 map构造函数
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数


3.8.2.2 map赋值操作
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器

3.8.2.3 map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.8.2.4 map插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";

*/
void test01()
{
	map<int, char>s;
	// 插入是通过对组进行的！！！！！！！！！！！！！！！！！！！！！
	// 第一种 通过pair的方式插入对象
	s.insert(pair<int, char>(3, 'C'));

	// 第二种 通过pair的方式插入对象
	s.insert(make_pair(2, 'B'));

	// 第三种 通过value_type的方式插入对象
	s.insert(map<int, char>::value_type(5, 'F'));

	// 第四种 通过数组的方式插入值
	s[10] = 'H';

	for (map<int, char>::iterator it = s.begin(); it != s.end(); it++)
		cout << "Key = " << it->first << "  Value = " << it->second << endl;

}


// ==================================================================

class Person
{
public:
	Person(string name, int age) : name_(name), age_(age) {}

public:
	int age_;
	string name_;
};

class MyCompareMap
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		if (p1.name_ > p2.name_) return true;
		else return false;
	}
};

// 逆序插入
void test02()
{
	Person p1("Judy", 13);
	Person p2("Nick", 14);
	Person p3("Funick", 23);
	Person p4("Yiff", 17);
	Person p5("Neko", 13);
	Person p6("Alisa", 7);
	Person p7("YiffYiff", 13);

	map<Person, int, MyCompareMap>s;
	// 第一种 通过pair的方式插入对象
	s.insert(pair<Person, int>(p2, 2));

	// 第二种 通过pair的方式插入对象
	s.insert(make_pair(p7, 7));

	// 第三种 通过value_type的方式插入对象
	s.insert(map<Person, int>::value_type(p5, 5));

	// 第四种 通过数组的方式插入值
	s[p4] = 4;

	// 第二种 通过pair的方式插入对象 is best
	s.insert(make_pair(p3, 3));
	s.insert(make_pair(p1, 1));
	s.insert(make_pair(p4, 4));
	s.insert(make_pair(p6, 6));

	for (map<Person, int, MyCompareMap>::iterator it = s.begin(); it != s.end(); it++)
		cout << "Name : " << it->first.name_ << "  Age : " << it->first.age_ << " Value : " << it->second << endl;


}


//3.8.2.6 map查找操作
//find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
//count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
void test03()
{
	map<string, int>m;
	m.insert(make_pair("LLL",6 ));
	m.insert(make_pair("QQQ",8 ));
	m.insert(make_pair("AAA", 1));
	m.insert(make_pair("SSS", 16));
	m.insert(make_pair("CCC", 3));

	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << "Key = " << it->first << "      Value = " << it->second << endl;

	map<string, int>::iterator map_it1 = m.find("AAA");
	if (map_it1 != m.end())
	{
		cout << "Have this Key :" << endl
			<< "Number is  = " << m.count(map_it1->first) << endl
			<< "Value = " << map_it1->first << "     Value = " << map_it1->second << endl;
	}
	else cout << "Dont have this key" << endl;

	pair<map<string, int>::iterator, map<string, int>::iterator> map_pair_it = m.equal_range("CCC");
	cout << "First element is >>> Key = " << map_pair_it.first->first << "     Value = " << map_pair_it.first->second << endl
		<< "Secound is >>> Key = " << map_pair_it.second->first << "      Value = " << map_pair_it.second->second << endl;
 
}

int main()
{
	test01();
	test02();
	test03();
}