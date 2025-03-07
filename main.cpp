#include <iostream>
#include <string>
#include <fstream>

#include "BMP.h"

using namespace std;

int main() {
	//cout << "Enter input BMP file name : ";
	//Path bmp_filename_in;
	//cin >> bmp_filename_in;
	BMP bmp;
	Path testpath("19x15box.bmp");
	bmp.LoadBMP(testpath);
	bmp.PrintBMP();
	cout<<Path(38, '-')<<'\n';
	bmp.MakeLine(3, 3,15, 11 );
	bmp.MakeLine(13, 3,4, 10 );
	bmp.PrintBMP();
}