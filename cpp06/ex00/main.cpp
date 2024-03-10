#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if (ac == 2)
    {
        std::string str;
        str = av[1];
        ScalarConverter a(str);
        a.convert(str);
    }
    else
        std::cout << "./convert param" << std::endl;
    return 0;
}
