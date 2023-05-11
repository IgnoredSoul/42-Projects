#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	return;
}

Cat::~Cat(void)
{
	delete this->brain;
	return;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->brain = new Brain();
	*this = other;
	return;
}

Cat	&Cat::operator=(const Cat &other)
{
	this->type = other.type;
	*(this->brain) = *(other.brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain	*Cat::get_brain() const
{
	return (this->brain);
}