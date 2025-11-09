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
	tmp = src->createMateria("ice");
    me->equipe(tmp);
	tmp = src->createMateria("cure");
    me->equipe(tmp);// _inventory = [0x100, NULL, NULL, NULL]
	me->unequipe(0);// _inventory = [NULL, NULL, NULL, NULL] // _inventoryCopy = [0x100, NULL, NULL, NULL]
	// me->equipe(tmp);
	me->unequipe(1);
	me->unequipe(2);
	me->unequipe(3);
	// tmp = src->createMateria("ice");
	// // me->equipe(tmp); // _inventory = [NULL, NULL, NULL, NULL] // _inventoryCopy = [0x100, 0x200, 0x300, 0x400]
	// me->equipe(tmp); // _inventory = [0x200, NULL, NULL, NULL] // _inventoryCopy = [0x100, 0x200, 0x300, 0x400]
	// me->unequipe(0);
	// me->unequipe(0);
	// me->equipe(tmp);
	// me->equipe(tmp);
	tmp = src->createMateria("ice");
    me->equipe(tmp);
    tmp = src->createMateria("cure");
    me->equipe(tmp);
	tmp = src->createMateria("ice");
    me->equipe(tmp);
	tmp = src->createMateria("cure");
	me->equipe(tmp);
	// me->unequipe(0);
	// me->unequipe(1);
	// me->unequipe(2);
	// me->unequipe(3);
	
    ICharacter* bob = new Character("bob");

	std::cout << std::endl;
	std::cout << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	// _inventuaryCopy needs more size: !memory leak
	std::cout << std::endl;
	std::cout << std::endl;

    delete bob;
    delete me;
    delete src;
	delete tmp;

	// AMateria*	test;
	// IMateriaSource*	m = new MateriaSource();
	// ICharacter*	me = new Character("me");
	// test = m->createMateria("ice");
	// me->equipe(test);
	// me->equipe(new Cure());
	// me->equipe(new Ice());
	// me->equipe(new Cure());
	// me->unequipe(0);
	// me->equipe(test);

	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// me->use(0, *me);
	// me->use(1, *me);
	// me->use(2, *me);

	// me->use(3, *me);
	// std::cout << std::endl;
	// std::cout << std::endl;

	// delete me;
	// delete test;
	// delete m;
    return (0);
}