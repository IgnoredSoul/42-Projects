#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include "AnsiColorSheet.hpp"


using std::endl;
using std::cout;
using std::cin;
using std::string;

class Harl 
{
	public:
	Harl();
	void complain(std::string level);

	private:
	struct _lut
	{
		string level;
		void (Harl::*f)(void);
	};
	struct _lut	lut[4];
	void info(void);
	void debug(void);
	void warning(void);
	void error(void);

};

#endif