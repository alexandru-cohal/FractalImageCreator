/*
 * This file contains the declaration of the ZoomList class.
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "Zoom.h"
using namespace std;

class ZoomList
{
private:
	int m_width{0};
	int m_height{0};
	vector<Zoom> zooms;

public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	pair<double, double> doZoom(int x, int y);
};

#endif /* ZOOMLIST_H_ */
