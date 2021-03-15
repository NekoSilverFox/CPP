#include <iostream>
#include<string>
#include<fstream>
using namespace std;

string str;
int CHECK_SIGN;

//----------------------------------------------���ѧ�ڧѧߧ� 4---------------------------------------------

//����ߧ��ڧ� �ӧ֧�֧��ӧ֧ߧߧ�� ��ڧ�ݧ� ����֧է֧ݧ֧ߧ� ��ݧ֧է���ڧ� ��ҧ�ѧ٧�� :
//<�ӧ֧�֧��ӧ֧ߧߧ��> :: = <�ާѧߧ�ڧ���> <�����է��> | <�٧ߧѧ�> <�ާѧߧ�ڧ���> <�����է��>
//<�ާѧߧ�ڧ���> :: = <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�> . <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�> | <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�>
//<�����է��> :: = E <�٧ߧѧ�> <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�>
//<��֧ݧ�� �ҧ֧� �٧ߧѧܧ�> :: = <��ڧ���> | <��ڧ���> <��֧ݧ�� �ҧ֧� �٧ߧѧܧ�>
//<��ڧ���> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//< �٧ߧѧ� > :: = +| -

//----------------------------------------------���ѧ٧ӧѧߧڧ�---------------------------------------------
bool fun_sign();				// �٧ߧѧ� - sign
bool fun_letter_Ee();		// �ҧ�ܧӧ� - letter
bool fun_number();			// ��ڧ��� - number
bool fun_unsigned();		// ��֧ݧ�� �ҧ֧� �٧ߧѧܧ� - unsigned
bool fun_exponent();		// �����է�� - exponent
bool fun_mantissa();		// �ާѧߧ�ڧ��� - mantissa
bool fun_realNum();		// �ӧ֧�֧��ӧ֧ߧߧ�� - real number
//------------------------------------------------------------------------------------------------------


bool fun_realNum() {
	if (fun_mantissa()) {
		if (fun_exponent()) {
			if (CHECK_SIGN == 2) {
				if (str[0] != '+' && str[0] != '-' || str[2] == '+' || str[2] == '-') {
					return false;
				}
			}
			else {
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


bool fun_mantissa() {
	if (fun_exponent())
	{

		int num_dot = count(str.begin(), str.end(), '.');

		int place_sign_dian = str.find('.');
		int place_letter_Ee = str.find('E');
		if (place_letter_Ee == -1) {
			place_letter_Ee = str.find('e');
		}

		if (num_dot == 1) {

			if (place_sign_dian > place_letter_Ee || str[place_letter_Ee + 2] == '\0') {
				return false;
			}
			else if (place_sign_dian == 0 || place_sign_dian + 1 == place_letter_Ee) {
				return false;
			}
			else {
				return true;// fun_realNum(); //  ��=====
			}
		}

		else if (num_dot == 0 && str[place_letter_Ee + 2] != '\0' && place_letter_Ee != 0)
		{
			return true; // fun_realNum(); //	��=====
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
	
}


bool fun_exponent() {
	if (fun_letter_Ee())
	{
		for (int i = 0; i < str.size(); i++) {
			if ((str[i] == 'E' || str[i] == 'e') && (str[i + 1] == '+' || str[i + 1] == '-')) {
				return true; // fun_mantissa();
			}
		}
	}
	else
	{
		return false;
	}
	
	return false;
}


bool fun_letter_Ee() {

	if (fun_sign())
	{
		if (fun_unsigned())
		{
			int check_Ee = 0, check_letter = 0;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] > 57 && str[i] < 127 || (str[i] > 32 && str[i] < 43)) {		// �����Ϊ E e ������Ϊ : ; < > ? ^ & * ( ) " ' ��ҵ�
					check_letter++;
				}
				if (str[i] == 'E' || str[i] == 'e') {
					check_Ee++;
				}
			}

			if (check_Ee == check_letter && check_Ee == 1) {
				return true; //fun_exponent();
			}
			else {
				return false;
			}


		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool fun_unsigned() {
	
	if (fun_number) {
		for (static int i = 0; i < sizeof(str); i++) {
			if (str[i] > 47 && str[i] < 58) {
				int num = 0;
				num++;
				if (num > 0) {
					return true;
				}
			}
			else
			{
				return fun_unsigned;
			}
		}
	}
}


bool fun_number() {
	int check_num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 47 && str[i] < 58) {
			check_num++;
		}
	}

	if (check_num != 0) {
		return true;//fun_letter_Ee();
	}
	else {
		return false;
	}
}


bool fun_sign() {
	CHECK_SIGN = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			CHECK_SIGN++;
		}
	}
	if (CHECK_SIGN < 3 && CHECK_SIGN > 0) {
		return true; //fun_number();
	}
	else {
		return false;
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
		cout.width(20) | cout.setf(ios::left);
		cout << str;
		if (fun_realNum()) {
			cout << "Ture" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}
	return 0;
}