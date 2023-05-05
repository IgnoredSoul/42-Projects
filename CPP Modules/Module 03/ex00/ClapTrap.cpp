#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :	_Name(), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0)
{

}

ClapTrap::ClapTrap(std::string Name) :  _Name(Name), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0)
{
}

ClapTrap::ClapTrap(ClapTrap &clapTrap)
{
	*this = clapTrap;
}

std::string	&ClapTrap::getName()
{
	return (_Name);
}

void ClapTrap::setName(std::string &Name)
{
	_Name = Name;
}

int &ClapTrap::getHitpoints()
{
	return (_Hitpoints);
}

void ClapTrap::setHitpoints(int Hitpoints)
{
	_Hitpoints = Hitpoints;
}

int	&ClapTrap::getEnergyPoints()
{
	return (_EnergyPoints);
}

void ClapTrap::setEnergyPoints(int EnergyPoints)
{
	_EnergyPoints = EnergyPoints;
}

int &ClapTrap::getAttackDamage()
{
	return (_AttackDamage);
}

void ClapTrap::setAttackDamage(int AttackDamage)
{
	_AttackDamage = AttackDamage;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clapTrap2)
{
	if (this != &clapTrap2)
	{
		this->_Name = clapTrap2._Name;
		this->_Hitpoints = clapTrap2._Hitpoints;
		this->_EnergyPoints = clapTrap2._EnergyPoints;
		this->_AttackDamage = clapTrap2._AttackDamage;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, ClapTrap &clapTrap)
{
	stream << ANSI_COLOR_BGREEN << "Name: " << ANSI_RESET << clapTrap.getName() 
    << ANSI_COLOR_BRED << " • Hitpoints: " << ANSI_RESET << clapTrap.getHitpoints()
    << ANSI_COLOR_BYELLOW << " • Energy Points: " << ANSI_RESET << clapTrap.getEnergyPoints()
    << ANSI_COLOR_BRED << " • Attack Damage: " << ANSI_RESET << clapTrap.getAttackDamage();
	return (stream);
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << this->getName() << " has " << ANSI_COLOR_BRED ANSI_BOLD << "attacked " << ANSI_RESET << target << ", " << "causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_EnergyPoints -= amount;
	std::cout << this->getName() << " has "
    << ANSI_COLOR_BRED ANSI_BOLD << "lost " << ANSI_RESET
    << amount << " healthpoints." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_EnergyPoints += amount;
	std::cout << this->getName() << " has "
    << ANSI_COLOR_BGREEN ANSI_BOLD << "recovered " << ANSI_RESET
    << amount << " healthpoints." << std::endl;
}