/*
 * This file contains the implementation of the Mandelbrot class used for generating the fractal.
 */

#include <complex>
#include "Mandelbrot.h"
using namespace std;

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}

int Mandelbrot::getIterations(double x, double y)
{
	complex<double> z = 0;
	complex<double> c(x, y);

	int iterations = 0;

	while (iterations < MAX_ITERATIONS) // Limit the number of iterations
	{
		z = z * z + c;

		if (abs(z) > 2) // Limit the increase to not reach infinity
		{
			break;
		}

		iterations++;
	}

	return iterations;
}
