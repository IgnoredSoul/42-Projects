#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	return;
}

WrongCat::~WrongCat(void)
{
	return;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	return;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type = other.getType();
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << ANSI_BG_YELLOW << this->getType() << ANSI_RESET << ": \"Meow\"" << std::endl;
}