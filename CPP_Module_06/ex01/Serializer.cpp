// ****************************************************************************** //
//                        file: Serializer.cpp                                    //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/19 14:53 by mait-all                   //
//                        Updated: 2025/11/20 09:40 by mait-all                   //
// ****************************************************************************** //

#include "Serializer.hpp"


// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
Serializer::Serializer()
{
}

// Copy constructor
Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

// Copy assignment operator
Serializer&	Serializer::operator=(const Serializer& other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

// Destructor
Serializer::~Serializer()
{
}


// -------------------------------
// Member functions
// -------------------------------

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
