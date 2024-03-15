#pragma once 

#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat{
  private:
    const std::string   Name;
    int                 Grade;
  public:
    Bureaucrat();
    Bureaucrat(const std::string &Name, int grade);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);
    class GradeTooHighException : public std::exception {
        public:
        const char * what () const throw(){
            return "grade too High";
        }
    };
    class GradeTooLowException : public std::exception {
        public:
        const char * what () const throw(){
            return "Grade too low";}
    };
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signedForm(AForm &obj);
    void executeForm(AForm const &obj);
    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj);