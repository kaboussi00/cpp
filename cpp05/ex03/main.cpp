#include "Intern.hpp"

int main(){
    try{
    Bureaucrat b("kk", 1);
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
    b.signedForm(*rrf);
    b.executeForm(*rrf);
    std::cout << b.getGrade() << std::endl;
    b.decrementGrade();
    std::cout << b.getGrade() << std::endl;
    }
    catch(std::exception const &ex){
        std::cout << ex.what() << std::endl;
    }
}