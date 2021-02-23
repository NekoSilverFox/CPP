/* cmath.h
   Definitions for the CMATH numerical methods package.
*/

/************************************************/
/*                                              */
/*  CMATH.  Copyright (c) 1989 Design Software  */
/*                                              */
/************************************************/


/* This C code written by ...  Peter & Nigel,
   ----------------------      Design Software,
                               42 Gubberley St,
                               Kenmore, 4069,
                               Australia.         */

/*-----------------------------------------------------------------*/

/* Select your machine/compiler.
   ----------------------------
   Find the defined variable that most closely matches your
   machine-compiler setup.  Set its value to 1 and all others to 0.

   (OR...  Jump to the next section and make your decisions directly.)

   ANSII      -- should work with any ANSII standard compiler

   TURBOC     -- Turbo-C version 2 on MS-DOS        (ANSII C-compiler)
   MSOFTC     -- Microsoft C version 5 on MS-DOS    (ANSII C-compiler)
   HI_TECH    -- Hi-Tech C version 3.12 on MS-DOS   (ANSII C-compiler)

   APOLLO     -- Apollo workstation
   IRIS       -- Personal Iris workstation
   SUN3       -- Sun series 3 workstation
   HP_UX      -- Hewlett-Packard series 9000 mini/workstation

   IBM_370    -- IBM mainframe compiler
   VAX_VMS    -- Digital Equipment Corporation VAX  (ANSII C-compiler)
   PE_UNIX    -- Perkin Elmer 3200 series mini
   PYRAMID    -- Pyramid supermini
   CONVEX     -- Convex supermini (vector processor)
*/

#define   ANSII      1

#define   TURBOC     0
#define   MSOFTC     0
#define   HI_TECH    0

#define   APOLLO     0
#define   IRIS       0
#define   SUN3       0
#define   HP_UX      0

#define   IBM_370    0
#define   VAX_VMS    0
#define   PE_UNIX    0
#define   PYRAMID    0
#define   CONVEX     0

/*-----------------------------------------------------------------*/

/* Now select some actions based on compiler choice.
   STDLIBH = 1  -- try to include stdlib.h
           = 0  -- don't bother looking
   STRINGH = 1  -- try to include string.h
           = 0  -- don't bother looking
   PROTOTYPE = 1  -- use full function prototypes
             = 0  -- classical C; no prototypes
*/

#if (PE_UNIX || SUN3 || PYRAMID || HP_UX || CONVEX || APOLLO)
#define  PROTOTYPE  0
#else
#define  PROTOTYPE  1
#endif

#if (PE_UNIX || SUN3 || PYRAMID || HP_UX || CONVEX || IRIS || APOLLO)
#define  STDLIBH  0
#else
#define  STDLIBH  1
#endif

#if (SUN3 || PYRAMID || HP_UX || CONVEX || APOLLO)
#define  STRINGH  0
#else
#define  STRINGH  1
#endif

/*-----------------------------------------------------------------*/

/* Machine epsilon :
   ---------------
   This is the smallest real value that your machine can distinguish.
   You may estimate it using the following piece of code.

   one = 1.0;
   two = 2.0;
   epsilon = one;
   do { epsilon /= two; } while (one+epsilon > one);
   epsilon *= two;

   We have selected a value that should allow the CMATH routines to
   work on a large range of machines but may not make the best use of
   a machine offering higher precision arithmetic.  Note that the
   values we supply will allow CMATH to work on ALL of the machine-
   compiler combinations mentioned above.

   */

#define  EPSILON  2.2e-16

/* Machine Overflow :
   ----------------
   The largest real number that can be represented. */

#define  OVRFLOW  1.0e+75

/* Machine Underflow :
   -----------------
   The smallest positive number that can be represented. */

#define  UNDRFLOW  1.0e-75

/*-----------------------------------------------------------------*/

/* The polynomial structure.
   ------------------------
   See the file poly.c for details.  */

// 2-5    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> CHANGE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//typedef struct polynomial { int n; double *cr; double *ci; };

/*-----------------------------------------------------------------*/

/* The COMPLEX number structure.
   ----------------------------
   See the file complex.h for details.  */

//typedef struct COMPLEX {double re; double im;};

/*-----------------------------------------------------------------*/

/*  The bspline structure.
    ----------------------
    See the file bspline.c for details.  */
/*
typedef struct BSPLSTRC  { int order;
                         int nknot;
                         double *knots;
                         double *cpnts; };
*/



