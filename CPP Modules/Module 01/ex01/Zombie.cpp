#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zom;
    std::string n;

    zom = (Zombie *)malloc(sizeof(Zombie) * N);
    for (int i = 0; i < N; i++)
        zom[i].setname(name + " (" + std::to_string(i+1)+")");
    return (zom);
}