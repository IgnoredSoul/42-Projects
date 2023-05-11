#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

#include <iostream>
#include "AnsiColorSheet.hpp"

class bureucrat 
{
    private:
        std::string _name;
        int         _grade;

    public:

        bureucrat(void);
        bureucrat(const std::string name, int grade);
        bureucrat(bureucrat const &oldBureucrat);
    
        bureucrat &operator=(bureucrat const &toCopy);
    
        int getGrade(void) const;
        std::string getName(void) const;
    
        void    incrementGrade(void);
        void    decrementGrade(void);
    
        class gradeTooHighException: public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };
        
        class gradeTooLowException: public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };
        
         class cannotIncrement: public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };
        
         class cannotDecrement: public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, bureucrat const &bCrat);

#endif