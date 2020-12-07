#include<iostream>

// 添加头文件
#include<ctime>
#include<cstdlib>

using namespace std;
int main(){

	// <------生成随机数 ----->
	
	// 添加随机数种子 ------>
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {

		// 生成随机数---> rand() % 最大的数
		cout << rand() % 100<< endl;
	}

	int num = 10;
	int* temp = new int;
	temp = &num;


	cout << "==========================================" << endl
		<< temp << endl
		<< *temp << endl;

	cin.get();
	return 0;
}