#include "Form.hpp"

Form::Form() : Name(""), Gradetosigne(150), Gradetoexecute(150){
    std::cout << "Form : Default constructor called" << std::endl;
    SignedForm = false;
}

Form::Form(std::string const &Name, const int Gradetosigne, const int Gradetoexecute) : Name(Name), Gradetosigne(Gradetosigne), Gradetoexecute(Gradetoexecute){
    std::cout << "Form : constructor with parameters called" << std::endl;
    if (Gradetosigne > 150 || Gradetoexecute > 150)
        throw GradeTooLowException();
    if (Gradetosigne < 1 || Gradetoexecute < 1)
        throw GradeTooHighException();
    SignedForm = false;
}

Form::Form(const Form &obj) : Name(obj.Name), Gradetosigne(obj.Gradetosigne), Gradetoexecute(obj.Gradetoexecute){
    std::cout << "form : Copy constructor called" << std::endl;
    *this = obj;
}

Form &Form::operator=(const Form &obj){
    std::cout << "Form : assignment operator called" << std::endl;
    if (this != &obj)
        SignedForm = false;
    return (*this);
}

const std::string Form::getName() const{
    return Name;
}

int Form::getGradetoSigne() const{
    return Gradetosigne;
}

int Form::getGradetoExecute() const{
    return Gradetoexecute;
}

void Form::setSigned(bool ret) {
    SignedForm = ret;
}

bool Form::isSigned()const{
    return SignedForm;
}

void Form::beSigned(const Bureaucrat &obj){
    if (obj.getGrade() > Gradetosigne)
        throw GradeTooLowException();
    SignedForm = true;
}

std::ostream &operator << (std::ostream& os, const Form& obj)
{
    os << "Form Name : " << obj.getName() << std::endl;
    os << "Is signed : " << obj.isSigned() << std::endl;
    os << "Grade to signe: " << obj.getGradetoSigne() << std::endl;
    os << "Grade to execute: " << obj.getGradetoExecute() << std::endl;
    return (os);
}

Form::~Form(){
    std::cout << "Form : Destructor called" << std::endl;
}