#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	return;
}

Cat::~Cat(void)
{
	return;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	return;
}

Cat	&Cat::operator=(const Cat &other)
{
	this->type = other.getType();
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << ANSI_COLOR_BYELLOW << this->getType() << ANSI_RESET << ": \"Meow\"" << std::endl;
}