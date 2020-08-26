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
#include <vector>
#include "Bitmap.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "RGB.h"
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

	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;

	bool m_gotFirstRange{false};

private:
	void calculateIteration();
	void calculateTotalIterations();
	void calculateRangeTotals();
	int getRange(int iterations) const;
	void drawFractal();
	void writeBitmap(string name);

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	void addZoom(const Zoom& zoom);
	void addRange(double rangeEnd, const RGB& rgb);
	void run(string name);
};

#endif /* FRACTALCREATOR_H_ */
