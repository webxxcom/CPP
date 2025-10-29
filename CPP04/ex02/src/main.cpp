#include <iostream>
#include "Cat.h"
#include "Dog.h"

void testForDeepCopy(Dog)
{
    std::cout << "Simulating some work..\n";
}

int main()
{
    const int N = 100;
    std::cout << "Creating an array of 100 pointers to Animal..\n";
    Animal *animals[N];

    std::cout << "Filling the array with cats and dogs..\n";
    for(size_t i = 0; i < N; ++i)
    {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << "Testing for deep copy..\n";
    testForDeepCopy(*(Dog *)animals[0]);
    std::cout << "Deleting the animal pointers..\n";
    for(size_t i = 0; i < N; ++i)
        delete animals[i];
}