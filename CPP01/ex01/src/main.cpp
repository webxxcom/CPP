#include "Zombie.h"
#include <iostream>

int main(){
    const int   N = 5;
    Zombie *z = zombieHorde(N, "Zombie");

    for(int i = 0; i < N; ++i)
    {
        std::cout << i << ") ";
        z[i].announce();
    }
    delete[] z;
    return 0;
}