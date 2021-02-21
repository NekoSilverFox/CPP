#pragma once

int quanc8(double(*fun)(double x), double a, double b,
	double abserr, double relerr,
	double *resultR, double *errestR,
	int *nofunR,
	double *posnR, int *flag);