/*-----------------------------------------------------------------*/

/* Message handler definitions */

#define  DECOMP_C    101
#define  SOLVE_C     102
#define  BANDFAC_C   103
#define  BANDSLV_C   104
#define  TRIDIAG_C   105
#define  TRISOLVE_C  106
#define  QR_C        107
#define  QRV_C       108
#define  QRVECTOR_C  109
#define  INVERT_C    110
#define  CDECOMP_C   111
#define  CSOLVE_C    112
#define  SVD_C       113
#define  SVDSOLVE_C  114

#define  ZEROIN_C    201
#define  ZEROV_C     202
#define  LAGUERRE_C  203
#define  POLYROOT_C  204

#define  SPLINE_C    301
#define  SEVAL_C     302
#define  DERIV_C     303
#define  SINTEG_C    304
#define  FITSPL_C    305
#define  CHEBY_C     306
#define  CHEBYC_C    307
#define  CHEBYD_C    308
#define  CHEBYI_C    309
#define  FITPOLY_C   310
#define  LSP_C       311

#define  BSPLINIT_C  320
#define  BISECT_C    321
#define  INTERV_C    322
#define  BSPLVB_C    323
#define  BSPLEND_C   324
#define  BSEVAL_C    325
#define  BSDCPNTS_C  326
#define  BSPLINE_C   327

#define  QK21_C      401
#define  QK21INIT_C  402
#define  QAGS_C      403
#define  QUANC8_C    404
#define  QINF_C      405

#define  RKF45_C     501
#define  RKFINIT_C   502
#define  RKFEND_C    503
#define  FEHL45_C    504

#define  STINT0_C    601
#define  STINT1_C    602
#define  STINT2_C    603
#define  STINT3_C    604

#define  NELMIN_C    701
#define  CONJGG_C    702

#define  FFT_C       801
#define  DFT_C       802
#define  CHIRP_C     803

#define  CDIVSN_C    901
#define  CMULTN_C    902
#define  CSQROOT_C   903
#define  CABSLT_C    904

#define  INDEXX_C   1001

#define  CMATHMSG_C 2001

/*-----------------------------------------------------------------*/

#if (PROTOTYPE)
/* Full function prototypes ... */

/* message translator */
char *cmathmsg (int routine, int flag);


/*  B-spline knot vector interval search.  */
int  interv (double knots[],
             int numknots,
             double parameter,
             int *left, int *flag);
int  bisect (void);
/*  B-spline basis function calculation.  */
int  bsplinit (int order, int *flag);
int  bsplvb (double t[],  int jhigh, int index,
             double parameter, int left,
             double biatp[], int *flag);
int  bsplend (void);
/*  Fit B-spline to (x,y) data set.  */
int  bspline (int number_of_data, double xdata[], double ydata[], int order,
              struct BSPLSTRC *xbspl, struct BSPLSTRC *ybspl, int *flag);
/*  Setup structure for  B-spline data.  */
int  bsplmake (int order, int number_knots, double knots[],
               double cpnts[], struct BSPLSTRC *bspldefn, int *flag);
/*  Free array memory in B-spline structure.  */
int  bspldest (struct BSPLSTRC *bspldefn, int *flag);
/*  B-spline evaluation.  */
double  bseval (int index, double parameter,
                struct BSPLSTRC *bspldefn, int *flag);
/*  B-spline derivative control points.  */
int  bsdcpnts (struct BSPLSTRC *derivm1,
               struct BSPLSTRC *deriv, int *flag);


/*  Banded matrix solver.  */
int bandfac (double *w, int nroww, int nrow, int nbandl,
            int nbandu, int *flag);
int bandslv (double *w, int nroww, int nrow, int nbandl, int nbandu,
               double b[]);


/* Some complex number bits. */
int    csqroot (double xr, double xi, double *zr, double *zi);
double cabslt  (double xr, double xi);
int    cmultn  (double xr, double xi, double yr, double yi,
               double *zr, double *zi);
int    cdivsn  (double xr, double xi, double yr, double yi,
               double *zr, double *zi);


/* Solve a COMPLEX matrix equation */
int cdecomp (int n, int ndim,
             struct COMPLEX *a, double *cond,
             int pivot[], int *flag);
int csolve (int n, int ndim,
           struct COMPLEX *a, struct COMPLEX b[],
           int pivot[]);


