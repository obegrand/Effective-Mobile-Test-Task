#include "BMP.h"
#include <iostream>

bool BMP::LoadBMP(Path& path){
	std::ifstream file(path, std::ios::binary);
	if (!file) return 0;

	file.read(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));
	file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
	
	for (int y = 0; y < infoHeader.biHeight; ++y) {
		for (int x = 0; x < infoHeader.biWidth; ++x) {
			tagRGBQUAD pixel;
			file.read(reinterpret_cast<char*>(&pixel), sizeof(tagRGBQUAD));
			pixels.push_back(pixel);
		}
	}
	return 1;
}

bool BMP::SaveBMP(Path& path){
	return false;
}

void BMP::PrintBMP(){
}
