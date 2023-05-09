#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form 
{
    public:

        PresidentialPardonForm();
        PresidentialPardonForm(std::string Target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(PresidentialPardonForm const & obj);
        void action() const;
    
	private:

        std::string Target;
};