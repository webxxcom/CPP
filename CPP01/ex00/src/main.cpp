#include "Zombie.h"
#include <iostream>

int main(){
    Zombie *z = newZombie("Heap allocated zombie");
    z->announce();
    randomChump("Stack allocated zombie");
    std::cout << "exiting main..\n";
    delete z;
    return 0;
}