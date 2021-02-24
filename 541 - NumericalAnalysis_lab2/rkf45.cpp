/* rkf45.c
   ODE integration using Fehlberg Fourth-Fifth Order Runge-Kutta Method.
*/

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

/* global definitions */

static double *F1, *F2, *F3, *F4, *F5, *SAVRE, *SAVAE;
static int    *KOP, *INIT, *JFLAG, *KFLAG;

/*-----------------------------------------------------------------*/

#if (PROTOTYPE)

int rkfinit (int NEQN, int *fail)

#else

int rkfinit (NEQN, fail)
int NEQN, *fail;

#endif

/* Purpose...
   -------
   This routine allocates the work space and must be called
   before using rkf45().

   Input ...
   -----
   NEQN  : Number of ODE's

   Output ...
   ------
   fail  : Status indicator
           = 0 : successful allocation of workspace
           = 1 : could not allocate memory for workspace
           = 2 : illegal value for NEQN (i.e. < 1)
   */

{
*fail = 0;

if (NEQN <= 0)
   {
   *fail = 2;
   return (0);
   }

KOP = (int *) NULL;
INIT = (int *) NULL;
JFLAG = (int *) NULL;
KFLAG = (int *) NULL;
SAVRE = (double *) NULL;
SAVAE = (double *) NULL;
F1 = (double *) NULL;
F2 = (double *) NULL;
F3 = (double *) NULL;
F4 = (double *) NULL;
F5 = (double *) NULL;

KOP = (int *) malloc(sizeof(int));
if (KOP == NULL)
   {
   *fail = 1;
   return (0);
   }
INIT = (int *) malloc(sizeof(int));
if (INIT == NULL)
   {
   *fail = 1;
   return (0);
   }
JFLAG = (int *) malloc(sizeof(int));
if (JFLAG == NULL)
   {
   *fail = 1;
   return (0);
   }
KFLAG = (int *) malloc(sizeof(int));
if (KFLAG == NULL)
   {
   *fail = 1;
   return (0);
   }

SAVRE = (double *) malloc(sizeof(double));
if (SAVRE == NULL)
   {
   *fail = 1;
   return(0);
   }
SAVAE = (double *) malloc(sizeof(double));
if (SAVAE == NULL)
   {
   *fail = 1;
   return (0);
   }

F1 = (double *) malloc(NEQN * sizeof(double));
if (F1 == NULL)
   {
   *fail = 1;
   return (0);
   }
F2 = (double *) malloc(NEQN * sizeof(double));
if (F2 == NULL)
   {
   *fail = 1;
   return (0);
   }
F3 = (double *) malloc(NEQN * sizeof(double));
if (F3 == NULL)
   {
   *fail = 1;
   return (0);
   }
F4 = (double *) malloc(NEQN * sizeof(double));
if (F4 == NULL)
   {
   *fail = 1;
   return (0);
   }
F5 = (double *) malloc(NEQN * sizeof(double));
if (F5 == NULL)
   {
   *fail = 1;
   return (0);
   }

return (0);
}  /* end of rkfinit() */

/*-----------------------------------------------------------------*/

#if (PROTOTYPE)

int rkfend (void)

#else

int rkfend ()

#endif

/* Purpose...
   -------
   This routine cleans up the work space and should be called
   when the user is finished with rkf45().
   */

{
if (F5 != NULL) { free (F5); F5 = NULL; }
if (F4 != NULL) { free (F4); F4 = NULL; }
if (F3 != NULL) { free (F3); F3 = NULL; }
if (F2 != NULL) { free (F2); F2 = NULL; }
if (F1 != NULL) { free (F1); F1 = NULL; }
if (SAVAE != NULL) { free (SAVAE); SAVAE = NULL; }
if (SAVRE != NULL) { free (SAVRE); SAVRE = NULL; }
if (KFLAG != NULL) { free (KFLAG); KFLAG = NULL; }
if (JFLAG != NULL) { free (JFLAG); JFLAG = NULL; }
if (INIT  != NULL) { free (INIT); INIT = NULL; }
if (KOP   != NULL) { free (KOP); KOP = NULL; }

return (0);
}

