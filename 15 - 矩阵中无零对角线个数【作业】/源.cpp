#include<iostream>
#include<fstream>
using namespace std;

void N2Arr(int x_rows, int y_cols) {

	// 申请内存
	int** n2Arr = new int* [x_rows];
	for (int i = 0; i < x_rows; i++)
		n2Arr[i] = new int[y_cols];


	// 开始录入数值
	for (int x = 0; x < x_rows; x++) {
		for (int y = 0; y < y_cols; y++) {
			cin >> n2Arr[x][y];
			cout << &n2Arr[x][y] << " ";
		}
		cout << endl;
	}

	// 打印测试
	cout << endl;
	for (int i = 0; i < x_rows; i++) {
		for (int j = 0; j < y_cols; j++) {
			cout << n2Arr[i][j] << " ";
		}
		cout << endl;
	}

	// 对角线的个数
	int num = x_rows + y_cols - 1;
	cout << "All the numbers of diagonal: " << num << endl;

	/*	1  2  3  4  5  6  7
		 |   |   |   |   |   |   |
	A-	4  5  7  0  8  2  1				4			5			7			0			8			2			1
	B-	2  3  6  4  9  5  7						4			3			6			4			9			5			7*						7 x 3  == (7 + 3) - 1 ==  9条对角线
	C-	1  3  5  7  8  8  9								1			3			5			7			8			8*			9*
*/

// 第一次运算，计算左侧的对角线
	for (int y = 0; y < y_cols - 1; y++) {
		for (int x = 0, for_y = y; x < x_rows && for_y >= 0; x++, for_y--) {
			if (n2Arr[x][for_y] == 0) {
				num--;
				break;
			}
			// cout << n2Arr[x][for_y];

		}
		// cout << endl;
	}

	// 第二次运算，计算右侧的对角线
	//			7*	
	//		8*		9*
	for (int y = y_cols - 1, x = 1, count = x_rows - 1; count > 0; count--, x++) {
		for (int x_right = x, for_y = y; x_right < x_rows; x_right++, for_y--) {
			if (n2Arr[x_right][for_y] == 0) {
				num--;
				break;
			}
			// cout << n2Arr[x_right][for_y];
		}
		// cout << endl;
	}

	// 对角线的个数(不包含0) Количество диагоналей
	cout << "Numbers of diagonal (with out 0): " << num - 1 << endl;

	// 动态申请空间记得释放，分两次释放。先释放每一行指针的地址空间，然后释放存放rows维指针的空间
	for (int j = 0; j < x_rows; j++)
		delete[] n2Arr[j];
	delete[] n2Arr;

}

int main() {

	// x_row - 行             y_cols - 列
	int x_rows, y_cols;
	cout << "Number of rows (x_rows): "; cin >> x_rows;
	cout << "Number of columns (y_cols): "; cin >> y_cols;
	
	N2Arr(x_rows, y_cols);

	cin.get();
	return EXIT_SUCCESS;
}