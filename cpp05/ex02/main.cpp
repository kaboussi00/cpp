 #include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void)
{
    {
        Bureaucrat b("ana", 40);
        ShrubberyCreationForm shrubbery("home");
        b.executeForm(shrubbery);
        b.signedForm(shrubbery);
        b.executeForm(shrubbery);
    }
    std::cout << "--------------------------------\n";
    {
        Bureaucrat b("president", 1);
        PresidentialPardonForm pres("pres");
        b.signedForm(pres);
        b.executeForm(pres);
    }
    std::cout << "--------------------------------\n";
    {
        Bureaucrat b("robotomy", 1);
        RobotomyRequestForm robot("randomForm");
        b.signedForm(robot);
        b.executeForm(robot);
    }
}