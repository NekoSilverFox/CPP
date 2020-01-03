// 目的：判断输入 的数是否为 0 - 10，如果不是重新循环输入！
// 注意 如果将字母输入到 int 类型中，会导致标志位的损坏
// cin.fail() - 查看标志位   0 - 正常  |  1 - 损坏
// cin.clear() - 重置标志位
// cin.sync() - 清空缓冲区

#include<iostream>
using namespace std;

int main()
{
	while (true)
	{
		int num;
		cout << "请输入一个 0 - 10之间的数字：";
		cin >> num;
		if (num >= 0 && num < 11 && cin.fail() == 0)
		{
			cout << "你输入的数字为：" << num;
			break;
		}
		//重置标志位
		cin.clear();

		// 2015 版本的 vs 下 用 ignore 处理 
		cin.ignore();

		cin.sync(); // 清空缓冲区


		cout << "标志位: " << cin.fail() << endl; //标志位 0 正常的  1 不正常
		cout << "您输入的有误，请重新输入：";
	}

}