// ****************************************************************************** //
//                        file: BaseFactory.cpp                                   //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/20 19:59 by mait-all                   //
//                        Updated: 2025/11/21 09:17 by mait-all                   //
// ****************************************************************************** //

#include "BaseFactory.hpp"


// generate a random object
Base*	generate(void)
{
	int		generatedRandomNb;
	Base*	availableObjs[3] = {
									new A(),
									new B(),
									new C()
								};
	srand(static_cast<unsigned int>(time(0)));

	generatedRandomNb = rand() % 3;

	// free unused objects
	for (int i = 0; i < 3; i++)
	{
		if (i != generatedRandomNb)
			delete availableObjs[i];
	}

	return (availableObjs[generatedRandomNb]);
}

// detect the type of generated object: pointer version
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type (pointer): A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type (pointer): B" << std::endl;
	else
		std::cout << "Type (pointer): C" << std::endl;
}

// detect the type of generated object: reference version
void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type (reference): A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type (reference): B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type (reference): C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	
	std::cout << "Unknown type" << std::endl;
}