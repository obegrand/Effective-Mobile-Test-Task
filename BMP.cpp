#include "BMP.h"
#include <iostream>

bool BMP::LoadBMP(Path& path) {
	std::ifstream file(path, std::ios::binary);
	if (!file) return false;

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
	return true;
}

bool BMP::SaveBMP(Path& path) {
	return false;
}

bool BMP::MakeLine(int x1, int y1, int x2, int y2) {
	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 ||
		x1 >= infoHeader.biWidth || x2 >= infoHeader.biWidth ||
		y1 >= infoHeader.biHeight || y2 >= infoHeader.biHeight) {
		return false;
	}

	//�������� �����������: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int err = dx - dy;

	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;

	while (true) {
		SetColor(White, x1, y1);
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
	return true;

}

void BMP::PrintBMP() {
	if (pixels.size() == 0)return;
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

void BMP::SetColor(Color color, int x, int y) {
	int index = (infoHeader.biHeight - y - 1) * infoHeader.biWidth + x;
	RGBTRIPLE* pixel = &pixels[index];
	if (color == White){
		pixel->rgbtBlue = 255;
		pixel->rgbtGreen = 255;
		pixel->rgbtRed = 255;
	}
	else {
		pixel->rgbtBlue = 0;
		pixel->rgbtGreen = 0;
		pixel->rgbtRed = 0;
	}
}
