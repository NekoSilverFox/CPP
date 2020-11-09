#include <iostream>
using namespace std;

string intToRoman(int num)
{
    const char* c[4][10] = {
        {"","I","II","III","IV","V","VI","VII","VIII","IX"},
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"","M","MM","MMM"}
    };
    string roman;
    roman.append(c[3][num / 1000 % 10]);
    roman.append(c[2][num / 100 % 10]);
    roman.append(c[1][num / 10 % 10]);
    roman.append(c[0][num % 10]);

    return roman;
}

string intToRoman2(int num)
{
    const char* c[40] =
    {
        "","I","II","III","IV","V","VI","VII","VIII","IX",
        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
        "","M","MM","MMM"
    };
    string roman;
    roman.append(c[3 * 10 + num / 1000 % 10]);
    roman.append(c[2 * 10 + num / 100 % 10]);
    roman.append(c[1 * 10 + num / 10 % 10]);
    roman.append(c[0 * 10 + num % 10]);

    return roman;
}

int main()
{
    cout << intToRoman(0) << endl
        << intToRoman(1) << endl
        << intToRoman(2) << endl
        << intToRoman(5) << endl
        << intToRoman(10) << endl
        << intToRoman(11) << endl;

    cout << "============" << endl;

    cout << intToRoman2(0) << endl
        << intToRoman2(1) << endl
        << intToRoman2(2) << endl
        << intToRoman2(5) << endl
        << intToRoman2(10) << endl
        << intToRoman2(11) << endl;

}