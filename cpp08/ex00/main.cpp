#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int>m(4);
    std::vector<int>::iterator ptr;
    m[0] = 10;
    m[1] = 20;
    m[2] = 30;
    m[3] = 30;
    try
    {
        ptr = easyfind(m, 1);
        std::cout << *ptr << std::endl;
    }
    catch(const not_found& e)
    {
        std::cerr << e.what() << '\n';
    }
}