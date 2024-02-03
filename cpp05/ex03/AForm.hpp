#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm{
  private:
    const std::string  Target;
    const std::string Name;
    bool SignedForm;
    const int Gradetosigne;
    const int Gradetoexecute;
  public:

    AForm();
    AForm(std::string const &target, std::string const &Name,  const int gradetosigne, const int gradetoexecute);
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);
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
    class NotSignedAForm : public std::exception{
            public:
            const char * what () const throw(){
                return "AForm Not Signed";
            }
    };
    const std::string getName() const;
    std::string getTarget() const;
    int  getGradetoSigne() const;
    int  getGradetoExecute() const;
    bool isSigned() const;
    void setSigned(bool ret);
    void beSigned(const Bureaucrat &obj);
    virtual void execute(Bureaucrat const & executor) const = 0;
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream& out, const AForm& b);