#include <conio.h> 
#include <cstdlib>

double fun129(double x, double absError, int numberMax) {
	if (x > 3 || x < 2) {
		throw 1;
	}
	int n = 0;
	double elem = 1;
	// double sum = elem;

	while (abs(elem) > absError) {
		n++;

		if (n > numberMax) {
			throw 2;
		}

		elem += 1 / ((n * 2 - 1) * pow(x, 2 * n - 1));
		// sum += elem;
	}

	return elem * 2;
}