#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():Name("none") 
{
    this->Grade = LOWEST;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade):Name(Name) 
{
    if (Grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    if (Grade > LOWEST)
        throw  Bureaucrat::GradeTooLowException();
    this->Grade = Grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) 
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & obj) 
{
    if (obj.Grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    if (obj.Grade > LOWEST)
        throw  Bureaucrat::GradeTooLowException();
    this->Grade = obj.Grade;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj) 
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return o;
}

std::string Bureaucrat::getName() const 
{
    return this->Name;
}

int Bureaucrat::getGrade() const 
{
    return this->Grade;
}

void Bureaucrat::incrementGrade() 
{
    this->Grade--;
    if (this->Grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() 
{
    this->Grade++;
    if (this->Grade > LOWEST)
        throw  Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ANSI_ERROR ANSI_UNDERLINE "ERROR:" ANSI_RESET " TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ANSI_ERROR ANSI_UNDERLINE "ERROR:" ANSI_RESET " TooLowException";
}