/*
 * @author:
 * 			ToDo...
 * 
 * @github:
 * 			ToDo...
 * 
 * @description:
 * 			ToDo...
 * 
 * 
 * @usage:
 * 			ToDo...
 *
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