#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", "RobotomyRequestForm", 72, 45){
    std::cout << "RobotomyRequestForm : Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, "RobotomyRequestForm", 72, 45){
    std::cout << "RobotomyRequestForm : Constructor with param called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj.getTarget(), obj.getName(), obj.getGradetoSigne(), obj.getGradetoExecute()){
    std::cout << "RobotomyRequestForm : Copy constructor called" << std::endl;
    *this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
    std::cout << "RobotomyRequestForm : assignment operator called" << std::endl;
    AForm::operator=(obj);
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int i = 0;
    if (executor.getGrade() > getGradetoExecute())
        throw (GradeTooLowException());
    if (this->isSigned() == false)
        throw (NotSignedAForm());
    while(i < 10){
        if (i < 5)
            std::cout << executor.getName() << " has been robotomized successfully!" << std::endl;
        else
            std::cout << "The robotomy of " << executor.getName() << "failed!" << std::endl;
        i++;
    }
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm : Destructor called" << std::endl;
}