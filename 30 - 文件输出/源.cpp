#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void write() {

	// 读数据
	ofstream ofs;
	ofs.open("./text.txt", ios::out | ios::trunc);

	// 判断是否打开成功
	if (!ofs.is_open()) {
		cerr << "Can't open the file!" << endl; 
	}

	// 输出数据
	ofs << "Name: Nick Wilde" << endl;
	ofs << "Which furry: fox" << endl;
	ofs << "Age: 12" << endl;

	int x = 1;
	while (x != 0)
	{
		cin >> x; ofs << x << endl;
	}

	ofs.close();
}

void read() {
	// 读数据
	ifstream ifs;
	ifs.open("./text.txt", ios::in);

	// 是否打开成功
	if (!ifs.is_open()) {
		cerr << "打开失败！" << endl;
	}

	// 使用了第二种方法读取文件
	char buf[1024];
	while (!ifs.eof()) // eor() - 是否读到尾
	{
		ifs.getline /* <--- getline按行读取*/ (buf/* 数据 */,sizeof(buf)/* 计算长度*/);
		cout << buf << endl;
	}
}

// 主函数
int main(void) {

	read();
	// cin.get();
	return 0;
}