#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

void test1() {

	string test1; // 默认构造
	test1 = "Hello World";
	cout << test1 << endl;

	string test2(test1); // 拷贝构造
	cout << test2 << endl;

	string test3 = test1; // 拷贝构造
	cout << test3 << endl;

	string test4 = "使用字符串初始化 - test4"; // 使用字符串初始化
	cout << test4 << endl;

	string test5(20, '-'); // 使用 n 个   字符  初始化
	cout << test5 << endl;


	// 基本赋值
	test4 = test3;
	cout << test4 << endl;

	test4 = "基本赋值";
	cout << test4 << endl;

	// 重载操作
	string test6;
	test6.assign("中文测试是是是", 6);  // 将字符串的前 n 个 字符重新赋值给字符串
	cout << test6 << endl;

	string test7;
	test7.assign(test2, 1, 6); // 将 test2 ，从第 1 个字符起（注意：从 0 开始索引），后面的 n 个赋值给 string test7;
	cout << test7 << endl;
}


void test2() {

	/*
		string存取字符操作
		char& operator[](int n);//通过[]方式取字符
		char& at(int n);//通过at方法获取字符
	*/

	string str1;
	str1 = "Nick Wilde";

	for (int i = 0; i < str1.size() /*注意这里用了 .size()  - 来获取字符串大小*/ ; i++) {
		// cout << str1[i];
		cout << str1.at(i);
		// 两种的区别：
		// 【】会访问越界，直接挂掉
		

		try {
			//cout << str1[100] << endl;     // 【】会访问越界，直接挂掉
			cout << str1.at(100) << endl;     // at 会抛出异常
		}

		// 系统标准 out_of_range -  越界异常           使用 a - 引用(随便一个字符)       因为系统要调用并且输出异常，不要忘了要用头文件 #include<stdexcept>
		catch (out_of_range & a) {
			cout << a.what()  /*调用*/ << endl;
		}
		catch(...){
			cout << "越界异常" << endl;
		}
	}
}


void test3() {
	/*string拼接操作
			string& operator+=(const string& str);//重载+=操作符
			string& operator+=(const char* str);//重载+=操作符
			string& operator+=(const char c);//重载+=操作符
			string& append(const char *s);//把字符串s连接到当前字符串结尾
			string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
			string& append(const string &s);//同operator+=()
			string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
			string& append(int n, char c);//在当前字符串结尾添加n个字符c
	*/

	string str1 = "Мне ";
	string str2 = "наровится Санкт-Петербург";
	str1 += str2;
	cout << str1 << endl;

	str1.append("наровится Санкт-Петербург");
	cout << str1 << endl;
}


void test4() {
	/*string查找和替换

			find - 从左往右找		rfind - 从右往左找

			int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
			int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
			int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
			int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
			int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
			int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
			int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
			int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
			string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
			string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
	*/

	string test1 = "a.bc.def..ghi..jbc...k";
	int pos = test1.find("bc"); // 找不到为 -1
	int num_dot = count(test1.begin(), test1.end(), '.');  // 查找 ‘。’出现的次数！！！！！！ 重点！
	cout << "num_dot = " << num_dot << endl;
	num_dot++;
	cout << "num_dot = " << num_dot << endl;
	cout << "pos = " << pos << endl;

	int pos2 = test1.rfind("bc"); // 从右往左查，但是编号是从左向右！！！！
	cout << "pos2 = " << pos2 << endl;



	// 替换
	string test2 = "Zootopia";
	test2.replace(1, 3, "乌托邦"); //替换从pos开始n个字符为字符串str
	cout << test2 << endl;
}


void test7() {
	/*string插入和删除操作
		string& insert(int pos, const char* s); //插入字符串
		string& insert(int pos, const string& str); //插入字符串
		string& insert(int pos, int n, char c);//在指定位置插入n个字符c
		string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
*/

}


int main() {

	test4();

	cin.get();
	return 0;
}