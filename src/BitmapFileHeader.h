/*
 * This file contains the structure BitmapFileHeader which has the data which has
 * to be written at the beginning of a Bitmap file in order to be a valid file.
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>
using namespace std;

// Aligns structure members on 2-byte boundaries
#pragma pack(push, 2)

	struct BitmapFileHeader
	{
		char header[2]{'B', 'M'};
		int32_t fileSize; // The size of the final file
		int32_t reserved{0}; // Always set to 0
		int32_t dataOffset; // Where the actual data begins is the file
	};

#pragma pack(pop)

#endif /* BITMAPFILEHEADER_H_ */
