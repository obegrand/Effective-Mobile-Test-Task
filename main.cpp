#include <iostream>
#include <string>
#include <fstream>

#include "BMP.h"

using namespace std;

#define DEBUG

int main() {
#ifdef DEBUG
	Path bmp_filename_in("in.bmp");
	BMP bmp;
	bmp.LoadBMP(bmp_filename_in);
	bmp.PrintBMP();
	bmp.MakeLine(4, 4, 17, 13);
	bmp.MakeLine(19, 3, 6, 16);
	bmp.PrintBMP();
	Path bmp_filename_out("out.bmp");
	bmp.SaveBMP(bmp_filename_out);
#endif // DEBUG
#ifndef DEBUG
	cout << "Enter input BMP file name : ";
	Path bmp_filename_in;
	cin >> bmp_filename_in;
	BMP bmp;
	bmp.LoadBMP(bmp_filename_in);
	bmp.PrintBMP();
	cout << "Enter x1, y1, x2, y2 for first line: ";
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	bmp.MakeLine(x1, y1, x2, y2);
	cout << "Enter x1, y1, x2, y2 for second line: ";
	cin >> x1 >> y1 >> x2 >> y2;
	bmp.MakeLine(x1, y1, x2, y2);
	bmp.PrintBMP();
	cout << "Enter output BMP file name : ";
	Path bmp_filename_out;
	cin >> bmp_filename_out;
	bmp.SaveBMP(bmp_filename_out);
#endif // !DEBUG
}