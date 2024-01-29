#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name(""){
  std::cout << "Bureaucrat : Default constructor called" << std::endl;
  Grade = 150;
}

Bureaucrat::Bureaucrat(std::string const &Name, int grade) : Name(Name){
    std::cout << "Bureaucrat : constructor with parameters called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->Grade=grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : Name(obj.getName()){
    std::cout << "Bureaucrat : Copy constructor called" << std::endl;
    *this = obj;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj){
    std::cout << "Bureaucrat : Assignment operator called" << std::endl;
    if (this != &obj){
      this->Grade = obj.Grade;
    }
    return (*this);
}

const std::string Bureaucrat::getName() const{
    return Name;
}

int Bureaucrat::getGrade() const{
    return Grade;
}

void Bureaucrat::incrementGrade(){
  if (Grade > 1 && Grade <= 150)
    Grade--;
  else
    throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
  if (Grade >= 1 && Grade < 150)
    Grade++;
  else
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat :  Destructor called" << std::endl;
}

void Bureaucrat::signedForm(AForm &obj){
    try{
        obj.beSigned(*this);
        std::cout << Name << " signed " << obj.getName() << std::endl;}
    catch(const std::exception& ex){
      std::cout << Name << " couldn't signed " << obj.getName() << " because "<< ex.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &obj){
	try{
		obj.execute(*this);
		std::cout << Name << " executed " << obj.getName() << std::endl;
	}
	catch (std::exception& ex){
		std::cout << "Cannot execute Form because: " << ex.what() << std::endl;
}}

std::ostream &operator << (std::ostream& os, const Bureaucrat& obj){
  os <<obj.getName() << ", bureaucrat grade is " << obj.getGrade() << std::endl;
  return (os);
}