// ****************************************************************************** //
//                        file: Serializer.hpp                                    //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/19 14:53 by mait-all                   //
//                        Updated: 2025/11/19 19:37 by mait-all                   //
// ****************************************************************************** //

#ifndef	SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

// Data struct
typedef struct t_Data {
	int	x;
} Data;

// ****************************************************************************** //
//                               Serializer Class                                 //
// ****************************************************************************** //

class Serializer {

	public:
		// member functions
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		// ocf
		// ocf is private to make the class instantiable
		Serializer();
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer();
};


#endif /* __SERIALIZER_HPP__ */