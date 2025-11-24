// ****************************************************************************** //
//                        file: Array.tpp                                         //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/24 11:34 by mait-all                   //
//                        Updated: 2025/11/24 14:29 by mait-all                   //
// ****************************************************************************** //

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array() : _arr(NULL), _len(0)
{
}

// Parametrised constructor
template <typename T>
Array<T>::Array(unsigned int n) : _len(n)
{
	_arr = new T[n]();
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other)
{
	*this = other;
}

// Copy assignment operator
template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		if (other._arr)
			delete []other._arr;
		this->_len = other._len;
		this->_arr = new T[this._len]();
		for (int i = 0; i < this->_len; i++)
		{
			this->_arr[i] = other._arr[i];
		}
	}
	return (*this);
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete []this->_arr;
}

// [] subscript operator: non-const version
template <typename T>
T&		Array<T>::operator[](size_t index)
{
	if (index >= this->_len)
		throw std::out_of_range("index is out of range");
	return (this->_arr[index]);
}

// [] subscript operator: const version
template <typename T>
const T&	Array<T>::operator[](size_t index) const
{
	if (index >= this->_len)
		throw std::out_of_range("index is out of range");
	return (this->_arr[index]);
}

// member function: returns the nb of array's elements
template <typename T>
unsigned int	Array<T>::size() const 
{
	return (_len);
}


#endif /* __ARRAY_TPP__ */
