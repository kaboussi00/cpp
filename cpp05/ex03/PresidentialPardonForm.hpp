#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &obj);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        void execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
};