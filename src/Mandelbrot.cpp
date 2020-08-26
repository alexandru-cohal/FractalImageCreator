/*
 * This file contains the implementation of the Mandelbrot class used for calculating the
 * number of iterations for each pixel of the fractal.
 */

#include <complex>
#include "Mandelbrot.h"
using namespace std;

Mandelbrot::Mandelbrot()
{
}

Mandelbrot::~Mandelbrot()
{
}

int Mandelbrot::getIterations(double x, double y)
{
	complex<double> z = 0;
	complex<double> c(x, y);

	int iterations = 0;

	while (iterations < MAX_ITERATIONS) // Limit the number of iterations
	{
		z = z * z + c;

		if (abs(z) > MAX_LIMIT) // Limit the increase to not reach infinity
		{
			break;
		}

		iterations++;
	}

	return iterations;
}
