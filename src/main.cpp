#include <iostream>
#include "Bitmap.h"
using namespace std;

int main()
{
	Bitmap bitmap(800, 600);

	bitmap.write("test.bmp");

	return 0;
}
