
#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat _b("Alex", 152);
        std::cout << _b;

        std::cout << "incrementing bureaucrat " << _b.getName() << " ..." << std::endl; 
        _b.incrementGrade();
        _b.incrementGrade();
        _b.incrementGrade();
        _b.decrementGrade();
        _b.incrementGrade();
        _b.incrementGrade();
        _b.incrementGrade();
        _b.incrementGrade();
        _b.incrementGrade();
        _b.incrementGrade();
        _b.incrementGrade();
        std::cout << _b;
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
}