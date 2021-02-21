#ifndef _SPLINES
 #define _SPLINES

	void spline(int n,double * x,double * y,double * b,double * c,double * d);

	double seval(int n, double * u,
		 double * x,double * y,double * b,double * c,
		 double * d);

#endif