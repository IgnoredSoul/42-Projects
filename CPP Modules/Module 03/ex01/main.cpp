#include "ScavTrap.hpp"

int	main()
{
	std::cout << "──────────────────────────── SCAVTRAP MAIN ────────────────────────────\n" << std::endl;

	ScavTrap ScavTrapA("ScavTrap A");
	ScavTrap ScavTrapB("ScavTrap B");

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapA.attack(ScavTrapB.getName());
	ScavTrapB.takeDamage(ScavTrapA.getAttackDamage());

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapB.beRepaired(5);

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	ScavTrapB.guardGate();

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	return (0);
}