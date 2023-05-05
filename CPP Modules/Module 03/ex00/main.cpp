#include "ClapTrap.hpp"

int	main()
{
	std::cout << "──────────────────────────── CLAPTRAP MAIN ────────────────────────────\n" << std::endl;

	ClapTrap ClaptrapA("Claptrap A");
	ClapTrap ClaptrapB("Claptrap B");

	ClapTrap ClapTrapC(ClaptrapA);

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	ClaptrapA.attack(ClaptrapB.getName());
	ClaptrapB.takeDamage(ClaptrapA.getAttackDamage());

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	ClaptrapB.beRepaired(5);

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;
    
    std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
	return (0);
}