/* Chebyshev polynomials */
int chebyc (double (*f)(double x), double a, double b, double c[],
           int n, int *flag);
double cheby (double x, double a, double b, double c[],
              int m, int *flag);
int chebyi (double a, double b, double c[], double cint[],
            int n, int *flag);
int chebyd (double a, double b, double c[], double cder[],
            int n, int *flag);


/* Conjugate gradient function minimizer */
int conjgg (double (*f)(int n, double x[]), int mf,
            int (*df)(int n, double x[], double dfdx[]),
            double p[],
            int n, double ftol, double *fret,
            int *flag, int itmax, double xmax,
	    int *iter, int *nfe, int *nje);
/* bracketing the minimum along a line */
int braket (double (*f)(int n, double x[]),
            double xvector[], double direct[],
            int n, double *ax, double *bx, double *cx,
            double bound, double *fa, double *fb, double *fc,
            double uvect[], int *nfe, int *flag);
/* finding the minimum along a line */
double linem (double (*f)(int n, double x[]),
              double xvector[], double direct[],
              int n, double reqmin, int itmax, double *xmin,
              double bound, double uvect[], int *nfe, int *flag);
/* partial derivatives */
int partiald (int n, double (*f)(int n, double x[]),
              double x[], double fp, double dfdx[], int *nfe);


/* Decompose a square matrix */
int decomp (int n, int ndim,
            double *a, double *cond,
            int pivot[], int *flag);
/* Solve a linear system */
int solve (int n, int ndim,
           double *a, double b[],
           int pivot[]);


/* Discrete Fourier Transform */
int dft (int n, int n2,
         double zr[], double zi[],
         double wr[], double wi[],
         int direct, int *flag);
int chirpmult (int n, double zr[], double zi[], int direct);
int chirp (int n, int n2, double wr[], double wi[], int *flag);


/* Fast Fourier transform */
int fft (int n, double zr[], double zi[], int direct, int *flag);


/* Chebyshev polynomial fitting */
int fitpoly (int nd, double x[], double y[], double weight[],
            double a, double b, int m, double c[], int *fail);


/* Fit a cubic spline */
int fitspl (int nd, double x[], double y[], double w[],
            int ns, double xs[], double ys[],
            double *s1, double *s2,
            double *sums, int *flag);
double L2spl (int nf, double yf[]);
int L2deriv (int nf, double yf[], double dfdyf[]);


/* index an array of numbers      */
int indexx (int n, double x[], int indx[]);


/* invert a matrix                */
int invert (int n, int ndim,
            double *A, double *Ainv,
            int *flag);


/* Fit a polynomial using least squares */
int lsp (int n, int m,
         double x[], double y[], double c[],
         double shift, double relerr, double *resid,
         int *ierr);


/* Nelder-Mead simplex minimization */
int nelmin (double (*f)(int n, double x[]),
            int n,
            double x[], double *fmin, double reqmin,
            double dx[],
            int konvge, int *nfe, int maxfe,
            int *numres, int *flag,
            double reltol, double abstol);


/* Polynomial bits */
int polyroot (int n, double cr[], double ci[],
              double xr[], double xi[],
              int *nr, double abserr,
              int polish, int *flag );
int polymake (struct polynomial *q,
              int n, double cr[], double ci[]);
int polyeval (struct polynomial *q,
              double xr,    double xi,
              double *pr,   double *pi,
              double *pdr,  double *pdi,
              double *pddr, double *pddi,
              double *errest );
int polydiv (struct polynomial *q,
             double ar, double ai);
int laguerre (struct polynomial *q,
              double *xr,    double *xi,
              double errtol, int polish, int *flag );


/* adaptive Gaussian quadrature   */
int qags (double (*f)(double x), double a, double b,
          double epsabs, double epsrel,
          double *result, double *errest,
          int *nfe, int *flag);
int qextn (int *n, double epstab[], double *result,
           double *abserr, double res3la[], int *nres);
int qqsort (int limitl, int last, int *maxerr,
            double *ermax, double elist[], int iord[], int *nrmax);


/* quadrature over an infinite domain */
int qinf (double (*f)(double x), double a, int inf,
          double epsabs, double epsrel,
          double *result, double *errest,
          int *nfe, int *flag);
double ftrnsfm (double t);


/* fixed rule Gaussian quadrature */
int qk21 (double (*f)(double x), double a, double b,
          double *result, double *abserr,
          double *resabs, double *resasc);
