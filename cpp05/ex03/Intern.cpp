#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern : default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj){
    std::cout << "Intern : copy constructor called" << std::endl;
    (void) obj;
}

Intern &Intern::operator=(const Intern &obj){
    std::cout << "Intern : assignment operator called" << std::endl;
    (void) obj;
    return (*this);
}

AForm *Intern::makeForm(std::string const &form, std::string const &target){
    const std::string forms[3] = {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm",
    };
    int i = 0;
    while (i < 3 && form != forms[i])
        i++;
    switch (i){
        case 0:{
            std::cout << "Intern creates " << forms[i] << std::endl;
            return (new PresidentialPardonForm(target));
        }
        case 1:
            std::cout << "Intern creates " << forms[i] << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << forms[i] << std::endl;
            return (new ShrubberyCreationForm(target));
        case 3:
            throw InvalidForm();
    }
    return (NULL);
}

Intern::~Intern(){
    std::cout << "Intern : destructor called\n";
}