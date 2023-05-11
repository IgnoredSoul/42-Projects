#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	return;
}

Dog::~Dog(void)
{
	delete this->brain;
	return;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	this->brain = new Brain();
	*this = other;
	return;
}

Dog	&Dog::operator=(const Dog &other)
{
	this->type = other.type;
	*(this->brain) = *(other.brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << ANSI_COLOR_BBLUE << this->getType() << ANSI_RESET ": Woof" << std::endl;
}

Brain	*Dog::get_brain(void) const
{
	return (this->brain);
}