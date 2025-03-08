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
	bmp.MakeLine(6, 6,16, 15 );
	bmp.MakeLine(16, 6,7, 12 );
	bmp.PrintBMP();
Path testpathout("19x15boxOUT.bmp");
	bmp.SaveBMP(testpathout);
}