#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

void randomNum(int num, int numMax) {

	int x;

	int* arr = new int[num - 1];  //<------ ���������Ǹ�ʲô������

	srand((unsigned int)time(NULL));  // ��ȡ�������

	for (int i = 0; i < num ; i++) {
		x = rand() % numMax + 1; // ���������
		// cout << x << endl;
		arr[i] = x;
	}

	ofstream ofs;
	ofs.open("./Array.txt", ios::out | ios::trunc);
	ofs << "�������Ŀ��" << num << endl;
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
	cout << "�������������Ŀ��"; cin >> num;
	cout << "���������ֵ��"; cin >> numMax;
	randomNum(num, numMax);

	ifstream ifs;
	ifs.open("./Array.txt", ios::in);

	
	// int* arr = new int[num - 1];  //<------ ���������Ǹ�ʲô������

	//while (!ifs.eof()) // eor() - �Ƿ����β
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


	while (!ifs.eof()) // eor() - �Ƿ����β
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

	cout << "����õĽ��Ϊ��" << sum / counter;
	cin.get();
	return 0;
}