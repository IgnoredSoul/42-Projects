#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include "AnsiColorSheet.hpp"

class ClapTrap
{
	protected:

		std::string	_Name;
		int _Hitpoints;
		int _EnergyPoints;
		int _AttackDamage;
	
	public:

		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(ClapTrap &clapTrap);
		ClapTrap &operator=(ClapTrap const &clapTrap2);

		std::string &getName();
		void setName(std::string &Name);
		int	&getHitpoints();
		void setHitpoints(int Hitpoints);
		int	&getEnergyPoints();
		void setEnergyPoints(int EnergyPoints);
		int	&getAttackDamage();
		void setAttackDamage(int AttackDamage);

		virtual void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &stream, ClapTrap &clapTrap);

#endif