#pragma once
#include <cstdint>

struct BMP_File {

	//Header (size = 14)
	char b_symbol = 'B';
	char m_symbol = 'M';
	uint32_t FileSize = 0;
	uint32_t Reserved = 0;
	uint32_t DataOffset = 54;

	//InfoHeader
	uint32_t Size = 40;
	uint32_t Width = 0;
	uint32_t Height = 0;
	uint16_t Planes = 1;
	uint16_t BitCount = 24; //или 32
	uint32_t Compression = 0;
	uint32_t ImageSize = 0;
	uint32_t XpixelsPerM = 11811; //300 pixels per inch
	uint32_t YpixelsPerM = 11811; //300 pixels per inch
	uint32_t ColorsUsed = 0;
	uint32_t ColorsImportant = 0;
};
