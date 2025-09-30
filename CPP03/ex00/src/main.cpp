#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

void testCat(void)
{
    Animal *cat = new Cat();
    std::cout << "The animal has type of " << cat->getType() << " and has sound ";
    cat->makeSound();
    delete cat;
}

void testDog(void)
{
    Animal const *dog = new Dog();
    std::cout << "The animal has type " << dog->getType() << " and has sound ";
    dog->makeSound();
    delete dog;
}

void testAnimal(void)
{
    Animal *an = new Animal();
    an->makeSound();
    delete an;
}

void testWrongCat(void)
{
    WrongAnimal *cat = new WrongCat();
    cat->makeSound();
    delete cat;
}

int main()
{
    std::cout << "Testing cat.." << std::endl;
    testCat();
    std::cout << "\nTesting dog.." << std::endl;
    testDog();
    std::cout << "\nTesting just an animal.." << std::endl;
    testAnimal();
    std::cout << "\nTesting wrong animal.." << std::endl;
    testWrongCat();
}