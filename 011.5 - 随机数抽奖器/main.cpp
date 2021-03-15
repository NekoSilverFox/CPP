#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int min_value;
	int max_value;
	srand((unsigned int)time(NULL));

	cout << "bilibili：冰糖雪狸和狐萝卜" << endl
			<< "开奖时间(莫斯科时间)：" << __TIMESTAMP__ << endl << endl;

	cout << "请输入最小值："; cin >> min_value;
	cout << "请输入最大值："; cin >> max_value;

	cout << endl
		<< "\033[32m"
		<< "中奖楼层：" << min_value + (rand() % (max_value - min_value + 1)) << endl
		<< "\033[0m";
}