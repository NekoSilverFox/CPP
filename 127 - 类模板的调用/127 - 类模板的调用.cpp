#include<iostream>
using namespace std;

template<typename T1, typename T2>
class A
{
public:
	A(T1 a, T2 b)
	{}

	T1 t1;
	T2 t2;
};

int main()
{
	A<float, int> B(0.1, 0);
	A<2, 'a'> B(int, char);
	A<T1, T2> B(T1, T2);
	A<int, char> B(2, 'a');
	A<a, b> B(5, 3);
	A<bool, bool> B(true, false);
}