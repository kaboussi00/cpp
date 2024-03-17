#include "rpn.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "invalid arguments" << std::endl;
        return 1;
    }
    std::string exp = argv[1];
    try
    {
        int result = evaluateRPN(exp);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}