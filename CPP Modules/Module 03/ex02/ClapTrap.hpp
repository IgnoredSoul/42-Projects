#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

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

#ifndef ANSI_COLOR_H
#define ANSI_COLOR_H

// ANSI color codes for text color
#define ANSI_COLOR_BLACK     "\x1b[30m"
#define ANSI_COLOR_RED       "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_YELLOW    "\x1b[33m"
#define ANSI_COLOR_BLUE      "\x1b[34m"
#define ANSI_COLOR_MAGENTA   "\x1b[35m"
#define ANSI_COLOR_CYAN      "\x1b[36m"
#define ANSI_COLOR_WHITE     "\x1b[37m"

#define ANSI_COLOR_BBLACK     "\x1b[30m"
#define ANSI_COLOR_BRED       "\x1b[31m"
#define ANSI_COLOR_BGREEN     "\x1b[32m"
#define ANSI_COLOR_BYELLOW    "\x1b[33m"
#define ANSI_COLOR_BBLUE      "\x1b[34m"
#define ANSI_COLOR_BMAGENTA   "\x1b[35m"
#define ANSI_COLOR_BCYAN      "\x1b[36m"
#define ANSI_COLOR_DWHITE     "\x1b[37m"

// ANSI color codes for background color
#define ANSI_BG_BLACK        "\x1b[40m"
#define ANSI_BG_RED          "\x1b[41m"
#define ANSI_BG_GREEN        "\x1b[42m"
#define ANSI_BG_YELLOW       "\x1b[43m"
#define ANSI_BG_BLUE         "\x1b[44m"
#define ANSI_BG_MAGENTA      "\x1b[45m"
#define ANSI_BG_CYAN         "\x1b[46m"
#define ANSI_BG_WHITE        "\x1b[47m"

// ANSI color codes for text formatting
#define ANSI_BOLD            "\x1b[1m"
#define ANSI_UNDERLINE       "\x1b[4m"
#define ANSI_BLINK           "\x1b[5m"
#define ANSI_REVERSE         "\x1b[7m"
#define ANSI_RESET           "\x1b[0m"

#endif /* ANSI_COLOR_H */