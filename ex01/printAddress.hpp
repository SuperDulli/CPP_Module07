#ifndef PRINT_ADDRESS_H
#define PRINT_ADDRESS_H

#include <iostream>

template<typename T>
void printAddress(T const& obj) {
	std::cout << obj << " at " << static_cast<void const*>(&obj) << std::endl;
}

#endif
