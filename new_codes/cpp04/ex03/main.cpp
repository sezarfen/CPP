#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    // Tests provided by the subject
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    ////////////////

    // My Tests
    std::cout << "TEST 1 : Normal initialization" << std::endl;
    Ice *ice = new Ice();
    std::cout << "Type of the ice : " << ice->getType() << std::endl;
    Cure *cure = new Cure();
    std::cout << "Type of the cure : " << cure->getType() << std::endl;
    std::cout << "--- END OF TEST 1 ---" << std::endl;

    std::cout << "TEST 2 : Other member functions" << std::endl;


    MateriaSource *source = new MateriaSource();
    source->learnMateria(ice);
    source->learnMateria(cure);
    //MateriaSource *source2 = new MateriaSource(*source);
    AMateria *newIce = source->createMateria("ice");





    ICharacter *myCharacter = new Character("myCharacter");
    myCharacter->equip(ice);
    myCharacter->unequip(0);
    myCharacter->equip(newIce);
    myCharacter->use(0, *myCharacter);
    std::cout << "--- END OF TEST 2 ---" << std::endl;
    int i = 0;
    delete ice;
    std::cout << i++ << std::endl;
    delete cure;
    std::cout << i++ << std::endl;
    delete source;
    std::cout << i++ << std::endl;
    delete myCharacter; // will also delete newIce
    return 0;
}