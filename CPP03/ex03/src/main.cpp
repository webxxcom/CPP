#include "DiamondTrap.h"
#include <iostream>

int	main(void)
{
	std::string s1 = "Clyde";
	std::string s2 = "Scarlet";
	std::string s3 = "Fred";
	std::string s4 = "Diego";

	// Constructors
	DiamondTrap	diamondtrap(s4);
	std::cout << std::endl;

	// Repairs
	std::cout << "DiamondTrap is going to take 14 damage and repair itself for 18" << std::endl;
	std::cout << "DiamondTrap hp before: " << diamondtrap.getHitPoints() << std::endl;
	diamondtrap.takeDamage(14);
	diamondtrap.beRepaired(18);
	std::cout << "DiamondTrap hp after: " << diamondtrap.getHitPoints() << std::endl;
	std::cout << std::endl;

	// New class attack
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);
	diamondtrap.attack(s2);
	std::cout << std::endl;

	diamondtrap.guardGate();
	diamondtrap.attack(s2);
	std::cout << std::endl;
	diamondtrap.takeDamage(1000);
	diamondtrap.guardGate();
	diamondtrap.attack(s2);
	diamondtrap.beRepaired(10);
	std::cout << std::endl;
	
	// New class personal method call
	diamondtrap.highFivesGuys();
	std::cout << std::endl;

	diamondtrap.whoAmI();
	std::cout << std::endl;
	// Repair over max hp
	diamondtrap.beRepaired(180000);

	// Take damage
	diamondtrap.takeDamage(50);

	// Die
	diamondtrap.takeDamage(50);

	// Do something after dying
	diamondtrap.beRepaired(20);
	diamondtrap.attack(s2);

	std::cout << std::endl;
	return (0);
}