#include<iostream>
using namespace std;

class String
{
public:
	String(const char* string)
	{
		size_t lengthString = length(string);
		string_ = new char[lengthString + 1];
		for (int i = 0; i < lengthString; i++)
		{
			string_[i] = string[i];
		}
	}

	int calculateNumberOfoccurrences(char ch, String string_test)
	{
		int num_occurrences = 0;
		for (int i = 0; string_test.string_[i] != '\0'; i++)
		{
			if (string_test.string_[i] == ch) num_occurrences++;
		}
		cout << num_occurrences << endl;
		return num_occurrences;
	}

private:
	char* string_;

	size_t length(const char* str)
	{
		size_t i = 0;
		for (i = 0; str[i] != '\0'; i++);
		return i;
	}
};



int main()
{
	String string_test("asdfgfashsr");
	string_test.calculateNumberOfoccurrences('s', string_test);

}