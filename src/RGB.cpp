/*
 * This file contains the implementation of the RGB class used for manipulating colors in the RGB format.
 */

#include "RGB.h"

RGB::RGB(double r, double g, double b): r(r), g(g), b(b)
{
}

RGB operator-(const RGB& first, const RGB& second)
{
	return RGB(first.r-second.r, first.g-second.g, first.b-second.b);
}
