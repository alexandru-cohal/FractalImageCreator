/*
 * This file contains the declaration and the implementation of the Zoom class.
 */

#ifndef ZOOM_H_
#define ZOOM_H_

class Zoom
{
public:
	int x{0};
	int y{0};
	double scale{0.0};

	Zoom(int x, int y, double scale): x(x), y(y), scale(scale) {};

};

#endif /* ZOOM_H_ */
