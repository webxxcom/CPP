#include "ClapTrap.h"
#include <iostream>

int main(void)
{
    ClapTrap a("Jack");
    ClapTrap b("Bob");

    std::cout << "\n=== BASIC ACTIONS ===\n";
    a.attack("Bob");
    b.takeDamage(3);
    b.beRepaired(2);

    std::cout << "\n=== ENERGY DRAIN TEST ===\n";
    for (int i = 0; i < 10; ++i)
        a.attack("training dummy");
    // This one should fail — no energy left
    a.attack("training dummy");

    std::cout << "\n=== DAMAGE AND DEATH TEST ===\n";
    b.takeDamage(20); // Should drop below zero HP
    b.attack("Jack"); // Should fail (no HP)
    b.beRepaired(5);  // Should fail (no HP)

    std::cout << "\n=== MULTIPLE REPAIRS ===\n";
    ClapTrap c("Healer");
    for (int i = 0; i < 3; ++i)
        c.beRepaired(4);

    std::cout << "\n=== END OF TESTS ===\n";
    return 0;
}
