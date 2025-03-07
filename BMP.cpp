#include "BMP.h"
#include <iostream>

bool BMP::LoadBMP(Path& path) {
	std::ifstream file(path, std::ios::binary);
	if (!file) return 0;

	file.read(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));
	file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));

	pixels.reserve(infoHeader.biHeight * infoHeader.biWidth);
	for (int y = 0; y < infoHeader.biHeight; ++y) {
		for (int x = 0; x < infoHeader.biWidth; ++x) {
			RGBTRIPLE pixel;
			file.read(reinterpret_cast<char*>(&pixel), sizeof(RGBTRIPLE));
			pixels.push_back(pixel);
		}
		int padding32bit = (4 - (infoHeader.biWidth * sizeof(RGBTRIPLE) % 4)) % 4;
		file.ignore(padding32bit);
	}
	return 1;
}

bool BMP::SaveBMP(Path& path) {
	return false;
}

void BMP::PrintBMP() {
	for (int y = infoHeader.biHeight; y != 0; --y) {
		for (int x = 0; x < infoHeader.biWidth; ++x) {
			RGBTRIPLE pixel = pixels[(y - 1) * infoHeader.biWidth + x];
			if (pixel.rgbtBlue == 255) {
				std::cout << char(219) << char(219);
			}
			else {
				std::cout << char(32) << char(32);
			}
		}
		std::cout << '\n';
	}
}