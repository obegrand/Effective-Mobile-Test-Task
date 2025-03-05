#pragma once
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using Path = std::string;

class BMP {
public:
	BMP();
	bool LoadBMP(Path& path);
	bool SaveBMP(Path& path);
	void PrintBMP();
private:
	//https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapfileheader
	BITMAPFILEHEADER fileHeader;
	//https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader
	BITMAPINFOHEADER infoHeader;
	//https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-rgbquad
	std::vector<tagRGBQUAD> pixels;
};