#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h> 
using namespace std;

// ����������������������
double function_19(double x, double absError, int numberMax);

// �����Ķ���
double function_19(double x, double absError, int numberMax) {
	
	// �����Χ����ȷ����Χ��
	if (x > 3 || x < 2) {
		throw 1;
	}

	double n = 0, elem = 1.0, sum = 0; // elem - Ԫ��

	while (abs(elem) > absError) {  // ���Ǹ�ʲô����
			n++;
			if (n >= numberMax) {
				throw 2;
			}
			elem = 1 / ((n * 2 - 1) * pow(x, 2 * n - 1));
			sum += elem;
		}
	return sum * 2;
}

int main() {
	double x, absError, interval; // interval  - Ϊ�����������
	int numberMax;

	cout << "��������(����)��"; cin >> interval; cout << endl;
	cout << "�����뾫�ȣ�"; cin >> absError; cout << endl;
	cout << "�������������ֵ��"; cin >> numberMax; cout << endl;
	x = interval + 2;

	// �ж��������
	if (!cin) {
		cerr << "ERROR! ���ӧ�էڧ� ��ڧ�ݧ�!";
		return 1;
	}

	for (interval; x < 3; x += interval) {
		cout << x << "    ";
		cout << log((x + 1) / (x - 1)) << "    ";

		try {
			cout << function_19(x, absError, numberMax) << endl;
		}

		// ���� swish �������� ֮ǰ throw �׳��Ĵ���
		catch (int exc) {
			switch (exc) {
			case 1:
				cerr << "��Χ����" << endl;
				break;
			case 2:
				cerr << "���Ȳ��㣡" << endl;
				break;
			default:
				break;
			}
		}
	}
	cin.get();
	return 0;
}