/*-----------------------------------------------------------------*/

#if (PROTOTYPE)

int rkf45 (int (*F)(int n, double t, double y[], double yp[]), int NEQN,
           double Y[], double YP[],
           double *T, double TOUT,
           double *RELERR, double ABSERR,
           double *H,
           int *NFE, int MAXNFE, int *IFLAG)

#else

int rkf45 (F, NEQN, Y, YP, T, TOUT, RELERR, ABSERR, H,
           NFE, MAXNFE, IFLAG)

int    (*F)();
int    NEQN;
double Y[], YP[];
double *T, TOUT;
double *RELERR, ABSERR, *H;
int    *NFE, MAXNFE, *IFLAG;

#endif


/* Purpose ...
   -------
   Function rkf45() integrates a system of neqn first order
   ordinary differential equations of the form
         dy[i]/dt = f(t,y[0],y[1],...,y[neqn-1])
   where the y[i], i = 0 ... neqn-1 are given at t.

   RKF45 is primarily designed to solve non-stiff and mildly stiff
   differential equations when derivative evaluations are inexpensive.
   RKF45 should generally not be used when the user is demanding
   high accuracy.

   Typically the subroutine is used to integrate from T to TOUT but it
   can be used as a one-step integrator to advance the solution a
   single step in the direction of TOUT. On return the parameters in
   the call list are set for continuing the integration. The user has
   only to call rkf45() again (and perhaps define a new value for TOUT).
   For further details see note () below.

   RKF45 in turn calls subroutine fehl45 which computes an approximate
   solution over one step.

   Input ...
   -----
   (*F)()  : User supplied function
	     int F (NEQN, T, Y, YP)
             int    NEQN;
	     double T, Y[], YP[];
	     to evaluate derivatives YP[i] = dy[i]/dt
   NEQN    : number of equations to be integrated
   Y[]     : solution vector at T with elements 0 thru NEQN-1
   *T      : independent variable, starting value
   TOUT    : output point at which solution is desired
   *RELERR,
   ABSERR  : relative and absolute error tolerances for local
	     error test. At each step the code requires that
	     fabs(local error) <= RELERR * fabs(Y) + ABSERR
	     for each component of the local error vector and Y[].
	     Both must be non-negative. RELERR must be a variable while
	     ABSERR may be a constant. The code should normally not be
	     used with relative error control smaller than about 1.e-8 .
	     To avoid limiting precision difficulties the code requires
	     RELERR to be larger than an internally computed relative
	     error parameter which is machine dependent. In particular,
	     pure absolute error is not permitted. If a smaller than
	     allowable value of RELERR is attempted, RKF45 increases
	     RELERR appropriately and returns control to the user before
	     continuing the integration.
   MAXNFE  : Maximum number of function evaluations allowed.  The
             maximum number of steps that will be taken is approximately
             MAXNFE/6.
   *IFLAG  : indicator for status of integration
	     +1,-1 indicator to initialize the code for each new
	     problem. normal input is +1. the user should set IFLAG=-1
	     only when one-step integrator control is essential. In this
	     case, rkf45 attempts to advance the solution a single step
	     in the direction of TOUT each time it is called. Since this
	     mode of operation results in extra computing overhead, it
	     should be avoided unless needed.

   Output ...
   ------
   Y[]     : solution vector at T
   *T      : independent variable, final value reached
	     T=TOUT is allowed on the first call only, in which case
	     rkf45() returns with IFLAG = 2 if continuation is possible.
   *IFLAG  : indicator for status of integration
	      = 2 : Integration reached TOUT. Indicates successful return
		    and is the normal mode for continuing integration.
	      =-2 : A single successful step in the direction of TOUT
		    has been taken. Normal mode for continuing
		    integration one step at a time.
	      = 3 : Integration was not completed because relative error
		    tolerance was too small. RELERR has been increased
		    appropriately for continuing.
	      = 4 : Integration was not completed because more than
		    MAXNFE derivative evaluations were needed. This
		    is approximately MAXNFE/6 steps.
	      = 5 : Integration was not completed because solution
		    vanished making a pure relative error test
		    impossible. Must use non-zero ABSERR to continue.
		    using the one-step integration mode for one step
		    is a good way to proceed.
	      = 6 : Integration was not completed because requested
		    accuracy could not be achieved using smallest
		    allowable stepsize. User must increase the error
		    tolerance before continued integration can be
		    attempted.
	      = 7 : It is likely that RKF45 is inefficient for solving
		    this problem. Too much output is restricting the
		    natural stepsize choice. Use the one-step integrator
		    mode.
	      = 8 : Invalid input parameters
		    This indicator occurs if any of the following is
		    satisfied -  NEQN <= 0
				 T=TOUT and IFLAG .NE. +1 or -1
				 RELERR or ABSERR < 0.0
				 IFLAG == 0 or < -2 or > 8

   Subsequent calls to RKF45 ...
   -------------------------
   Function rkf45() returns with all information needed to continue
   the integration. If the integration reached TOUT, the user need only
   define a new TOUT and call rkf45() again. In the one-step integrator
   in the direction of the current TOUT. Upon reaching TOUT (indicated
   by changing IFLAG to 2),the user must then define a new TOUT and
   reset IFLAG to -2 to continue in the one-step integrator mode.

   If the integration was not completed but the user still wants to
   continue (IFLAG=3,4 case), he just calls rkf45() again. With IFLAG=3
   the RELERR parameter has been adjusted appropriately for continuing
   the integration. In the case of IFLAG=4 the function counter will
   be reset to 0 and another 100 function evaluations are allowed.

   However,in the case IFLAG=5, the user must first alter the error
   criterion to use a positive value of ABSERR before integration can
   proceed. If he does not,execution is terminated.

   Also,in the case IFLAG=6, it is necessary for the user to reset
   IFLAG to 2 (or -2 when the one-step integration mode is being used)
   as well as increasing either ABSERR,RELERR or both before the
   integration can be continued. If this is not done, execution will
   be terminated. The occurrence of IFLAG=6 indicates a trouble spot
   (solution is changing rapidly,singularity may be present) and it
   often is inadvisable to continue.

   If IFLAG=7 is encountered, the user should use the one-step
   integration mode with the stepsize determined by the code or
   consider switching to the Adams codes DE/STEP,INTRP. If the user
   insists upon continuing the integrator with rkf45(), he must reset
   IFLAG to 2 before calling RKF45 again. Otherwise,execution will be
   terminated.

   If IFLAG=8 is obtained, integration can not be continued unless
   the invalid input parameters are corrected.

   Workspace ...
   ---------
   The following arrays and simple variables are used internally
   by rkf45() and should not be altered between calls.

   YP[],F1[], : array to hold information internal to rkf45() which
   F2[],F3[],   is necessary for subsequent calls.
   F4[],F5[]    Must be dimensioned at least NDIM
   H          : next step size to be attempted
   SAVRE      : saved relative error tolerance
   SAVAE      : saved absolute error tolerance
   NFE        : number of derivative function evaluations
   KOP        : indicator for too many output points
   INIT       : initialization completion (internal) flag
   JFLAG      : saved input IFLAG
   KFLAG      : continuation (internal) flag

   This C code written by ...  Peter & Nigel,
   ----------------------      Design Software,
                               42 Gubberley St,
                               Kenmore, 4069,
                               Australia.

   Version ... 2.0, 12-Feb-1989
   -------     1.0, 25-Jan-1988
               2.1, 17-Apr-1989  (memory allocation for workspace)
               2.2,    Jul-1989  (neqn added to user function call)

   Notes ...
   -----
   (1) The original FORTRAN code was written by
       H.A.Watts and L.F.Shampine
       Sandia Laboratories
       Albuquerque,New Mexico

   (2) For the FORTRAN source, see the book ...
       Forsythe G.E., Malcolm, M.A., and Moler, C.B.
       Computer Methods for Mathematical Computations
       Prentice Hall

   (3) rkf45() uses the Runge-Kutta-Fehlberg (4,5) method described
       in the reference
       E.Fehlberg , Low-order classical Runge-Kutta formulas with
       stepsize control , NASA TR R-315
       The performance of rkf45() is illustrated in the reference
       L.F.Shampine,H.A.Watts,S.Davenport, Solving non-stiff ordinary
       differential equations-the state of the art ,
       Sandia Laboratories Report SAND75-0182.

   (4) Requires the math library functions fabs(), pow(), abs() and
       the system function exit() (from stdlib.h).

-------------------------------------------------------------------*/

