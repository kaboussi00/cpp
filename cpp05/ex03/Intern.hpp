#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{  
    public:
        Intern();
        Intern(Intern const &obj);
        Intern &operator=(const Intern &obj);
        class InvalidForm : public std::exception {
            public:
            const char * what () const throw(){
                return "invalid form";
            }
        };
        AForm *makeForm(std::string const &form, std::string const &target);
        ~Intern();
};
