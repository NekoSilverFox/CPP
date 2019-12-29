#include <iostream>
using namespace std;


bool fun_bool_test() {
	int a;
	cout << "请输入第一个小于 10 的值："; cin >> a;

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