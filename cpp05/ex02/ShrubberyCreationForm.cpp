#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", "ShrubberyCreationForm", 145, 137){
    std::cout << "ShrubberyCreationForm : default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, "ShrubberyCreationForm", 145, 137){
    std::cout << "ShrubberyCreationForm : constructor with param called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getTarget(), obj.getName(), obj.getGradetoSigne(), obj.getGradetoExecute()){
    std::cout << "ShrubberyCreationForm : copy constructor called" << std::endl;
    *this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){
    std::cout << "ShrubberyCreationForm : assignment operator called" << std::endl;
    AForm::operator=(obj);
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > getGradetoExecute())
        throw (GradeTooLowException());
    if (this->isSigned() == false)
        throw (NotSignedAForm());
    std::ofstream   file(executor.getName() + "_shrubbery");
    if (!file.is_open()){
        std::cout << "Can't open file!" << std::endl;
        return;
    }
    file << ARBRE;
    std::cout << "Form : " << getName() << " executed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm : destructor called" << std::endl;
}