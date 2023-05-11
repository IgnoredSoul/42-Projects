#include "Bureaucrat.hpp"

bureucrat::bureucrat(void) 
{
    this->_name = "Usual Drongo Bureucrat";
    this->_grade = 150;
}

bureucrat::bureucrat(const std::string name, int grade) 
{
    this->_name = name;
    if (grade < 1)
        throw gradeTooHighException();
    else if (grade > 150)
        throw gradeTooLowException();
    else 
        this->_grade = grade;
}

bureucrat::bureucrat(bureucrat const &oldBureucrat) 
{
    *this = oldBureucrat;
}

bureucrat &bureucrat::operator=(bureucrat const &toCopy)
{
    this->_grade = toCopy._grade;
    this->_name = toCopy._name;
    return(*this);
}

std::ostream &operator<<(std::ostream &stream, bureucrat const &bCrat) 
{
    stream << "Bureucrat: " << ANSI_BOLD ANSI_COLOR_BCYAN << bCrat.getName() << ANSI_RESET << " - Official Grade: " << bCrat.getGrade() << std::endl;
    return(stream);
}

int bureucrat::getGrade(void) const 
{
    return(this->_grade);
}

std::string bureucrat::getName(void) const 
{
    return(this->_name);
}

void bureucrat::incrementGrade(void) 
{
    if (_grade == 1)
        throw cannotIncrement();
    else
        this->_grade--;
}

void bureucrat::decrementGrade(void) 
{
    if (_grade == 150)
        throw gradeTooLowException();
    else
        this->_grade++;
}

const char *bureucrat::gradeTooLowException::what(void) const throw()
{
    return(ANSI_WARN "Warning: " ANSI_RESET "Grade is too low should be between 1 & 150");
} 

const char *bureucrat::gradeTooHighException::what(void) const throw()
{
    return(ANSI_WARN "Warning: " ANSI_RESET "Grade is too high should be between 1 & 150");
} 

const char *bureucrat::cannotIncrement::what(void) const throw()
{
    return(ANSI_WARN "Warning: " ANSI_RESET "Grade is already at maximum, can't increment");
} 

const char *bureucrat::cannotDecrement::what(void) const throw()
{
    return(ANSI_WARN "Warning: " ANSI_RESET "Grade is already at maximum, can't increment");
} 