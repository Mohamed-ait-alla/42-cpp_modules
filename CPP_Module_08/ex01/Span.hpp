// ****************************************************************************** //
//                        file: Span.hpp                                          //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/28 08:57 by mait-all                   //
//                        Updated: 2025/11/28 17:30 by mait-all                   //
// ****************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>


// ****************************************************************************** //
//                                   Span Class                                   //
// ****************************************************************************** //

class Span {
	
	public:
		// ocf
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		// member functions
		void	addNumber(int nb);
		void	shortestSpan();
		void	longestSpan();


		// === addRangeOfNumbers<T>() ================================================= //
		// add a range of numbers to the vector.
		// ============================================================================ //
		template <typename Iterator>
		void	addRangeOfNumbers(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) > static_cast<unsigned int>(_maxSize - _vect.size()))
				throw std::out_of_range("Error: No enough space in span to all numbers!");
			_vect.insert(_vect.begin(), begin, end);
		}

	private:
		std::vector<int>	_vect;
		unsigned int		_maxSize;

};

#endif /* __SPAN_HPP__ */