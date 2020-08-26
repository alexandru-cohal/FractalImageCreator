/*
 * This file contains the declaration of the RGB class used for manipulating colors in the RGB format.
 */

#ifndef RGB_H_
#define RGB_H_

class RGB
{
public:
	double r;
	double g;
	double b;

public:
	RGB(double r, double g, double b);
};

RGB operator-(const RGB& first, const RGB& second);

#endif /* RGB_H_ */
