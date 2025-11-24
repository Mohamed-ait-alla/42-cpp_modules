// ****************************************************************************** //
//                        file: Array.hpp                                         //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/24 09:54 by mait-all                   //
//                        Updated: 2025/11/24 14:10 by mait-all                   //
// ****************************************************************************** //

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstddef>

// ****************************************************************************** //
//                             Array Class Template                               //
// ****************************************************************************** //

template <typename T> class Array {

	public:
		// ocf
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array();

		// operators
		T&				operator[](size_t index);
		const T&		operator[](size_t index) const;	

		// member functions
		unsigned int	size() const;

	private:
		T*				_arr;
		unsigned int	_len;

};


#endif /* __ARRAY_HPP__ */