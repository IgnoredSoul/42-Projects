#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	return;
}

Animal::~Animal(void)
{
	return;
}

Animal::Animal(Animal const &other) : type(other.type)
{
	return;
}

Animal &Animal::operator=(Animal const &other)
{
	type = other.type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << ANSI_COLOR_BGREEN << this->getType() << ANSI_RESET << ": Some noise" << std::endl;
}

std::string	Animal::getType(void) const
{
	if(type == "Dog")
		return (ANSI_COLOR_BBLUE + type + ANSI_RESET);
	else
		return (ANSI_COLOR_BYELLOW + type + ANSI_RESET);
}