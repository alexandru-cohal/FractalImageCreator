/*
 * This file contains the structure BitmapInfoHeader which has the information
 * about the Bitmap data contained in the file.
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>
using namespace std;

// Aligns structure members on 2-byte boundaries
#pragma pack(push, 2)

	struct BitmapInfoHeader
	{
		int32_t headerSize{40}; // The size of the struct (bytes)
		int32_t width; // The width of the bitmap
		int32_t height; // The height of the bitmap
		int16_t planes{1};
		int16_t bitsPerPixel{24}; // One byte for each color (R, G, B)
		int32_t compression{0}; // 0 = No compression
		int32_t dataSize{0}; // The size of the data written in the file
		int32_t horizontalResolution{2400};
		int32_t verticalResolution{2400};
		int32_t colors{0};
		int32_t importantColors{0};
	};

#pragma pack(pop)

#endif /* BITMAPINFOHEADER_H_ */
