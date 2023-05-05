#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	this->setType(weaponType);
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string const &Weapon::getType()
{
	return (this->_type);
}

void		Weapon::setType(std::string weaponType)
{
	this->_type = weaponType;
}