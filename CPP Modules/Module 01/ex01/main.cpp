#include "Zombie.hpp"

int	main(void)
{
	int number = 0;
	std::string	name;
	Zombie *z;

	std::cout << "────────────────────────────────────────" << std::endl;

	std::cout << "name of zombie\n> " && std::cin >> name && std::cout << std::endl;
	std::cout << "number of zombies\n> " && std::cin >> number && std::cout << std::endl;
    
	z = zombieHorde(number, name);

	std::cout << "────────────────────────────────────────" << std::endl;

	for (int i = 0; i < number; i++)
		z[i].announce();

	std::cout << "────────────────────────────────────────" << std::endl;

	for (int i = 0; i < number; i++)
		z[i].distroyz();

	free(z);

	std::cout << "────────────────────────────────────────" << std::endl;
}