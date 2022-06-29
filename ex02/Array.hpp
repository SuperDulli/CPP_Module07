#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template< typename T >
class Array {

public:

	Array(void): m_elements(NULL), m_len(0) {}
	Array(Array<T> const& other): m_elements(NULL) {
		*this = other;
	}
	Array(unsigned int n): m_len(n) {
		this->m_elements = new T[n];
	}
	~Array(void) {
		if (this->m_elements)
			delete[] this->m_elements;
	}

	Array<T>& operator=(Array<T> const& other) {
		if (this->m_elements)
			delete[] this->m_elements;
		this->m_len = other.m_len;
		this->m_elements = new T[m_len];
		for (size_t i = 0; i < this->m_len; i++)
		{
			this->m_elements[i] = other.m_elements[i];
		}
		return *this;
	}

	// subscript operator
	T& operator[](unsigned int idx) throw(std::exception) {
		if (idx >= this->m_len) {
			throw std::out_of_range("index out of the array bounds.");
		}
		return this->m_elements[idx];
	}

	// subscript operator for constant instances
	T const& operator[](unsigned int idx) const throw(std::exception) {
		if (idx >= m_len) {
			throw std::out_of_range("index out of the array bounds.");
		}
		return m_elements[idx];
	}

	unsigned int size(void) const {
		return m_len;
	}

private:

	T*				m_elements;
	unsigned int	m_len;

};

#endif
