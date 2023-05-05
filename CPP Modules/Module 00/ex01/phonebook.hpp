#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	public:
	std::string name;
	std::string Last_name;
	std::string Nick_name;
	std::string secret;
	std::string phone;

	void display(void)
	{
		std::cout << name;
		std::cout << " : ";
		std::cout << phone << std::endl;
	}
};

class PhoneBook
{
	public:
	Contact Cons[8];
	int num;
};

#endif