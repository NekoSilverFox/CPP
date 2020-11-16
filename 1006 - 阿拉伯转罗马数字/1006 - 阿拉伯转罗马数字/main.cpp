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

string intToRoman3(int num)
{
    const char* arr1[10] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
    const char* arr2[10] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
    const char* arr3[10] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
    const char* arr4[4] = { "","M","MM","MMM" };

    string roman;
    roman.append(arr4[num / 1000 % 10]);
    roman.append(arr3[num / 100 % 10]);
    roman.append(arr2[num / 10 % 10]);
    roman.append(arr1[num % 10]);

    return roman;
}

int main()
{
    cout << intToRoman3(4999) << endl
        << intToRoman3(6000) << endl
        << intToRoman3(7000) << endl
        << intToRoman3(8000) << endl
        << intToRoman3(9000) << endl
        << intToRoman3(9999) << endl
        << intToRoman3(99) << endl;

    cout << "============" << endl;

    //cout << intToRoman2(0) << endl
    //    << intToRoman2(1) << endl
    //    << intToRoman2(2) << endl
    //    << intToRoman2(5) << endl
    //    << intToRoman2(10) << endl
    //    << intToRoman2(99) << endl;

    //cout << "============" << endl;

    //cout << intToRoman3(0) << endl
    //    << intToRoman3(1) << endl
    //    << intToRoman3(2) << endl
    //    << intToRoman3(5) << endl
    //    << intToRoman3(10) << endl
    //    << intToRoman3(9999) << endl;

}