{  /* --- start of function RKF45 --- */

#define   MIN(a,b)   (((a) < (b)) ? (a) : (b))
#define   MAX(a,b)   (((a) > (b)) ? (a) : (b))
#define   ISIGN(a,b)  (((b) > 0) ? abs(a) : -abs(a))
#define   RSIGN(a,b)  (((b) > 0.0) ? fabs(a) : -fabs(a))

static int    HFAILD, OUTPUT;

static double A, AE, DT, EE, EEOET, ESTTOL, ET, HMIN, RER, S,
       SCALE, TOL, TOLN, U26, YPK;

static int    K, MFLAG;


/* REMIN is the minimum acceptable value of RELERR. Attempts
   to obtain higher accuracy with this subroutine are usually
   very expensive and often unsuccessful. */

#define  REMIN  1.0e-12
U26 = 26.0 * EPSILON;

/* ----------------------
   Check input parameters
   ---------------------- */

#define  BailOut  { *IFLAG = 8; return 0; } /* exit on invalid input */

if (NEQN < 1) BailOut;
if (((*RELERR) < 0.0) || (ABSERR < 0.0)) BailOut;
MFLAG = abs (*IFLAG);
if ((MFLAG == 0) || (MFLAG > 8)) BailOut;

if (MFLAG != 1)
   {
   /* NOT the first call: Check continuation possibilities */
   if ((*T == TOUT) && (*KFLAG != 3)) BailOut;
   if (MFLAG == 2)
      {  /*  IFLAG = +2 or -2 */
      switch (*KFLAG) {
         case 3 : if (*INIT == 0)
                     { /* Reset flag value from previous call */
                     *IFLAG = *JFLAG;
                     MFLAG = abs(*IFLAG);
                     }
                  break;
         case 4 : *NFE = 0;  /* Reset function evaluation counter */
                  break;
         case 5 : if (ABSERR == 0.0) exit(0); /* stop here, user did */
                  break;                      /* not heed warning    */
         case 6 : if (((*RELERR) <= *SAVRE) && (ABSERR <= *SAVAE)) exit(0);
                  break;                      /* as for case 5       */
         }  /* end switch (*KFLAG) ... */
      }
   else
      {  /* IFLAG = 3,4,5,6,7 OR 8 */
      switch (*IFLAG) {
         case 3 : *IFLAG = *JFLAG;
                  if (*KFLAG == 3) MFLAG = abs (*IFLAG);
                  break;
         case 4 : NFE = 0;
                  *IFLAG = *JFLAG;
                  if (*KFLAG == 3) MFLAG = abs (*IFLAG);
                  break;
         case 5 : if (ABSERR > 0.0)
                     {  /* Reset flag from previous call */
                     *IFLAG = *JFLAG;
                     if (*KFLAG == 3) MFLAG = abs (*IFLAG);
                     }
                  break;
         default : exit(0);    /* stop here as the user did not
                                  fix the problem pertaining to
                                  IFLAG = 5, 6, 7 or 8   */
         }  /* end switch (*IFLAG) */
      }  /* end if (MFLAG == 2) ... */
   } /* end if (MFLAG != 1) ... */


/* -----------------
   Do some real work ...
   -----------------     */

/* Save input IFLAG and set continuation flag value for subsequent
   input checking */
*JFLAG = *IFLAG;
*KFLAG = 0;

/* Save RELERR and ABSERR for checking input on subsequent calls */
*SAVRE = (*RELERR);
*SAVAE = ABSERR;

/* Restrict relative error tolerance to be at least as large as
   2*EPSILON+REMIN to avoid limiting precision difficulties arising
   from impossible accuracy requests  */

RER = 2.0 * EPSILON + REMIN;
if ((*RELERR) < RER)
   {  /* Relative error tolerance too small  */
   (*RELERR) = RER;
   *IFLAG = 3;
   *KFLAG = 3;
   return 0;
   }

DT = TOUT - *T;


/* --------------
   Initialization ...
   -------------- */

if (MFLAG == 1)
   {  /* set initialization completion indicator,INIT
         set indicator for too many output points,KOP
         evaluate initial derivatives
         set counter for function evaluations,NFE  */
   *INIT = 0;
   *KOP = 0;
   A = *T;
   (*F) (NEQN, A, Y, YP);
   *NFE = 1;
   if (*T == TOUT)
      {
      *IFLAG = 2;
      return 0;
      }
   }

if ((MFLAG == 1) || (*INIT == 0))
   {  /* estimate starting stepsize */
   *INIT = 1;
   *H = fabs (DT);
   TOLN = 0.0;
   for (K = 0; K < NEQN; ++K)
      {
      TOL = (*RELERR) * fabs(Y[K]) + ABSERR;
      if (TOL <= 0.0) continue;
      TOLN = TOL;
      YPK = fabs (YP[K]);
      /* *H and TOL/YPK always +ve */
      if ((YPK * pow(*H,5.0)) > TOL) *H = pow((TOL/YPK),0.2);
      }
   if (TOLN <= 0.0) *H = 0.0;
   *H = MAX(*H, U26 * MAX(fabs(*T), fabs(DT)));
   *JFLAG = ISIGN(2, *IFLAG);
   }

/* Set stepsize for integration in the direction from T to TOUT  */
*H = RSIGN(*H, DT);

/* Test to see if RKF45 is being severely impacted by too many
   output points */
if (fabs(*H) >= 2.0* fabs(DT)) ++(*KOP);
if (*KOP == 100)
   {  /* Unnecessary frequency of output  */
   *KOP = 0;
   *IFLAG = 7;
   return 0;
   }

/* If too close to output point, extrapolate (linearly) and return  */
if (fabs(DT) <= U26*fabs(*T))
   {
   for (K = 0; K < NEQN; ++K)  Y[K] += DT * YP[K];
   A = TOUT;
   (*F) (NEQN, A, Y, YP);
   ++(*NFE);
   *T = TOUT;
   *IFLAG = 2;
   return 0;
   }

/* Initialize output point indicator  */
OUTPUT = 0;  /* FALSE */

/* To avoid premature underflow in the error tolerance function.
   scale the error tolerances  */
SCALE = 2.0 / (*RELERR);
AE = SCALE * ABSERR;


/* ------------------------
   Step by step integration ...
   ------------------------ */

TakeSomeSteps:

HFAILD = 0;   /* .FALSE. */

/* Set smallest allowable stepsize */
HMIN = U26 * fabs(*T);

/* Adjust stepsize if necessary to hit the output point.
   look ahead two steps to avoid drastic changes in the stepsize and
   thus lessen the impact of output points on the code.  */
DT = TOUT - *T;
if (fabs(DT) < 2.0*fabs(*H))
   {
   if (fabs(DT) <= fabs(*H))
      {  /* The next successful step will complete the integration to the
         output point  */
      OUTPUT = 1;   /* .TRUE. */
      *H = DT;
      }
   else  *H = 0.5 * DT;
   }


/* ----------------------------------------
   Core integrator for taking a single step ...
   ----------------------------------------

   The tolerances have been scaled to avoid premature underflow in
   computing the error tolerance function ET.
   To avoid problems with zero crossings,relative error is measured
   using the average of the magnitudes of the solution at the
   beginning and end of a step.
   The error estimate formula has been grouped to control loss of
   significance.
   To distinguish the various arguments, *H is not permitted
   to become smaller than 26 units of roundoff in T.
   Practical limits on the change in the stepsize are enforced to
   smooth the stepsize selection process and to avoid excessive
   chattering on problems having discontinuities.
   To prevent unnecessary failures, the code uses 9/10 the stepsize
   it estimates will succeed.
   After a step failure, the stepsize is not allowed to increase for
   the next attempted step. This makes the code more efficient on
   problems having discontinuities and more effective in general
   since local extrapolation is being used and extra caution seems
   warranted.
*/

/* Test number of derivative function evaluations.
   If okay,try to advance the integration from t to t+h  */

TakeAStep:
if (*NFE > MAXNFE)
   {  /* Too much work */
   *IFLAG = 4;
   *KFLAG = 4;
   return 0;
   }

/* Advance an approximate solution over one step of length H  */
fehl45 (F, *T, *H, Y, YP, F1, F2, F3, F4, F5, NEQN);
*NFE += 5;

/* Compute and test allowable tolerances versus local error estimates
   and remove scaling of tolerances. Note that relative error is
   measured with respect to the average of the magnitudes of the
   solution at the beginning and end of the step.  */
EEOET = 0.0;
for (K = 0; K < NEQN; ++K)
   {
   ET = fabs(Y[K]) + fabs(F1[K]) + AE;
   if (ET <= 0.0)
      {   /* Inappropriate error tolerance */
      *IFLAG = 5;
      return 0;
      }
   EE = fabs((-2090.0 * YP[K] + (21970.0 * F3[K] - 15048.0 * F4[K])) +
             (22528.0 * F2[K] - 27360.0 * F5[K]));
   EEOET = MAX(EEOET, EE/ET);
   }

ESTTOL = fabs(*H) * EEOET * SCALE / 752400.0;

if (ESTTOL > 1.0)
   {  /* --- Unsuccessful step ---
      reduce the stepsize , try again
      the decrease is limited to a factor of 1/10  */
   HFAILD = 1;  /* .TRUE.  */
   OUTPUT = 0;  /* .FALSE. */
   S = 0.1;
   /* ESTTOL always +ve */
   if (ESTTOL < 59049.0)  S = 0.9 / pow(ESTTOL, 0.2);
   *H *= S;
   if (fabs(*H) <= HMIN)
      { /* Requested error unattainable at smallest
           allowable stepsize  */
      *IFLAG = 6;
      *KFLAG = 6;
      return 0;
      }
   goto TakeAStep;
   }

/* --- successful step ---
   store solution at T+H
   and evaluate derivatives there  */
*T += *H;
for (K = 0; K < NEQN; ++K)  Y[K] = F1[K];
A = *T;
(*F) (NEQN, A, Y, YP);
++(*NFE);


/* --- Choose next stepsize. ---
   The increase is limited to a factor of 5.
   If step failure has just occurred, next
   stepsize is not allowed to increase.  */
S = 5.0;
if (ESTTOL > 1.889568E-4)  S = 0.9 / pow(ESTTOL, 0.2);
if (HFAILD) S = MIN(S, 1.0);
*H = RSIGN(MAX(S * fabs(*H), HMIN), *H);

/* ----------------------
   End of core integrator ...
   ---------------------- */


/* --- Should we take another step? --- */

if (OUTPUT)
   {  /* Integration successfully completed over the interval */
   *T = TOUT;
   *IFLAG = 2;
   return 0;
   }

if (*IFLAG > 0) goto TakeSomeSteps;
else
   {  /* A single step was taken successfully */
   *IFLAG = (-2);
   return 0;
   }

/* --- Cleanup --- */
#undef   MIN
#undef   MAX
#undef   ISIGN
#undef   RSIGN
#undef   REMIN
}  /* --- end of function RKF45 --- */

