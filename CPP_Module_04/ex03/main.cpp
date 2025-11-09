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
	std::cout << "========== [ TEST 1: Basic Materia Learning ] ==========\n";
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

	std::cout << "\n========== [ TEST 2: Create Materias ] ==========\n";
	AMateria*	ice = src->createMateria("ice");
	AMateria*	cure = src->createMateria("cure");
	AMateria*	unknown = src->createMateria("fire"); // NULL expected

	std::cout << std::endl;

	if (ice)
		std::cout << "Created materia: " << ice->getType() << std::endl;
	if (cure)
		std::cout << "Created materia: " << cure->getType() << std::endl;
	if (!unknown)
		std::cout << "Error: Invalid materia type" << std::endl;
	
	std::cout << "\n========== [ TEST 3: Character Equip/Use/Unequip ] ==========\n";
	ICharacter*	me = new Character("me");

	std::cout << std::endl;
	std::cout << std::endl;

	me->equipe(ice);
	me->equipe(cure);

	std::cout << "--- Before unequipe ---" << std::endl;
	me->use(0, *me);
	me->use(1, *me);

	me->unequipe(0);
	me->unequipe(1);

	std::cout << "--- after unequipe ---" << std::endl;
	me->use(0, *me);
	me->use(1, *me);

	std::cout << "--- Equipe again ---" << std::endl;
	me->equipe(ice);
	me->equipe(cure);
	me->use(0, *me);
	me->use(1, *me);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "\n========== [ TEST 4: Deep Copy Character ] ==========\n";
	Character a(*(Character*)me);

	a.unequipe(0);
	a.equipe(new Cure());
	std::cout << std::endl;
	a.use(0, a);
	a.use(1, a);
	std::cout << "---- ---- ---- ----" << std::endl;
	me->use(0, *me);
	me->use(1, *me);

	std::cout << std::endl;
	std::cout << std::endl;

	delete src;
	delete me;

    return (0);
}