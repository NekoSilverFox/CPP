#include"Person.hpp"

// C++ 是做单元编译的！！！
// 建议将声明放在头文件中，然后将 .h 变为 .hpp
int main()
{
	Person<string, int> p("Juddy", 12);
	p.showPerson();
}