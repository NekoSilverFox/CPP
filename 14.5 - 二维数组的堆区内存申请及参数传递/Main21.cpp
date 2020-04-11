#include <conio.h>
#include <iostream>
#include <ctime>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

const int M = 2, N = 3;

void out2DArrayStatic(int array[][N], const int dimRows);
void out2DArrayStaticVer2(int* array, int dimRows, int dimColumns);

void in2DArray(int **array, int dimRows, int dimColumns);
void randomize2DArray(int **array, int dimRows, int dimColumns);
void out2DArray(int **array, int dimRows, int dimColumns);
void swapRows(int **array, int strNum1, int strNum2);
void cleanUp2DArray(int **array, int dimRows);

void in2DArray(int **array, int dimRows, int dimColumns) {
    cout << "Enter " + std::to_string(dimColumns) + " elements and press Enter" << endl;
    cout << "(" + std::to_string(dimRows) + " times)" << endl;
    for (int i = 0; i < dimRows; i++) {
        for (int j = 0; j < dimColumns; j++) {
            cin >> array[i][j];
            //array[i][j] == *(*(array + i) + j)
        }
    }
}

void randomize2DArray(int **array, int dimRows, int dimColumns) {
    srand(time(0));
    for (int i = 0; i < dimRows; i++) {
        for (int j = 0; j < dimColumns; j++) {
            array[i][j] = rand() % 10 + 1;
        }
    }
}

void out2DArray(int **array, int dimRows, int dimColumns) {
    for (int i = 0; i < dimRows; i++) {
        for (int j = 0; j < dimColumns; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void out2DArrayStatic(int array[][N], const int dimRows) {
    for (int i = 0; i < dimRows; i++) {
        for (int j = 0; j < N; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void out2DArrayStaticVer2(int *array, int dimRows, int dimColumns) {
    for (int i = 0; i < dimRows; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(array + i * dimColumns + j) << " "; //see Slide
        }
        cout << endl;
    }
}

void swapRows(int **array, int rowNum1, int rowNum2) {
    int *temp;
    temp = array[rowNum1];
    array[rowNum1] = array[rowNum2];
    array[rowNum2] = temp;
}

void cleanUp2DArray(int **array, int dimRows) {
    for (int i = 0; i < dimRows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    //static
    int dArr1[M][N] = { {1, 2, 3},
                        {4, 5, 6} };
    //const int dimDepth = 4;
    //int tArr[dimRows][dimColumns][dimDepth]; //3D
    cout << "Static array:" << endl;
    out2DArrayStatic(dArr1, M);
    cout << endl;
    out2DArrayStaticVer2(*dArr1, M, N);
    cout << "Dynamic array:" << endl;
    cout << "Enter numbers of rows and columns:\n";
    int dimRows, dimColumns;
    cin >> dimRows >> dimColumns;
    //dynamic
    int **ptrArr = new int *[dimRows]; //array of pointers to rows; column
    for (int i = 0; i < dimRows; i++) {
        ptrArr[i] = new int[dimColumns]; //ptrArr[i] == array name == pointer
        //*(ptrArr + i) == ptrArr[i]
    }
    in2DArray(ptrArr, dimRows, dimColumns);
    cout << "You entered:" << endl;
    out2DArray(ptrArr, dimRows, dimColumns);
    cout << "Randomizing array" << endl;
    randomize2DArray(ptrArr, dimRows, dimColumns);
    cout << "Result: " << endl;
    out2DArray(ptrArr, dimRows, dimColumns);
    int rowNum1, rowNum2;
    cout << "Enter rowNum1 and rowNum2 between 0 and " + std::to_string(dimRows - 1) << endl;
    cin >> rowNum1 >> rowNum2;
    swapRows(ptrArr, rowNum1, rowNum2);
    cout << "Result:" << endl;
    out2DArray(ptrArr, dimRows, dimColumns);
    cleanUp2DArray(ptrArr, dimRows);
    cout << "Cleaned up";
    _getch();
    return 0;
}