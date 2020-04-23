#include <iostream>
using namespace std;
int main(void) {

	int N, blank, for_blank, star, for_star = 0;				// N--为输入的值，即为三角形的边长; blank--为应输入的空格, for_blank 为限制输出空格的数量

	cout << "N= "; cin >> N; cout << endl;
	for_blank = N;															// 将 N 的值赋给 for_star

	while (for_star != N) {

		for (blank = for_blank; blank > 0; blank--) {		//输出空格
			cout << " ";
		}

		for (star = 0; star <= for_star; star++) {			//输出 "* " ;	star 为每行打印的星星的数量; for_star 为限制输出 "* " 的数量
			cout << "* ";
		}

		cout << endl;
		for_star++, for_blank--;
	}
}