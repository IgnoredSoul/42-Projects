#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	return;
}

WrongAnimal::~WrongAnimal(void)
{
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	*this = other;
	return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	this->type = other.getType();
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << ANSI_BG_YELLOW << this->getType() << ANSI_RESET << ": \"Some noise\"" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (ANSI_BG_YELLOW + this->type + ANSI_RESET);
}