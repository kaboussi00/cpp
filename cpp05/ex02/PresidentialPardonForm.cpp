#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", "PresidentialPardonForm", 25, 5){
    std::cout << "PresidentialPardonForm : Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, "PresidentialPardonForm", 25, 5){
    std::cout << "PresidentialPardonForm : constructor with param called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj.getTarget(), obj.getName(), obj.getGradetoSigne(), obj.getGradetoExecute()){
    std::cout << "PresidentialPardonForm : Copy constructor called" << std::endl;
    *this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
    std::cout << "PresidentialPardonForm : assignment operator called" << std::endl;
    AForm::operator=(obj);
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > getGradetoExecute())
        throw (GradeTooLowException());
    if (this->isSigned() == false)
        throw (NotSignedAForm());
    std::cout << getTarget() << " has been pardoned by " << executor.getName() <<"." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm : Destructor called" << std::endl;
}
