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
	if (bmp.LoadBMP(bmp_filename_in)) {
		cout << "file uploaded successfully\n";
	}
	else {
		cout << "file upload fail\n";
	}
	bmp.PrintBMP();
	if (bmp.MakeLine(4, 4, 17, 13)) {
		cout << "line drawed successfully\n";
	}
	else {
		cout << "line drawed fail\n";
	}
	if (bmp.MakeLine(19, 3, 6, 16)) {
		cout << "line drawed successfully\n";
	}
	else {
		cout << "line drawed fail\n";
	}
	bmp.PrintBMP();
	Path bmp_filename_out("out.bmp");
	if (bmp.SaveBMP(bmp_filename_out)) {
		cout << "file saving successfully\n";
	}
	else {
		cout << "file saving fail\n";
	}
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