#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	return;
}

Dog::~Dog(void)
{
	return;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	*this = other;
	return;
}

Dog	&Dog::operator=(const Dog &other)
{
	this->type = other.getType();
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << ANSI_COLOR_BBLUE << this->getType() << ANSI_RESET << ": \"Woof\"" << std::endl;
}