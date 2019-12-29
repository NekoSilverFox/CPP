#include <iostream>
using namespace std;
int main() {
	int mark, forVerdict = 0;

	cout << "请输入你的成绩："; cin >> mark;

	/*forVerdict = 0 <= mark <= 59 ? 2 : 0;
	forVerdict = 60 <= mark <= 79 ? 3 : 0;
	forVerdict = 80 <= mark <= 89 ? 4 : 0;
	forVerdict = 90 <= mark <= 100 ? 5 : 0;*/

	if (90 <= mark && mark <= 100) {
		forVerdict = 5;
	}
	if (80 <= mark && mark <= 89) {
		forVerdict = 4;
	}
	if (60 <= mark && mark <= 79) {
		forVerdict = 3;
	}
	if (0 <= mark && mark <= 59) {
		forVerdict = 2;
	}

	switch (forVerdict)
	{
	case 5:
		cout << "极好！";
		break;
	case 4:
		cout << "优秀！";
		break;
	case 3:
		cout << "良好！";
		break;
	case 2:
		cout << "不及格！";
		break;

	default:
		cout << "你输入的成绩有误！请重新输入！" << endl;
		break;
	}

	cin.get();
	return 0;
}