/*
 * This file contains the main function of the project which triggers the creation of the fractal.
 */

#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"
using namespace std;

int main()
{
	// Create the FractalCreator object with width = 800px and height = 600px
	FractalCreator fractalCreator(800, 600);

	// Add the iteration ranges for changing the colors
	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(65, 0, 0));
	fractalCreator.addRange(0.5, RGB(124, 125, 60));
	fractalCreator.addRange(1.0, RGB(255, 255, 120));

	// Add the zooms
	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));

	// Create the fractal
	fractalCreator.run("Fractal.bmp");

	cout << "DONE" << endl;

	return 0;
}
