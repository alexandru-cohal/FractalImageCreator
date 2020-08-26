/*
 * This file contains the declaration of the FractalCreator class which contains the
 * core members and methods for creating a fractal saved in a Bitmap file.
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <memory>
#include <cstdint>
#include <math.h>
#include <vector>
#include "Bitmap.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "RGB.h"
using namespace std;

class FractalCreator
{
private:
	int m_width; // The width of the output Bitmap image
	int m_height; // The height of the output Bitmap image
	unique_ptr<int[]> m_histogram; // The histogram (contains the number of pixels for each number of iterations)
	unique_ptr<int[]> m_fractal; // The fractal
	Bitmap m_bitmap; // The Bitmap
	ZoomList m_zoomList; // The zooms list
	int m_total{0};
	vector<int> m_ranges; // The ranges array
	vector<RGB> m_colors; // The colors array corresponding to the iteration ranges
	vector<int> m_rangeTotals; // The number of pixels for each interations interval
	bool m_gotFirstRange{false}; // Flag for skipping the first iteration range element added to the array (i.e. which defines the initial color of the first interval)

private:
	void calculateIteration(); // Calculate the interation value for each pixel
	void calculateTotalIterations(); // Calculate the total number of pixels
	void calculateRangeTotals(); // Calculate the total number of pixels for each number of iterations interval
	int getRange(int iterations) const; // Get the range of a specific iterations value based on the initial provided iteration ranges array
	void drawFractal(); // Draw the fractal
	void writeBitmap(string name); // Write the fractal to a Bitmap image file

public:
	FractalCreator(int width, int height); // The constructor
	virtual ~FractalCreator(); // The destructor

	void addZoom(const Zoom& zoom); // Add a zoom to the zooms array
	void addRange(double rangeEnd, const RGB& rgb); // Add a range to the ranges array
	void run(string name); // Generate the fractal
};

#endif /* FRACTALCREATOR_H_ */
