#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

void randomNum(int num, int numMax) {

	int x;

	int* arr = new int[num - 1];  //<------ 搞明白这是个什么鬼玩意

	srand((unsigned int)time(NULL));  // 获取随机种子

	for (int i = 0; i < num ; i++) {
		x = rand() % numMax + 1; // 生成随机数
		// cout << x << endl;
		arr[i] = x;
	}

	ofstream ofs;
	ofs.open("./Array.txt", ios::out | ios::trunc);
	ofs << "所需的数目：" << num << endl;
	for (int i = 0; i < num; i++) {
		ofs << arr[i] << endl;
	}
	ofs.close();
}

//double judgeNumArr() {
//	int numMax, sum = 0, counter = 0;
//	int* arr = new int[num - 1]
//	for (int i = 0; i <= numMax; i++) {
//		arr[i];
//
//		for (int iForIndex = 0; i < numMax; iForIndex++) {
//			int index = iForIndex * iForIndex;
//			if (arr[i] == index) {
//				sum += arr[i];
//				counter++;
//				break;
//			}
//		}
//		
//	}
//	return sum / counter;
//}

int main() {
	int num, numMax, sum = 0, counter = 0, i = -1,x;
	cout << "请输入所需的数目："; cin >> num;
	cout << "请输入最大值："; cin >> numMax;
	randomNum(num, numMax);

	ifstream ifs;
	ifs.open("./Array.txt", ios::in);

	
	// int* arr = new int[num - 1];  //<------ 搞明白这是个什么鬼玩意

	//while (!ifs.eof()) // eor() - 是否读到尾
	//{
	//	
	//	ifs >> arr[i];
	//	cout << arr[i] << endl;
	//	i++;
	//}

	//// int* arr = new int[num - 1];
	//for (int i = 0; i < num - 1; i++) {
	//	arr[i];

	//	for (int iForIndex = 0; iForIndex < numMax; iForIndex++) {
	//		int index = iForIndex * iForIndex;
	//		if (arr[i] == index) {
	//			sum += arr[i];
	//			counter++;
	//			break;
	//		}
	//	}
	//}


	while (!ifs.eof()) // eor() - 是否读到尾
	{
		
		if (i == -1) {
			i++;
			continue;
		}

		ifs >> x;

		for (int iForIndex = 0; iForIndex < numMax; iForIndex++) {

			if (x == iForIndex * iForIndex) {
				sum += x;
				counter++;
				break;
			}

		}
		cout << x << endl;
	}

	// int* arr = new int[num - 1];		

	ifs.close();

	cout << "所求得的结果为：" << sum / counter;
	cin.get();
	return 0;
}