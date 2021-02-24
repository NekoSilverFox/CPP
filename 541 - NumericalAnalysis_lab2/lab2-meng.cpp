#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "cmath.h"
#include <iomanip>
#include <vector>

const int DIM_8 = 8;
double cond;
static int flag = -1;
int pivot[DIM_8];
std::ofstream out("lab2-result.txt");

double* minus(double* x1, double* x2)
{
	double* result = new double[DIM_8];
	for (int j = 0; j < 8; j++)
	{
		result[j] = fabs(x1[j] - x2[j]);
	}
	return result;
}

double get_relative_norm(double* x1, double* x2)
{
	double minus_norm = 0;
	double norm_x1 = 0;
	for (int j = 0; j < 8; j++)
	{
		minus_norm += fabs(x1[j] - x2[j]);
		norm_x1 += fabs(x1[j]);
	}
	return (minus_norm / norm_x1);
}


double* set_matrix_A(double p)
{

	double* retP = new double[64];

	retP[0] = p + 27; retP[1] = -6;  retP[2] = -1;  retP[3] = -6;  retP[4] = -3;  retP[5] = -4;  retP[6] = -3;  retP[7] = -4;
	retP[8] = -6;     retP[9] = 35;  retP[10] = -1; retP[11] = -6; retP[12] = -5; retP[13] = -6; retP[14] = -3; retP[15] = -8;
	retP[16] = -1;    retP[17] = -1; retP[18] = 19; retP[19] = -6; retP[20] = -8; retP[21] = -2; retP[22] = 0;  retP[23] = -1;
	retP[24] = -6;    retP[25] = -6; retP[26] = -6; retP[27] = 36; retP[28] = -4; retP[29] = -3; retP[30] = -4; retP[31] = -7;
	retP[32] = -3;    retP[33] = -5; retP[34] = -8; retP[35] = -4; retP[36] = 25; retP[37] = 0;  retP[38] = -1; retP[39] = -4;
	retP[40] = -4;    retP[41] = -6; retP[42] = -2; retP[43] = -3; retP[44] = 0;  retP[45] = 28; retP[46] = -8; retP[47] = -5;
	retP[48] = -3;    retP[49] = -3; retP[50] = 0;  retP[51] = -4; retP[52] = -1; retP[53] = -8; retP[54] = 21; retP[55] = -2;
	retP[56] = -4;    retP[57] = -8; retP[58] = -1; retP[59] = -7; retP[60] = -4; retP[61] = -5; retP[62] = -2; retP[63] = 31;

	return retP;
}

double* set_vector_b(double p)
{
	double* ret_b = new double[DIM_8];
	ret_b[0] = 8 * p + 140;
	ret_b[1] = -91;
	ret_b[2] = -7;
	ret_b[3] = 142;
	ret_b[4] = 7;
	ret_b[5] = -99;
	ret_b[6] = 25;
	ret_b[7] = -117;

	return ret_b;

}

void show_matrix(double* arr)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			out << std::scientific << std::setprecision(3) << setiosflags(std::ios::left);
			//out << std::setw(15) << arr[i * 8 + j];
			out << arr[i * 8 + j] << '\t';
		}
		out << std::endl;
	}
	out << std::endl;
}

void show_2d_array(double** arr)
{
	out << " before decomp, P1=\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			out << std::scientific << std::setprecision(3) << setiosflags(std::ios::left);
			out << std::setw(15) << arr[i][j];
		}
		out << std::endl;
	}
	out << std::endl;
}

void show_vector(double* v)
{
	for (int i = 0; i < 8; i++)
	{
		out << std::scientific << std::setprecision(3) << setiosflags(std::ios::left);
		// out << std::setw(15) << v[i];
		out << v[i] << '\n';
	}
	out << std::endl;
}

