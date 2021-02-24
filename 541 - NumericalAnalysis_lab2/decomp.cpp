//head	1.1;
//access;
//symbols;
//locks; strict;
//comment	@ * @;
//
//
//1.1
//date	98.08.08.11.36.05;	author peterj;	state Exp;
//branches;
//next	;
//
//
//desc
//@CMATH 1989 code
//@
//
//
//1.1
//log
//@Initial revision
//@
//text
//@/* decomp.c
//   Matrix decomposition by Gaussian elimination */

/************************************************/
/*                                              */
/*  CMATH.  Copyright (c) 1989 Design Software  */
/*                                              */
/************************************************/

#include "cmath.h"
#if (STDLIBH)
#include <stdlib.h>
#endif
#include <stdio.h>
#include <math.h>

#ifndef NULL
#define  NULL  0
#endif


/*-----------------------------------------------------------------*/

#if (PROTOTYPE)

int decomp (int n, int ndim,
            double *a, double *cond,
            int pivot[], int *flag)

#else

int decomp (n, ndim, a, cond, pivot, flag)

int    n,
       ndim;
double *a,
       *cond;
int    pivot[],
       *flag;

#endif

/* Purpose ...
   -------
   Decomposes a real matrix by gaussian elimination
   and estimates the condition of the matrix.

   Use Solve to compute solutions to linear systems.

   Input ...
   -----
   n    = order of the matrix
   ndim = row dimension of matrix as defined in the calling program
   *a   = pointer to matrix to be triangularized

   Output ...
   ------
   *a          pointer to  an upper triangular matrix U and a
	       permuted version of a lower triangular matrix I-L
	       so that
	       (permutation matrix) * a = L * U
   cond      = an estimate of the condition of a .
	       For the linear system a * x = b, changes in a and b
	       may cause changes cond times as large in x.
	       If cond+1.0 .eq. cond , a is singular to working
	       precision, cond is set to 1.0e+32 if exact (or near)
	       singularity is detected.
   pivot     = the pivot vector.
   pivot[k]  = the index of the k-th pivot row
   pivot[n-1]= (-1)**(number of interchanges)
   flag      = Status indicator
               0 : successful execution
               1 : could not allocate memory for workspace
               2 : illegal user input n < 1, a == NULL,
                   pivot == NULL, n > ndim.
               3 : matrix is singular

   Work Space ...
   ----------
   The vector work[0..n] is allocated internally by decomp().

   This C code written by ...  Peter & Nigel,
   ----------------------      Design Software,
                               42 Gubberley St,
                               Kenmore, 4069,
                               Australia.

   Version  ... 1.1 ,  2-Dec-87
   -------      2.0 , 11-Feb-89  (pointer used for a)
                2.1 , 15-Apr-89  (work[] allocated internally)
                2.2 , 14-Aug-89  (fixed pivoting)
                2.3 , 3 -Sep-89  (face lift)
                3.0 , 30-Sep-89  (optimize for rowwise storage)

   Notes ...
   -----
   (1) Subscripts range from 0 through (ndim-1).

   (2) The determinant of a can be obtained on output by
       det(a) = pivot[n-1] * a[0][0] * a[1][1] * ... * a[n-1][n-1].

   (3) This routine has been adapted from that in the text
       G.E. Forsythe, M.A. Malcolm & C.B. Moler
       Computer Methods for Mathematical Computations.

   (4) Uses the functions fabs(), free() and malloc().
*/

#define AINDEX(i,j) (i * ndim + j)

