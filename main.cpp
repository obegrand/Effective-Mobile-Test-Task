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
	bmp.LoadBMP(bmp_filename_in);
	system("pause");
}