#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	return;
}

Animal::~Animal(void)
{
	return;
}

Animal::Animal(Animal const &other)
{
	*this = other;
	return;
}

Animal &Animal::operator=(const Animal &other)
{
    if ((this->type == "Cat" || this->type == "Dog") && (other.type == "Cat" || other.type == "Dog"))
        *get_brain() = *other.get_brain();
    this->type = other.type;
	return *this;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

Brain	*Animal::get_brain(void) const
{
	return (NULL);
}