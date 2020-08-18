/*
 * This file contains the implementation of the Bitmap class used for writing the Bitmap file.
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
using namespace std;

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{})
{
}

bool Bitmap::write(string filename)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	// Fill in the Bitmap file header
	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	// Fill in the Bitmap information
	infoHeader.width = m_width;
	infoHeader.height = m_height;

	// Open the file
	ofstream file;
	file.open(filename, ios::out | ios::binary);
	if (!file)
	{
		return false;
	}

	// Write to the file
	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), m_width*m_height*3);

	// Close the file
	file.close();
	if (!file)
	{
		return false;
	}

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t *pPixel = m_pPixels.get();

	pPixel += (y * m_width + x) * 3; // 3 is the number of bytes for each pixel -> red, green, blue

	// blue, green, red order because Bitmap is a little-endian file format
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

Bitmap::~Bitmap()
{
}