double* inv(double* arr)
{
	static int flag;
	int pivot[DIM_8];
	double* a_inv = new double[64];
	double b[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	decomp(DIM_8, DIM_8, arr, &cond, pivot, &flag);

	if (flag != 0)
	{
		out << "Fail to decompose!! flag =" << flag << "\n";
		return NULL;
	}

	for (int i = 0; i < DIM_8; i++)
	{
		b[i] = 1;
		solve(8, 8, arr, b, pivot);
		for (int j = 0; j < DIM_8; j++)
		{
			a_inv[j * 8 + i] = b[j];
			b[j] = 0;
		}
	}

	out << "A^-1:\n";
	show_matrix(a_inv);

	out << "cond(A^-1)=" << cond << "\n\n";

	return a_inv;
}

// matrix multiply by vector
double* multiply_by_vector(double* matrix, double* vec)
{
	double* result_vector = new double[DIM_8];

	double temp_element = 0;
	for (int i = 0; i < DIM_8; ++i)
	{
		temp_element = 0;
		for (int j = 0; j < DIM_8; ++j)
		{
			temp_element += matrix[i * DIM_8 + j] * vec[j];
		}
		result_vector[i] = temp_element;
	}

	return result_vector;
}

double* decomp_solve_2d(double matrix_A[][8], double* vec_b)
{

	decomp(DIM_8, DIM_8, *matrix_A, &cond, pivot, &flag);
	if (flag != 0)
	{
		out << "fail to decompose! flag=" << flag << '\n';
	}
	solve(8, 8, *matrix_A, vec_b, pivot);

	out << "x2(solution with decomp and solve)=\n";
	show_vector(vec_b);

	return vec_b;
}


void lab2()
{

	using std::endl;
	double cond = 0;

	double p1 = 1.0;
	double p2 = 0.1;
	double p3 = 0.01;
	double p4 = 0.0001;
	double p5 = 0.000001;

	double* b1 = set_vector_b(p1);
	double* b2 = set_vector_b(p2);
	double* b3 = set_vector_b(p3);
	double* b4 = set_vector_b(p4);
	double* b5 = set_vector_b(p5);

	double* A1 = set_matrix_A(p1);
	double* A2 = set_matrix_A(p2);
	double* A3 = set_matrix_A(p3);
	double* A4 = set_matrix_A(p4);
	double* A5 = set_matrix_A(p5);

	double P1[DIM_8][DIM_8] = {
	{p1 + 27, -6, -1, -6, -3,  -4, -3, -4},
	{-6,   35, -1, -6, -5,  -6, -3, -8,},
	{-1,   -1, 19, -6, -8,  -2,  0, -1,},
	{-6,   -6, -6, 36, -4,  -3, -4, -7,},
	{-3,   -5, -8, -4, 25,   0, -1, -4,},
	{-4,   -6, -2, -3,  0,  28,  -8, -5,},
	{-3,   -3,  0, -4, -1,  -8, 21, -2,},
	{-4,   -8, -1, -7, -4,  -5, -2, 31}
	};

	double P2[DIM_8][DIM_8] = {
  {p2 + 27, -6, -1, -6, -3,  -4, -3, -4},
  {-6,   35, -1, -6, -5,  -6, -3, -8,},
  {-1,   -1, 19, -6, -8,  -2,  0, -1,},
  {-6,   -6, -6, 36, -4,  -3, -4, -7,},
  {-3,   -5, -8, -4, 25,   0, -1, -4,},
  {-4,   -6, -2, -3,  0,  28,  -8, -5,},
  {-3,   -3,  0, -4, -1,  -8, 21, -2,},
  {-4,   -8, -1, -7, -4,  -5, -2, 31}
	};

	double P3[DIM_8][DIM_8] = {
  {p3 + 27, -6, -1, -6, -3,  -4, -3, -4},
  {-6,   35, -1, -6, -5,  -6, -3, -8,},
  {-1,   -1, 19, -6, -8,  -2,  0, -1,},
  {-6,   -6, -6, 36, -4,  -3, -4, -7,},
  {-3,   -5, -8, -4, 25,   0, -1, -4,},
  {-4,   -6, -2, -3,  0,  28,  -8, -5,},
  {-3,   -3,  0, -4, -1,  -8, 21, -2,},
  {-4,   -8, -1, -7, -4,  -5, -2, 31}
	};

	double P4[DIM_8][DIM_8] = {
  {p4 + 27, -6, -1, -6, -3,  -4, -3, -4},
  {-6,   35, -1, -6, -5,  -6, -3, -8,},
  {-1,   -1, 19, -6, -8,  -2,  0, -1,},
  {-6,   -6, -6, 36, -4,  -3, -4, -7,},
  {-3,   -5, -8, -4, 25,   0, -1, -4,},
  {-4,   -6, -2, -3,  0,  28,  -8, -5,},
  {-3,   -3,  0, -4, -1,  -8, 21, -2,},
  {-4,   -8, -1, -7, -4,  -5, -2, 31}
	};

	double P5[DIM_8][DIM_8] = {
  {p5 + 27, -6, -1, -6, -3,  -4, -3, -4},
  {-6,   35, -1, -6, -5,  -6, -3, -8,},
  {-1,   -1, 19, -6, -8,  -2,  0, -1,},
  {-6,   -6, -6, 36, -4,  -3, -4, -7,},
  {-3,   -5, -8, -4, 25,   0, -1, -4,},
  {-4,   -6, -2, -3,  0,  28,  -8, -5,},
  {-3,   -3,  0, -4, -1,  -8, 21, -2,},
  {-4,   -8, -1, -7, -4,  -5, -2, 31}
	};


	// output result
	out << "---------------------------- A1 * x = b1 ---------------------------------\n";
	out << "p1=" << p1 << "\n\n";
	out << "A1:\n";
	show_matrix(A1);

	double* invA1 = inv(A1);
	double* x1_1 = multiply_by_vector(invA1, b1);

	out << "x1(invA1*b1)=\n";
	show_vector(x1_1);

	double* x2_1 = decomp_solve_2d(P1, b1);

	out << "|x1-x2|=\n";
	show_vector(minus(x1_1, x2_1));

	out << "||x2-x1||/||x1||=" << get_relative_norm(x1_1, x2_1) << '\n';


	out << "---------------------------- A2 * x = b2 ---------------------------------\n";
	out << "p2=" << p2 << "\n\n";

	out << "A2:\n";
	show_matrix(A2);

	double* invA2 = inv(A2);
	double* x1_2 = multiply_by_vector(invA2, b2);

	out << "x1(invA2*b2)=\n";
	show_vector(x1_2);

	double* x2_2 = decomp_solve_2d(P2, b2);
	out << "|x1-x2|=\n";
	show_vector(minus(x1_2, x2_2));


	out << "||x2-x1||/||x1||=" << get_relative_norm(x1_2, x2_2) << '\n';


	out << "---------------------------- A3 * x = b3 ---------------------------------\n";
	out << "p3=" << p3 << "\n\n";

	out << "A3:\n";
	show_matrix(A3);

	double* invA3 = inv(A3);
	double* x1_3 = multiply_by_vector(invA3, b3);

	out << "x1(invA3*b3)=\n";
	show_vector(x1_3);

	double* x2_3 = decomp_solve_2d(P3, b3);
	out << "|x1-x2|=\n";
	show_vector(minus(x1_3, x2_3));


	out << "||x2-x1||/||x1||=" << get_relative_norm(x1_3, x2_3) << '\n';



	out << "---------------------------- A4 * x = b4 ---------------------------------\n";
	out << "p4=" << p4 << "\n\n";

	out << "A4:\n";
	show_matrix(A4);

	double* invA4 = inv(A4);
	double* x1_4 = multiply_by_vector(invA4, b4);

	out << "x1(invA4*b4)=\n";
	show_vector(x1_4);

	double* x2_4 = decomp_solve_2d(P4, b4);
	out << "|x1-x2|=\n";
	show_vector(minus(x1_4, x2_4));


	out << "||x2-x1||/||x1||=" << get_relative_norm(x1_4, x2_4) << '\n';


	out << "---------------------------- A5 * x = b5 ---------------------------------\n";
	out << "p5=" << p5 << "\n\n";

	out << "A5:\n";
	show_matrix(A5);

	double* invA5 = inv(A5);
	double* x1_5 = multiply_by_vector(invA5, b5);

	out << "x1(invA5*b5)=\n";
	show_vector(x1_5);

	double* x2_5 = decomp_solve_2d(P5, b5);
	out << "|x1-x2|=\n";
	show_vector(minus(x1_5, x2_5));

	out << "||x2-x1||/||x1||=" << get_relative_norm(x1_5, x2_5) << '\n';
}

