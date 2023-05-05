#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
}

FragTrap::FragTrap(const std::string &Name) : ClapTrap(Name)
{
	setHitpoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	*this = fragTrap;
}

FragTrap &FragTrap::operator=(FragTrap &fragTrap)
{
	if (this != &fragTrap)
	{
		this->setName(fragTrap.getName());
		this->setHitpoints(fragTrap.getHitpoints());
		this->setEnergyPoints(fragTrap.getEnergyPoints());
		this->setAttackDamage(fragTrap.getAttackDamage());
	}
	return (*this);
}

void FragTrap::attack(std::string const & target)
{
	std::cout << this->getName() << " has " << ANSI_COLOR_BRED ANSI_BOLD << "attacked " << ANSI_RESET << target << ", " << "causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << this->getName() << ": \"HIGH FIVES GUYS!\"" << std::endl;
}