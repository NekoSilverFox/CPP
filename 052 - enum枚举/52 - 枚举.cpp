#include<iostream>
using namespace std;

enum ATM
{
	card_in = 1, passw, check_moey, moey_in, moey_out, card_out  // <------ ע�⣡ ���ﲻ�� �� �� ��
};

int main() {
	int card, user_in = 1;
	ATM atm;
	cout << "-------------------- ����˹��������ϵͳ --------------------" << endl;
	cout << "������ 1 ��Ῠ: "; cin >> card;



	while (user_in || user_in != 6)
	{
		cout << "3. Check money \n4. Money in\n5.Money out \n6.Card out\n"; cin >> user_in;

		switch (user_in)
		{
		case card_in:
			cout << "Password : "; cin >> user_in;
			cout << "3. Check money \n4. Money in\n5.Money out \n6.Card out\n"; cin >> user_in;
			break;
		case passw:
			break;
		case check_moey:
			cout << "Leave money: $ 233\n";
			cout << "3. Check money \n4. Money in\n5.Money out \n6.Card out\n"; cin >> user_in;
			break;
		case moey_in:
			cout << "How many : "; cin >> user_in;
			cout << "Ok, Money have in the Bank\n";
			cout << "3. Check money \n4. Money in\n5.Money out \n6.Card out\n"; cin >> user_in;
			break;
		case moey_out:
			cout << "How many : "; cin >> user_in;
			cout << "Ok, Money have out\n";
			cout << "3. Check money \n4. Money in\n5.Money out \n6.Card out\n"; cin >> user_in;
			break;
		case card_out:
			cout << "ByeBye.\n";
			break;
		default:
			cout << "���᲻�ᣬ�������" << endl;
			break;
		}
		cout << "3. Check money \n4. Money in\n5.Money out \n6.Card out\n"; cin >> user_in;
		continue;
	}




}