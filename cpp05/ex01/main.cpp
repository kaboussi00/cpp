#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat ll("name", 89);
        Form b("kautar",8989,89);
        b.beSigned(ll);
        b.beSigned(ll);
        std::cout << b ;
    }
    catch(const std::exception & y){
        std::cout << y.what() << std::endl;
    }
    std::cout<< "-----------------\n";
    try
    {
        Bureaucrat jaeskim("jaeskim", 2);
        std::cout << jaeskim;
        jaeskim.incrementGrade();
        jaeskim.incrementGrade();
        std::cout << jaeskim;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}