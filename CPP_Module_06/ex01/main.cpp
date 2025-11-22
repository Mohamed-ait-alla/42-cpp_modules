/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise introduces low-level pointer manipulation in C++ through a simple
 * 			serialization concept. The goal is to understand how reinterpret_cast works
 * 			by converting raw pointers to integer representations and back.
 * 
 * 			A Serialize class is implemented with two static member functions:
 * 
 * 				- serialize(Data* ptr)
 * 					Converts a pointer to a uintptr_t integer representation.
 * 
 * 				- deserialize(uintptr_t raw)
 * 					Converts the integer value back into the original Data* pointer.
 * 
 * 			The purpose of this exercise is to gain familiarity with pointer casting and
 * 			understand when reinterpret_cast is appropriate and when it is dangerous.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./serializer
 * 			3. CleanUp:	make fclean
*/

#include "Serializer.hpp"

int	main()
{
	Data data;
	data.x = 10;

	Data*		ptr = &data;

	std::cout << "--------- Before converting ---------" << std::endl;
	std::cout << "Address of ptr: " << ptr << " and it's value: " << ptr->x << std::endl;

	uintptr_t	raw = Serializer::serialize(ptr);
	Data*		convertedPtr = Serializer::deserialize(raw);

	std::cout << "\n--------- After converting ---------" << std::endl;
	std::cout << "Address of convertedPtr: " << convertedPtr << " and it's value: " << convertedPtr->x << std::endl;

	return (0);
}