#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &obj);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
        void execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();
};