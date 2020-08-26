/*
 * This file contains the declaration of the Mandelbrot class used for calculating the
 * number of iterations for each pixel of the fractal.
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

class Mandelbrot
{
public:
	static const int MAX_ITERATIONS = 1000; // The maximum number of iterations
	static const int MAX_LIMIT = 2; // The maximum limit of the absolute value of the complex number on which the each pixel of the fractal is defined

public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double x, double y);
};

#endif /* MANDELBROT_H_ */
