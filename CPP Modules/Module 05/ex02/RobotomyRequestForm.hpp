#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public Form 
{
    public:

        RobotomyRequestForm();
        RobotomyRequestForm(std::string Target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(RobotomyRequestForm const & obj);
        void action() const;
    
	private:

        std::string Target;
};