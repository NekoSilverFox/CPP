#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isRightSign(string, int);
bool isRightNumber(string, int);
bool isRightRealNumber(string);
bool isRightOrder(string);
bool isRightMantissa(string);

int main()
{
	setlocale(LC_ALL, "RUS");
	fstream input("input.txt", ios::in);
	string inputstring;
	getline(input, inputstring);
	input.close();
	if (isRightRealNumber(inputstring) == true) cout << "ÄÀ";
	else cout << "ÍÅÒ";
	return 0;
}

bool isRightRealNumber(string inputstring)
{
	if (isRightOrder(inputstring) == true and isRightMantissa(inputstring) == true) return true;
	else return false;
}
bool isRightOrder(string inputstring)
{
	int p = 0;
	while (inputstring[p] != 'E' and inputstring.size() > p)
	{
		p++;
	}
	if (inputstring[p] != 'E') return false;
	p++;
	if (isRightSign(inputstring, p) == true and isRightNumber(inputstring, p) == true) return true;
	else return false;

}
bool isRightSign(string inputstring, int p)
{
	if (!(inputstring[p] == '+' or inputstring[p] == '-')) return false;
	else return true;
}

bool isRightNumber(string inputstring, int p)
{
	if (p == -2)
	{
		bool test = false;
		int p1 = 0;
		while (inputstring[p1] != '.')
		{
			if (!(inputstring[p1] == '0' or
				inputstring[p1] == '1' or
				inputstring[p1] == '2' or
				inputstring[p1] == '3' or
				inputstring[p1] == '4' or
				inputstring[p1] == '5' or
				inputstring[p1] == '6' or
				inputstring[p1] == '7' or
				inputstring[p1] == '8' or
				inputstring[p1] == '9')) return false;
			p1++;
		}
		p1++;
		while (inputstring[p1] != 'E')
		{
			if (!(inputstring[p1] == '0' or
				inputstring[p1] == '1' or
				inputstring[p1] == '2' or
				inputstring[p1] == '3' or
				inputstring[p1] == '4' or
				inputstring[p1] == '5' or
				inputstring[p1] == '6' or
				inputstring[p1] == '7' or
				inputstring[p1] == '8' or
				inputstring[p1] == '9')) return false;
			else test = true;
			p1++;
		}
		return test;
	}

	else
	{
		if (p == -1)
		{
			int p1 = 1;
			bool test = false;
			while (inputstring[p1] != 'E')
			{
				if (!(inputstring[p1] == '0' or
					inputstring[p1] == '1' or
					inputstring[p1] == '2' or
					inputstring[p1] == '3' or
					inputstring[p1] == '4' or
					inputstring[p1] == '5' or
					inputstring[p1] == '6' or
					inputstring[p1] == '7' or
					inputstring[p1] == '8' or
					inputstring[p1] == '9')) return false;
				else test = true;
				p1++;
			}
			return test;
		}
		else
		{
			bool test = false;
			for (int i = p + 1; i < inputstring.size(); i++)
			{
				if (!(inputstring[i] == '0' or
					inputstring[i] == '1' or
					inputstring[i] == '2' or
					inputstring[i] == '3' or
					inputstring[i] == '4' or
					inputstring[i] == '5' or
					inputstring[i] == '6' or
					inputstring[i] == '7' or
					inputstring[i] == '8' or
					inputstring[i] == '9')) return false;
				else test = true;
			}
			return test;
		}
	}
}
bool isRightMantissa(string inputstring)
{
	if (inputstring[0] == '.' and isRightNumber(inputstring, -1) == true) return true;
	else if (isRightNumber(inputstring, -2) == true) return true;
	else return false;
}