{   /* --- function decomp() --- */

double ek, t, pvt, anorm, ynorm, znorm;
int    i, j, k, m;
double *pa, *pb;      /* temporary pointers */
double *work;

*flag = 0;
work = (double *) NULL;

if (a == NULL || pivot == NULL || n < 1 || ndim < n)
   {
   *flag = 2;
   return (0);
   }

pivot[n-1] = 1;
if (n == 1)
   {
   /* One element only */
   *cond = 1.0;
   if (*a == 0.0)
      {
      *cond = 1.0e+32;  /* singular */
      *flag = 3;
      return (0);
      }
   return (0);
   }

work = (double *) malloc(n * sizeof(double));
if (work == NULL)
   {
   *flag = 1;
   return (0);
   }

/* --- compute 1-norm of a --- */

anorm = 0.0;
for (j = 0; j < n; ++j)
   {
   t = 0.0;
   for (i = 0; i < n; ++i) t += fabs(a[AINDEX(i,j)]);
   if (t > anorm) anorm = t;
   }

/* Apply Gaussian elimination with partial pivoting. */

for (k = 0; k < n-1; ++k)
   {
   /* Find pivot and label as row m.
      This will be the element with largest magnitude in
      the lower part of the kth column. */
   m = k;
   pvt = fabs(a[AINDEX(m,k)]);
   for (i = k+1; i < n; ++i)
      {
      t = fabs(a[AINDEX(i,k)]);
      if ( t > pvt )  { m = i; pvt = t; }
      }
   pivot[k] = m;
   pvt = a[AINDEX(m,k)];

   if (m != k)
      {
      pivot[n-1] = -pivot[n-1];
   /* Interchange rows m and k for the lower partition. */
   for (j = k; j < n; ++j)
      {
      pa = a+AINDEX(m,j); pb = a+AINDEX(k,j);
      t = *pa; *pa = *pb; *pb = t;
      }
   }
   /* row k is now the pivot row */

   /* Bail out if pivot is too small */
   if (fabs(pvt) < anorm * EPSILON)
      {
      /* Singular or nearly singular */
      *cond = 1.0e+32;
      *flag = 3;
      goto DecompExit;
      }

   /* eliminate the lower matrix partition by rows
      and store the multipliers in the k sub-column */
   for (i = k+1; i < n; ++i)
      {
      pa = a+AINDEX(i,k);          /* element to eliminate */
      t = -( *pa / pvt );          /* compute multiplier   */
      *pa = t;                     /* store multiplier     */
      for (j = k+1; j < n; ++j)    /* eliminate i th row */
         {
         if (fabs(t) > anorm * EPSILON)
	    a[AINDEX(i,j)] += a[AINDEX(k,j)] * t;
         }
      }

   }  /* End of Gaussian elimination. */

/* cond = (1-norm of a)*(an estimate of 1-norm of a-inverse)
   estimate obtained by one step of inverse iteration for the
   small singular vector. This involves solving two systems
   of equations, (a-transpose)*y = e and a*z = y where e
   is a vector of +1 or -1 chosen to cause growth in y.
   estimate = (1-norm of z)/(1-norm of y)

   Solve (a-transpose)*y = e   */

for (k = 0; k < n; ++k)
   {
   t = 0.0;
   if (k != 0)
      {
      for (i = 0; i < k; ++i)  t += a[AINDEX(i,k)] * work[i];
      }
   if (t < 0.0) ek = -1.0; else  ek = 1.0;
   pa = a+AINDEX(k,k);
   if (fabs(*pa) < anorm * EPSILON)
      {
      /* Singular */
      *cond = 1.0e+32;
      *flag = 3;
      goto DecompExit;
      }

   work[k] = -(ek + t) / *pa;
   }

for (k = n-2; k >= 0; --k)
   {
   t = 0.0;
   for (i = k+1; i < n; i++)
      t += a[AINDEX(i,k)] * work[i];
      /* we have used work[i] here, however the use of work[k]
	 makes some difference to cond */
   work[k] = t;
   m = pivot[k];
   if (m != k) { t = work[m]; work[m] = work[k]; work[k] = t; }
   }

ynorm = 0.0;
for (i = 0; i < n; ++i) ynorm += fabs(work[i]);

/* --- solve a * z = y */
solve (n, ndim, a, work, pivot);

znorm = 0.0;
for (i = 0; i < n; ++i) znorm += fabs(work[i]);

/* --- estimate condition --- */
*cond = anorm * znorm / ynorm;
if (*cond < 1.0) *cond = 1.0;
if (*cond + 1.0 == *cond) *flag = 3;

DecompExit:
if (work != NULL) { free (work); work = (double *) NULL; }
return (0);
}   /* --- end of function decomp() --- */

/*-----------------------------------------------------------------*/

#if (PROTOTYPE)

int solve (int n, int ndim,
           double *a, double b[],
           int pivot[])

#else

int solve (n, ndim, a, b, pivot)

int    n,
       ndim,
       pivot[];
double *a,
       b[];

#endif

/* Purpose :
   -------
   Solution of linear system, a * x = b.
   Do not use if decomp() has detected singularity.

   Input..
   -----
   n     = order of matrix
   ndim  = row dimension of a
   a     = triangularized matrix obtained from decomp()
   b     = right hand side vector
   pivot = pivot vector obtained from decomp()

   Output..
   ------
   b = solution vector, x

*/

{   /* --- begin function solve() --- */

int    i, j, k, m;
double t;

if (n == 1)
   {
   /* trivial */
   b[0] /= a[0];
   }
else
   {
   /* Forward elimination: apply multipliers. */
   for (k = 0; k < n-1; k ++)
      {
      m = pivot[k];
      t = b[m]; b[m] = b[k]; b[k] = t;
      for (i = k+1; i < n; ++i) b[i] += a[AINDEX(i,k)] * t;
      }

   /* Back substitution. */
   for (k = n-1; k >= 0; --k)
      {
      t = b[k];
      for (j = k+1; j < n; ++j) t -= a[AINDEX(k,j)] * b[j];
      b[k] = t / a[AINDEX(k,k)];
      }
   }

return(0);
}  /* --- end function solve() --- */

/*-----------------------------------------------------------------*/

//@
