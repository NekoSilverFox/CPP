#include<iostream>
using namespace std;

// x_row - ��             y_cols - ��
int x_rows, y_cols;
int** n2Arr = new int* [x_rows];

void XY_get() {
	cout << "Number of rows (x_rows): "; cin >> x_rows;
	cout << "Number of columns (y_cols): "; cin >> y_cols;
}

void memory_get() {
	// �����ڴ�
	for (int i = 0; i < x_rows; i++)
		n2Arr[i] = new int[y_cols];
}

void function() {
	// ��ʼ¼����ֵ
	for (int x = 0; x < x_rows; x++) {
		for (int y = 0; y < y_cols; y++) {
			cin >> n2Arr[x][y];
		}
	}

	// ��ӡ����
	cout << endl;
	for (int i = 0; i < x_rows; i++) {
		for (int j = 0; j < y_cols; j++) {
			cout << n2Arr[i][j] << " ";
		}
		cout << endl;
	}

	// �Խ��ߵĸ���
	int num = x_rows + y_cols - 1;
	cout << "All the numbers of diagonal: " << num << endl;
	// ��һ�����㣬�������ĶԽ���
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

	// �Խ��ߵĸ���(������0) ����ݧڧ�֧��ӧ� �էڧѧԧ�ߧѧݧ֧�
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