int qk21init (void);


/* matrix eigensystem for a general real matrix */
int qr (int nm, int n, double *a,
        double *wr, double *wi, int *ierr);
int qrv (int ndim, int n, double *a,
         double *wr, double *wi, double *z,
         int *flag);
int balanc (int ndim, int n, double *a, int *low,
            int *igh, double *scale);
int elmhes (int ndim, int n, int low, int igh,
            double *a, int *intg);
int eltran (int ndim, int n, int low, int igh, double *a,
            int *intg, double *z);
int hqr (int nm, int n, int Low, int igh, double *h,
         double *wr, double *wi, int *ierr);
int hqr2 (int ndim, int n, int Low, int igh, double *h,
          double *wr, double *wi, double *z, int *ierr);
int balbak (int ndim, int n, int low, int igh, double *scale,
            int m, double *z);
int qrvector (int j, int nm, int n,
              double *z, double wr[], double wi[],
              double vr[], double vi[], int *flag);


/* adaptive Newton-Cotes quadrature */
int quanc8 (double (*f)(double x), double a, double b,
            double epsabs, double epsrel,
            double *result, double *errest,
            int *nfe, double *posn, int *flag);


/* Runge-Kutta ODE integrator */
int rkf45 (int (*f)(int n, double t, double y[], double yp[]),
           int n,
           double y[], double yp[],
           double *x1, double x2,
           double *relerr, double abserr,
           double *h,
           int *nfe, int maxfe, int *flag);
/* rkf45 single step part */
int fehl45(int (*f)(int n, double t, double y[], double yp[]),
           double x, double h,
           double y[], double yp[], double F1[],
           double F2[], double F3[], double F4[],
           double F5[], int n);
/* rkf45 initialization */
int rkfinit (int n, int *fail);
/* rkf45 clean-up */
int rkfend (void);


/* Cubic spline coefficients */
int spline (int n, int e1, int e2,
            double s1, double s2,
            double x[], double y[],
            double b[], double c[], double d[],
            int *flag);
/* spline evaluation */
double seval (int n, double xx,
              double x[], double y[],
              double b[], double c[], double d[],
              int *last);
/* derivative evaluation */
double deriv (int n, double xx,
              double x[],
              double b[], double c[], double d[],
              int *last);
/* integral of spline */
double sinteg (int n, double u,
              double x[], double y[],
              double b[], double c[], double d[],
              int *last);


/* Stiff ODE intializer */
int stint0(int n, int *fail);
/* Stiff ODE integrator */
int stint1 (int n, double y[],
            double *x1, double x2,
            double dx, double relerr,
            int mf, int *nfe, int *nje, int *flag,
            int (*f)(int n, double t, double y[], double dy[]),
            int (*jacob)(int n, double t, double y[], double rj[]) );
/* stint2() is the difficult-to-use version
   -- do not use it directly */
int stint2 (int n, double *t, double *h, double *hnext,
            double hmin, double hmax, double eps,
            int *nfe, int *nje, int *kflag, int *knext,
            int *jstart, int maxord, int mf,
            int (*deriv)(int n, double t, double y[], double dy[]),
            int (*jacob) (int n, double t, double y[], double rj[]) );
/* stint clean-up */
int stint3 (void);


/* Singular value decomposition. */
int svd (int nm, int m, int n,
         double a[], double w[],
         int matu, double u[],
         int matv, double v[],
         int *ierr);
/* Solve for RHS given decomposition. */
int svdsolve (int nm, int m, int n,
    double u[], double w[], double v[], double b[], double x[],
    double tol, int *ierr);


/* tridiagonal matrix solver */
int tridiag (int n,
             double ld[], double d[], double ud[],
             int *flag);
/* back-substitution */
int trisolve (int n,
              double ld[], double d[], double ud[], double x[],
              int *flag);


/* zero of a function */
double zeroin (double left, double right, double (*f)(double x),
               double tol, int *flag);


/* solution of simultaneous functions   */
int zerov (int (*f)(int n, double *x, double *fv),
           int (*jac) (int n, double *x, double *df),
           int n,
           double x[], double fvec[],
           double xtol, double ftol,
           int method, int *nfe, int *ifail);
double residsq (int n, double x[]);
int dresid (int n, double x[], double dfdx[]);
int jacobn (int n, int ndim, int (*f)(int n, double *x, double *fv),
            double *x, double *fv, double *dfdx, int *nfe);


