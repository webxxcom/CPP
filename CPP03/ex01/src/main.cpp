#include "ClapTrap.h"
#include "ScavTrap.h"
#include <iostream>

int main(void)
{
    std::cout << "\n=== CONSTRUCTION CHAIN TEST ===\n";
    ScavTrap *s1 = new ScavTrap("Serena");

    std::cout << "\n=== BASIC ACTIONS ===\n";
    s1->attack("TargetDummy");  // ScavTrap override
    s1->takeDamage(30);
    s1->beRepaired(10);

    std::cout << "\n=== UNIQUE ABILITY ===\n";
    s1->guardGate();

    std::cout << "\n=== ENERGY & DAMAGE TEST ===\n";
    for (int i = 0; i < 5; ++i)
        s1->attack("EnergyTarget"); // uses energy
    s1->beRepaired(5);

    std::cout << "\n=== DEAD ROBOT TEST ===\n";
    s1->takeDamage(150);   // should drop to 0 HP
    s1->attack("Nope");    // should fail (no HP)
    s1->guardGate();       // still can print, but semantically "dead"

    std::cout << "\n=== DESTRUCTION CHAIN TEST ===\n";
    delete s1;
    return 0;
}
