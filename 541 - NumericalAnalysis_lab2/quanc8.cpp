#include <math.h>

int quanc8(double(*fun)(double x), double a, double b,
	double abserr, double relerr,
	double *resultR, double *errestR,
	int *nofunR,
	double *posnR, int *flag)

{  /* begin function quanc8 */

   /* this code has been translated from fortran, hence use
   elements 1 .. n */
	double w0, w1, w2, w3, w4, area, x0, f0, stone, step, cor11;
	double qprev, qnow, qdiff, qleft, esterr, tolerr;
	static double qright[32], f[17], x[17], fsave[9][31];
	static double xsave[9][31];
	double posn, result, errest;
	double temp, temp1;
	int nofun;
	int levmin, levmax, levout, nomax, nofin, lev, nim, i, j, ii;

	/* check user input */
	if (abserr < 0.0 || relerr < 0.0)
	{
		*flag = 1;
		*resultR = 0.0;
		*errestR = 0.0;
		*posnR = 0.0;
		*nofunR = 0;
		return (0);
	}

	/*  ***  stage 1 ***  general initialization
	set constants.  */
	levmin = 1;
	levmax = 30;
	levout = 6;
	nomax = 5000;

	{
		ii = 1;
		for (i = 0; i <= levout; i++) ii *= 2;
	} /* ---> ii = 2 ** (levout+1) */
	nofin = nomax - 8 * (levmax - levout + ii);
	/* note that there will be trouble when nofun reaches nofin */

	temp = 14175.0;
	w0 = 3956.0 / temp;
	w1 = 23552.0 / temp;
	w2 = -3712.0 / temp;
	w3 = 41984.0 / temp;
	w4 = -18160.0 / temp;

	/* initialize running sums to zero. */
	*flag = 0;
	posn = 0.0;
	result = 0.0;
	cor11 = 0.0;
	errest = 0.0;
	area = 0.0;
	nofun = 0;
	if (a == b) goto ExitQuanc8;

	/* ***  stage 2 ***  initialization for first interval */
	lev = 0;
	nim = 1;
	x0 = a;
	x[16] = b;
	qprev = 0.0;

	/* set up evenly spaced panels */
	f0 = (*fun) (x0);
	stone = (b - a) / 16.0;
	x[8] = 0.5 * (x0 + x[16]);
	x[4] = 0.5 * (x0 + x[8]);
	x[12] = 0.5 * (x[8] + x[16]);
	x[2] = 0.5 * (x0 + x[4]);
	x[6] = 0.5 * (x[4] + x[8]);
	x[10] = 0.5 * (x[8] + x[12]);
	x[14] = 0.5 * (x[12] + x[16]);
	for (j = 2; j <= 16; j = j + 2)  f[j] = (*fun) (x[j]);
	nofun = 9;

	/* ***  stage 3 ***  central calculation
	requires qprev,x0,x2,x4,...,x16,f0,f2,f4,...,f16.
	calculates x1,x3,...x15, f1,f3,...f15,qleft,qright,qnow,qdiff,area.
	*/
Stage3:
	x[1] = 0.5 * (x0 + x[2]);
	f[1] = (*fun) (x[1]);
	for (j = 3; j <= 15; j = j + 2)
	{
		x[j] = 0.5 * (x[j - 1] + x[j + 1]);
		f[j] = (*fun) (x[j]);
	}
	nofun += 8;
	step = (x[16] - x0) / 16.0;
	qleft = (w0 * (f0 + f[8]) + w1 * (f[1] + f[7]) + w2 * (f[2] + f[6])
		+ w3 * (f[3] + f[5]) + w4 * f[4]) * step;
	qright[lev + 1] = (w0 * (f[8] + f[16]) + w1 * (f[9] + f[15]) + w2 * (f[10] + f[14])
		+ w3 * (f[11] + f[13]) + w4 * f[12]) * step;
	qnow = qleft + qright[lev + 1];
	qdiff = qnow - qprev;
	area += qdiff;

	/* ***  stage 4 *** interval convergence test */
	esterr = fabs(qdiff) / 1023.0;
	{
		tolerr = abserr;
		temp = relerr * fabs(area);
		if (temp > tolerr) tolerr = temp;
	}  /* ---> tolerr = max(abserr, relerr * abs(area)) */
	tolerr *= (step / stone);

	if (lev < levmin)     goto Stage5;  /* keep subdividing               */
	if (lev >= levmax)    goto Stage6B; /* too many nested levels         */
	if (nofun > nofin)    goto Stage6;  /* close to limit on fn calls     */
	if (esterr <= tolerr) goto Stage7;  /* this interval has converged    */

										/* ***  stage 5  ***  no convergence
										locate next interval.             */
Stage5:
	nim *= 2;
	++lev;

	/* store right hand elements for future use. */
	for (i = 1; i <= 8; i++)
	{
		fsave[i][lev] = f[i + 8];
		xsave[i][lev] = x[i + 8];
	}

	/* assemble left hand elements for immediate use. */
	qprev = qleft;
	for (i = 1; i <= 8; i++)
	{
		j = (-i);
		f[2 * j + 18] = f[j + 9];
		x[2 * j + 18] = x[j + 9];
	}

	goto Stage3;

	/* ***  stage 6  ***  trouble section
	number of function values is about to exceed limit.  */
Stage6:
	nofin *= 2;
	levmax = levout;
	posn = x0;   /* this is our trouble spot */
	goto Stage7;

	/* current level is levmax. */
Stage6B:
	--(*flag);   /* another interval has not converged */

				 /* ***  stage 7  ***  interval converged
				 add contributions into running sums.  */
Stage7:
	result += qnow;
	errest += esterr;
	cor11 += qdiff / 1023.0;

	/* locate next interval. */
	while (nim != (2 * (nim / 2)))
	{
		nim /= 2;
		--lev;
	}
	++nim;
	if (lev <= 0) goto Stage8;

	/* assemble elements required for the next interval. */
	qprev = qright[lev];
	x0 = x[16];
	f0 = f[16];
	for (i = 1; i <= 8; i++)
	{
		f[2 * i] = fsave[i][lev];
		x[2 * i] = xsave[i][lev];
	}
	goto Stage3;

	/* ***  stage 8  ***  finalize and return */
Stage8:
	result += cor11;

	/* make sure errest not less than roundoff level. */
	if (errest == 0.0) goto ExitQuanc8;
	temp1 = fabs(result);
	temp = temp1 + errest;
	while (temp == temp1)
	{
		errest *= 2.0;
		temp = temp1 + errest;
	}

ExitQuanc8:
	/* --- return variables --- */
	*resultR = result;
	*errestR = errest;
	*posnR = posn;
	*nofunR = nofun;
	return (0);
}  /* end of quanc8() */