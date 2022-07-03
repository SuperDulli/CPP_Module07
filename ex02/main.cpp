#include <iostream>
#include <string>
#include "Array.hpp"

void printCharArray(Array<char> const& arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

int main(void) {

	Array<int> intArray = Array<int>();
	std::cout << intArray.size() << std::endl;
	// std::cout << intArray[0] << std::endl; // array is empty -> exception is thrown

	Array<char> charArray(5);
	charArray[0] = 'P';
	charArray[1] = 'e';
	charArray[2] = 'p';
	charArray[3] = 's';
	charArray[4] = 'i';

	Array<char> copy(charArray);
	copy[0] = 'S';
	copy[1] = 'u';
	copy[2] = 'n';
	copy[3] = 'n';
	copy[4] = 'y';

	Array<char> assign = charArray;
	assign[2] = 'X';

	printCharArray(charArray);
	printCharArray(copy);
	printCharArray(assign);

	try
	{
		charArray[-1] = 'x';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		charArray[5] = 'x';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<std::string> const strArray(3);
	std::cout << strArray[1] << std::endl;
	// strArray[1] = "World"; // can't write to a const
	// std::cout << strArray[1].append("42") << std::endl; // return value is const is array is const

	return 0;
}
