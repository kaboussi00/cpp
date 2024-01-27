#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form{
  private:
    const std::string Name;
    bool SignedForm;
    const int Gradetosigne;
    const int Gradetoexecute;
  public:
    Form();
    Form(std::string const &Name, const int gradetosigne, const int gradetoexecute);
    Form(const Form &obj);
    Form &operator=(const Form &obj);
    class GradeTooHighException : public std::exception{
        public:
        const char * what () const throw(){
            return "Too High Grade";
        }
    };
    class GradeTooLowException : public std::exception {
        public:
        const char * what () const throw(){
            return "Too Low Grade";
        }
    };
    const std::string getName() const;
    int  getGradetoSigne() const;
    int  getGradetoExecute() const;
    bool isSigned() const;
    void setSigned(bool ret);
    void beSigned(const Bureaucrat &obj);
    ~Form();
};

std::ostream &operator<<(std::ostream& out, const Form& b);