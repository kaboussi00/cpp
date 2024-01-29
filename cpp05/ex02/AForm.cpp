#include "AForm.hpp"

AForm::AForm() : Target(""),  Name(""), Gradetosigne(150), Gradetoexecute(150){
    std::cout << "AForm : Default constructor called" << std::endl;
    SignedForm = false;
}

AForm::AForm(std::string const &target, std::string const &Name, const int Gradetosigne, const int gradetoeGradetoexecute) : Target(target) , Name(Name), Gradetosigne(Gradetosigne), Gradetoexecute(gradetoeGradetoexecute){
    std::cout << "AForm : constructor with parameters called" << std::endl;
    if (Gradetosigne > 150 || gradetoeGradetoexecute > 150)
        throw GradeTooLowException();
    if (Gradetosigne < 1 || gradetoeGradetoexecute < 1)
        throw GradeTooHighException();
    SignedForm = false;
}

AForm::AForm(const AForm &obj) : Target(obj.Target), Name(obj.Name), Gradetosigne(obj.Gradetosigne), Gradetoexecute(obj.Gradetoexecute){
    std::cout << "Aform : Copy constructor called" << std::endl;
    *this = obj;
}

AForm &AForm::operator=(const AForm & obj){
    std::cout << "AForm : assignment operator called" << std::endl;
    (void)obj;
    return (*this);
}

const std::string AForm::getName() const{
    return Name;
}

std::string AForm::getTarget() const{
    return Target;
}

int AForm::getGradetoSigne() const{
    return Gradetosigne;
}

int AForm::getGradetoExecute() const{
    return Gradetoexecute;
}

void AForm::setSigned(bool ret) {
    SignedForm = ret;
}

bool AForm::isSigned()const{
    return SignedForm;
}

void AForm::beSigned(const Bureaucrat &obj){
    if (obj.getGrade() > Gradetosigne)
        throw GradeTooLowException();
    SignedForm = true;
}

std::ostream &operator << (std::ostream& os, const AForm& obj)
{
    os << "Form Name : " << obj.getName() << std::endl;
    os << "Is signed : " << obj.isSigned() << std::endl;
    os << "Grade to signe: " << obj.getGradetoSigne() << std::endl;
    os << "Grade to execute: " << obj.getGradetoExecute() << std::endl;
    return (os);
}

AForm::~AForm(){
    std::cout << "AForm : Destructor called" << std::endl;
}