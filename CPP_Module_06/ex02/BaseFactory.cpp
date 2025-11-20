// ****************************************************************************** //
//                        file: BaseFactory.cpp                                   //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/20 19:59 by mait-all                   //
//                        Updated: 2025/11/20 20:46 by mait-all                   //
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
