#include <iostream>
using namespace std;
int main() {
	int mark, forVerdict = 0;

	cout << "��������ĳɼ���"; cin >> mark;

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
		cout << "���ã�";
		break;
	case 4:
		cout << "���㣡";
		break;
	case 3:
		cout << "���ã�";
		break;
	case 2:
		cout << "������";
		break;

	default:
		cout << "������ĳɼ��������������룡" << endl;
		break;
	}

	cin.get();
	return 0;
}