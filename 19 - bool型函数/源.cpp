#include <iostream>
using namespace std;


bool fun_bool_test() {
	int a;
	cout << "�������һ��С�� 10 ��ֵ��"; cin >> a;

	if (a < 10) {
		return true;
	}
	else {
		return false;
	}

}


int main() {

	if (fun_bool_test()) {
		cout << "Ture" << endl;
	}
	else {
		cout << "False" << endl;

	}


	cin.get();
	return 0;
}