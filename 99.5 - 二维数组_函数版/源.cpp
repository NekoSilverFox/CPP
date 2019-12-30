#include<iostream>
using namespace std;

// x_row - 行             y_cols - 列
int x_rows, y_cols;
int** n2Arr = new int* [x_rows];

void XY_get() {
	cout << "Number of rows (x_rows): "; cin >> x_rows;
	cout << "Number of columns (y_cols): "; cin >> y_cols;
}

void memory_get() {
	// 申请内存
	for (int i = 0; i < x_rows; i++)
		n2Arr[i] = new int[y_cols];
}

void function() {
	// 开始录入数值
	for (int x = 0; x < x_rows; x++) {
		for (int y = 0; y < y_cols; y++) {
			cin >> n2Arr[x][y];
		}
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
	// 第一次运算，计算左侧的对角线
	for (int y = 0; y < y_cols - 1; y++) {
		for (int x = 0, for_y = y; x < x_rows && for_y >= 0; x++, for_y--) {
			if (n2Arr[x][for_y] == 0) {
				num--;
				break;
			}
		}
	}

	for (int y = y_cols - 1, x = 1, count = x_rows - 1; count > 0; count--, x++) {
		for (int x_right = x, for_y = y; x_right < x_rows; x_right++, for_y--) {
			if (n2Arr[x_right][for_y] == 0) {
				num--;
				break;
			}
		}
	}

	// 对角线的个数(不包含0) Количество диагоналей
	cout << "Numbers of diagonal (with out 0): " << num - 1 << endl;

}

void memory_delete() {
	for (int j = 0; j < x_rows; j++)
		delete[] n2Arr[j];
	delete[] n2Arr;
}


int main() {

	XY_get();
	memory_get();
	function();
	memory_delete();
	
	cin.get();
	return EXIT_SUCCESS;
}