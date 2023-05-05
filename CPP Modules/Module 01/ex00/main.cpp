#include "Zombie.hpp"

int main(void) 
{
	Zombie *heap;

	heap = newZombie("Heap");
	heap->announce();
	randomChump("Stack");

	delete heap;
	return 0;
}