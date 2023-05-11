#include "Bureaucrat.hpp"

int main(void) 
{
    // Passing
	try 
	{
        Bureaucrat bureaucrat("Soul", 2);
        std::cout << bureaucrat << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << "TooHighException" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << "TooLowException" << std::endl;
    }

    // Too High
    try 
	{
        Bureaucrat bureaucrat1("bob", 1);
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << ANSI_ERROR ANSI_UNDERLINE "ERROR:" ANSI_RESET " TooHighException" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << ANSI_ERROR ANSI_UNDERLINE "ERROR:" ANSI_RESET " TooLowException" << std::endl;
    }

    // Too Low
    try 
	{
        Bureaucrat bureaucrat2("bob", 150);
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << e.what() << std::endl;
    }
}