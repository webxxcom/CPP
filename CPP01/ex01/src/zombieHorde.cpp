#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name){
    Zombie *zs = new Zombie[N];

    for(int i = 0; i < N; ++i)
        zs[i] = Zombie(name);
    return (zs);
}