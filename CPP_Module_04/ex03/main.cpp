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

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main (void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria*   tmp;
    tmp = src->createMateria("ice");
    me->equipe(tmp);
    tmp = src->createMateria("cure");
    me->equipe(tmp);
    me->equipe(tmp);
    me->equipe(tmp);
    me->equipe(tmp);

    ICharacter* bob = new Character("bob");

	std::cout << std::endl;
	std::cout << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
	me->use(2, *bob);
	// _inventuaryCopy needs more size: !memory leak
	std::cout << std::endl;
	std::cout << std::endl;

    delete bob;
    delete me;
    delete src;

    return (0);
}