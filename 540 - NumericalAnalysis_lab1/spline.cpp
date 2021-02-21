#include "splines.h"
#include <math.h>

void spline(int n, double* x, double* y, double* b, double* c, double* d)
{
  int i, ib, nm1;
  double t;

  nm1 = n - 1;
  if (n < 2)  return;
  if (n < 3)  goto l20;
  d[1] = x[2] - x[1];
  c[2] = (y[2] - y[1]) / d[1];
  for (i = 2; i <= nm1; i++)
  {
    d[i] = x[i + 1] - x[i];
    b[i] = 2 * (d[i - 1] + d[i]);
    c[i + 1] = (y[i + 1] - y[i]) / d[i];
    c[i] = c[i + 1] - c[i];
  }
  b[1] = -d[1];
  b[n] = -d[n - 1];
  c[1] = 0;
  c[n] = 0;
  if (n == 3) goto l10;
  c[1] = c[3] / (x[4] - x[2]) - c[2] / (x[3] - x[1]);
  c[n] = c[n - 1] / (x[n] - x[n - 2]) - c[n - 2] / (x[n - 1] - x[n - 3]);
  c[1] = c[1] * sqrt(d[1]) / (x[4] - x[1]);
  c[n] = -c[n] * sqrt(d[n - 1]) / (x[n] - x[n - 3]);

l10:    for (i = 2; i <= n; i++)
{
  t = d[i - 1] / b[i - 1];
  b[i] = b[i] - t * d[i - 1];
  c[i] = c[i] - t * c[i - 1];
}
c[n] = c[n] / b[n];
for (ib = 1; ib <= nm1; ib++)
{
  i = n - ib;
  c[i] = (c[i] - d[i] * c[i + 1]) / b[i];
}
b[n] = (y[n] - y[nm1]) / d[nm1] + d[nm1] * (c[nm1] + 2 * c[n]);
for (i = 1; i <= nm1; i++)
{
  b[i] = (y[i + 1] - y[i]) / d[i] - d[i] * (c[i + 1] + 2 * c[i]);
  d[i] = (c[i + 1] - c[i]) / d[i];
  c[i] = 3 * c[i];
}
c[n] = 3 * c[n];
d[n] = d[n - 1];
return;
l20:  b[1] = (y[2] - y[1]) / (x[2] - x[1]);
c[1] = 0;
d[1] = 0;
b[2] = b[1];
c[2] = 0;
d[2] = 0;

l30:
return;
}

double seval(int n, double* u,
  double* x, double* y, double* b, double* c,
  double* d)
{
  int i, j, k;
  double dx;
  i = 1;
  if (i >= n) i = 1;
  if (*u < x[i]) goto l10;
  if (*u <= x[i + 1]) goto l30;

l10: i = 1;
  j = n + 1;


l20: k = (i + j) / 2;
  if (*u < x[k]) j = k;
  if (*u >= x[k]) i = k;
  if (j > (i + 1)) goto l20;

l30: dx = *u - x[i];
  return y[i] + dx * (b[i] + dx * (c[i] + dx * d[i]));
}
