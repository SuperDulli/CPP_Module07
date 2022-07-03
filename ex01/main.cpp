#include <iostream>
#include <string>
#include "iter.hpp"
#include "printAddress.hpp"

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

void printString(std::string const& s) {
	std::cout << s << " ";
}

void iterString(std::string const& s) {
	iter<char>(s.c_str(), s.length(), putChar);
}

int main(void) {
	std::cout << "--- Test with int array ---" << std::endl;

	int integers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter(integers, 5, printInt);
	std::cout << std::endl;
	iter(integers, sizeof(integers) / sizeof(int), printInt);
	std::cout << std::endl;

	iter(integers, sizeof(integers) / sizeof(int), increment);
	iter(integers, sizeof(integers) / sizeof(int), printInt);
	std::cout << std::endl;
	iter(integers, sizeof(integers) / sizeof(int), printAddress<int>);
	// iter(integers, sizeof(integers) / sizeof(int), printAddress<char>); // type of the instantiated function templated does not match the type of the array

	std::cout << "--- Test with char array ---" << std::endl;

	std::string noise = "* feedback noises *";
	iter(noise.c_str(), noise.length(), putChar);
	std::cout << std::endl;

	char* str = &noise.at(0);
	iter(str, noise.length(), toUppercase);
	iter(noise.c_str(), noise.length(), putChar);
	std::cout << std::endl;

	iter(str, noise.length(), printAddress<char>);

	std::cout << "--- Test with std::strings ---" << std::endl;

	std::string strings[] = {
		"Pepsi",
		"Sunny",
		"end"
	};

	iter(strings, 2, printAddress<std::string>);
	iter(strings, 3, printString);
	std::cout << std::endl;
	iter(strings, 3, iterString);
	std::cout << std::endl;

	return 0;
}
