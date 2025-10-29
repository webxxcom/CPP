#include "ScavTrap.h"
#include "FragTrap.h"
#include <iostream>

int main(void)
{
    std::cout << "\n=== CONSTRUCTION CHAIN TEST ===\n";
    FragTrap *f1 = new FragTrap("Fraggy");

    std::cout << "\n=== BASIC ACTIONS ===\n";
    f1->attack("Training Dummy");
    f1->takeDamage(20);
    f1->beRepaired(10);

    std::cout << "\n=== UNIQUE ABILITY ===\n";
    f1->highFivesGuys();

    std::cout << "\n=== ENERGY & DAMAGE TEST ===\n";
    for (int i = 0; i < 5; ++i)
        f1->attack("Target");
    f1->beRepaired(15);

    std::cout << "\n=== DAMAGE TO DEATH TEST ===\n";
    f1->takeDamage(200);
    f1->attack("Nobody");
    f1->beRepaired(5);
    f1->highFivesGuys();

    std::cout << "\n=== DESTRUCTION CHAIN TEST ===\n";
    delete f1;
    return 0;
}
