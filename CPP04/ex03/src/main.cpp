#include <iostream>
#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"
#include "ICharacter.h"
#include "Character.h"
#include "IMateriaSource.h"
#include "MateriaSource.h"

void test1(void)
{
    std::cout << "=== TEST 1: Basic creation & clone ===" << std::endl;
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();
    std::cout << "Ice type: " << ice->getType() << " (expected: ice)" << std::endl;
    std::cout << "Cure type: " << cure->getType() << " (expected: cure)" << std::endl;

    AMateria *iceClone = ice->clone();
    std::cout << "Clone type: " << iceClone->getType() << " (expected: ice)" << std::endl;

    delete iceClone;
    delete ice;
    delete cure;
}

void test2(void)
{
    std::cout << "\n=== TEST 2: Basic use ===" << std::endl;
    Character cloud("Cloud");
    Character seph("Sephiroth");
    cloud.equip(new Ice());
    cloud.equip(new Cure());
    cloud.use(0, seph);  // expected: shoots ice bolt at Sephiroth
    cloud.use(1, cloud); // expected: heals Cloud's wounds
}

void test3(void)
{
    std::cout << "\n=== TEST 3: Inventory limits ===" << std::endl;
    ICharacter *cloud = new Character("Cloud");
    Character seph("Sephiroth");

    cloud->equip(new Ice());
    cloud->equip(new Cure());
    cloud->equip(new Ice());
    cloud->equip(new Cure());
    cloud->equip(new Ice()); // should be ignored (5th materia)
    for (int i = 0; i < 5; i++)
        cloud->use(i, seph);
    delete cloud;
}

void test4(void)
{
    std::cout << "\n=== TEST 4: Unequip behavior ===" << std::endl;
    ICharacter *cloud = new Character("Cloud");
    Character seph("Sephiroth");

    AMateria *tmp = new Ice();
    cloud->equip(tmp);
    cloud->unequip(0);   // should not delete tmp
    cloud->use(0, seph); // nothing happens
    delete cloud;
}

void test5(void)
{
    std::cout << "\n=== TEST 5: Copy semantics (deep copy) ===" << std::endl;
    Character cloud("Cloud");
    Character seph("Sephiroth");

    cloud.equip(new Ice());
    Character copyCloud(cloud); // copy constructor
    cloud.use(0, seph);
    copyCloud.use(0, seph); // should still work
    cloud.unequip(0);       // remove from cloud
    copyCloud.use(0, seph); // copy still has its own Ice
    Character assignCloud("Temp");
    assignCloud = cloud;      // operator=
    assignCloud.use(0, seph); // must work or do nothing safely
}

void test6(void)
{
    std::cout << "\n=== TEST 6: MateriaSource learning & creating ===" << std::endl;
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice()); // ignored (5th)

    AMateria *createdIce = src.createMateria("ice");
    AMateria *createdCure = src.createMateria("cure");
    AMateria *unknown = src.createMateria("fire"); // nullptr

    std::cout << "Created ice type: " << (createdIce ? createdIce->getType() : "null") << std::endl;
    std::cout << "Created cure type: " << (createdCure ? createdCure->getType() : "null") << std::endl;
    std::cout << "Created fire type: " << (unknown ? unknown->getType() : "null (expected)") << std::endl;

    delete createdIce;
    delete createdCure;
    // unknown is nullptr, no delete
}

void test7(void)
{
    std::cout << "\n=== TEST 7: Integration ===" << std::endl;
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());

    Character hero("Cloud");
    Character villain("Sephiroth");

    AMateria *m1 = src.createMateria("ice");
    AMateria *m2 = src.createMateria("cure");

    hero.equip(m1);
    hero.equip(m2);

    hero.use(0, villain);
    hero.use(1, hero);

    hero.unequip(0);
    villain.equip(m1);
}

void test8(void)
{
    std::cout << "\n=== TEST 8: Destructor / memory leaks ===" << std::endl;
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    {
        Character temp("Temporary");
        temp.equip(src.createMateria("ice"));
        temp.equip(src.createMateria("cure"));
        // automatic cleanup at scope exit
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}
