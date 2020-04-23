#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
const char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
const char letters[9] = { 'a','b','c','d','e','f','x','y','z' };
bool statement(string s);
bool num(string s);
bool ind(char c);
bool mult(string s);
bool term(string s);

int main()
{
	int n = 0;
	std::ifstream file;
	file.open("input.txt");
	file >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		file >> s;
		if (statement(s))
		{
			cout << "Да" << endl;
		}
		else
		{
			cout << "Нет" << endl;
		}
	}
	return 0;
}

bool statement(string s)
{
	long int d = s.length();
	if (term(s))
	{
		return true;
	}
	else if (s[0] == '(')
	{
		int t = -1;
		int braketo = 0;
		int braketc = 0;
		for (int i = 0; i < d; i++)
		{
			if (s[i] == '(')
			{
				braketo++;
			}
			if (s[i] == ')')
			{
				braketc++;
			}
			if (braketo == braketc)
			{
				t = i;
				break;
			}
		}
		if (t == d - 1)
		{
			return statement(s.substr(1, d - 2));
		}
		if (t != -1)
		{
			if (term(s.substr(0, t + 1)) && statement(s.substr(t + 2, d - t - 1)) && (s[t + 1] == '+' || s[t + 1] == '-'))
			{
				return true;
			}
		}
	}
	else
	{
		int t = -1;
		for (int i = 0; i < d; i++)
		{
			if (s[i] == '+' || s[i] == '-')
			{
				t = i;
				break;
			}
		}
		if (t != -1)
		{
			if (term(s.substr(0, t)) && statement(s.substr(t + 1, d - t)))
			{
				return true;
			}
		}
	}
	return false;
}

bool num(string s)
{
	long int d = s.length();
	int check = 0;
	for (char i : s)
	{
		for (char n : numbers)
		{
			if (i == n)
			{
				check++;
				break;
			}
		}
	}
	return d == check;
}

bool ind(char c)
{
	for (char l : letters)
	{
		if (c == l)
		{
			return true;
		}
	}
	return  false;
}

bool mult(string s)
{
	long int d = s.length();
	if (num(s) || (ind(s[0]) && d == 1) || (s[0] == '(' && statement(s.substr(1, d - 2)) && s[d - 1] == ')'))
	{
		return true;
	}
	else
		return false;
}

bool term(string s)
{
	long int d = s.length();
	if (mult(s))
	{
		return true;
	}
	else if (s[0] == '(' && s[d - 1] == ')')
	{
		int t = -1;
		int braketo = 0;
		int braketc = 0;
		if (s[1] == '(')
		{
			for (int i = 1; i < d - 1; i++)
			{
				if (s[i] == '(')
				{
					braketo++;
				}
				if (s[i] == ')')
				{
					braketc++;
				}
				if (braketo == braketc)
				{
					t = i;
					break;
				}
			}
		}
		if (t == -1)
		{
			for (int i = 0; i < d; i++)
			{
				if (s[i] == '*' || s[i] == '/')
				{
					t = i;
					break;
				}
			}
			if (mult(s.substr(1, t - 1)) && term(s.substr(t + 1, d - t - 2)))
			{
				return true;
			}
		}
		else if (t == d - 2)
		{
			return term(s.substr(1, d - 2));
		}
		else if (t != -1)
		{
			if (mult(s.substr(1, t)) && term(s.substr(t + 2, d - t - 2)) && (s[t + 1] == '*' || s[t + 1] == '/'))
			{
				return true;
			}
		}
	}
	return false;
}