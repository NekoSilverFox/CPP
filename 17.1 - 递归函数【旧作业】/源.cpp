#include <iostream>
#include<string>
#include<fstream>
using namespace std;

string str;
int ANSWER, CHECK_NUM = 0;

//----------------------------------------------���ѧ�ڧѧߧ� 4---------------------------------------------
//
//����ߧ��ڧ� �ӧ֧�֧��ӧ֧ߧߧ�� ��ڧ�ݧ� ����֧է֧ݧ֧ߧ� ��ݧ֧է���ڧ� ��ҧ�ѧ٧�� :
//<�ӧ֧�֧��ӧ֧ߧߧ��> :: = <�ާѧߧ�ڧ���> <�����է��> | <�٧ߧѧ�> <�ާѧߧ�ڧ���> <�����է��>
//<�ާѧߧ�ڧ���> :: = <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�> . <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�> | <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�>
//<�����է��> :: = E <�٧ߧѧ�> <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�>
//<��֧ݧ�� �ҧ֧� �٧ߧѧܧ�> :: = <��ڧ���> | <��ڧ���> <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�>
//<��ڧ���> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//< �٧ߧѧ� > :: = +| -
//----------------------------------------------���ѧ٧ӧѧߧڧ�---------------------------------------------
// �ӧ֧�֧��ӧ֧ߧߧ�� - real number
// �ާѧߧ�ڧ��� - mantissa
// �����է�� - exponent
// ��֧ݧ�� �ҧ֧� �٧ߧѧܧ� - unsigned
// ��ڧ��� - number
// �٧ߧѧ� - sign
//------------------------------------------------------------------------------------------------------


// �ӧ֧�֧��ӧ֧ߧߧ�� - real number
int fun_realNum() {
	int check_realNum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			if ((str[i - 1] > 47 && str[i - 1] < 58) && (str[i + 1] > 47 && str[i + 1] < 58) ) {
				check_realNum++;
			}
		}
	}

	if (check_realNum != 0) {
		return 6;
	}
	else {
		return 4;
	}
}


// �ާѧߧ�ڧ��� - mantissa
int fun_mantissa() {
	int check_mantissa = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			if ((str[i - 1] > 47 && str[i - 1] < 58) && (str[i + 1] > 47 && str[i + 1] < 58)) {
				check_mantissa++;
			}
		}
		if ((str[i] > 47 && str[i] < 58) && (str[i + 1] != '.' && str[i + 1] != '+' && str[i + 1] != '-')){
			check_mantissa++;			
		}
	}

	if (check_mantissa != 0) {
		return fun_realNum();
	}
	else {
		return 4;
	}
}


// �����է�� - exponent
int fun_exponent() {
	int check_exponent = 0;

	for (int i = 0; i < str.size(); i++) {
		if ((str[i] == 'E' || str[i] == 'e') && (str[i + 1] == '+' || str[i + 1] == '-') && (str[i + 2] > 47 && str[i + 2] < 58) && (str[i + 3] != '+' && str[i + 3] != '-')) {
			check_exponent++;
		}
	}

	if (check_exponent == 1) {
		return fun_mantissa();
	}
	else {
		return 4;
	}
}


//��֧ݧ�� �ҧ֧� �٧ߧѧܧ� - fun_unsigned
int fun_unsigned() {
	int check_unsign = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 47 && str[i] < 58) {
			if (str[i + 1] == '+' || str[i + 1] == '-') {
				check_unsign++;
			}
		}
	}
	if (check_unsign == CHECK_NUM) {
		return 4;
	}
	else {
		return fun_exponent();
	}
}


// ��ڧ��� - number
int fun_number() {
	CHECK_NUM = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 47 && str[i] < 58) {
			CHECK_NUM++;
		}
	}

	if (CHECK_NUM != 0) {
		return fun_unsigned();
	}
	else {
		return 4;
	}
}


//�٧ߧѧ� ::= + || -
int fun_sign() {
	int check_sign = 0, check_letter = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			check_sign++;
		}

		else {
			if ((str[i] > 64 && str[i] < 69) || (str[i] > 69 && str[i] < 101) || (str[i] > 101 && str[i] < 123)) {
				check_letter++;
			}
		}
	}

	if (check_sign != 0 && check_letter == 0) {
		return fun_number();
	}
	else {
		return 4;
	}
}


int main() {
	ifstream ifs;
	ifs.open("./Input.txt", ios::in);
	if (!ifs.is_open()) {
		cerr << "Can't open the file!" << endl;
	}

	while (!ifs.eof())
	{
		ifs >> str;

		ANSWER = fun_sign();
		
		switch (ANSWER)
		{
			case 6:{
				cout << "True" << endl;
				break;
			}
			case 4:{
				cout << "False" << endl;
				break;
			}
		}
	}
	cin.get();
	return 0;
}