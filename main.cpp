#include <iostream>
#include <string>
#include <fstream>

#include "BMP.h"

using namespace std;

int main() {
	cout << "Enter input BMP file name : ";
	Path bmp_filename_in;
	cin >> bmp_filename_in;
	BMP bmp;
	Path testpath(bmp_filename_in);
	bmp.LoadBMP(testpath);
	bmp.PrintBMP();
}