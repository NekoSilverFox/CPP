#include<iostream>
using namespace std;
//int main(void) {
//
//	char buf[10]; // 注意！！这里是【】不是 ()
//
//	cin.getline(buf, 5);
//
//	/*cin >> buf;*/
//	cout << buf;
//
//	cin.get();
//	return 0;
//}


void num0_20() {

	while (true)
	{
		int num;
		cout << "请输入一个1-10 的数字："; cin >> num;

		if (num >= 1 && num <= 10) {
			cout << "你们输入的数字为：" << num;
			break;
		}
		
			cout << "标志位：" << cin.fail() << endl; // cin.fail() - 读取标志位
			cout << "您输入的数字有误，请重新输入！" << endl;
			cin.sync();				 // 清空缓存区
			cin.clear();		   	// 重置标志位
	}

}

// 判断输入的是否为0-10 的数字
int main(void) {

	num0_20();

	cin.get();
	return 0;
}