#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "──────────────────────────── FRAGTRAP MAIN ────────────────────────────\n" << std::endl;

	FragTrap	FragTrapA("FragTrap A");
	FragTrap	FragTrapB("FragTrap B");

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapA.attack(FragTrapB.getName());
	FragTrapB.takeDamage(FragTrapA.getAttackDamage());

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.beRepaired(5);

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.highFivesGuys();

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	return (0);
}