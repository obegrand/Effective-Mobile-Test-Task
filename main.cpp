#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::cout << "Enter input BMP file name : ";
	std::string bmp_in;
	std::cin >> bmp_in;
	std::ifstream in(bmp_in);
	if (in.fail()) return 1;
	//тут и начинаеться магия

}