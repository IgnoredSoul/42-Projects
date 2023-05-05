#include "Harl.hpp"

int main()
{
    Harl harl;
	std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("ERROR");
    harl.complain("WARNING");
    std::cout << "───────────────────────────────────────────────────────────────────────" << std::endl;
    return 0;
}