#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "Type: " << dog->getType() << " " << std::endl;
	std::cout << "Type: " << cat->getType() << " " << std::endl;
	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	const WrongAnimal* wcat = new WrongCat();

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "Type: " << wcat->getType() << " " << std::endl;
	wcat->makeSound();

	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
	WrongCat wcat2;
	std::cout << "Type: " << wcat2.getType() << " " << std::endl;
	wcat2.makeSound();
	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;

	delete wcat;
	return (0);
}