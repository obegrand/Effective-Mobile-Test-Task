#pragma once
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using Path = std::string;

class BMP {
public:
	bool LoadBMP(Path& path);
	bool SaveBMP(Path& path);
	bool MakeLine(int x1, int y1, int x2, int y2);
	void PrintBMP();
private:
	enum Color {
		Black = 0,
		White = 1
	};
	void SetColor(Color color, int x1, int y1);

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	std::vector<RGBTRIPLE> pixels;
};