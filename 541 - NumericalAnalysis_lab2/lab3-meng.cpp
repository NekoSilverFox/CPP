#include <math.h>
#include <stdio.h>
#include "cmath.h"
#include <iostream>
using namespace std;

double x, y[], dydx[];
double a = 0, b = 1.6;
const int MAX_NUM_POINTS = 20000;
const int number_stating_points = 4;

int rkf(double input_h);
void adams_method(double input_h); //Adams

void lab3()
{
	rkf(0.08);
	adams_method(0.008);
	adams_method(0.001);
}


double adamsf0(double x, double y0, double y1)
{
	return(-44 * y0 - 160 * y1 + cos(1 + x));
}

double adamsf1(double x, double y0, double y1)
{
	return(y0 + atan(1 + x * x));
}


int f(int n, double x, double y[], double dydx[])
{
	dydx[0] = (-44 * y[0] - 160 * y[1] + cos(1 + x));
	dydx[1] = (y[0] + atan(1 + x * x));
	return (0);
}


int rkf(double input_h) //RKF45
{
	double  h, relerr, abserr, x1, x2;
	int     n, flag, nfe, maxfe, fail, step;
	double  y[2], yp[2];


	n = 2;
	flag = 1;
	maxfe = 5000;
	relerr = 1.0e-4;
	abserr = 1.0e-4;

	rkfinit(n, &fail);
	

	if (fail == 0){

		y[0] = 2.0;
		y[1] = 0.5;
		double t1 = 0.0, t2 = 0.0;
		double t_end = 1.6;
		size_t count = static_cast<size_t>((t_end - t1) / input_h);


		printf("       t      x[0]       x[1]\n");
		printf("-------------- rkf ----------------\n");

		while (t1 <= t_end) {
			t2 = t1 + input_h;
			rkf45(f, n, y, yp, &t1, t2, &relerr, abserr, &h, &nfe, maxfe, &flag);
			printf("%10.6f %10.6f %10.6f \n", t1, y[0], y[1]);
		}
		rkfend();
	}

	return (0);
}


void adams_method(double input_h) //Adams
{
	double  h, relerr, abserr, x1, x2;
	int     n, flag, nfe, maxfe, fail, step;
	double  y[2], yp[2];
	

	n = 2;
	flag = 1;
	maxfe = 5000;
	relerr = 1.0e-4;
	abserr = 1.0e-4;
	rkfinit(n, &fail);

	if (fail == 0)
	{
		y[0] = 2.0;
		y[1] = 0.5;
		double y0_adams[MAX_NUM_POINTS];
		double y1_adams[MAX_NUM_POINTS];
		const int number_points = (b - a) / input_h;

		printf("       t      x[0]       x[1]\n");
		cout << "------------- adams, h=" << input_h << " ---------------\n";
		x1 = a;
		x2 = a + input_h;
		y0_adams[0] = 2;
		y1_adams[0] = 0.5;

		for (int i = 1; i <= 3; i++)
		{
			rkf45(f, n, y, yp, &x1, x2, &relerr, abserr, &h, &nfe, maxfe, &flag);
			y0_adams[i] = y[0];
			y1_adams[i] = y[1];

			x1 = x2;
			x2 += input_h;
		}
		
		// 4-step Adams method
		for (int i = number_stating_points; i <= number_points; i++)
		{
			x2 = input_h * i;

			y0_adams[i] = 
				y0_adams[i - 1] + input_h / 24 * 
			 (55 * adamsf0(x2,									y0_adams[i - 1], y1_adams[i - 1]) -
				59 * adamsf0(x2 - input_h,			y0_adams[i - 2], y1_adams[i - 2]) +
				37 * adamsf0(x2 - 2 * input_h, y0_adams[i - 3], y1_adams[i - 3]) -
				 9 * adamsf0(x2 - 3 * input_h, y0_adams[i - 4], y1_adams[i - 4]));

			y1_adams[i] = 
				y1_adams[i - 1] + input_h / 24 * 
				 (55 * adamsf1(x2,									y0_adams[i - 1], y1_adams[i - 1]) -
					59 * adamsf1(x2 - input_h,			y0_adams[i - 2], y1_adams[i - 2]) +
					37 * adamsf1(x2 - 2 * input_h, y0_adams[i - 3], y1_adams[i - 3]) -
					 9 * adamsf1(x2 - 3 * input_h,	y0_adams[i - 4], y1_adams[i - 4]));
		}
		
		// output Adams result
		for (int i = 0; i <= number_points; i++)
		{
			x1 = input_h * i;
			printf("%10.6f %10.6f %10.6f \n", x1, y0_adams[i], y1_adams[i]);
		}
		
		rkfend();
	}

	return ;
}
