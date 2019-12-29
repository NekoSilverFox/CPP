#include <iostream>
using namespace std;
int main(void)

{
	int limit;
	cout << "请输入初始值：" ;
		cin >> limit;
		int i;
		for (i = limit; i; i--)
			cout << "i=" << i << "\n";
		cout << "现在结束输出，此时i=" << i << "\n";
		return 0;

}