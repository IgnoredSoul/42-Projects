#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)
{
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	*this = scavTrap;
}

ScavTrap &ScavTrap::operator=(ScavTrap &scavTrap)
{
	if (this != &scavTrap)
	{
		this->setName(scavTrap.getName());
		this->setHitpoints(scavTrap.getHitpoints());
		this->setEnergyPoints(scavTrap.getEnergyPoints());
		this->setAttackDamage(scavTrap.getAttackDamage());
	}
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "'" << this->getName() << "'" << " has entered in " << ANSI_COLOR_BYELLOW << "Gate keeper mode." << ANSI_RESET << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << this->getName() << " has " << ANSI_COLOR_BRED ANSI_BOLD << "attacked " << ANSI_RESET << target << ", " << "causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}