#else
/* Old style function prototypes ... */

char   *cmathmsg ();             /* error message translator       */

int     interv ();               /* B-spline knot vector interval search. */
int     bisect ();
int     bsplinit ();             /* B-spline basis function calculation. */
int     bsplvb ();
int     bsplend ();
int     bspline ();              /* Fit B-spline to (x,y) data set.     */
int     bsplmake ();             /* Setup structure for  B-spline data. */
int     bspldest ();             /* Free array memory in B-spline structure. */
double  bseval ();               /* B-spline evaluation.                */
int     bsdcpnts ();             /* B-spline derivative control points. */

int    bandfac ();               /*  Banded matrix factorization    */
int    bandslv ();

int    csqroot ();               /* complex square-root            */
double cabslt  ();               /* complex magnitude              */
int    cmultn  ();               /* complex multiplication         */
int    cdivsn  ();               /* complex division               */

int    cdecomp ();               /* Solve a COMPLEX matrix equation */
int    csolve ();

int    chebyc ();                /* fit Chebyshev coefficients     */
double cheby ();                 /* evaluate Chebyshev polynomials */
int    chebyd ();                /* differentiate coefficients     */
int    chebyi ();                /* integrate coefficients         */

int    conjgg ();                /* Conjugate gradient minimizer   */
int    braket ();                /* bracket minimum                */
double linem  ();                /* line minimization              */
int    partiald ();              /* partial derivatives            */

int    decomp ();                /* Decompose a square matrix      */
int    solve  ();                /* Solve a linear system          */

int    dft ();                   /* Discrete Fourier Transform     */
int    chirpmult ();             /* multiply by Chirp function     */
int    chirp ();                 /* fft of chirp function          */

int    fft ();                   /* Fast Fourier transform         */

int    fitpoly ();               /* Fit a polynomial               */

int    fitspl ();                /* Fit a cubic spline             */
double L2spl ();
int    L2deriv ();

int    indexx ();                /* index an array of numbers      */

int    invert ();                /* invert a matrix                */

int    lsp ();                   /* Least-squares polynomial       */

int    nelmin ();                /* Nelder-Mead simplex minimizer  */

int    polyroot ();              /* find all polynomial roots      */
int    polymake ();              /* set up polynomial structure    */
int    polyeval ();              /* evaluate polynomial and deriv. */
int    polydiv ();               /* divide polynomial by (x-a)     */
int    laguerre ();              /* find a single root             */

int    qags  ();                 /* adaptive Gaussian quadrature   */
int    qqsort ();
int    qextn  ();

int    qk21 ();                  /* fixed rule Gaussian quadrature */
int    qk21init ();

int    qinf ();                  /* quadrature on an infinite domain */
double ftrnsfm ();

int    qr ();                    /* matrix eigensystem, qr method  */
int    qrv ();                   /* eigenvalues and eigenvectors   */
int    balanc ();                /* balance matrix                 */
int    elmhes ();                /* reduce to upper Hessenberg     */
int    eltran ();                /* accumulate transformations     */
int    hqr ();                   /* eigenvalues only               */
int    hqr2 ();                  /* compute eigenvalues & vectors  */
int    balbak ();                /* form eigenvectors              */
int    qrvector ();              /* extract eigenvector from z     */

int    quanc8 ();                /* adaptive Newton-Cotes quadrature */

int    rkf45   ();               /* ode integrator                 */
int    fehl45  ();               /* single step part               */
int    rkfinit ();               /* rkf45 initialization           */
int    rkfend  ();               /* rkf45 clean-up                 */

int    spline ();                /* Cubic spline coefficients      */
double seval  ();                /* spline evaluation              */
double deriv  ();                /* derivative evaluation          */
double sinteg ();                /* integral evaluation            */

int    stint0 ();                /* Stiff ODE intializer           */
int    stint1 ();                /* easy-to-use stiff ODE integ.   */
int    stint2 ();                /* difficult-to-use version       */
int    stint3 ();                /* stint clean-up                 */

int    svd ();                   /* Singular Value Decomposition   */
int    svdsolve ();

int    tridiag ();               /* tridiagonal matrix solver      */
int    trisolve ();              /* back-substitution              */

double zeroin ();                /* zero of a function             */

int    zerov ();                 /* solution of simultaneous fns   */
double residsq ();
int    dresid ();
int    jacobn ();

#endif

/*-----------------------------------------------------------------*/

