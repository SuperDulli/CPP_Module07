# CPP_Module07
C++ templates

## ex00: Start with a few functions

intro to template functions

**swap**: Swaps the values of two given arguments. Does not return anything.

**min**: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.

**max**: Compares the two values passed in its arguments and returns the greatest
one. If the two of them are equal, then it returns the second one.

all of these functions take in two arguments of the same type and they must support the comparison operators.

## ex01: Iter

template function that takes three parameters and return nothing.

- adress of the array,
- length of the array,
- function to call on each element of the array.

the function can also be an instantiated dunction template.

## ex02: Array

class template

- Default constructor: creates empty array
- constructor with parameter *unsigned int n*: creates array of *n* elements with their default value
- copying the array by copy constructor or copy assignment operator: creates deep copy
- dynamicly allocates memory with **new[]**
- provide read/write access to elements with the subscript operator **[]**
- throws an exception when trying to access an element which index is out of bounds: `array[-1];` `array[len];`
- member function *size()* that returns the number of elements in the array.
