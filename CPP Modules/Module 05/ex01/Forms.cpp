#include "Forms.hpp"

Forms::Forms(void){
    this->_name = "Unknown";
    this->_isSigned = false;
    this->_gradeLevelSign = 150;
    this->_gradeLevelExecution = 150;
}

Forms::Forms(const std::string name, int signGrade, int execGrade) {
    this->_name = name;
    this->_isSigned = false;
    if (signGrade < 1 || execGrade < 1)
        throw gradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw gradeTooLowException();
    else if (signGrade > execGrade)
        throw gradeTooHighException();
    else {
        this->_gradeLevelSign = signGrade;
        this->_gradeLevelExecution = execGrade;
    }
}

Forms::Forms(Forms const &oldForm) {
    *this = oldForm;
    std::cout << "Form Photocopied" << std::endl;
}

Forms::~Forms(void) 
{
    std::cout << ANSI_BOLD << this->_name << " Form " ANSI_RESET "got lit on fire and tossed out the window" << std::endl;
}

Forms &Forms::operator=(Forms const &toCopy) 
{
    this->_name = toCopy._name;
    this->_isSigned = toCopy._isSigned;
    this->_gradeLevelExecution = toCopy._gradeLevelExecution;
    this->_gradeLevelSign = toCopy._gradeLevelSign;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, Forms const &obj)
{
	out << ANSI_BOLD << obj.getName() << " Form; " ANSI_RESET << std::endl;
	out << ANSI_BOLD ANSI_COLOR_BGREEN "Status: " ANSI_RESET << obj.isSigned() << std::endl;
	out << ANSI_BOLD ANSI_COLOR_BBLUE "Grade to sign: " ANSI_RESET << obj.getSignGrade() << std::endl;
	out << ANSI_BOLD ANSI_COLOR_BMAGENTA "Grade to execute: " ANSI_RESET << obj.getExecGrade() << std::endl;
	return (out);
}

std::string Forms::getName(void) const 
{
    return (this->_name);
}

int Forms::getSignGrade(void) const 
{
    return (this->_gradeLevelSign);
}

int Forms::getExecGrade(void) const 
{
    return (this->_gradeLevelExecution);
}

std::string Forms::isSigned(void) const 
{
    if (_isSigned)
        return("True");
    else
        return("False");
}

void Forms::setSignature(bureucrat const &bcrat) 
{
   if (this->_isSigned == true)
        std::cout << "Form already signed mate" << std::endl;
    else if (this->_gradeLevelSign < bcrat.getGrade()){
        std::cout << "Bureucrat " ANSI_INFO ANSI_UNDERLINE << bcrat.getName() << ANSI_RESET " not qualified to sign this form." << std::endl;
        throw gradeTooLowException();
    }
    else 
    {
        this->_isSigned = true;
        std::cout << "Bureucrat " ANSI_INFO ANSI_UNDERLINE << bcrat.getName() << ANSI_RESET " has signed the " << this->_name << " form" << std::endl;
    }
        
}

const char *Forms::gradeTooLowException::what(void) const throw()
{
    return(ANSI_WARN "Warning: " ANSI_RESET "Bureucrats Grade is too low and cant sign this form");
} 

const char *Forms::gradeTooHighException::what(void) const throw()
{
    return(ANSI_WARN "Warning: " ANSI_RESET "Grade is too high should be between 1 & 150");
} 