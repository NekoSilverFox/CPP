#include<iostream>
#include<fstream>
using namespace std;

void N2Arr(int x_rows, int y_cols) {

	// �����ڴ�
	int** n2Arr = new int* [x_rows];
	for (int i = 0; i < x_rows; i++)
		n2Arr[i] = new int[y_cols];


	// ��ʼ¼����ֵ
	for (int x = 0; x < x_rows; x++) {
		for (int y = 0; y < y_cols; y++) {
			cin >> n2Arr[x][y];
			cout << &n2Arr[x][y] << " ";
		}
		cout << endl;
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

	/*	1  2  3  4  5  6  7
		 |   |   |   |   |   |   |
	A-	4  5  7  0  8  2  1				4			5			7			0			8			2			1
	B-	2  3  6  4  9  5  7						4			3			6			4			9			5			7*						7 x 3  == (7 + 3) - 1 ==  9���Խ���
	C-	1  3  5  7  8  8  9								1			3			5			7			8			8*			9*
*/

// ��һ�����㣬�������ĶԽ���
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

	// �ڶ������㣬�����Ҳ�ĶԽ���
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

	// �Խ��ߵĸ���(������0) ����ݧڧ�֧��ӧ� �էڧѧԧ�ߧѧݧ֧�
	cout << "Numbers of diagonal (with out 0): " << num - 1 << endl;

	// ��̬����ռ�ǵ��ͷţ��������ͷš����ͷ�ÿһ��ָ��ĵ�ַ�ռ䣬Ȼ���ͷŴ��rowsάָ��Ŀռ�
	for (int j = 0; j < x_rows; j++)
		delete[] n2Arr[j];
	delete[] n2Arr;

}

int main() {

	// x_row - ��             y_cols - ��
	int x_rows, y_cols;
	cout << "Number of rows (x_rows): "; cin >> x_rows;
	cout << "Number of columns (y_cols): "; cin >> y_cols;
	
	N2Arr(x_rows, y_cols);

	cin.get();
	return EXIT_SUCCESS;
}