/*-----------------------------------------------------------------*/

#if (PROTOTYPE)

int fehl45(int (*F)(int n, double t, double y[], double yp[]),
           double T, double H,
           double Y[], double YP[], double F1[],
           double F2[], double F3[], double F4[],
           double F5[], int NEQN)

#else

int fehl45(F, T, H, Y, YP, F1, F2, F3, F4, F5, NEQN)

int (*F)();
double T, H;
double Y[], YP[], F1[], F2[], F3[], F4[], F5[];
int NEQN;

#endif

/* Fehlberg fourth-fifth order Runge-Kutta method

   fehl45 integrates a system of NEQN first order
   ordinary differential equations of the form
         dy(0)/dt=F(T,Y(0),...,Y(NEQN-1))
   where the initial values Y(1) and the initial derivatives
   YP(1) are specified at the starting point T. fehl45 advances
   the solution over the fixed step H and returns
   the fifth order (sixth order accurate locally) solution
   approximation at T+H in array F1(1).
   F2,...,F5 are arrays of dimension NDIM which are needed
   for internal storage.
   The formulas have been grouped to control loss of significance.
   fehl45() should be called with an H not smaller than 13 units of
   roundoff in T so that the various independent arguments can be
   distinguished.

*/
{  /* --- start of function fehl45() ---- */
double CH;
int    K;

CH = H / 4.0;
for (K = 0; K < NEQN; ++K)  F5[K] = Y[K] + CH * YP[K];
(*F) (NEQN, T+CH, F5, F1);

CH = 3.0 * H / 32.0;
for (K = 0; K < NEQN; ++K)  F5[K] = Y[K] + CH * (YP[K] + 3.0*F1[K]);
(*F) (NEQN, T+3.0*H/8.0, F5, F2);

CH = H / 2197.0;
for (K = 0; K < NEQN; ++K)
    F5[K] = Y[K] + CH * (1932.0 * YP[K] + (7296.0 * F2[K] -
                                           7200.0 * F1[K]));
(*F) (NEQN, T+12.0*H/13.0, F5, F3);

CH = H / 4104.0;
for (K = 0; K < NEQN; ++K)
    F5[K] = Y[K] + CH * ((8341.0 * YP[K] - 845.0 * F3[K]) +
            (29440.0 * F2[K] - 32832.0 * F1[K]));
(*F) (NEQN, T+H, F5, F4);

CH = H / 20520.0;
for (K = 0; K < NEQN; ++K)
    F1[K] = Y[K] + CH * ((-6080.0 * YP[K] + (9295.0 * F3[K] -
            5643.0 * F4[K])) + (41040.0 * F1[K] - 28352.0 * F2[K]));
(*F) (NEQN, T+H/2.0, F1, F5);

/* --- Compute approximate solution at T+H. --- */

CH = H / 7618050.0;
for (K = 0; K < NEQN; ++K)
    F1[K] = Y[K] + CH * ((902880.0 * YP[K] + (3855735.0 * F3[K] -
            1371249.0 * F4[K])) + (3953664.0 * F2[K] +
            277020.0 * F5[K]));

return 0;
}  /* --- end of function fehl45() --- */

/*-----------------------------------------------------------------*/

