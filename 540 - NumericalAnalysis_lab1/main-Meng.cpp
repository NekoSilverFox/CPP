#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "SPLINES.H"
#include "quanc8.h"

double point;
double h = 0.1;
double x_beg = 2.0;
double x_end = 3.0;
int count_points = ((x_end - x_beg) / h) + 1;
double x_beg_compare = 2.0;
double posnR;
int N = 10;

double func(double x)
{
  return ((1 - cos(point)) / point);
}

double omega(double x, int k)
{
  double ans = 1; double xk = x_beg;
  for (int i = 0; i < count_points; i++)
  {
    if (i != k)
      ans *= x - xk; xk += h;
  }
  return ans;
}

double Lagrange(double x, double* f)
{
  double ans = 0; double xk = x_beg;
  for (int i = 0; i < N; i++)
  {
    ans += (omega(x, i) / omega(xk, i)) * f[i];
    xk += h;
  }
  return ans;
}

int main()
{
  double x[11], f[11];
  x[0] = x_beg;

  std::ofstream s, l, q, in;
  s.open("s.txt");
  l.open("l.txt");
  q.open("q.txt");
  in.open("in.txt");

  double ans1 = 0, ans2 = 0, errest;
  int flag;
  int col;
  std::cout << "Integral (quanc8)" << std::endl;

  for (int i = 0; i < count_points; i++)
  {
    point = x[i];
    quanc8(func, 0, x_beg, 0.0001, 0.0001, &ans1, &errest, &col, &posnR, &flag);

    std::cout << x[i] << " int=" << ans1 << " errest=" << errest << " " << " col="
      << col << "	flag=" << flag << std::endl;
    in << ans1 << std::endl;
    f[i] = ans1;
    if (i < (count_points - 1))
      x[i + 1] = x[i] + h;
  }

  double b[20], c[20], d[20];
  double x_s[20], f_s[20];

  for (int i = 0; i < count_points; i++)
  {
    x_s[i + 1] = x[i];
    f_s[i + 1] = f[i];
  }

  spline(11, x_s, f_s, b, c, d);
  double xj = 0;

  std::cout << "\n\n Comparing Integral(quanc8) and Spline" << std::endl;
  std::cout << std::setw(8) << "  t\t\t| " << "\tquanc8\tSpline\tQ-S" << std::endl;

  xj = 2.05;
  for (int j = 0; j < N; j++)
  {
    point = xj;
    quanc8(func, 0, x_beg, 0.0001, 0.0001, &ans1, &errest, &col, &posnR, &flag);
    ans2 = seval(count_points, &xj, x_s, f_s, b, c, d);
    std::cout << std::setw(8) << xj << "	|	" << ans1 << "	" << ans2 << "\t" << (ans1 - ans2) << std::endl;
    s << ans2 << std::endl; q << ans1 << std::endl;
    xj += 0.1;
  }

  std::cout << "	" << std::endl;
  std::cout << " Compareing (quanc8) and Lagrange" << std::endl;
  std::cout << std::setw(8) << "  t\t\t| " << "\tquanc8\tLagrange\tQ-L" << std::endl;

  xj = 2.05;
  for (int j = 0; j < N; j++)
  {
    point = xj;
    quanc8(func, 0, x_beg, 0.0001, 0.0001, &ans1, &errest, &col, &posnR, &flag);
    ans2 = Lagrange(xj, f);
    std::cout << std::setw(8) << xj << "	|	" << ans1 << "	" << ans2 << "\t\t" << (ans1 - ans2) << std::endl;
    l << ans2 << std::endl;
    xj += 0.1;
  }

  return 0;
}
