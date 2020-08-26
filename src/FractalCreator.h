/*
 * This file contains the declaration of the FractalCreator class which contains the
 * core members and methods for creating a fractal saved in a Bitmap.
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <memory>
#include <cstdint>
#include <math.h>
#include "Bitmap.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
using namespace std;

class FractalCreator
{
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total{0};

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(string name);
};

#endif /* FRACTALCREATOR_H_ */
