#include<iostream>

// ���ͷ�ļ�
#include<ctime>
#include<cstdlib>

using namespace std;
int main(){

	// <------��������� ----->
	
	// ������������ ------>
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {

		// ���������---> rand() % ������
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