#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int i) {
	std::cout << i << " ";
}

void increment(int& i) {
	i++;
}

void putChar(char const& c) {
	std::cout << c;
}

void toUppercase(char& c) {
	c = toupper(c);
}

int main(void) {

	int integers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter(integers, sizeof(integers) / sizeof(int), printInt);
	std::cout << std::endl;

	iter(integers, sizeof(integers) / sizeof(int), increment);
	iter(integers, sizeof(integers) / sizeof(int), printInt);
	std::cout << std::endl;

	std::string noise = "* feedback noises *";
	iter(noise.c_str(), noise.length(), putChar);
	std::cout << std::endl;

	char* str = &noise.at(0);
	iter(str, noise.length(), toUppercase);
	iter(noise.c_str(), noise.length(), putChar);
	std::cout << std::endl;

	return 0;
}
